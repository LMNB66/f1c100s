#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <errno.h>
#include <mysql/mysql.h>


#define HOST 		"192.168.43.198"    // 所连数据库的ip 127.0.0.1是本机ip
#define USER 		"lmnb"         		// 数据库用户
#define PASSWORD 	"123456"   			// 该用户密码（自设）
#define DBNAME 		"oems"       		// 要操作的数据库名


#define lora_file				"/dev/lora"
#define serial_file				"/dev/ttyS1"

#define CHANNEL			0x17

//3 : 21dBm
//2 : 17dBm
//1 : 14dBm
//0 : 11dBm
#define POWER			0x02	

//7 ： 62.5K
//6 ： 50K
//5 ： 38.4K
//4 ： 19.2K
//3 ： 9.6K
//2 ： 4.8K
//1 ： 2.4K
//0 ： 1.2K
#define SPEED			0x02	

#define CPS				(unsigned short)((CHANNEL<<5)|(POWER<<3)|(SPEED))

#define LOCAL_GROUP		0x00
#define LOCAL_ADDR		0x00
#define TARGET_GROUP	0x00
#define TARGET_ADDR		0x00

#define AWAKEN_TIME		0x10

#define LORA_REG_VERSION		0x00
#define LORA_REG_CPS			0x06
#define LORA_REG_MODE			0x07
#define LORA_REG_SLEEP			0x14
#define LORA_REG_AWAKEN			0x17
#define LORA_REG_LGROUP			0x18
#define LORA_REG_LADDR			0x19
#define LORA_REG_TGROUP			0x1a
#define LORA_REG_TADDR			0x1b
#define LORA_REG_RESET			0x22

MYSQL *mysql = NULL;
int lora_fd = -1;
int serial_fd = -1;
unsigned char serial_buff[255];

/* set_opt(fd,115200,8,'N',1) */
int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop)
{
	struct termios newtio,oldtio;
	
	if ( tcgetattr( fd,&oldtio) != 0) { 
		perror("SetupSerial 1");
		return -1;
	}
	
	bzero( &newtio, sizeof( newtio ) );
	newtio.c_cflag |= CLOCAL | CREAD; 
	newtio.c_cflag &= ~CSIZE; 

	newtio.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/
	newtio.c_oflag  &= ~OPOST;   /*Output*/

	switch( nBits )
	{
		case 7:
			newtio.c_cflag |= CS7;
		break;
		case 8:
			newtio.c_cflag |= CS8;
		break;
	}

	switch( nEvent )
	{
		case 'O':
			newtio.c_cflag |= PARENB;
			newtio.c_cflag |= PARODD;
			newtio.c_iflag |= (INPCK | ISTRIP);
		break;
		case 'E': 
			newtio.c_iflag |= (INPCK | ISTRIP);
			newtio.c_cflag |= PARENB;
			newtio.c_cflag &= ~PARODD;
		break;
		case 'N': 
			newtio.c_cflag &= ~PARENB;
		break;
	}

	switch( nSpeed )
	{
		case 2400:
			cfsetispeed(&newtio, B2400);
			cfsetospeed(&newtio, B2400);
		break;
		case 4800:
			cfsetispeed(&newtio, B4800);
			cfsetospeed(&newtio, B4800);
		break;
		case 9600:
			cfsetispeed(&newtio, B9600);
			cfsetospeed(&newtio, B9600);
		break;
		case 115200:
			cfsetispeed(&newtio, B115200);
			cfsetospeed(&newtio, B115200);
		break;
		default:
			cfsetispeed(&newtio, B9600);
			cfsetospeed(&newtio, B9600);
		break;
	}
	
	if( nStop == 1 )
		newtio.c_cflag &= ~CSTOPB;
	else if ( nStop == 2 )
		newtio.c_cflag |= CSTOPB;
	
	newtio.c_cc[VMIN]  = 255;
	newtio.c_cc[VTIME] = 1;

	tcflush(fd,TCIFLUSH);
	
	if((tcsetattr(fd,TCSANOW,&newtio))!=0)
	{
		perror("com set error");
		return -1;
	}
	return 0;
}

int open_port(char *com)
{
	int fd;
	//fd = open(com, O_RDWR|O_NOCTTY|O_NDELAY);
	fd = open(com, O_RDWR|O_NOCTTY);
    if (-1 == fd){
		return(-1);
    }
	
	if(fcntl(fd, F_SETFL, 0)<0) /* 设置串口为阻塞状态*/
	{
		printf("fcntl failed!\n");
		return -1;
	}
  
	return fd;
}

int lora_send_bytes(unsigned char *data, int len)
{
	if(data == NULL)
		return -1;
	printf("tx:");
	for(int i=0;i<len;i++)
		printf("%02x ", data[i]);
	printf("\n");
	return write(serial_fd, data, len);
}

int lora_rece_bytes(unsigned char *data, int get_len)
{
	int len;
	len = read(serial_fd, serial_buff, 255);
	if(len)
	{
		printf("rx:");
		for(int i=0;i<len;i++)
			printf("%02x ", serial_buff[i]);
		printf("\n");
		if(get_len < len)
			len = get_len;
		if(data != NULL)
			memcpy(data, serial_buff, len);
		
		memset(serial_buff, 0, sizeof(serial_buff));
	}
	return len;
}

int lora_write_reg(unsigned char reg, unsigned char *data, int len)
{
	unsigned char i[3] = {0x80, reg, 0x01};
	if(lora_send_bytes(i, 3)<0)
		return -1;
	if(lora_send_bytes(data, len)<0)
		return -1;
	if(lora_rece_bytes(NULL, 0)<0)
		return -1;
	return 0;
}

int lora_read_reg(unsigned char reg, unsigned char *data, int get_len)
{
	int len;
	unsigned char i[3] = {0x00, reg, 0x01};
	if(lora_send_bytes(i, 3)<0)
		return -1;
	len = lora_rece_bytes(data, get_len);
	if(len<0)
		return -1;
	return len;
}

void lora_config(void)
{
	unsigned char d[2] = {0};
	
	if(write(lora_fd, d, 1) != 1)
		return;
	usleep(100000);
	
	d[0] = (unsigned char)(CPS>>8);
	d[1] = (unsigned char)CPS;
	lora_write_reg(LORA_REG_CPS, d, 2);
	
	d[0] = LOCAL_GROUP;
	lora_write_reg(LORA_REG_LGROUP, d, 1);
	d[0] = LOCAL_ADDR;
	lora_write_reg(LORA_REG_LADDR, d, 1);	
	
	d[0] = TARGET_GROUP;
	lora_write_reg(LORA_REG_TGROUP, d, 1);
	d[0] = TARGET_ADDR;
	lora_write_reg(LORA_REG_TADDR, d, 1);
	
	d[0] = AWAKEN_TIME;
	lora_write_reg(LORA_REG_SLEEP, d, 1);
	d[0] = 0x00;
	d[1] = 0x80;
	lora_write_reg(LORA_REG_AWAKEN, d, 2);
	
	d[0] = 1;
	write(lora_fd, d, 1);
	usleep(100000);
	d[0] = 2;
	write(lora_fd, d, 1);
	usleep(100000);
}

void lora_parse(void)
{
	unsigned char btmp[50];
	float humidity = 0, temperature = 0;
	float soil = 0;
	float light = 0;
	unsigned short co2 = 0, tvoc = 0;
	char rSql[256]={0};
	
	if(lora_rece_bytes(btmp, 50) < 0)
	{
		printf("rec err!\n");
		return;
	}
	
	humidity = ((unsigned short)btmp[0]<<8) | btmp[1];
	humidity /= 10;
	
	temperature = ((unsigned short)btmp[2]<<8) | btmp[3];
	temperature /= 10;
	
	soil = btmp[4];
	
	light = ((unsigned int)btmp[5]<<24) | ((unsigned int)btmp[6]<<16)
			|((unsigned int)btmp[7]<<8) | btmp[8];
	light /= 100;
	
	co2 = ((unsigned short)btmp[9]<<8) | btmp[10];
	tvoc = ((unsigned short)btmp[11]<<8) | btmp[12];
	
	printf("btmp:");
	for(int i=0;i<13;i++)
		printf("%02x ", btmp[i]);
	printf("\n");
	
	printf("sd: %.2f\n", humidity);
	printf("wd: %.2f\n", temperature);
	printf("tr: %.1f\n", soil);
	printf("gz: %.2f\n", light);
	printf("co2: %d\n", co2);
	printf("tvoc: %d\n", tvoc);
	
	//strcpy(rSql, "INSERT INTO measure(hum,temp,soil,light,co2,tvoc) VALUES('60.00', '28.10', '81.0', '57.50', '416', '34')");
		
	snprintf(rSql, sizeof(rSql), "INSERT INTO measure(hum,temp,soil,light,co2,tvoc) VALUES('%.2f', '%.2f', '%.1f', '%.2f', '%d', '%d')", 
		humidity, temperature, soil, light, co2, tvoc);

	
	printf("rSql: %s\n", rSql);
	
	if(mysql_query(mysql,rSql) != 0){
    	printf("mysql_query err\n");
    	exit(1);
    }
	printf("mysql_query ok!\n");
}

int main(int argc, char **argv)
{
	serial_fd = open_port(serial_file);
	if (serial_fd < 0)
	{
		printf("serial open err!\n");
		return -1;
	}

	if (set_opt(serial_fd, 9600, 8, 'N', 1))
	{
		printf("set port err!\n");
		return -1;
	}
	
	lora_fd = open(lora_file, O_WRONLY);
	if (lora_fd < 0)
	{
		printf("lora open err!\n");
		return -1;
	}
	lora_config();
	
	// 定义mysql指针并初始化
    mysql=mysql_init(NULL);
    if(mysql== NULL)
    {
        printf("mysql init error!\n");
        return -1;
    }
    // 初始化成功就连接数据库
    mysql = mysql_real_connect(mysql,HOST,USER,PASSWORD,DBNAME,0,NULL,0);
    if(mysql == NULL)
    {
        printf("connect err!\n");
        return -1;
    }
    printf("mysql init ok!\n");
	
	while(1)
	{
		lora_parse();
	}
	
	mysql_close(mysql);
	close(serial_fd);
	close(lora_fd);
	return 0;	
}














