/*               
 *
 *  Author: devEmbeddedSystem
 *
 */
#include <iostm8s003.h>
#include <stdint.h> 


#include "CS1621_HT1621.h"


int main(void)
{
	CS1621_HT1621_init();
	
	CS1621_HT1621_set_dot(0, 1);
	CS1621_HT1621_set_dot(1, 1);
	CS1621_HT1621_set_dot(2, 1);
	CS1621_HT1621_set_dot(3, 1);

	CS1621_HT1621_set_icons(0, 1);
	CS1621_HT1621_set_icons(1, 1);
	CS1621_HT1621_set_icons(2, 1);
	CS1621_HT1621_set_icons(3, 1);
	CS1621_HT1621_set_icons(4, 1);
	CS1621_HT1621_set_icons(5, 1);
	CS1621_HT1621_set_icons(6, 1);
	CS1621_HT1621_set_icons(7, 1);

	CS1621_HT1621_set_digit_value(0, 0);
	CS1621_HT1621_set_digit_value(1, 1);
	CS1621_HT1621_set_digit_value(2, 2);
	CS1621_HT1621_set_digit_value(3, 3);
	CS1621_HT1621_set_digit_value(4, 4);
	CS1621_HT1621_set_digit_value(5, 5);
	CS1621_HT1621_set_digit_value(6, 6);
	CS1621_HT1621_set_digit_value(7, 7);
	CS1621_HT1621_set_digit_value(8, 8);

	CS1621_HT1621_set_segment(9, CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_D | CS1621_HT1621_SEGMENT_E | CS1621_HT1621_SEGMENT_F);
	CS1621_HT1621_set_segment(10, CS1621_HT1621_SEGMENT_A | CS1621_HT1621_SEGMENT_B | CS1621_HT1621_SEGMENT_G | CS1621_HT1621_SEGMENT_F);
 
 
	while(1)
	{
	}
	return 0;
}