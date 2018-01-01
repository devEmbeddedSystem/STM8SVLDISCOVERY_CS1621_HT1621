/*               
 *
 *  Author: devEmbeddedSystem
 *
 */
#include <iostm8s003.h>
#include <stdint.h> 


#include "CS1621_HT1621.h"
#include "CS1621_HT1621_spi_software.h"


static uint8_t CS1621_HT1621_array_characters[11] =
{
	CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_B | CS1621_HT1621_SEGMENT_C | CS1621_HT1621_SEGMENT_D | CS1621_HT1621_SEGMENT_E | CS1621_HT1621_SEGMENT_F,
	CS1621_HT1621_SEGMENT_B | CS1621_HT1621_SEGMENT_C,	
	CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_B | CS1621_HT1621_SEGMENT_D | CS1621_HT1621_SEGMENT_E | CS1621_HT1621_SEGMENT_G,
	CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_B | CS1621_HT1621_SEGMENT_C | CS1621_HT1621_SEGMENT_D | CS1621_HT1621_SEGMENT_G,
 	CS1621_HT1621_SEGMENT_C | CS1621_HT1621_SEGMENT_B | CS1621_HT1621_SEGMENT_F | CS1621_HT1621_SEGMENT_G,
	CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_C | CS1621_HT1621_SEGMENT_D | CS1621_HT1621_SEGMENT_F | CS1621_HT1621_SEGMENT_G,
	CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_C | CS1621_HT1621_SEGMENT_D | CS1621_HT1621_SEGMENT_E | CS1621_HT1621_SEGMENT_F | CS1621_HT1621_SEGMENT_G,
	CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_B | CS1621_HT1621_SEGMENT_C,
	CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_B | CS1621_HT1621_SEGMENT_C | CS1621_HT1621_SEGMENT_D | CS1621_HT1621_SEGMENT_E | CS1621_HT1621_SEGMENT_F | CS1621_HT1621_SEGMENT_G ,
	CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_B | CS1621_HT1621_SEGMENT_C | CS1621_HT1621_SEGMENT_D | CS1621_HT1621_SEGMENT_F | CS1621_HT1621_SEGMENT_G,
	0
};


void CS1621_HT1621_init(void)
{
	CS1621_HT1621_spi_software_init();

	CS1621_HT1621_spi_write_data(CS1621_HT1621_COMMAND_ID | CS1621_HT1621_SYS_EN);
	CS1621_HT1621_spi_write_data(CS1621_HT1621_COMMAND_ID | CS1621_HT1621_LCD_ON);
	CS1621_HT1621_spi_write_data(CS1621_HT1621_COMMAND_ID | CS1621_HT1621_BIAS_1_3_4_COMMONS_OPTION);

	CS1621_HT1621_clear();
}

static void CS1621_HT1621_write_data_to_the_ram(uint16_t data)
{
	CS1621_HT1621_spi_write_data(CS1621_HT1621_WRITE_ID | data);
}

static uint8_t CS1621_HT1621_read_data_from_the_ram(uint8_t address)
{
	return CS1621_HT1621_spi_read_data(CS1621_HT1621_READ_ID | address);
}

void CS1621_HT1621_clear(void)
{
	uint8_t i = 0;

	for(i = 0; i < 0x18; i++)
	{
		CS1621_HT1621_write_data_to_the_ram(i<<4);
	}
}

void CS1621_HT1621_set_digit_value(uint8_t digit, uint8_t value)
{
	uint8_t data = 0;
	
	if(digit == 0)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x17);
		data = (data & 0x8);
		data = (data | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0x17<<0x4) | data);
		CS1621_HT1621_write_data_to_the_ram((0x16<<0x4) | (CS1621_HT1621_array_characters[value]>>0x4));
	}
	else if(digit == 1)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x15);
		data = (data & 0x8);
		data = (data | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0x15<<0x4) | data);
		CS1621_HT1621_write_data_to_the_ram((0x14<<0x4) | (CS1621_HT1621_array_characters[value]>>0x4));
	}
	else if(digit == 2)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x13);
		data = (data & 0x8);
		data = (data | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0x13<<0x4) | data);
		CS1621_HT1621_write_data_to_the_ram((0x12<<0x4) | (CS1621_HT1621_array_characters[value]>>0x04));
	}
	else if(digit == 3)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x11);
		data = (data & 0x8);
		data = (data | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0x11<<0x4) | data);
		CS1621_HT1621_write_data_to_the_ram((0x10<<0x4) | (CS1621_HT1621_array_characters[value]>>0x4));
	}
	else if(digit == 4)
	{
		CS1621_HT1621_write_data_to_the_ram((0xF<<0x4) | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0xE<<0x4) |  (CS1621_HT1621_array_characters[value]>>0x4));
	}
	else if(digit == 5)
	{
		CS1621_HT1621_write_data_to_the_ram((0xD<<0x4) | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0xC<<0x4) | (CS1621_HT1621_array_characters[value]>>0x4));
	}
	else if(digit == 6)
	{
		CS1621_HT1621_write_data_to_the_ram((0xB<<0x4) | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0xA<<0x4) | (CS1621_HT1621_array_characters[value]>>0x4));
	}
	else if(digit == 7)
	{
		CS1621_HT1621_write_data_to_the_ram((0x9<<0x4) | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0x8<<0x4) | (CS1621_HT1621_array_characters[value]>>0x4));
	}
	else if(digit == 8)
	{
		CS1621_HT1621_write_data_to_the_ram((0x7<<0x4) | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0x6<<0x4) | (CS1621_HT1621_array_characters[value]>>0x4));
	}
	else if(digit == 9)
	{
		CS1621_HT1621_write_data_to_the_ram((0x5<<0x4) | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0x4<<0x4) | (CS1621_HT1621_array_characters[value]>>0x4));
	}
	else if(digit == 10)
	{
		CS1621_HT1621_write_data_to_the_ram((0x3<<0x4) | (0xF & CS1621_HT1621_array_characters[value]));
		CS1621_HT1621_write_data_to_the_ram((0x2<<0x4) | (CS1621_HT1621_array_characters[value]>>0x4));
	}
}

void CS1621_HT1621_set_dot(uint8_t dot, uint8_t state)
{
	uint8_t data = 0;
	
	if(dot == 0)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x17);
		if(state) data |= 0x8;
		else data &= ~0x8;
		CS1621_HT1621_write_data_to_the_ram((0x17<<0x4) | data);
	}
	else if(dot == 1)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x15);
		if(state) data |= 0x8;
		else data &= ~0x8;
		CS1621_HT1621_write_data_to_the_ram((0x15<<0x4) | data);
	}
	else if(dot == 2)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x13);
		if(state) data |= 0x8;
		else data &= ~0x8;
		CS1621_HT1621_write_data_to_the_ram((0x13<<0x4) | data);
	}
	else if(dot == 3)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x11);
		if(state) data |= 0x8;
		else data &= ~0x8;
		CS1621_HT1621_write_data_to_the_ram((0x11<<0x4) | data);
	}
}

void CS1621_HT1621_set_icons(uint8_t icons, uint8_t state)
{
	uint8_t data = 0;
	
	if(icons == 0)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x1);
		if(state) data |= 0x8;
		else data &= ~0x8;
		CS1621_HT1621_write_data_to_the_ram((0x1<<0x4) | data);
	}
	else if(icons == 1)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x1);
		if(state) data |= 0x4;
		else data &= ~0x4;
		CS1621_HT1621_write_data_to_the_ram((0x1<<0x4) | data);
	}
	else if(icons == 2)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x1);
		if(state) data |= 0x2;
		else data &= ~0x2;
		CS1621_HT1621_write_data_to_the_ram((0x1<<0x4) | data);
	}
	else if(icons == 3)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x1);
		if(state) data |= 0x1;
		else data &= ~0x1;
		CS1621_HT1621_write_data_to_the_ram((0x1<<0x4) | data);
	}
	else if(icons == 4)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x0);
		if(state) data |= 0x8;
		else data &= ~0x8;
		CS1621_HT1621_write_data_to_the_ram((0x0<<0x4) | data);
	}
	else if(icons == 5)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x0);
		if(state) data |= 0x4;
		else data &= ~0x4;
		CS1621_HT1621_write_data_to_the_ram((0x0<<0x4) | data);
	}
	else if(icons == 6)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x0);
		if(state) data |= 0x2;
		else data &= ~0x2;
		CS1621_HT1621_write_data_to_the_ram((0x0<<0x4) | data);
	}
	else if(icons == 7)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x0);
		if(state) data |= 0x1;
		else data &= ~0x1;
		CS1621_HT1621_write_data_to_the_ram((0x0<<0x4) | data);
	}
}

void CS1621_HT1621_set_segment(uint8_t digit, uint8_t segment)
{
	uint8_t data = 0;
	
	if(digit == 0)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x17);
		data = data & 0x8;
		segment = data | segment;
		CS1621_HT1621_write_data_to_the_ram((0x17<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0x16<<0x4) | (segment)>>0x4);
	}
	else if(digit == 1)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x15);
		data = data & 0x8;
		segment = data | segment;
		CS1621_HT1621_write_data_to_the_ram((0x15<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0x14<<0x4) | (segment>>0x4));
	}
	else if(digit == 2)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x13);
		data = data & 0x8;
		segment = data | segment;
		CS1621_HT1621_write_data_to_the_ram((0x13<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0x12<<0x4) | (segment>>0x04));
	}
	else if(digit == 3)
	{
		data = CS1621_HT1621_read_data_from_the_ram(0x11);
		data = data & 0x8;
		segment = data | segment;
		CS1621_HT1621_write_data_to_the_ram((0x11<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0x10<<0x4) | (segment>>0x4));
	}
	else if(digit == 4)
	{
		CS1621_HT1621_write_data_to_the_ram((0xF<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0xE<<0x4) | (segment>>0x4));
	}
	else if(digit == 5)
	{
		CS1621_HT1621_write_data_to_the_ram((0xD<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0xC<<0x4) | (segment>>0x4));
	}
	else if(digit == 6)
	{
		CS1621_HT1621_write_data_to_the_ram((0xB<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0xA<<0x4) | (segment>>0x4));
	}
	else if(digit == 7)
	{
		CS1621_HT1621_write_data_to_the_ram((0x9<<0x4) |  (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0x8<<0x4) | (segment>>0x4));
	}
	else if(digit == 8)
	{
		CS1621_HT1621_write_data_to_the_ram((0x7<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0x6<<0x4) | (segment>>0x4));
	}
	else if(digit == 9)
	{
		CS1621_HT1621_write_data_to_the_ram((0x5<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0x4<<0x4) | (segment>>0x4));
	}
	else if(digit == 10)
	{
		CS1621_HT1621_write_data_to_the_ram((0x3<<0x4) | (0xF & segment));
		CS1621_HT1621_write_data_to_the_ram((0x2<<0x4) | (segment>>0x4));
	}
}

void CS1621_HT1621_display_all_characters(void)
{
	uint8_t i = 0;

	for(i = 0; i < 0x18; i++)
	{
		CS1621_HT1621_write_data_to_the_ram((i<<0x4) | 0xF);
	}
}