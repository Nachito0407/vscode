#include "pmodAD1.h"

unsigned short AD74XX_GetRegisterValue(int spi_handler)
{
    unsigned char  dataWord[SPI_RX_BUFFER];
    unsigned short convResult;

	spiRead(spi_handler, dataWord, SPI_RX_BUFFER);

	convResult = (((unsigned short)((dataWord[0] << 8) & 0x0F00))) + (dataWord[1] & 0xFF );

    return convResult;
}