#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "FMI_int.h"
#include "FMI_prv.h"


void MFMI_vSectorErase(u8 A_u8SectorNumber)
{
	/*1-wait if flash is busy */
	while(GET_BIT(FLASH->SR,BSY));
	/*2-Unlock flash register using KEYR*/
	if(GET_BIT(FLASH->CR,LOCK))
	{
		FLASH->KEYR = KEY1;
		FLASH->KEYR = KEY2;
	}
	/*3-Select sector number to erase*/
	FLASH->CR &=~ ((u32)(0b1111<<3)) ;
	FLASH->CR |= ((u32)(A_u8SectorNumber<<3)) ;
	/*4- activate Sector erase*/
	SET_BIT(FLASH->CR,SER);
	/*4-Start erase operation*/
	SET_BIT(FLASH->CR,STRT);
	/*5-wait for Busy flag*/
	while(GET_BIT(FLASH->SR,BSY));
	/*7- Clear EOP flag*/
	SET_BIT(FLASH->SR,EOP);
	/*4- deactivate Sector erase*/
	CLR_BIT(FLASH->CR,SER);
}

void MFMI_vFlashWrite( u32  A_u32Address,
		              u16* A_pu16Data,
					  u16  A_u16Length
					  )
{
	/*1-wait if flash is busy */
	while(GET_BIT(FLASH->SR,BSY));
	/*2-Unlock flash register using KEYR*/
	if(GET_BIT(FLASH->CR,LOCK))
	{
		FLASH->KEYR = KEY1;
		FLASH->KEYR = KEY2;
	}
	/*3- select element size */
	FLASH->CR &=~ ((u32)(0b11<<8)) ;
	FLASH->CR |= ((u32)((0b01)<<8)) ;
	/*4-Activate Programming mode */
	SET_BIT(FLASH->CR,PG);
	/*5- write Data Array on flash address*/
	for(u16 i=0;i<A_u16Length;i++)
	{
		*((volatile u16*)A_u32Address) =  A_pu16Data[i];
		A_u32Address+=2;
		/*wait if flash is busy */
		while(GET_BIT(FLASH->SR,BSY));
		/*Clear EOP flag*/
		SET_BIT(FLASH->SR,EOP);
	}
	CLR_BIT(FLASH->SR,PG);
}




