#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

const char PCF8591 = 0x48;
int fd, adcVal;

int main(void) 
{
	if(wiringPiSetup() == -1) exit(1);
	fd = wiringPiI2CSetup(PCF8591);
	while(1) 
	{
		adcVal = wiringPiI2CReadReg8(fd, PCF8591+0);
		printf("ADC val: %d\n", adcVal);

		delay(500);
	} 
 	return 0; 
}