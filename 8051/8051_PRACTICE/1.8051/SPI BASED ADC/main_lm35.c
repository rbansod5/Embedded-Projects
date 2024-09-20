#include <reg51.h>
#include "types.h"
#include "mcp3204.h"
#include "lcd.h"
#include "delay.h"

main()
{
  	f32 analogR;
	u8 temp;

	LCD_Init();;

	Write_CMD_LCD(0x80);
	Write_str_LCD("LM35 TEST:");
	
	while(1)
  	{
    	analogR=Read1_ADC_MCP3204(0);
		temp = analogR * 100;
		Write_CMD_LCD(0xC0);
		Write_int_LCD(temp);
		Write_DAT_LCD(223);;
		Write_str_LCD("C  ");
		delay_ms(500);
  	}
}
