/****************************************************************
		MAIN_PROJECT_FILE.C
 ***************************************************************/

#include<lpc21xx.h>

#include <stdlib.h>

#include "delay.h"

#include "uart.h"

#include "defines.h"

#include "lcd.h"
#include"lcd_defines.h"

#include "keypad.h"

#define LED_DATA 8

int main()

{

	u32 i;

	u8 ch,ch1,cp;

    InitLCD();

	InitUART0();

	

	while(1)

	{

	MENU: U0TXSTR("**********MENU**********");

		    U0TXSTR("\r\n");

		    delay_ms(300);

		    U0TXSTR("1.LEDS");

	     	U0TXSTR("\r\n");

		    delay_ms(300);

        U0TXSTR("2.SWITCH");

		   U0TXSTR("\r\n");

		     delay_ms(300);

        U0TXSTR("3.LCD");

		    U0TXSTR("\r\n");

		    delay_ms(300);

        U0TXSTR("4.KEYPAD");

		    U0TXSTR("\r\n");

		    delay_ms(300);

        U0TXSTR("5.BUZZER");

		    U0TXSTR("\r\n");

		   delay_ms(300);

        ch=U0RXCHAR();

		    U0TXCHAR(ch);

				U0TXSTR("\r\n");

		switch(ch)

		{

			case '1':

				LED:   U0TXSTR("----You have selected for LED interfacing----");

               U0TXSTR("\r\n");  			

               U0TXSTR("Use port pins from p0.0 to p0.8 for interfacing");

			         U0TXSTR("\r\n");

               U0TXSTR("Are you completed with connections");

			         U0TXSTR("\r\n");

			         U0TXSTR("1.YES 2.NO");

			         U0TXSTR("\r\n");

			         ch=U0RXCHAR();

			         U0TXCHAR(ch);

			if(ch==2)

			{

				 U0TXSTR("check for the connections again");

				goto LED;

			}

			else if(ch==1)

			{

				goto CHECK;

			}

			CHECK:WRITEBYTE(IODIR0,LED_DATA,0XFF);

			      WRITEBYTE(IOPIN0,LED_DATA,0XF0);

			

		  

		

			

             U0TXSTR("LEDS are working");

             U0TXSTR("\r\n");

             U0TXSTR("1.YES 2.NO");

			       U0TXSTR("\r\n");

			      ch=U0RXCHAR();

			      U0TXCHAR(ch); 

				    U0TXSTR("\r\n");

			   if(ch==1)

			    {

					//	break;

					}

					else if(ch==2)

					{						

				   

						U0TXSTR("1.check the connectors");

						U0TXSTR("\r\n");

						U0TXSTR("as GND to Active Low LED");

						U0TXSTR("\r\n");

						U0TXSTR("2.check the connections"); 

						U0TXSTR("\r\n");

						U0TXSTR("3.check the program in debugger");

						U0TXSTR("\r\n");

						U0TXSTR("4.check the interfacing");

						U0TXSTR("\r\n");

					}

				//	break;

						

						

			case '2':U0TXSTR("---You have selected for SWITCH interfacing---");

               U0TXSTR("\r\n");

               U0TXSTR("connect an Active low SWITCH to Active low LED");

			         U0TXSTR("\r\n");

				//	break;

			case '3':

				LCD:		U0TXSTR("---You have selected for LCD interfacing---");

			         U0TXSTR("\r\n");

			         U0TXSTR("use port pins from p0.8 to p0.15 as DATA bits on to LCD");

			         U0TXSTR("\r\n");	

               U0TXSTR("CONNECT P0.16 RS to p0.17 EN");

			         U0TXSTR("\r\n");

					     U0TXSTR("Are you done with connection");

					     U0TXSTR("\r\n");

			         U0TXSTR("1.YES 2.NO");

			         U0TXSTR("\r\n");

			         ch=U0RXCHAR();

			         U0TXCHAR(ch);

					       U0TXSTR("\r\n");

					if(ch1==1)

					{

						goto CHECK1;

					}

					else if(ch1==2)

					{

							   U0TXSTR("check for the connection again");

	             goto LCD;

					}						

	

						 CHECK1:  CmdLCD(0x80);

						 for(i=0;i<13;i++)

					{

						CharLCD('A'+i);

							 delay_ms(300);

					}

					CmdLCD(0xc0);

					for(i=13;i<26;i++)

					{

					CmdLCD('A'+i);

					delay_ms(300);

				  }

								 

    

		    U0TXSTR("is LCD working");

				U0TXSTR("\r\n");

				U0TXSTR("1.YES 2.NO");

	      U0TXSTR("\r\n");

			  ch=U0RXCHAR();

				U0TXCHAR(ch);

				U0TXSTR("\r\n");

						 if(ch==1)

					 {

						// break;

					 }

					 

					 else if(ch==2)

						 {

             U0TXSTR("1.check the connections as started above");						 

				      U0TXSTR("\r\n");		 

							U0TXSTR("2.check the program in Debugger");

							U0TXSTR("\r\n");

							U0TXSTR("3.check the interfacing");

							 U0TXSTR("\r\n");

						 }

					//	 break;

							 

			case '4':U0TXSTR("---You have selected for 4x4 KEYPAD interfacing---");

				       U0TXSTR("\r\n");

               U0TXSTR("use port pins from p1.16 to p1.9 as 4 ROWS");

						   U0TXSTR("\r\n");

						   U0TXSTR("use port pins from p1.20 to p1.23 as COLUMNS");

						   U0TXSTR("\r\n");

		

		      ch = keyscan();

		      CharLCD(cp);

					U0TXCHAR(cp);

				  U0TXSTR("\r\n");		 

			//	 break;

	

			 					

			case '6': U0TXSTR("---You have selected for BUZZER interfacing---");

						   U0TXSTR("\r\n");

						   U0TXSTR("connect an Active HIGH SWITCH to BUZZER port pin");

						   U0TXSTR("\r\n");

	           //  break;



			default:  break;

					 }



							 U0TXSTR("---Do you wanna  continue---");

						   U0TXSTR("\r\n");

						   U0TXSTR("1.CONTINUE 2.EXIT");

							 U0TXSTR("\r\n");

							 ch=U0RXCHAR();

							 U0TXCHAR(ch);

							 if(ch==1)

							 {

								 goto MENU;

							 }

							 else if(ch==2)

							 {

								 exit(0);

							 }

						 }

					 }


				 

					 