/*
 * SYSTICK_prv.c
 *
 *  Created on: Aug 15, 2023
 *      Author: john
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRV_C_
#define MCAL_SYSTICK_SYSTICK_PRV_C_


#define STK_BASE_ADDR 0xE000E010

#define ENABLE 0
#define TICKINT 1
#define CLKSOURCE 2
#define COUNTFLAG 16

#define single 0
#define periodic 1



typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;

}STK_MemMap_t ;




#define STK ((volatile STK_MemMap_t*)(STK_BASE_ADDR))



#endif /* MCAL_SYSTICK_SYSTICK_PRV_C_ */
