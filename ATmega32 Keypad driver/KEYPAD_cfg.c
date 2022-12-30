/**************************************/
/* Description : Keypad cfg .c file   */
/* Author      : Abo elnour           */
/* Version     : 0.1v                 */
/* Date        : 16 Dec 2022          */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "DIO.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"
tstrKeyPadConfigSet KEYPAD_astrKeyPadConfigSet[MAX_KEYPAD_NUM]=
{
		/*KEYPAD 0 CFG*/
		{
				/*array input pins*/
				{
						DIO_PIN_NUM_0 ,DIO_PIN_NUM_1,
						DIO_PIN_NUM_2 ,DIO_PIN_NUM_3
				},
				/*array output pins*/
				{
						DIO_PIN_NUM_4 ,DIO_PIN_NUM_5,
						DIO_PIN_NUM_6 ,DIO_PIN_NUM_7
				},
				//input num
				 4 ,
				//o/p num
				 4
		}
#if 0
	,
	/*Keypad 1 CFG*/
  {
	/* array inputs pins */
		{
			DIO_PIN_NUM_8 ,DIO_PIN_NUM_9,
			DIO_PIN_NUM_10
		}
		,
		/* array Outputs pins */
		{
			DIO_PIN_NUM_11 ,DIO_PIN_NUM_12,
			DIO_PIN_NUM_13 ,DIO_PIN_NUM_14,
			DIO_PIN_NUM_15
		}
		,
		/* Input pins number*/
		3
		,
		/* Output pins number*/
		5

	}
#endif
};


uint8 KEYPAD_au8Mapping[MAX_KEYPAD_NUM][KEYPAD_MAX_OUTPUT_NUM][KEYPAD_MAX_INPUT_NUM]=
{
   /*Keypad 0 CFG*/
	{
		{'7' ,'8' ,'9' ,'/' },
		{'4' ,'5' ,'6' ,'X' },
		{'1' ,'2' ,'3' ,'-' },
		{'.' ,'0' ,'=' ,'+' }
		//Dummy dead code
		//{ 0  , 0  ,  0 ,0   }
	}
#if 0
	,
	/*Keypad 1 CFG*/
	{
		{ '7' ,'8' ,'9',0},
		{ '4' ,'5' ,'6',0},
		{ '1' ,'2' ,'3',0},
		{ '-' ,'0' ,'=',0},
		{ 'X' , '/','+',0}
	}
#endif
};
