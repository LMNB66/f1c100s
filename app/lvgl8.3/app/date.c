#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> 
#include "date.h"

#define DEST_PORT 80
#define DEST_IP_BY_NAME "quan.suning.com"


int date_modify(void)
{
    int sock_fd;
    struct sockaddr_in addr_serv;

    unsigned char cmd[128];
    unsigned char temp_buf[128];
    int i= 0, j= 0;
    memset(cmd, 0, sizeof(cmd));
    memset(temp_buf, 0, sizeof(temp_buf));

    int send_num;
    int recv_num;
    unsigned char send_buf [1024];
    unsigned char recv_buf [1024];
    memset(send_buf, 0, sizeof(send_buf));
    memset(recv_buf, 0, sizeof(recv_buf));
    
    //域名通过gethostbyname转换
    struct hostent* hostInfo = gethostbyname(DEST_IP_BY_NAME);
    if(NULL == hostInfo){
        printf("hostInfo is null\n");
        return -6;
    }
    memset(&addr_serv, 0, sizeof(addr_serv));
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = htons(DEST_PORT);
    // printf("Ip address = %s \n",inet_ntoa(*((struct in_addr*)hostInfo->h_addr)));
    memcpy(&addr_serv.sin_addr, &(*hostInfo->h_addr_list[0]), hostInfo->h_length);

    sock_fd=socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        perror("sock error");
        exit(1);
    }

    if (connect(sock_fd, (struct sockaddr*)(&addr_serv), sizeof(addr_serv)) < 0)
    {
        perror("connect error\n");
        exit(1);
    }
    
    //构建GET请求
    strcat(send_buf, "GET /getSysTime.do HTTP/1.1\r\n");
    strcat(send_buf,"Host: quan.suning.com\r\n");
    strcat(send_buf,"\r\n\r\n");

    send_num = send(sock_fd, send_buf,strlen(send_buf),0);
    if (send_num < 0)
    {
        perror("send error");
        exit(1);
    }
    else
    {
        recv_num = recv(sock_fd,recv_buf,sizeof(recv_buf),0);
        if(recv_num < 0){
            perror("recv");
            printf("recv error\n");
            exit(1);
        }
    }

    //解析服务器返回的时间数据，由于数据结构比较简单，就没有使用json解析
    send_num = 0;
    for(int i=0;i<recv_num;i++)
    {
        if(recv_buf[i] == '"'){
            send_num++;
        }
        if(send_num == 3){
            temp_buf[j++] = recv_buf[i];
        }
        if(send_num>3){ temp_buf[j++] = recv_buf[i];break;}
    }

    //构建命令修改系统时间 
    strcat(cmd, "date -s ");
    strcat(cmd, temp_buf);
    // printf("\n%s\n", cmd);
    system(cmd);

    close(sock_fd);
	return 0;
}