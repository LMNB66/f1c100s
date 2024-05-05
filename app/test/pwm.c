#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PWM_PATH "/sys/class/pwm/pwmchip0"
#define PERIOD_NS 1000000
#define MIN_DUTY_CYCLE_NS 0
#define MAX_DUTY_CYCLE_NS 1000000

int back_light_init(void)
{
	FILE *pwm_export = fopen(PWM_PATH "/export", "w");
	if (!pwm_export) {
        perror("Failed to open PWM export");
        return -1;
    }
	fprintf(pwm_export, "1");
    fclose(pwm_export);
	
	FILE *period_file = fopen(PWM_PATH "/pwm1/period", "w");
    if (!period_file) {
        perror("Failed to open PWM period");
        return -2;
    }
    fprintf(period_file, "%d", PERIOD_NS);
    fclose(period_file);
	
	FILE *enable_file = fopen(PWM_PATH "/pwm1/enable", "w");
    if (!enable_file) {
        perror("Failed to open PWM enable");
        return -3;
    }
    fprintf(enable_file, "1");
    fclose(enable_file);
	
	FILE *polarity_file = fopen(PWM_PATH "/pwm1/polarity", "w");
    if (!polarity_file) {
        perror("Failed to open PWM enable");
        return -4;
    }
    fprintf(polarity_file, "normal");
    fclose(polarity_file);
	
	FILE *duty_file = fopen(PWM_PATH "/pwm1/duty_cycle", "w");
    if (!duty_file) {
        perror("Failed to open PWM enable");
        return -5;
    }
    fprintf(duty_file, "%d", 500000);
	fclose(duty_file);
	return 0;
}

void set_bl(int level)
{
	int duty;
	
	if(level<0) level = 0;
	else if(level>100) level = 100;
	
	duty = level*PERIOD_NS/100;
	printf("duty: %d\n", duty);
	
	FILE *duty_file = fopen(PWM_PATH "/pwm1/duty_cycle", "w");
    if (!duty_file) {
        perror("Failed to open PWM enable");
        return;
    }
	fprintf(duty_file, "%d", duty);
	fclose(duty_file);
}


void back_light_exit(void)
{
	
	FILE *pwm_unexport = fopen(PWM_PATH "/unexport", "w");
    if (!pwm_unexport) {
        perror("Failed to open PWM unexport");
        return;
    }
    fprintf(pwm_unexport, "1");
    fclose(pwm_unexport);
}

int main(int argv, char **argc)
{
	if(argv != 2)
	{
		printf("err\n");
		return -1;
	}
	if(back_light_init()<0)
	{
		printf("err\n");
		return -1;
	}
	set_bl(atoi(argc[1]));
	//back_light_exit();
	
	return 0;
}














