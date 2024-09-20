#include<LPC21xx.h>
#include "types.h"
#include "lcd_defines.h"
#include "defines.h"

#include "delay.h"

void WriteLCD(u8 Dat)
{
	SCLRBIT(IOCLR0,LCD_RW);
	WRITEBYTE(IOPIN0,8,Dat);
	SSETBIT(IOSET0,LCD_EN);
	delay_us(1);
	SCLRBIT(IOCLR0,LCD_EN); 
	delay_ms(2);
}
void CmdLCD(u8 cmd)
{
	SCLRBIT(IOCLR0,LCD_RS);
	WriteLCD(cmd);
}


void InitLCD(void)
{
	//delay_ms(15);
	WRITEBYTE(IODIR0,8,0xff);
	SETBIT(IODIR0,LCD_RS);
	SETBIT(IODIR0,LCD_RW);
	SETBIT(IODIR0,LCD_EN);

	CmdLCD(0x30);
	delay_ms(100);
	CmdLCD(0x30);
	delay_ms(100);
	CmdLCD(0x30);
	delay_ms(100);
	CmdLCD(0x38);
	CmdLCD(0x08);
	CmdLCD(0x01);
	CmdLCD(0x06);
	CmdLCD(0x0e);//0x0E,0x0F
	CmdLCD(GOTO_LINE1_POS0);
	CmdLCD(DISP_ON_CUR_BLK);
	CmdLCD(CLRSCR);
	CmdLCD(SHIFT_CUR_RIGHT);
}

 void CharLCD(u8 asciiV)
{
	SSETBIT(IOSET0,LCD_RS);
	WriteLCD(asciiV);
}

void StrLCD(s8 *s)
{

     while(*s)
	CharLCD(*s++);
	
	
}

void U32LCD(u32 n)
{
	s8 i=0;
	u8 a[10];
	SSETBIT(IOSET0,LCD_RS);
	if(n==0)
	{
		WriteLCD('0');
	}
	else
	{
		while(n)
		{
			a[i++]=(n%10)+48;
			n/=10;
		}
		for(--i;i>=0;i--)
		{
			WriteLCD(a[i]);
		}
	}
}

void S32LCD(s32 n)
{
	u32 t;
	SSETBIT(IOSET0,LCD_RS);
	if(n<0)
	{
		WriteLCD('-');
		t=-n;
	}
	U32LCD(t);
}

void F32LCD(f32 f,u8 nDP)
{
	u32 ipart;
	u8 i;
	if(f<0.0)
	{
		CharLCD('-');
		f=-f;
	}
	ipart=f;
	U32LCD(ipart);
	CharLCD('.');
	for(i=0;i<nDP;i++)
	{
		f=(f-ipart)*10;
		ipart=f;
		CharLCD(ipart+48);
	}
}
void Rotate_Array(u8 *p,u8 dir)
{
s8 i,temp;
u8 a[17];
if(dir=='r')
{
temp=a[15];
for(i=15;i>0;i--)
{
a[i]=a[i-1];
}
a[0]=temp;
}
else if(dir=='l')
{
temp=a[0];
for(i=0;i<15;i++)
{
a[i]=a[i+1];
}
a[15]=temp;
}
}
void BuildCGRAM(u8 *p,u8 nBytes)
{
u8 i;
//point to cgram
CmdLCD(GOTO_CGRAM);
for(i=0;i<nBytes;i++)
{
//write into cgram
CharLCD(p[i]);
}
//relocate tp DDRAM
//CmdLCD(GOTO_LINE1_POS0);
CmdLCD(GOTO_LINE1_POS0);
}
void HexLCD(u32 n)
{
u8 a[8]={'0'};
s8 i=0,t;
while(n)
{
t=(n%16);
a  [i++]=(t>9)?((t-10)+'A'):(t+48);
n/=10;
}
for(--i;i>=0;i--)
CharLCD(a[i]);
}
void hexLCD (u32 n,u8 choice)
{		                                                                                                            
u8 a[8]={'0'};
s8 i=0,t;
if(choice=='b')
{
while(n)
{
t=(n%16);
a[i++]=t>9?(t>10)+'A':(t+48);
n=16;
}
}
}
void OctLCD(u32 num)
{
        u32 octnum[100];
        u32 i=0;
		s32 j;
        while(num!=0)
        {
                octnum[i]=num%8;
                num=num/8;
                i++;
        }
        for(j=i-1;j>=0;j--)
        {
                U32LCD(octnum[j]);
        }
        
}
void BinLCD(u32 n,u8 nBD)
{
s8 i;
for(i=(nBD-1);i>=0;i--)
{
CharLCD(((n>>i)&1)+48);
}
}
