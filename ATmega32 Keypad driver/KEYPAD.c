/**************************************/
/* Description : Keypad program file  */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 16 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/delay.h>
#include "DIO.h"
#include "KEYPAD.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"
void KEYPAD_voidInit(void)
{
	uint8 u8CntrLoc;
	uint8 u8InputCntrLoc ;
	uint8 u8OutputCntrLoc ;
	//go through all keypads
	/* Loop Through all keypads*/
	for(u8CntrLoc = 0 ; u8CntrLoc < MAX_KEYPAD_NUM ; u8CntrLoc++)
	{
		// put  input pins pulllup res
		/* all inputs activate pull up resistor     */
		for (u8InputCntrLoc = 0 ; u8InputCntrLoc < KEYPAD_astrKeyPadConfigSet[u8CntrLoc].u8InputPinsNum; u8InputCntrLoc++)
		{
			DIO_enuStatePullup(KEYPAD_astrKeyPadConfigSet[u8CntrLoc].au8InputPins[u8InputCntrLoc],DIO_ACTIVATE);
		}
		/* all output seq ones no switch under test */
			//put high on all o/p pins

		for (u8OutputCntrLoc = 0 ; u8OutputCntrLoc < KEYPAD_astrKeyPadConfigSet[u8CntrLoc].u8OutputPindNum; u8OutputCntrLoc++)
		{
			DIO_enuWritePin(KEYPAD_astrKeyPadConfigSet[u8CntrLoc].au8OutputPins[u8OutputCntrLoc], DIO_HIGH);
		}

	}

}
uint8 KEYPAD_u8GetPressedKey(uint8 u8KeyPadIdxCpy)

{
	uint8 u8SeqCntrLoc;
	//seq count is outnums
	//var to put the read value of input in
	uint16 u16InputReadignLoc;
	//var to put the check reading in it
	uint8 u8ReturnKeyLoc =0xFF;
	//loop to know seq counter
	for(u8SeqCntrLoc = 0 ; u8SeqCntrLoc < KEYPAD_astrKeyPadConfigSet[u8KeyPadIdxCpy].u8OutputPindNum ;u8SeqCntrLoc++)
	{
	//to make it more generaic we will create fns for write seq , read inputs and check reading
	/* write seq u8seqCntrLoc  */
	voidWriteSeq(u8KeyPadIdxCpy ,u8SeqCntrLoc);
	/* delay */
	_delay_ms(50);
	//read inputs
	u16InputReadignLoc = u16ReadInputs(u8KeyPadIdxCpy);
	//check break; FF->nothing is pressed
	u8ReturnKeyLoc = u8CheckReading(u8KeyPadIdxCpy , u8SeqCntrLoc , u16InputReadignLoc);
	if(u8ReturnKeyLoc != 0xFF)
	{
		//means if another button is getting pressed so we want when a key is pressed break
		break;
	}


	}
	return u8ReturnKeyLoc;
}
//fn to write seq
static void voidWriteSeq(uint8 u8KeyPadIdxCpy , uint8 u8SeqIdxCpy)
{
	uint8 u8CntrLoc  ;
	//we want to put on all output pins high -> 1 except the one that is cntr == seq id put it to low
		for (u8CntrLoc = 0 ; u8CntrLoc < KEYPAD_astrKeyPadConfigSet[u8KeyPadIdxCpy].u8OutputPindNum; u8CntrLoc++)
		{
			if (u8CntrLoc == u8SeqIdxCpy)
			{
				DIO_enuWritePin(KEYPAD_astrKeyPadConfigSet[u8KeyPadIdxCpy].au8OutputPins[u8CntrLoc], DIO_LOW);
			}
			else
			{
	    		DIO_enuWritePin(KEYPAD_astrKeyPadConfigSet[u8KeyPadIdxCpy].au8OutputPins[u8CntrLoc], DIO_HIGH);
			}

		}

}
//fn to read inouts from your keypad
static uint16 u16ReadInputs(uint8 u8KeyPadIdxCpy)
{
	//loop thriugh inputs and read each bit
	uint16 u16ReturnReadingLoc = 0xFFFF ;
    uint8  u8InputCntrLoc             ;
	uint8  u8TempReadingLoc  =     0  ;
	for (u8InputCntrLoc = 0 ; u8InputCntrLoc < KEYPAD_astrKeyPadConfigSet[u8KeyPadIdxCpy].u8InputPinsNum; u8InputCntrLoc++)
	{
	  DIO_enuReadPin(KEYPAD_astrKeyPadConfigSet[u8KeyPadIdxCpy].au8InputPins[u8InputCntrLoc],&u8TempReadingLoc);
	  //if bit is low then the switch is pressed
	  if (u8TempReadingLoc == 0)
	  {
		 //we need the bit in the reading and break after that
		 CLR_BIT(u16ReturnReadingLoc , u8InputCntrLoc );
		 break ;
	  }

	}
	return u16ReturnReadingLoc ;


}
//fn to check the intersection between the seq and the readinginput and get which switch is pressed
static uint8 u8CheckReading(uint8 u8KeyPadIdxCpy ,uint8 u8SeqIdxCpy , uint16 u16InputReadingCpy)
{
	//mapping between i and o
	uint8 u8ReturnKeyLoc;
	uint8 u8InputCntrLoc ;
	uint8 u8InputBitLoc  ;
	//checking if no key is pressed
	if(u16InputReadingCpy == 0xFFFF)
	{
		u8ReturnKeyLoc = 0xFF;
	}
	else
	{
		//loop through the reading to find which bit is low
		//and then we say the bit with num # instersection with seq # gives us res
		for (u8InputCntrLoc = 0 ; u8InputCntrLoc < KEYPAD_astrKeyPadConfigSet[u8KeyPadIdxCpy].u8InputPinsNum; u8InputCntrLoc++)
		{
		   u8InputBitLoc =  GET_BIT(u16InputReadingCpy ,u8InputCntrLoc );
		   if (u8InputBitLoc == 0)
		   {
			    // input  --> u8InputCntrLoc  output   --> u8SeqIdxCpy

			   u8ReturnKeyLoc = KEYPAD_au8Mapping[u8KeyPadIdxCpy][u8SeqIdxCpy][u8InputCntrLoc];
				break ;
		   }

		}
	}
	return u8ReturnKeyLoc;

}

