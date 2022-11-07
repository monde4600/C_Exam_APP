/*
 * Keypad_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "STD.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "Keypad_Private.h"
#include "Keypad_Config.h"
u8 KEY_u8_COLPINs[] = COL_PINS;

void H_void_KEYPAD_Init(void)
{
	//single Row
	u8 Local_u8_COLIterator;
	for(Local_u8_COLIterator=0 ;Local_u8_COLIterator<COL_N ;Local_u8_COLIterator++)
	{
		M_DIO_Void_SetPinDirection(KEY_u8_COLPINs[Local_u8_COLIterator],INPUT);
		//M_DIO_Void_SetPinDirection(PD7_PIN,INPUT);
	}
	//
}
u8 H_u8_KEYPAD_GetPressedKey(u8* Copy_u8_PressedKey)
{

}
