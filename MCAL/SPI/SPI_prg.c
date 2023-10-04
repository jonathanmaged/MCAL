

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"
#include "SPI_int.h"

void MSPI_vInit(void)
{
	/*1 SPI MOSDE CPHA & CPOL*/
	SET_BIT(SPI1->CR1,0);
	SET_BIT(SPI1->CR1,1);
	/*2- Select master/slave*/
	SET_BIT(SPI1->CR1,2);
	/*3- Select Baud Rate */
	SPI1->CR1 &= ~((0b111)<<3) ;
	SPI1->CR1 |= ((SPI1_BAUDRATE)<<3) ;
	/*4-MSB/LSB First */
	CLR_BIT(SPI1->CR1,LSBFIRST);
	/*5- Data Frame*/
	CLR_BIT(SPI1->CR1,11); //DFF
	/*6- SPI enable */
	SET_BIT(SPI1->CR1,6);//SPE
	/*MOSI */
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_MODE_ALTFUN);
	MGPIO_vSetPinOutputType(GPIO_PORTA,GPIO_PIN7,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN7,5);
	/*MISO*/
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_MODE_ALTFUN);
	MGPIO_vSetPinOutputType(GPIO_PORTA,GPIO_PIN6,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN6,5);
	/*SCK*/
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_MODE_ALTFUN);
	MGPIO_vSetPinOutputType(GPIO_PORTA,GPIO_PIN5,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN5,5);

}
u16 MSPI_u16Transceive(u16 A_u16Data)
{
	SPI1->DR = A_u16Data ;
	while(GET_BIT(SPI1->SR,7)==1);
	return SPI1->DR ;
}
