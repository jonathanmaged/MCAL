/*
 * UART_prg.c
 *
 *  Created on: Aug 23, 2023
 *      Author: john
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"UART_int.h"
#include"UART_cfg.h"
#include"UART_prv.h"
#include "../SYSTICK/SYSTICK_int.h"

void MUSART_vInit(USART_cfg* A_USARTcfg,USART_MemMap_t *USARTx)
{

	switch(A_USARTcfg->OverSampling){
	case USART_OVER_SAMPLING_16: USARTx->BRR = UART_BRR_SAMPLING16(P_CLK,A_USARTcfg->BaudRate); break;
	case USART_OVER_SAMPLING_8: USARTx->BRR = UART_BRR_SAMPLING8(P_CLK,A_USARTcfg->BaudRate); break;
//	case USART_OVER_SAMPLING_8: USARTx->BRR = (104<<4)| (2<<0); break;

	}
	USARTx->CR1 = (A_USARTcfg->OverSampling)<<MUSART_CR1_OVER8_BIT  |
				  (A_USARTcfg->DataWidth)<<MUSART_CR1_M_BIT |
				  (A_USARTcfg->ParityEnable)<<MUSART_CR1_PCE_BIT |
				  (A_USARTcfg->ParitySelection)<<MUSART_CR1_PS_BIT |
				  (A_USARTcfg->TransferDirection)<<MUSART_CR1_RE_BIT  ;

	USARTx->CR2 = (A_USARTcfg->StopBits)<<MUSART_CR2_STOP_BIT ;


}
void MUSART_vEnable(USART_MemMap_t *USARTx){
	SET_BIT(USARTx->CR1,MUSART_CR1_UE_BIT);
}

void MUSART_vDisable(USART_MemMap_t *USARTx){
	CLEAR_BIT(USARTx->CR1,MUSART_CR1_UE_BIT);
}

void MUSART_vTransmitByteBlocking(USART_MemMap_t *USARTx , u8 Data){
	while(GET_BIT(USARTx->SR,MUSART_SR_TXE_BIT)==0 ) ;
	USARTx->DR =Data ;
	while(GET_BIT(USARTx->SR,MUSART_SR_TC_BIT)==0 ) ;
	CLEAR_BIT(USARTx->SR,MUSART_SR_TC_BIT);
}
u8 MUSART_u8TransmitByteNonBlocking(USART_MemMap_t *USARTx , u8 Data){
	u8 ReturnValue ;
	if(GET_BIT(USARTx->SR,MUSART_SR_TXE_BIT)==1 )
	{
		USARTx->DR =Data ;
		ReturnValue=1 ;
	} else
		ReturnValue =0 ;
	return ReturnValue ;

	while(GET_BIT(USARTx->SR,MUSART_SR_TC_BIT)==0 ) ;
	CLEAR_BIT(USARTx->SR,MUSART_SR_TC_BIT);
}
void MUSART_vTransmitString(USART_MemMap_t *USARTx,char *A_ptru8string)
{
	for(int i=0; A_ptru8string[i] != '\0';i++){
		MUSART_vTransmitByteBlocking(USARTx, A_ptru8string[i]) ;
		 MSYSTICK_vSetBusyWait(300000);
	}
}

u8 MUSART_u8RecieveByteBlocking(USART_MemMap_t *USARTx){
	u8 L_u8Data = '0' ;
	while(GET_BIT(USARTx->SR,MUSART_SR_RXNE_BIT)==0 ) ;
	L_u8Data = USARTx->DR  ;
	return L_u8Data ;

}
u8 MUSART_u8RecieveByteNonBlocking(USART_MemMap_t *USARTx ){
	u8 L_u8Data = 0 ;
	if(GET_BIT(USARTx->SR,MUSART_SR_RXNE_BIT)==1 ){
	L_u8Data =  USARTx->DR  ;
	}
	return L_u8Data ;
}
void MUSART_u8RecieveString(USART_MemMap_t *USARTx,char A_u8string[],u32 A_u32Size){
	u8 L_u8Iterator=0;
	while(L_u8Iterator<A_u32Size)
	{
		A_u8string[L_u8Iterator] = MUSART_u8RecieveByteBlocking(USARTx) ;

		if(A_u8string[L_u8Iterator] == '\r' || A_u8string[L_u8Iterator] == '\n' )
		{
			A_u8string[L_u8Iterator] = '\0' ;
			break;
		}
		L_u8Iterator++ ;
	}
	A_u8string[A_u32Size-1]='\0' ;

}
