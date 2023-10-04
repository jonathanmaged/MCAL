/*
 * SYSTICK_int.c
 *
 *  Created on: Aug 15, 2023
 *      Author: john
 */

#ifndef MCAL_SYSTICK_SYSTICK_INT_C_
#define MCAL_SYSTICK_SYSTICK_INT_C_

/******************** TO START USE SYSTICK*********************/
/*
 * MODIFY THE CONFIG FILE
 * CALL THE FUNCTION INIT
 * USE EITHER BUSYWAIT OR INTERVALSINGLE OR INTERVALPERIODIC
 */
void MSYSTICK_vStartTimer(void);

void MSYSTICK_vStopTimer(void);

void MSYSTICK_vInit(void);

void MSYSTICK_vSetBusyWait(u32 A_u32time);

void MSYSTICK_vSetIntervalSingle(u32 A_u32time, void(*CallBackFun)(void));

void MSYSTICK_vSetIntervalPeriodic(u32 A_u32time,void(*CallBackFun)(void));

u32 MSYSTICK_vGetElapsedTime();

u32 MSYSTICK_vGetRemainingTime();


#endif /* MCAL_SYSTICK_SYSTICK_INT_C_ */
