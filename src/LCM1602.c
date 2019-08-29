/***********************************************************************************
*	{LCM1602_C}
*	LCM1602.c
*		by Austin Atteberry
*
*	PERFORMANCE:
*	Defines functions to interface with the LCM1602 I2C LCD panel
*
************************************************************************************/
#include "headers/LCM1602.h"
#include <stdio.h>
#include <string.h>

/* lcm1602WriteByte function
*  Writes a byte to the LCD
*/
int lcm1602WriteByte(int fd, int byteVal) {
	if(wiringPiI2CWrite(fd, byteVal) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
}

/* lcm1602WriteLine function
*  Writes a line of text to the LCD
*/
int lcm1602WriteLine(int fd, char message[], int line) {
	int temp1 = (line & 0xF0) | 0x08;
	int temp2 = ((line<<4) & 0xF0) | 0x08;

	if(wiringPiI2CWrite(fd, temp1) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, temp1 | ENABLE) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, temp1 & ~ENABLE) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, temp2) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, temp2 | ENABLE) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, temp2 & ~ENABLE) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	int length = strlen(message);

	for(int i=0; i < length; i++) {
		int temp = message[i];
		temp1 = 0x01 | (temp & 0xF0) | 0x08;
		temp2 = 0x01 | ((temp<<4) & 0xF0) | 0x08;

		if(wiringPiI2CWrite(fd, temp1) != 0) {
		return(-1);
		}
		else {
			delayMicroseconds(500);
		}

		if(wiringPiI2CWrite(fd, temp1 | ENABLE) != 0) {
			return(-1);
		}
		else {
			delayMicroseconds(500);
		}

		if(wiringPiI2CWrite(fd, temp1 & ~ENABLE) != 0) {
			return(-1);
		}
		else {
			delayMicroseconds(500);
		}

		if(wiringPiI2CWrite(fd, temp2) != 0) {
			return(-1);
		}
		else {
			delayMicroseconds(500);
		}

		if(wiringPiI2CWrite(fd, temp2 | ENABLE) != 0) {
			return(-1);
		}
		else {
			delayMicroseconds(500);
		}

		if(wiringPiI2CWrite(fd, temp2 & ~ENABLE) != 0) {
			return(-1);
		}
		else {
			delayMicroseconds(500);
		}
	}
 }

/* lcm1602ClearDisplay function
*  Clears the display
*/
int lcm1602ClearDisplay(int fd) {
	if(wiringPiI2CWrite(fd, 0x08) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x0C) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x08) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x18) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x1C) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x18) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	return(0);
}

/* lcm1602FunctionSet function
*  Sets interface to 4-bit, 2 line mode
*/
int lcm1602FunctionSet(int fd) {
	
	if(wiringPiI2CWrite(fd, 0x28) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x2C) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x28) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x88) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x8C) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}
	if(wiringPiI2CWrite(fd, 0x88) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	return(0);
}

/* lcm1602DisplaySettings function
*  Sets the LCD's cursor and blink settings
*/
int lcm1602DisplaySettings(int fd, int mode) {

	switch(mode) {

		/* Cursor & Blink Off*/
		case 0:

			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0x0C) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xC8) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xCC) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xC8) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			break;

		/* Cursor Off, Blink On */
		case 1:
			
			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0x0C) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xD8) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xDC) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xD8) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			break;

		/* Cursor On, Blink Off */
		case 2:
			
			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0x0C) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xE8) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xEC) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xE8) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			break;

		/* Cursor & Blink On */
		case 3:
			
			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0x0C) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xF8) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xFC) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			if(wiringPiI2CWrite(fd, 0xF8) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			break;

		default:
			return(-1);
	}

	return(0);
}

/* lcm1602CursorDirection function
*  Sets the cursor direction
*/
int lcm1602CursorDirection(int fd, int direction) {

	switch(direction) {

		case 0:
			
			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x0C) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x68) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x6C) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x68) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			break;

		case 1:
			
			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x0C) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x08) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x78) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x7C) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}
			if(wiringPiI2CWrite(fd, 0x78) != 0) {
				return(-1);
			}
			else {
				delayMicroseconds(500);
			}

			break;

		default:
			return(-1);
	}

	return(0);
}

/* lcm1602Initialize function
*  Performs the initialization routine on the LCD
*/
int lcm1602Initialize(int fd) {

	if(wiringPiI2CWrite(fd, 0x38) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x3C) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x38) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x38) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x3C) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x38) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x38) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x3C) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x38) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x28) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x2C) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	if(wiringPiI2CWrite(fd, 0x28) != 0) {
		return(-1);
	}
	else {
		delayMicroseconds(500);
	}

	return(0);
}

/* lcm1602Setup function
*  Sets up the LCD
*/
int lcm1602Setup(const int devId, int direction, int mode) {

	int fd = wiringPiI2CSetup(devId); //File Descriptor

	if(fd < 0) {
		printf("Error setting up display\n");
		return(-1);
	}

	if(lcm1602Initialize(fd) != 0) {
		printf("Error initializing display\n");
		return(-1);
	}

	if(lcm1602CursorDirection(fd, direction) != 0) {
		printf("Error setting cursor direction\n");
		return(-1);
	}

	if(lcm1602DisplaySettings(fd, mode) != 0) {
		printf("Error configuring display settings\n");
		return(-1);
	}

	if(lcm1602FunctionSet(fd) != 0) {
		printf("Error setting display function\n");
		return(-1);
	}

	if(lcm1602ClearDisplay(fd) != 0) {
		printf("Error clearing display\n");
		return(-1);
	}

	delayMicroseconds(500);

	return(fd);
}
