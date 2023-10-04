#ifndef MCAL_FMI_FMI_INT_H_
#define MCAL_FMI_FMI_INT_H_

enum{
	SECTOR0,
	SECTOR1,
	SECTOR2
};

void MFMI_vSectorErase(u8 A_u8SectorNumber);

void MFMI_vFlashWrite( u32 A_u32Address,
		              u16* A_pu16Data,
					  u16 A_u16Length
					  );

#endif /* MCAL_FMI_FMI_INT_H_ */
