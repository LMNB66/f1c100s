#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	
	fd = open("/dev/lora", O_WRONLY);
	if (fd < 0)
	{
		printf("can not open\n");
		return -1;
	}

	write(fd, argv[1], 1);
	return 0;	
}

