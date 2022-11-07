/*
 * Projects_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "Projects_Interface.h"
/*
 GLOBAL VARIABLE that is timer of seconds during app runtime
 */
 static u16 APP_u16_TimesSEC =0;
void APP_void_TimeCounter()
{
	APP_u16_TimesSEC++;

}

// This Function for display time at first line
void APP_void_TimeDisplay(u16 Copy_u8_TimeSEC)
{
	// the seconds count from 0 to 59 until reach 60 second  minute counter is plus
	u8 Local_u8_Seconds = Copy_u8_TimeSEC %60;
	u8 Local_u8_Minutes = (Copy_u8_TimeSEC/60)%60;
	u8 Local_u8_Hour = (Copy_u8_TimeSEC/60)/60;

	H_Lcd_Void_LCDGoTo(0,6);
	if(Local_u8_Hour)
	{
		if(!(Local_u8_Hour/10)) //If number contain 1 digit print 0 then number
		{

			H_Lcd_Void_LCDWriteCharacter('0');
			H_Lcd_Void_LCDWriteNumber(Local_u8_Hour);
		}
		else H_Lcd_Void_LCDWriteNumber(Local_u8_Hour);
	}
	else H_Lcd_Void_LCDWriteString("00"); // To zeros counter
	H_Lcd_Void_LCDWriteCharacter(':');

	if(Local_u8_Minutes)
	{
		if(!(Local_u8_Minutes/10))
		{

			H_Lcd_Void_LCDWriteCharacter('0');
			H_Lcd_Void_LCDWriteNumber(Local_u8_Minutes);
		}
		else H_Lcd_Void_LCDWriteNumber(Local_u8_Minutes);
	}
	else H_Lcd_Void_LCDWriteString("00");
	H_Lcd_Void_LCDWriteCharacter(':');

	if(Local_u8_Seconds)
	{
		if(!(Local_u8_Seconds/10))
		{

			H_Lcd_Void_LCDWriteCharacter('0');
			H_Lcd_Void_LCDWriteNumber(Local_u8_Seconds);
		}
		else H_Lcd_Void_LCDWriteNumber(Local_u8_Seconds);
	}
	else H_Lcd_Void_LCDWriteString("00");
}

/*
 * Function to print Question number and choices
 */
void APP_void_PrintQuestion(u8 Copy_u8_QNO)
{
	H_Lcd_Void_LCDGoTo(1,2);
	H_Lcd_Void_LCDWriteString("Q-");
	if(Copy_u8_QNO/10)
	{
		H_Lcd_Void_LCDWriteNumber(Copy_u8_QNO);
	}
	else{
		H_Lcd_Void_LCDWriteCharacter('0');
		H_Lcd_Void_LCDWriteNumber(Copy_u8_QNO);
	}
	H_Lcd_Void_LCDWriteString("    A B C D");

}
u8 APP_u8_AnsCheck(u8 Copy_u8_Ans)
{
	//Assume that no pushbutton not pressed
	u8 Local_u8_Result = NOT_PRESSED;
	//Sorting pushbuttons in array be able to be looped
	u8 Local_u8_Au8_Buttons[]={PUSH_BUTTON_0,PUSH_BUTTON_1,PUSH_BUTTON_2,PUSH_BUTTON_3};
	//Sorting Answers according to pushbuttons
		u8 Local_u8_Au8_BUTValue[]={'A','B','C','D'};
		//loop to check the right answer
	for(u8 i= 0;i<4;i++)
		if(H_PushButton_U8_PushButtonRead(Local_u8_Au8_Buttons[i])==LOW)
		{	if(Copy_u8_Ans == Local_u8_Au8_BUTValue[i])
		{
				Local_u8_Result = TRUE;
				H_LED_Void_LedInit(LED_GRN);
				 H_LED_Void_LedOn(LED_GRN);
				 H_LED_Void_LedOff(LED_RED);
		}
			else
				{Local_u8_Result = FALSE;
				H_LED_Void_LedInit(LED_RED);
			 H_LED_Void_LedOn(LED_RED);
			 H_LED_Void_LedOff(LED_GRN);
				}
			/*
			 * Next code to select  answer by printing brackets around it
			 */
			H_Lcd_Void_LCDGoTo(1,2*(Local_u8_Au8_BUTValue[i]-'A')+9);
			H_Lcd_Void_LCDWriteCharacter('[');
			H_Lcd_Void_LCDWriteCharacter(Local_u8_Au8_BUTValue[i]);
			H_Lcd_Void_LCDWriteCharacter(']');
			H_Buzzer_Void_BuzzerOnce();
		}

	return Local_u8_Result;
}


int main()
{
	H_Buzzer_Void_BuzzerInit();
	H_Buzzer_Void_BuzzerOnce();
	_delay_ms(100);
	H_Buzzer_Void_BuzzerOnce();
	H_Lcd_Void_LCDInit();

	M_Timer_Void_TimerInit();
	//This function send the address of timer counter function to the Timer_0 overflow Interrupt
	M_Timer_Void_SetCallBack(APP_void_TimeCounter);
	//Set System Tick by  1 Second
	M_Timer_Void_TimerSetTime(1000);

	M_Timer_Void_TimerStart(TIMER0_CHANNEL);
	M_GIE_Void_GlobalInterruptEnable();

	u8 Local_u8_QNumber=1;
	H_PushButton_Void_PushButtonInit(PUSH_BUTTON_0);
	H_PushButton_Void_PushButtonInit(PUSH_BUTTON_1);
	H_PushButton_Void_PushButtonInit(PUSH_BUTTON_2);
	H_PushButton_Void_PushButtonInit(PUSH_BUTTON_3);
	//This array of correct answers
	u8 Local_Au8_CorrectAnss[]=ANSES;
	while(1)
	{
			APP_void_TimeDisplay(APP_u16_TimesSEC);



		APP_void_PrintQuestion(Local_u8_QNumber);
		u8 Local_u8_Result = APP_u8_AnsCheck(Local_Au8_CorrectAnss[Local_u8_QNumber-1]);
		//If right answer print -> GREAT <-
		if(Local_u8_Result!=NOT_PRESSED)
		{

			if(Local_u8_Result==TRUE)
			{
				H_Lcd_Void_LCDGoTo(1,0);
				H_Lcd_Void_LCDWriteString("      -> GREAT <-     ");
				//H_Lcd_Void_LCDWriteCharacter('D');
				_delay_ms(1000);
				//if answer correct go to next question
				Local_u8_QNumber++;
			}
			else
			{
				//IF WRONG ANSWER INCREMENT COUNTER BY 60 TO INCREMENT MINUTES BY 1
				APP_u16_TimesSEC+=60;
				H_Lcd_Void_LCDGoTo(1,0);
				H_Lcd_Void_LCDWriteString("  1 MINUTE BENALIY");
				//H_Lcd_Void_LCDWriteCharacter('D');
				H_Lcd_Void_LCDGoTo(1,0);
				_delay_ms(1000);
				H_Lcd_Void_LCDWriteString("        LOSER        ");
				_delay_ms(1000);
				H_Lcd_Void_LCDGoTo(1,0);
				H_Lcd_Void_LCDWriteString("                      ");
			}//H_Lcd_Void_LCDWriteCharacter('f');
		}
		if(Local_u8_QNumber==QUES_NOMBERS+1)
			break;

	}
	H_Lcd_Void_LCDGoTo(1,0);
	H_Lcd_Void_LCDWriteString("   Congratulations      ");

	return 0;
}
