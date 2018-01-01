/*               
 *
 *  Author: devEmbeddedSystem
 *
 */
#ifndef CS1621_HT1621
#define CS1621_HT1621


#define CS1621_HT1621_COMMAND_ID (1<<0xC)
#define CS1621_HT1621_WRITE_ID   (5<<0xA)
#define CS1621_HT1621_READ_ID    (6<<0x6)

#define CS1621_HT1621_SYS_DIS   (0x0)
#define CS1621_HT1621_SYS_EN    (0x4)
#define CS1621_HT1621_LCD_OFF   (0x8)
#define CS1621_HT1621_LCD_ON    (0xC)
#define CS1621_HT1621_TIMER_DIS (0x10)
#define CS1621_HT1621_WDT_DIS   (0x14)
#define CS1621_HT1621_TIMER_EN  (0x18)
#define CS1621_HT1621_WDT_EN    (0x1C)
#define CS1621_HT1621_TONE_OFF  (0x20)
#define CS1621_HT1621_TONE_ON   (0x24)
#define CS1621_HT1621_CLR_TIME  (0x30)
#define CS1621_HT1621_CLR_WDT   (0x38)

#define CS1621_HT1621_XTAL_32_K (0x50)
#define CS1621_HT1621_RC_256_K  (0x60)
#define CS1621_HT1621_EXT_256_K (0x70)

#define CS1621_HT1621_BIAS_1_2_2_COMMONS_OPTION (0x80)
#define CS1621_HT1621_BIAS_1_2_3_COMMONS_OPTION (0x90)
#define CS1621_HT1621_BIAS_1_2_4_COMMONS_OPTION (0xA0)

#define CS1621_HT1621_BIAS_1_3_2_COMMONS_OPTION (0x84)
#define CS1621_HT1621_BIAS_1_3_3_COMMONS_OPTION (0x94)
#define CS1621_HT1621_BIAS_1_3_4_COMMONS_OPTION (0xA4)

#define CS1621_HT1621_TONE_4_K 	(0x100)
#define CS1621_HT1621_TONE_2_K 	(0x180)
#define CS1621_HT1621_IRQ_DIS 	(0x200)
#define CS1621_HT1621_IRQ_EN 	(0x220)
#define CS1621_HT1621_F1 	(0x280)
#define CS1621_HT1621_F2 	(0x284)
#define CS1621_HT1621_F4	(0x288)
#define CS1621_HT1621_F8 	(0x28C)
#define CS1621_HT1621_F16 	(0x290)
#define CS1621_HT1621_F32 	(0x294)
#define CS1621_HT1621_F64	(0x298)
#define CS1621_HT1621_F128 	(0x29C)
#define CS1621_HT1621_TEST 	(0x380)
#define CS1621_HT1621_NORMAL 	(0x38C)

#define CS1621_HT1621_SEGMENT_A (1<<0x4)
#define CS1621_HT1621_SEGMENT_B (1<<0x0)
#define CS1621_HT1621_SEGMENT_C (1<<0x2)
#define CS1621_HT1621_SEGMENT_D (1<<0x7)
#define CS1621_HT1621_SEGMENT_E (1<<0x6)
#define CS1621_HT1621_SEGMENT_F (1<<0x5)
#define CS1621_HT1621_SEGMENT_G (1<<0x1)


void CS1621_HT1621_init(void);
void CS1621_HT1621_clear(void);
void CS1621_HT1621_set_digit_value(uint8_t digit, uint8_t value);
void CS1621_HT1621_set_dot(uint8_t dot, uint8_t state);
void CS1621_HT1621_set_icons(uint8_t icons, uint8_t state);
void CS1621_HT1621_set_segment(uint8_t digit, uint8_t segment);
void CS1621_HT1621_display_all_characters(void);


#endif