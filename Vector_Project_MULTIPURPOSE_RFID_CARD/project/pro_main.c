#include <LPC214x.h>
#include "delay.h"
#include "lcd.h"
#include "keypad.h"
#include "typ.h"
#include "i2c.h"
#include "uart.h"
#include <string.h>
extern char USER_pwd[6];

char cur_pwd[6]="012345",cur_id[15]="00353500",officer_id[15]="12528119",user_id[15];
 char buff[20];
extern unsigned char i,ch,r_flag;
int main()
{
	char ch,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	int i=0;
	i2cDevWrite(0xa0,0x0100,cnt1);
	i2cDevWrite(0xa0,0x0200,cnt2);
	i2cDevWrite(0xa0,0x0300,cnt3);
	i2cDevWrite(0xa0,0x0400,cnt4);
	//initialization
	LCD_Init();
	Init_UART0();
		while(1)
	{
	INSERT_ID:
	  	LCD_cmd(0x80);
	    LCD_str("Waiting for card");
  		i=0;r_flag=0;
 		while(r_flag != 2);
		LCD_cmd(0x01);
		LCD_str("Card received");
		delay_ms(500);
		LCD_cmd(0xC0);
 		LCD_str(buff);
 		delay_s(1);
		for(i=0;i<=9;i++)
					user_id[i]=buff[i];
			//comparing recieved id with pre-existing id's
			if(strcmp(user_id,cur_id)==0)
			{
				LCD_cmd(0x01);	
				LCD_cmd(0x80);
			//	LCD_str("Enter Password");
				LCD_cmd(0xc0);
			//	LCD_pwd();
				//if(strcmp(cur_pwd,USER_pwd)==0)
				//	{
						LCD_cmd(0x01);
						delay_ms(100);
						LCD_str("P1-");
						CGRAM_BAT();
						LCD_cmd(0x83);
						LCD_char(0);
						LCD_cmd(0x85);
						LCD_str("P2-");	
						Store_ROBO();
						LCD_cmd(0x88);
						LCD_char(1);	
						LCD_cmd(0xc0);
						LCD_str("P3-");
						CGRAM_HEART();
						LCD_cmd(0xc3);
						LCD_char(2);
						LCD_cmd(0xc5);
						LCD_str("P4-");	
						CGRAM_SMILE();
						LCD_cmd(0xc8);
						LCD_char(3);	
						delay_ms(3000);
						LCD_cmd(0x01);
						delay_ms(100);
						LCD_str("Enter your choice");
						//LCD_cmd(0xc0);
						ch=keyscan();
							//increase the count value of party ch
						if(ch=='1')
						{
							cnt1=i2cDevRead(0xa0,0x0100);
							delay_ms(500);
							cnt1++;
							i2cDevWrite(0xa0,0x0100,cnt1);
							LCD_cmd(0X01);
							delay_ms(100);
                            LCD_cmd(0X80);
							LCD_str("VOTING DONE");
							delay_ms(200);
							goto INSERT_ID;
						}					                               
						else if(ch=='2')
						{
							cnt2=i2cDevRead(0xa0,0x0200);
							cnt2++;
							i2cDevWrite(0xa0,0x0100,cnt2);
							LCD_cmd(0X01);
							delay_ms(100);
							LCD_str("VOTING DONE");
							delay_ms(200);
							goto INSERT_ID;
						}
						else if(ch=='3')
						{
							cnt3=i2cDevRead(0xa0,0x0300);
							cnt3++;
							i2cDevWrite(0xa0,0x0100,cnt3);
							LCD_cmd(0X01);
							delay_ms(100);
							LCD_str("VOTING DONE");
							delay_ms(200);
							goto INSERT_ID;
						}
						else if(ch=='4')
						{
							cnt4=i2cDevRead(0xa0,0x0400);
							cnt4++;
							i2cDevWrite(0xa0,0x0100,cnt4);
							LCD_cmd(0X01);
							delay_ms(100);
							LCD_str("VOTING DONE");
							delay_ms(200);
							goto INSERT_ID;
						}
					/*}
					else
					{
						LCD_cmd(0x01))
						LCD_str("WRONG PASSWORD");
						delay_ms(2000);
						goto INSERT_ID;
					}  */
				}	
	else if(strcmp(user_id,officer_id)==0)
	 {
		//if officer id is scanned then		 
		LCD_cmd(0x01); 
		delay_ms(100);		 
		 //checking officer password
		//compare it with pre-officer password
		//if match		
			LCD_str("Enter password:");
			LCD_cmd(0XC0);
			LCD_pwd();		
			//if match
		//display all partys votes			
			if(strcmp(cur_pwd,USER_pwd)==0)
		 {
				LCD_cmd(0x01);
			  delay_ms(100);
				LCD_str("p1-");
				LCD_char(i2cDevRead(0xa0,0x0100)/10 + 48);
				LCD_char(i2cDevRead(0xa0,0x0100)%10 + 48);
				//LCD_str("votes");
				LCD_cmd(0x85);
				LCD_str("p2-");
				LCD_char(i2cDevRead(0xa0,0x0200)/10 + 48);
				LCD_char(i2cDevRead(0xa0,0x0200)%10 + 48);
			    LCD_cmd(0xc0);
				LCD_str("p3-");
				LCD_char(i2cDevRead(0xa0,0x0300)/10 + 48);
				LCD_char(i2cDevRead(0xa0,0x0300)%10 + 48);
			//	LCD_str("votes");
				LCD_cmd(0xc5);
				LCD_str("p4-");
				LCD_char(i2cDevRead(0xa0,0x0400)/10 + 48);
				LCD_char(i2cDevRead(0xa0,0x0400)%10 + 48);
			//	LCD_str("votes");
				delay_ms(2000);
			}
			else
			{
				LCD_cmd(0x01);
				delay_ms(100);
				LCD_str("WRONG PASSWORD");
				delay_ms(2000);
				goto INSERT_ID;
			}
		}	 //end of if else
		else
		{
		 LCD_cmd(0x01);
		 delay_ms(100);
		 LCD_str("ID NOT MATCHED");
		 delay_s(1);
		 goto INSERT_ID;
		}	
 }//end of while loop
}//end of main

