/*
 * SYSTICK_prg.c
 *
 *  Created on: Aug 15, 2023
 *      Author: john
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SYSTICK_prv.h"
#include "SYSTICK_int.h"
#include "SYSTICK_cfg.h"

void (*G_CallBack)(void) ;
u8 G_Flag  ;
void MSYSTICK_vInit(void){

// CLOCK SOURCE
#if CLK_SOURCE_RATE == AHB/8
	CLEAR_BIT(STK->CTRL,CLKSOURCE);
#else
	SET_BIT(STK->CTRL,CLKSOURCE);
#endif

//CLEAR INTERUPT
	CLEAR_BIT(STK->CTRL,ENABLE);
	CLEAR_BIT(STK->CTRL,TICKINT);
};
void MSYSTICK_vStopTimer(void){
	CLEAR_BIT(STK->CTRL,ENABLE);
};
void MSYSTICK_vStartTimer(void){
	SET_BIT(STK->CTRL,ENABLE);
};

void MSYSTICK_vDelayms(u32 milisecound){
	for(u32 i=0;i<milisecound;i++){
		MSYSTICK_vSetBusyWait(1000);
	}
}
void MSYSTICK_vSetBusyWait(u32 A_u32Tick){
	// CLEAR VALUE REGISTER AND COUNT FLAG
	STK->VAL=0 ;
	//SET LOAD REGISTER WITH THE NUMBER OF TICKS
	STK->LOAD = A_u32Tick ;

	MSYSTICK_vStartTimer();

	while(GET_BIT(STK->CTRL,COUNTFLAG)== 0){}

	MSYSTICK_vStopTimer();

};

void MSYSTICK_vSetIntervalSingle(u32 A_u32Tick, void(*CallBackFun)(void)){
	SET_BIT(STK->CTRL,TICKINT);

	STK->VAL=0 ;

	STK->LOAD = A_u32Tick ;

	MSYSTICK_vStartTimer();

	G_CallBack = CallBackFun ;

	G_Flag = single ;

};

void MSYSTICK_vSetIntervalPeriodic(u32 A_u32Tick,void(*CallBackFun)(void)){
	SET_BIT(STK->CTRL,TICKINT);

	STK->VAL=0 ;

	STK->LOAD = A_u32Tick ;

	MSYSTICK_vStartTimer();

	G_CallBack = CallBackFun ;

	G_Flag = periodic ;

};

u32 MSYSTICK_vGetElapsedTime(){

	return (STK->LOAD - STK->VAL) ;
};

u32 MSYSTICK_vGetRemainingTime(){

	return STK->VAL ;
};
void SysTick_Handler(void){
	if(G_CallBack != 0)
	{
	G_CallBack();
	}
	if(G_Flag == single)
	{
	CLEAR_BIT(STK->CTRL,TICKINT);
	MSYSTICK_vStopTimer() ;
	}
	(void)GET_BIT(STK->CTRL,COUNTFLAG);
};
