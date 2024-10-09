#include "typ.h"
#include <LPC214x.h>
#include "keypad.h"
#include <string.h>
#include "defines.h"
#include "delay.h"
#include "lcd.h"


#define ROWS0 16 //P1.16
#define ROWS1 17 //P1.17
#define ROWS2 18 //P1.18
#define ROWS3 19 //P1.19	 
#define COL0 20 //P1.20
#define COL1 21 //P1.21
#define COL2 22 //P1.22
#define COL3 23 //P1.23

//char CUR_pwd[6];
char USER_pwd[10];
extern int cash;

char keypad_lut[4][4] = 
					   	{
						 {'1','2','3','A'},
			             {'4','5','6','B'},
		                 {'7','8','9','C'},
			             {'*','0','#','D'}
						};				


u8 scancodes[4]={14,13,11,7};

void InitKpm(void)
{
WRITENIBBLE(IODIR1,ROWS0,0xf);
//defult cols are input lines
//WRITENIBBLE(IODIR1,ROWS,COLS,0);
} 

void InitRows(void)
{
    WRITENIBBLE(IODIR1,ROWS0,0xf);
}
void InitCols(void)   
 {  WRITENIBBLE(IODIR1,COL0,0x0);		
 	}
						
u8 Colscan()
{
u8 t;
t=(READNIBBLE(IOPIN1,COL0)<15)?0:1;
return t;
}

u8 keyscan(void)
{
 

u8 rNO,cNO,Keyval=0,i;//wating to detect any key press
InitRows();
  while(Colscan())
  {
  Keyval++;
  }
  for(i=0;i<4;i++)
  {
  WRITENIBBLE(IOPIN1,ROWS0,scancodes[i]);
	if(!Colscan())
	{
	rNO=i;
	break;
    }
  }
  WRITENIBBLE(IOPIN1,ROWS0,0);
  for(i=0;i<4;i++)
  {
    if(READBIT(IOPIN1,COL0+i)==0)
	{
	cNO=i;
	break;
	}
   }
	Keyval =  keypad_lut[rNO][cNO];
	while(!Colscan());
	delay_ms(500);
	return Keyval;
	}

void LCD_pwd(void)
{
int i=0;
unsigned char ch;
	while(1)
	{
		ch=keyscan();
		if(ch>='0'&& ch<='9')
		{
			USER_pwd[i]=ch;
			LCD_char(ch);
			LCD_cmd(0X10);
			delay_ms(500);
	   //   delay_ms(1000);
			LCD_char('*');
			i++;
		}
		else if(ch=='*')
		{
			if(i>0)
			{
			LCD_cmd(0X10); //move cur to lift;
			delay_ms(200);
			LCD_char(' ');
			delay_ms(200);
			LCD_cmd(0X10);
			delay_ms(500);
			i--;
			}
		}
		else if(ch=='#')
		{
			USER_pwd[i]='\0';
			break;
		}
	}
}

void ATM(void)
{
int i=0;
unsigned char ch;
	while(1)
	{
		ch=keyscan();
		if(ch>='0'&& ch<='9')
		{
			//atm[i]=ch-48;
			LCD_char(ch);
			ch=ch-48;
			 cash=cash*10+ch;
          //  LCD_cmd(0x14);
		}
		else if(ch=='*')
		{
			if(i>0)
			{
			LCD_cmd(0X10); //move cur to lift;
			delay_ms(200);
			LCD_char(' ');
			delay_ms(200);
			LCD_cmd(0X10);
			delay_ms(500);
			i--;
			}
		}
		else if(ch=='#')
		{
		//	atm[i]
			break;
		}
	}
}


