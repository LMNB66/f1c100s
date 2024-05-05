/*************************************************************************
    > File Name: connect.c
    > Author: 杨永利
    > Mail: 1795018360@qq.com 
    > Created Time: 2020年08月14日 星期五 20时39分56秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// 定义连接时所需要的数据宏
#define HOST "192.168.43.198"    // 所连数据库的ip 127.0.0.1是本机ip
#define USER "lmnb"         // 数据库用户
#define PASSWORD "123456"   // 该用户密码（自设）
#define DBNAME "oems"       // 要操作的数据库名

// 打印结果集函数
void show_result(MYSQL_RES * result)
{
	//打印表头
	unsigned int num_fields;
	unsigned int i, j;
    // MYSQL_FIELD 该结构包含关于字段的信息，如字段名、类型和大小
	MYSQL_FIELD *fields;
	// 返回结果集中的行数。
	num_fields = mysql_num_fields(result);
    // mysql_fetch_fields 对于结果集，返回所有MYSQL_FIELD结构的数组。每个结构提供了结果集中1列的字段定义。
	fields = mysql_fetch_fields(result);
    // 输出结果
	for(i = 0; i < num_fields; i++)
	{
	   printf("%s\t", fields[i].name);
	}
    // 这个输出是打造表的结构边框便于查看数据，准确的输出按照你的数据自行增加减去+号
	printf("\n+----+-------+\n");
	
	// 行数
	MYSQL_ROW row;
	num_fields = mysql_num_fields(result);//取字段个数
	
	printf("num: %d\n", num_fields);
		
	while ((row = mysql_fetch_row(result)))//循环取一行
	{
	   for(i = 0; i < num_fields; i++)
	   {
           // 看是否为空
	       //printf("%s\t %d",  row[i] ? row[i] : "NULL", sizeof(row[i]));
		   if(row[i] != NULL)
		   {
				for(j=0;j<strlen(row[i]);j++)
				{
					printf("%c", row[i][j]);
				}
		   }
		   else
		   {
				printf("NULL");
		   }
		   printf("\t");
	   }
	   printf("\n");
	}
}


int main(int argc, char* argv[])
{
	char abc[] = "0";
	printf("%d, %d\n", sizeof(abc), strlen(abc));
    // 定义mysql指针并初始化
    MYSQL *mysql=mysql_init(NULL);
    if(mysql== NULL)
    {
        printf("init err! 数据库初始化错误！\n");
        return -1;
    }
    // 初始化成功就连接数据库
    mysql = mysql_real_connect(mysql,HOST,USER,PASSWORD,DBNAME,0,NULL,0);
    if(mysql == NULL)
    {
        printf("connect err! 数据库连接失败！ \n");
        return -1;
    }
    printf("数据库连接成功！\n"); 
    
    // 定义查询语句
    char rSql[256]={0};
    // 我的表名为example
    strcpy(rSql,"SELECT soil FROM measure order by id desc limit 10");
    // 查询指向的SQL查询
    if(mysql_query(mysql,rSql) != 0){
    	printf("mysql_query err! 查询失败\n");
    	exit(1);
    }

    // 取回结果集
    int i=0;
    // mysql_store_result()将查询的全部结果读取到客户端，分配1个MYSQL_RES结构，并将结果置于该结构中。
    MYSQL_RES * result = mysql_store_result(mysql);
    MYSQL_ROW row;
    if(result != NULL){
    	//需要打印结果集
    	show_result(result);
		mysql_free_result(result);//释放结果集
    }
    // 最后关闭连接
    mysql_close(mysql);
    printf("数据库关闭成功！\n");
    return 0;
}

