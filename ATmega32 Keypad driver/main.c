/*
 * main.c
 *
 *  Created on: Dec 16, 2022
 *      Author: mohamoud
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "KEYPAD.h"

void main(void)
{

	DIO_voidInit();
	LCD_voidInit();
	KEYPAD_voidInit();
	uint8 u8PressedLoc;
	while(1)
	{

		u8PressedLoc = KEYPAD_u8GetPressedKey(0);
		if( u8PressedLoc != 0xFF)
		{
			LCD_voidDisplayChar(0, u8PressedLoc);
		}
	}
}
