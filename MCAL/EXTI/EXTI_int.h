/*
 * EXTI_int.h
 *
 *  Created on: Aug 14, 2023
 *      Author: john
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#define Rising_Falling 2
#define Rising_Edge    1
#define Falling_Edge   0

#define EXTI_PORTA 0
#define EXTI_PORTB 1
#define EXTI_PORTC 2

enum EXTI_Line {
  EXTI_LINE0,
  EXTI_LINE1,
  EXTI_LINE2,
  EXTI_LINE3,
  EXTI_LINE4,
  EXTI_LINE5,
  EXTI_LINE6,
  EXTI_LINE7,
  EXTI_LINE8,
  EXTI_LINE9,
  EXTI_LINE10,
  EXTI_LINE11,
  EXTI_LINE12,
  EXTI_LINE13,
  EXTI_LINE14,
  EXTI_LINE15
};
/*
 * TO USE EXTI YOU MUST USE THE FUNCTION ENABLELINE AND IT INTERNALLY CALL INTERUPTCFG AND SETTRIGGER FUNCTIONS
 * THEN USE THE FUNCTION SETCALLBACK
 * AFTER FINISHING USING THE INTERUPT YOU MUST CLOSE IT USING THE FUNCTION CLEAR FLAG
 */
void MEXTI_vEnableLine(u8 A_u8Line,u8 A_u8PortId,u8 A_u8Trigger);

void MEXTI_vDisableLine(u8 A_u8Line);

void MEXTI_vSetTrigger(u8 A_u8Line,u8 A_u8Trigger);

void MEXTI_vSoftwareTrigger(u8 A_u8Line);

void MEXTI_vClearFlag(u8 A_u8Line);

void MEXTI_vInteruptcfg(u8 A_u8Line,u8 A_u8PortId);

void MEXTI_vSetCallBack(u8 A_u8Line,void(*ptr)(void));




#endif /* MCAL_EXTI_EXTI_INT_H_ */
