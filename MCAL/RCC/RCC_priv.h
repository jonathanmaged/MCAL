/*
 * RCC_priv.h
 *
 *  Created on: Aug 12, 2023
 *      Author: john
 */

#ifndef MCAL_RCC_RCC_PRIV_H_
#define MCAL_RCC_RCC_PRIV_H_

#define RCC_BASE_ADDR 0x40023800

/*
 * RCC clock control register BITS
 */
#define HSE_ON 16
#define HSI_ON 0
#define PLL_ON 24
#define HSE_BYP 18
#define CSS_ON 19
#define HPRE_BITS 4
#define PPRE1_BIT 10

typedef struct{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 RESERVED1;
	u32 RESERVED2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 RESERVED3;
	u32 RESERVED4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 RESERVED5;
	u32 RESERVED6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 RESERVED7;
	u32 RESERVED8;


}RCC_MemMap_t ;




#define RCC ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))




#endif /* MCAL_RCC_RCC_PRIV_H_ */
