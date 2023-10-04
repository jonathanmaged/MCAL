/*
 * RCC_cfg.h
 *
 *  Created on: Aug 21, 2023
 *      Author: john
 */

#ifndef MCAL_RCC_RCC_CFG_H_
#define MCAL_RCC_RCC_CFG_H_

/*
 * ENALBE
 * DISABLE
 */

#define RCC_HSE_ENABLE ENABLE
#define RCC_HSI_ENABLE DISABLE
#define RCC_PLL_ENABLE DISABLE
/*
 * AHB/2 0b1000
 * AHB/4 0b1001
 * AHB/8 0b1010
 * AHB/16 0b1011
 *
 */
#define AHBPRESCALAR 0b1000
/*
 * APB   0b000
 * APB/2 0b100
 * APB/4 0b101
 * APB/8 0b110
 * APB/16 0b111
 *
 */
#define APB1PRESCALAR 0b000


#endif /* MCAL_RCC_RCC_CFG_H_ */

