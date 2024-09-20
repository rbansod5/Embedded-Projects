/*

16X1-1 LINE,16 POSITIONS
16X2 - 2 LINES, EACH LINE 16 POSITIONS =16X2= 32 CHARACTERS CAN ABLE TO SEE AT A TIME
20x1
20x2
20x4

PINS - 16

GND,VCC,VADJ-VARAIBLE RESISTOR
RS,RW,EN - CONTROL SIGNAL PINS
D0 - D7 - 8 DATA LINES

LED+-VCC, LED- - GND  - For Back Light of LCD


MEMORY - RAM	ROM

 DDRAM - 80BYTES
	 CGRAM - 64 BYTES - At a time 8 customized characters can able to see on screen

hd44780 - Internal IC

HD - HITACHI


If we want to see the data on LCD


1) Enable number of datalines(8), no. of lines(2), pixel size(5X7) - 0X38 
2) If any data is there to display present data clear the previous data -  0X01
3) Make display off & cursor off - 0x10
4) If we want to see the data, we should make on our display - for  4 & 5 steps 0x0e	
5) If we need to know the present position make cursor on
6) By defualt if we the characters have to display in the next position of previous character - 0x06
make cursor towards right position / increment the cursor
Eg:A_
AB_
7) By default at intialization cursor has to display in first line first position - 0x 80

After completion of above steps pass required data what we are going to see on LCD

So for above 7 steps predefined commands are provided by the LCD manufacturer

1)We should write(RW=0) those commands on 8 data lines(D0-D7)
2) in command mode (RS=0)
3)To process that command apply high to low pulse on Enable pin with minimum of delay
EN=1 DELAY_MS(2); EN=0

*/


#include<reg51.h>

#define LCD_DATA P0

sbit RS=P2^0;
sbit RW=P2^1;
sbit EN=P2^2;

//char cgram_lut[]={0x17,0x14,0x14,0x1f,0x05,0x05,0x1d,0x00};
char cgram_lut[]={0x0f,0x12,0x14,0x14,0x14,0x12,0x0f,0x00,0x0f,0x13,0x15,0x15,0x15,0x13,0x0f,0x00};
// char cgram_lut[]={0x0e,0x07,0x03,0x01,0x03,0x07,0x0e,0x00,0x00,0x0f,0x1f,0x01,0x1f,0x0f,0x00,0x00};
void delay_ms(unsigned int dly)//mov r6,#hb, mov r7,#lb
{
	unsigned char i;
	for(;dly>0;dly--)//16bit condition at a time it's not possible to check 16 bit value
	// so divided into 2, 8 bits, So, 2 times have to check.2 times branch instruction has to take
	//Each time 2MC=Total 2x2=4MC
	// subtraction/dec also not possible with 16 bit
	//so, divided into 2,8-bits
	//2 times subtractions. Each time 2m.c=2x2=4MC
	{
		for(i=255;i>0;i--);//MOV R0,#255 , DJNZ R0,$
		for(i=232;i>0;i--);//MOV R0,#232 , DJNZ R0,4
	}
}//RET


void cmdlcd(char cmd)
{
	RS=0;		// COMMAND REGISTER WILL OPEN
	LCD_DATA=cmd;
	RW=0;		// WRITE MODE, 8 BIT INFO(CMD) IS WRITING ON LCD
	EN=1;
	delay_ms(2);
	EN=0;		// To Process the info
}	

void datalcd(char dat)
{
	RS=1;		// DATA REGISTER WILL OPEN
	LCD_DATA=dat;
	RW=0;		// WRITE MODE, 8 BIT INFO(CMD) IS WRITING ON LCD
	EN=1;
	delay_ms(2);
	EN=0;		// To Process the info
}	

void initlcd(void)
{
	cmdlcd(0x38);//5x7 pixel, 8-bit mode, 2lines
	cmdlcd(0x10);//display off , cursor off
	cmdlcd(0x01);//clear the screen
	cmdlcd(0x0e);//display on cursor on
	cmdlcd(0x80);//first line first position
}

void strlcd(char *str/*VECTOR*/)
{
	while(*str!='\0')//'V','E','C','T','O','R','\0' -  LOOP FAILS
	{
		datalcd(*str);//1('V')
		str++;//address will increment
	}
}


/* num=123  ---->  1	2	3  -----> '1'	'2'	'3' ------> display each ascii on lcd*/
void integerlcd(int num/*123*/)
{
	char a[10], index=0;
	if(num==0)
		datalcd(0+48);
	while(num)//123 is not zero //12 is not zero // 1 is not zero // 0 is zero. So, cond fails,breaks the loop
	{
		a[index++]=num%10;//(1)123%10 = > a[0]=3, index=1  (2)12%10=2 => a[1]=2 , index=2
		//(3)1%10=1 => a[2]=1,index=3
		num=num/10;	//(1) 123/10=12	(2)12/10=1  (3) 1/10=0 
	}
	for(--index;index>=0;index--)//index ==>3-1=2  //2-1=1				//1-1=0
		datalcd(a[index]+48);	//a[2]+48=>1+48='1'//a[1]+48=2+48='2'	//a[0]+48=3+48='3'
}

/* Store Customzied characters hexadecimal values in CGRAM */
void BuildCgram(void)
{
	char i=0;
	cmdlcd(0x50);//CGRAM ADDRESS STARTS FROM 0X50 - 0x4f - for 2 customized characters// index numbers 2,3
	for(i=0;i<16;i++)
		datalcd(cgram_lut[i]);
}


main()
{
	initlcd();//cursor will display in first line first position with out any data
	
//because of display on cursor is visible to us 
//data is writing using 8-data lines, data fixed in 5x7 pixel able to 32 characters in 16x2 lcd
	datalcd('A');
	cmdlcd(0x86);
	strlcd("VECTOR");
//	integerlcd(1546);
	BuildCgram();// CUSTOMIZED CHARACTER HEXADECIMAL VALUES ARE STORED IN CGRAM
	cmdlcd(0xc0);// To move the cursor secondline 1st position
//	If we need to display customized character, bring those hex values from CGRAM to DDRAM
	datalcd(2);//If Customized character hex values in 0x40 -0x47 - pass 0 index number
	datalcd(3);//If Customized character hex values in 0x40 -0x47 - pass 0 index number

/*	index number 1 - 0x48 - 0x4f
 	index number 2 - 0x50 - 0x57
	index number 3 - 0x58 - 0x5f
	index number 4 - 0x60 - 0x67
	index number 5 - 0x68 - 0x6f
	index number 6 - 0x70 - 0x77
	index number 7 - 0x78 - 0x7f
	*/
	while(1);

}


/*EG:

'V' - to display this ascii on lcd. We have to fix in 5x7 pixel -  7 roes 5 columns
LCD manufacturer drawn symbol on 5x7 pixel
calculated each row hexadecimal value
like will get 7 hexa decimal values and 8th one cursor
those hexadecimal values are stored in CGROM
When we applied high to low pulse on EN pin
One process will go that is
Whatever the data we are going to display, that ascii related hexadecimal values will
collect from CGROM and each hexadecimal value bring back to DDRAM in specific position

In CGROM manufacturer provoded hexadecimal values for
'a' - 'z'
'A' - 'Z'
'0' - '9'
All special characters except functin keys , arrow keys, enter,shift,backspace,delete keys
Each character hexadeimal values are 8 to fix in 5x7 pixel*/





/*1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
V	E	C	T	O	R
	V	E	C	T	O	R
		V	E	C	T	O	R



										 V	E	C	T	O	R
											V	E	C	T	O
												V	E	C	T
													V	E	C
														V	E
															V
	NOTHING

R											V	E	C	T	O
O	R											V	E	C	T


V	E	C	T	O	R	
					



1)  Scroll string from left to right
2)  Scroll String from right to left
3)  Circular rotate of string
4)  Display palidrome numbers which are in b/w 100 150
5)  Check the string is palindrome or not, if it is palindrome display on lcd.
*/
