/***********************************************************************************
*	{ADCDemo_C}
*	ADCDemo.c
*		by Austin Atteberry
*
*	PERFORMANCE:
*	Uses the ultrasonic ranging module (proximity sensor) to display
*   the distance to an object on the LCD
*
************************************************************************************/

/* Header files */
#include<stdio.h>
#include<wiringPi.h>
#include "headers/Definitions.h"
#include "headers/HCSR04.h"
#include "headers/LCM1602.h"

/* main function 
*  The program's entry point
*/
int main(int argc, char *argv[]) {
	
	/* WiringPi initialization */
	if(wiringPiSetup() != 0) {
		printf("Error initializing WiringPi\n");
		return(1);
	}

	/* Pin initialization */
	pinMode(RM_TRIG, OUTPUT);
	digitalWrite(RM_TRIG, LOW);
	pinMode(RM_ECHO, INPUT);
	pullUpDnControl(RM_ECHO, PUD_OFF);
	delayMicroseconds(500000);

	/* Initialize LCD */
	int fd = lcm1602Setup(0x27, 0, 0);
	char lcd2[17];
	lcd2[16] = '\0';

	/* Main program loop */
	while(1) {

		/* Clear LCD */
		if(lcm1602ClearDisplay(fd) != 0) {
			printf("Could not clear the display\n");
		}

		/* Reset distance string */
		for(int i=0; i<16; i++) {
			lcd2[i] = 0x20;
		}

		/* Get distance to object */
		double distance = getDistance(RM_TRIG, RM_ECHO);

		/* Convert distance to string */
		if((distance > 5.0) || (distance < 0)) {
			lcd2[0] = 0x55;		// U
			lcd2[1] = 0x6E;		// n
			lcd2[2] = 0x61;		// a
			lcd2[3] = 0x76;		// v
			lcd2[4] = 0x61;		// a
			lcd2[5] = 0x69;		// i
			lcd2[6] = 0x6C;		// l
			lcd2[7] = 0x61;		// a
			lcd2[8] = 0x62;		// b
			lcd2[9] = 0x6C;		// l
			lcd2[10] = 0x65;	// e
		}
		else {
			sprintf(lcd2, "%.3fm", distance);
		}

		/* Write lines to LCD */
		lcm1602WriteLine(fd, "Distance:       ", LINE_1);
		lcm1602WriteLine(fd, lcd2, LINE_2);
		
		/* Delay 5s before taking next measurement */
		delayMicroseconds(5000000);
	}

	return(0);
}
