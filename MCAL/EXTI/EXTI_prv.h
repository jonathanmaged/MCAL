/*
 * EXTI_prv.h
 *
 *  Created on: Aug 14, 2023
 *      Author: john
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define EXTI_BASE_ADDR 0x40013C00
#define SYSCFG_BASE_ADDR 0x40013800


typedef struct {
    u32 IMR;
    u32 EMR;
    u32 RTSR;
    u32 FTSR;
    u32 SWIER;
    u32 PR;
} EXTI_MemMap_t;

typedef struct {
    u32 MEMRMP;
    u32 PMC;
    u32 EXTICR1;
    u32 EXTICR2;
    u32 EXTICR3;
    u32 EXTICR4;
    u32 CMPCR;
} SYSCFG_MemMap_t;


#define EXTI   ((volatile EXTI_MemMap_t*)(EXTI_BASE_ADDR))
#define SYSCFG ((volatile SYSCFG_MemMap_t*)(SYSCFG_BASE_ADDR))


#endif /* MCAL_EXTI_EXTI_PRV_H_ */
