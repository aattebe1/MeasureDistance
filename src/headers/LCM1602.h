/***********************************************************************************
*	{LCM1602_H}
*	LCM1602.h
*		by Austin Atteberry
*
*	DEFINITIONS:
*	Prototypes the functions for the LCM1602 LCD
*
************************************************************************************/

#include<wiringPi.h>
#include<wiringPiI2C.h>

#ifndef _LCM1602_H
#define _LCM1602_H

#define LINE_1 0x80
#define LINE_2 0xC0
#define ENABLE 0x04

extern int lcm1602Setup(const int devId, int direction, int mode);
extern int lcm1602ClearDisplay(int fd);
extern int lcm1602WriteLine(int fd, char message[], int line);

#endif