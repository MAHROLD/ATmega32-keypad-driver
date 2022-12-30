/**************************************/
/* Description : Keypad private file  */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 16 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/

#ifndef KEYPAD_PRIV_H
#define KEYPAD_PRIV_H

//allocte max_input X max_output
typedef struct
{
	//configure input pins in array
	uint8 au8InputPins[KEYPAD_MAX_INPUT_NUM];
	//configure output pins in array
	uint8 au8OutputPins[KEYPAD_MAX_OUTPUT_NUM];
	//if the keypad array 4x5 and i have the keypad size 4x4 i want to loop onlty on 4x4 not 4x5 so we dummy var for i and o
	uint8 u8InputPinsNum;
	uint8 u8OutputPindNum;
}tstrKeyPadConfigSet;
//use the array in cfg.c to cfn all keypads
extern tstrKeyPadConfigSet KEYPAD_astrKeyPadConfigSet[MAX_KEYPAD_NUM];
extern uint8 KEYPAD_au8Mapping[MAX_KEYPAD_NUM][KEYPAD_MAX_OUTPUT_NUM][KEYPAD_MAX_INPUT_NUM];
static void voidWriteSeq(uint8 u8KeyPadIdxCpy , uint8 u8SeqIdxCpy);
static uint16 u16ReadInputs(uint8 u8KeyPadIdxCpy);
static uint8 u8CheckReading(uint8 u8KeyPadIdxCpy ,uint8 u8SeqIdxCpy , uint16 u16InputReadingCpy);
#endif
