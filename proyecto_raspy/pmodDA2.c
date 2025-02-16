#include "pmodDA2.h"

void DAC121S101_SendRegisterValue(unsigned short value, int spi_handler)
{
    unsigned char dataWord[SPI_TX_BUFFER];

	dataWord[0] = (unsigned char)((value >> 8) & 0x000F);
	dataWord[1] = (unsigned char)((value >> 0) & 0x00FF);

	spiWrite(spi_handler, dataWord, SPI_TX_BUFFER);
	
	return;
}