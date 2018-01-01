/*               
 *
 *  Author: devEmbeddedSystem
 *
 */
#ifndef CS1621_HT1621_SPI_SOFTWARE
#define CS1621_HT1621_SPI_SOFTWARE


#define CS1621_HT1621_CS_LOW (PB_ODR &= ~0b00000001)
#define CS1621_HT1621_CS_HIGH (PB_ODR |= 0b00000001)

#define CS1621_HT1621_RD_LOW (PB_ODR &= ~0b00000010)
#define CS1621_HT1621_RD_HIGH (PB_ODR |= 0b00000010)

#define CS1621_HT1621_WR_LOW (PB_ODR &= ~0b00000100)
#define CS1621_HT1621_WR_HIGH (PB_ODR |= 0b00000100)

#define CS1621_HT1621_DATA_LOW (PB_ODR &= ~0b00001000)
#define CS1621_HT1621_DATA_HIGH (PB_ODR |= 0b00001000)

#define CS1621_HT1621_DATA_IS_HIGH (PB_IDR & 0b00001000)


void CS1621_HT1621_spi_software_init(void);
void CS1621_HT1621_spi_write_data(uint16_t data); 
uint8_t CS1621_HT1621_spi_read_data(uint16_t address);


#endif