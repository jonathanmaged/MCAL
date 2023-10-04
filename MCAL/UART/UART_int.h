/*
 * UART_int.h
 *
 *  Created on: Aug 23, 2023
 *      Author: john
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

#include"UART_prv.h"


typedef struct{
	u32 BaudRate;
	u8 DataWidth;
	u8 OverSampling;
	u8 ParityEnable;
	u8 ParitySelection;
	u8 StopBits;
	u8 TransferDirection;
}USART_cfg;

#define USART_8_DATA_BITS 0
#define USART_9_DATA_BITS 1

#define USART_OVER_SAMPLING_16 0
#define USART_OVER_SAMPLING_8 1

#define ENABLE 1
#define DISABLE 0

#define EVEN_PARITY 0
#define ODD_PARITY 1

#define USART_STOP_BIT 00
#define USART_HALF_STOP_BIT 01
#define USART_TWO_STOP_BIT 10

#define USART_TX_ONLY 10
#define USART_RX_ONLY 01
#define USART_TX_RX   11



/*choose from USART1 ,USART2,USART6*/
void MUSART_vInit(USART_cfg*  A_USARTcfg,USART_MemMap_t *USARTx);
void MUSART_vEnable(USART_MemMap_t *USARTx);
void MUSART_vDisable(USART_MemMap_t *USARTx);

void MUSART_vTransmitByteBlocking(USART_MemMap_t *USARTx , u8 Data);
u8 MUSART_u8TransmitByteNonBlocking(USART_MemMap_t *USARTx , u8 Data);
void MUSART_vTransmitString(USART_MemMap_t *USARTx,char *A_ptru8string);

u8 MUSART_u8RecieveByteBlocking(USART_MemMap_t *USARTx);
u8 MUSART_u8RecieveByteNonBlocking(USART_MemMap_t *USARTx );
void MUSART_u8RecieveString(USART_MemMap_t *USARTx,char A_u8string[],u32 A_u32Size);



#endif /* MCAL_UART_UART_INT_H_ */
