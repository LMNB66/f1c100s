//==================获取键盘数据====================
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <string.h>
#include <unistd.h>


#define HOR 480
#define VER 272


int main(void)
{
    #define KEY_PATH	"/dev/input/event1"
	int fd = -1, ret = -1;
    int x=0, y=0;
	struct input_event ev;
	// 第1步：打开设备文件
	fd = open(KEY_PATH, O_RDONLY);
	if (fd < 0)
	{
		perror("open,error");
		return -1;
	}
    printf("welcome size=%d.\n",sizeof(struct input_event));
	
	while (1)
	{
		// 第2步：读取event事件包
		memset(&ev, 0, sizeof(struct input_event));
		ret = read(fd, &ev, sizeof(struct input_event));
		if (ret != sizeof(struct input_event))
		{
			perror("read,error");
			close(fd);
			return -1;
		}
		
		// 第3步：解析event包.
        printf("========================================================\n");
		//printf("[%11u] type: %3d, code: %3d, value: %3d \n",ev.time.tv_sec,ev.type,ev.code,ev.value);
        //type: 1:按键同步
        //code: 键码['a'=30]
        //value:0：按键释放，1：按键按下,2:长按下
        
        if(ev.type == EV_REL)
        {
            switch(ev.code)
            {
                case REL_X:
                    x += ev.value;
                    break;
                case REL_Y:
                    y += ev.value;
                    break;
            }
        }
        x = x>=HOR?HOR-1:(x<0?0:x);
        y = y>=VER?VER-1:(y<0?0:y);
        printf("x: %3d, y: %3d\n", x, y);

	}
 
	// 第4步：关闭设备
	close(fd);	
	return 0;
}
