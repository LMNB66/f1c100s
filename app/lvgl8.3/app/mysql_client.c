#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include "mysql_client.h"



#define HOST 		"192.168.43.198"    // 所连数据库的ip 127.0.0.1是本机ip
#define USER 		"lmnb"         		// 数据库用户
#define PASSWORD 	"123456"   			// 该用户密码（自设）
#define DBNAME 		"oems"       		// 要操作的数据库名

static int my_status = 0; 
static MYSQL *mysql = NULL;

int my_client_init(void)
{
	// 定义mysql指针并初始化
    mysql=mysql_init(NULL);
    if(mysql== NULL)
    {
        printf("mysql init error!\n");
		goto fail; 
    }
    // 初始化成功就连接数据库
    mysql = mysql_real_connect(mysql,HOST,USER,PASSWORD,DBNAME,0,NULL,0);
    if(mysql == NULL)
    {
        printf("connect err!\n");
        goto fail;
    }
    printf("mysql init ok!\n");
    printf("my_status: %d\n", my_status);
	return 0;
fail:
	my_status = 1;
	return -1;
}

int my_client_insert(measure_t *mea)
{
	char rSql[256]={0};
	
	if(my_status)
		return -1;
	if(mea == NULL)
		return -2;
	
	snprintf(rSql, sizeof(rSql), "INSERT INTO measure(hum,temp,soil,light,co2) VALUES('%.1f', '%.1f', '%.1f', '%.1f', '%d')", 
		mea->humidity, mea->temperature, mea->soil, mea->light, mea->co2);

	printf("rSql: %s\n", rSql);
	
	if(mysql_query(mysql,rSql) != 0)
	{
    	printf("mysql_query err\n");
    	return -3;
    }
	printf("mysql_query ok!\n");
	return 0;
}

int my_client_select(char *tn, char data[][10])
{
	char rSql[256]={0};
	MYSQL_RES *result = NULL;
	int i = 0;
	MYSQL_ROW row;
	
	if(my_status)
		return -1;
	
	snprintf(rSql, sizeof(rSql), "SELECT %s FROM measure order by id desc limit 50", tn);
	printf("rSql: %s\n", rSql);
	
	if(mysql_query(mysql,rSql) != 0)
	{
    	printf("mysql_query err\n");
    	return -2;
    }
	
	result = mysql_store_result(mysql);
	if(result == NULL)
	{
		printf("mysql no record!\n");
    	return -3;
	}
	
	while ((row = mysql_fetch_row(result)))//循环取一行
	{
	   if(row[0] != NULL)
	   {
		   memcpy(data[i], row[0], sizeof(row[0]));
	   }
	   else
	   {
		   memcpy(data[i], "0", 1);
	   }
	   i++;
	}
	return i;
}

void my_client_exit(void)
{
	if(my_status)
		return;
	mysql_close(mysql);
}

