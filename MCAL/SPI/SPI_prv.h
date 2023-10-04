
#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define SPI1_BASE_ADDRESS  0x40013000
typedef struct
{
	u32 CR1		;
	u32 CR2     ;
	u32 SR      ;
	u32 DR      ;
	u32 CRCPR   ;
	u32 RXCRCR  ;
	u32 TXCRCR  ;
	u32 I2SCFGR ;
	u32 I2SPR   ;

}SPI_MemMap;
#define SPI1  ((volatile SPI_MemMap*)(SPI1_BASE_ADDRESS))
#define LSBFIRST  7

#endif /* MCAL_SPI_SPI_PRV_H_ */
