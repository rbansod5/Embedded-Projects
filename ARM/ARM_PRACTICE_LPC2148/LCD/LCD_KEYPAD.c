#include <LPC214X.H>
#include"types.h"
#include"defines.h"
#include"delay.h"
#include"kpm_defines.h"
#include"lcd_defines.h"
#include<string.h>


#define Succuss_LED 16 //P0.16
#define Failure_LED 17 //P0.17

const u8 Current_Password[] = "12345";
int password(void);

int main()
{
    u8 i;
	int res;
	//initialize the required devices for this application
	InitKPM();
	InitLCD();
	SETBIT(IODIR0,Succuss_LED);
	SETBIT(IODIR0,Failure_LED);
	//Display "Enter password" on 1st line of LCD
	CmdLCD(GOTO_LINE1_POS0);
	StrLCD("Enter password");
	while(1)
	{  
		res = password();
		//call password function which returns succuss or failure
		if(res)
		{
			//Clear LCD display
			CmdLCD(CLEAR_LCD);
			//Display "Valid Password" on LCD
			CmdLCD(GOTO_LINE1_POS0);
			StrLCD("Valid password");
			//wait for some delay for visualization
			delay_ms(100);
			//blink the Succuss_Led for 5 times @ 0.5 seconds
			for(i=0;i<5;i++)
			{
			SETBIT(IOPIN0,Succuss_LED);
			delay_ms(500);
		    CLRBIT(IOPIN0,Succuss_LED);
			delay_ms(500);
			}
		}							
		else
		{
			//Clear LCD display
			CmdLCD(CLEAR_LCD);
			//Display "Wrong Password" on LCD
			CmdLCD(GOTO_LINE1_POS0);
			StrLCD("Wrong password");
			//wait for some delay for visualization
			delay_ms(100);
			//blink the Failure_Led for 5 times @ 0.5 seconds
			for(i=0;i<5;i++)
			{
			SETBIT(IOPIN0,Failure_LED);
			delay_ms(500);
		    CLRBIT(IOPIN0,Failure_LED);
			delay_ms(500);
			}
		}
	} 
}


int password(void)
{
	//declare the required variables
	u8 ch;
	s8 Index=0,User_Password[10];
	
	while(1)
	{		
		ch = KeyScan(); //read the key from keypad
		delay_ms(500);
		if(ch=='*')//if delete_key is pressed
		{
			//delete latest key information from User_Password arrary & on LCD
			if(Index>0)
			Index--;
			CmdLCD(GOTO_LINE2_POS0+Index);
			CharLCD(' ');
		}
		else if(ch=='#'|| Index==10) //if enter_key is pressed or array maximum size reached)
		{
			//update the '\0' character at the updated index position of User_Password 
			User_Password[Index]='\0';
			break;
		}
		else
		{
			//update the key value into User_Password array
			User_Password[Index++]=ch;
			//display '*' on lcd
			CmdLCD(0x80-1);
			CharLCD('*');
		}	
	}
	 
	if(!my_strcmp(User_Password,Current_Password))
		return 1;
	else
		return 0;

}

int my_strcmp(s8 *up,const s8 *cp)
{
	//write the function body for string comparision with proper return values
	int cmpstat=0;
	while((*up!='\0' && *cp!='\0')&& *up==*cp)
	{
	up++;
	cp++;
	}
	cmpstat=(*up==*cp)?0:(*up>*cp)?1:-1;
	return cmpstat;
}