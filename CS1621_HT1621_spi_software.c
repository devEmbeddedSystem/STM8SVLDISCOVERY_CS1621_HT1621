/*               
 *
 *  Author: devEmbeddedSystem
 *
 */
#include <iostm8s003.h>
#include <stdint.h> 


#include "CS1621_HT1621_spi_software.h"
 
 
typedef enum
{
	 CS1621_HT1621_DATA_PIN_OUTPUT = 0,
	 CS1621_HT1621_DATA_PIN_INPUT
}
CS1621_HT1621_data_pin_mode; 
 

void CS1621_HT1621_set_data_mode(CS1621_HT1621_data_pin_mode mode)
{
	if(mode == CS1621_HT1621_DATA_PIN_OUTPUT)
	{
		PB_DDR |= 0x08;
		PB_CR1 |= 0x08;
		CS1621_HT1621_DATA_HIGH;
	}
	else
	{
		PB_DDR &= ~0x08;
		PB_CR1 &= ~0x08;
		CS1621_HT1621_DATA_LOW;
	}
}

void CS1621_HT1621_spi_software_init(void)
{
 	PB_DDR |= 0x0f;
	PB_CR1 |= 0x0f;
	
	CS1621_HT1621_CS_HIGH;
	CS1621_HT1621_WR_HIGH;
	CS1621_HT1621_RD_HIGH;
	CS1621_HT1621_DATA_HIGH;
}

void CS1621_HT1621_spi_write_data(uint16_t data)
{
	uint16_t cnt = 0x1000;

	CS1621_HT1621_set_data_mode(CS1621_HT1621_DATA_PIN_OUTPUT);

	CS1621_HT1621_CS_LOW;
	while(cnt)
	{
		if(data & cnt)
		{
			CS1621_HT1621_DATA_HIGH;
		}
		else
		{
			CS1621_HT1621_DATA_LOW;
		}
		CS1621_HT1621_WR_LOW;
		CS1621_HT1621_WR_HIGH;
		cnt >>= 0x1;
	}
	CS1621_HT1621_CS_HIGH;
}

uint8_t CS1621_HT1621_spi_read_data(uint16_t address)
{
	uint16_t cnt = 0x100;
	uint8_t return_data = 0;

	CS1621_HT1621_set_data_mode(CS1621_HT1621_DATA_PIN_OUTPUT);

	CS1621_HT1621_CS_LOW;
	while(cnt)
	{
		if(address & cnt)
		{
			CS1621_HT1621_DATA_HIGH;
		}
		else
		{
			CS1621_HT1621_DATA_LOW;
		}
		CS1621_HT1621_WR_LOW;
		CS1621_HT1621_WR_HIGH;
		cnt >>= 0x1;
	}

	CS1621_HT1621_set_data_mode(CS1621_HT1621_DATA_PIN_INPUT);

	cnt = 0x8;
	while(cnt)
	{
		return_data <<= 0x1;
		CS1621_HT1621_RD_LOW;
		CS1621_HT1621_RD_HIGH;
		if(CS1621_HT1621_DATA_IS_HIGH) return_data |= 0x1;
		cnt >>= 0x1;
	}
	CS1621_HT1621_CS_HIGH;
return return_data;
}

