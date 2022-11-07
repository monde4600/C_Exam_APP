/*
 * PushButton_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_CONFIG_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_CONFIG_H_

/*--------------------------------------------------------------------------------------------*/
/*   SELECT MICROCONTROLERS PINS   */
/*--------------------------------------------------------------------------------------------*/
#define PUSH_BUTTON_0_PIN            PD7_PIN
#define PUSH_BUTTON_1_PIN            PD6_PIN
#define PUSH_BUTTON_2_PIN            PD5_PIN
#define PUSH_BUTTON_3_PIN            PD3_PIN

/*--------------------------------------------------------------------------------------------*/
/*   SELECT PB_MODE OPTIONS : ACTIVE_HIGH , ACTIVE_LOW   */
/*--------------------------------------------------------------------------------------------*/
#define PUSH_BUTTON_MODE            ACTIVE_LOW

/*--------------------------------------------------------------------------------------------*/
/*   SELECT PB_DEBOUNCING_TIME IN MILLI SECOND   */
/*--------------------------------------------------------------------------------------------*/
#define PUSH_BUTTON_DEBOUNCING_TIME    120

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_CONFIG_H_ */
