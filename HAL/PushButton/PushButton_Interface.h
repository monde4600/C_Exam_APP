/*
 * PushButton_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "STD.h"
#include "DIO_Interface.h"
#include <util/delay.h>

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define PUSH_BUTTON_0                    0
#define PUSH_BUTTON_1                    1
#define PUSH_BUTTON_2                    2
#define PUSH_BUTTON_3                    3
#define ACTIVE_LOW                       1
#define ACTIVE_HIGH                      2
#if   PUSH_BUTTON_MODE  == ACTIVE_HIGH
#define PUSH_BUTTON_PRESSED              1
#define PUSH_BUTTON_RELEASED             0
#elif PUSH_BUTTON_MODE  == ACTIVE_LOW
#define PUSH_BUTTON_PRESSED              0
#define PUSH_BUTTON_RELEASED             1
#endif

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_PushButton_Void_PushButtonInit(u8);
u8   H_PushButton_U8_PushButtonRead(u8);

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_ */
