#include <reg51.h>
#include "types.h"
#include "mcp3204.h"
#include "lcd.h"
#include "delay.h"

main()
{
  	f32 analogR;

	LCD_Init();;

	Write_CMD_LCD(0x80);
	Write_str_LCD("MCP3204 TEST:");
	
	while(1)
  	{
    	analogR=Read1_ADC_MCP3204(0);
		Write_CMD_LCD(0xC0);
		Write_float_LCD(analogR,2);
		Write_DAT_LCD('V');
		delay_ms(500);
  	}
}
