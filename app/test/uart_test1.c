#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>

static int serial_fd = -1;
static char serial_port[] = "/dev/ttyS1";

static void sig_func(int sig)
{
	char rx_buffer[256];
    int bytes_read = read(serial_fd, rx_buffer, sizeof(rx_buffer));
    if (bytes_read > 0) {
        rx_buffer[bytes_read] = '\0';
        printf("\rrx_buffer: \n %s ", rx_buffer);
    } else {
        printf("No data received.\n");
    }	
}

int main() 
{ 
	int	flags;
	signal(SIGIO, sig_func);

    serial_fd = open(serial_port, O_RDWR | O_NOCTTY);
    if (serial_fd == -1) {
        perror("Failed to open serial port");
        return 1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof(tty));

    if (tcgetattr(serial_fd, &tty) != 0) {
        perror("Error from tcgetattr");
        return 1;
    }

    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;

    if (tcsetattr(serial_fd, TCSANOW, &tty) != 0) {
        perror("Error from tcsetattr");
        return 1;
    }
	
	fcntl(serial_fd, F_SETOWN, getpid());
	flags = fcntl(serial_fd, F_GETFL);
	fcntl(serial_fd, F_SETFL, flags | FASYNC);


    char tx_buffer[] = "hello world!\n";
	
	while(1)
	{
		ssize_t bytes_written = write(serial_fd, tx_buffer, sizeof(tx_buffer));
		if (bytes_written < 0) {
			perror("Error writing to serial port");
			close(serial_fd);
			return 1;
		}
		//printf("\rtx_buffer: \n %s ", tx_buffer);
		
		sleep(2);
	}

    close(serial_fd);

    return 0;
}
