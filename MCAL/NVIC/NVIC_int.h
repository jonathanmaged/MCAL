/*
 * NVIC_int.h
 *
 *  Created on: Aug 13, 2023
 *      Author: john
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

#define NVIC_SYSTICK       -1
#define NVIC_PEND_SV       -2
#define NVIC_SV_CALL       -3
#define NVIC_USAGE_FAULT   -4
#define NVIC_BUS_FAULT     -5
#define NVIC_MEMORY_FAULT  -6

void MNVIC_VEnableInteruptPeripheral(u8 A_u8IntId);

void MNVIC_VDisableInteruptPeripheral(u8 A_u8IntId);

/*Test SW Interupt*/
void MNVIC_VSetPending(u8 A_u8IntId);

void MNVIC_VClearPending(u8 A_u8IntId);

//to check
u8 MNVIC_VGetActive(u8 A_u8IntId);


void MNVIC_VSetPriorityCfg(u8 A_u8Group);


void MNVIC_VSetPriority(s8 A_s8IntId,u8 A_u8GroupPriority,u8 A_u8SubPriority);








#endif /* MCAL_NVIC_NVIC_INT_H_ */
