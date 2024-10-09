#include <LPC214x.h>
#include <string.h>

#include "delay.h"
#include "lcd.h"
#include "keypad.h"
#include "typ.h"
#include "i2c.h"
#include "uart.h"



int money=0;
int cash=0;
unsigned char x,y;//for atm
//static char cnt=0;//for voting
char choice;
char cur_pwd[10]="1234",cur_id[]="00328237",officer_id[]="00328239",user_id[10];

extern char buff[20];
extern char USER_pwd[10];
extern unsigned char i,ch,flag;

void display(void);
void voting(void);
void ATM(void);
void atm(void);


int main()
{   
	char ch;
   	init_i2c();
	LCD_Init();
    Init_UART0();
//	i2c_eeprom_write(0xA0,0x0000,(1000&0xff));
//	i2c_eeprom_write(0xA0,0x0001,((1000>>8)&0xff));
	delay_ms(500);
	//initialization
    LCD_cmd(0x01);
	delay_ms(500);
    x=i2c_eeprom_read(0xA0,0x0000);
    y=i2c_eeprom_read(0xA0,0x0001);
    money=(y<<8)|x;
    u32LCD(money);
	delay_s(1);
	while(1)
	{
	INSERT_ID:
	  	LCD_cmd(0x80);//GOTO LINE 1
	    LCD_str("Waiting for card");
  		i=0;
		flag=0;
		delay_ms(500);
 		while(flag != 2);	
		LCD_cmd(0x01);				   
		LCD_str("Card received");
		delay_ms(500);
		LCD_cmd(0xC0);
 		LCD_str(buff);	 
 		delay_s(1);

		for(i=0;i<=9;i++)
					user_id[i]=buff[i];
			if(strcmp(user_id,cur_id)==0)
			{	  
			  LCD_cmd(0x01);
			LCD_cmd(0x080);
			LCD_str("1.pancrd");
			LCD_cmd(0x88);
			LCD_str("2.voting");
			LCD_cmd(0xc0);
			LCD_str("3.atm");
			LCD_cmd(0xc8);
			LCD_str("4.exit");
			delay_ms(2000);
			 LCD_cmd(0x01);
             LCD_cmd(0X80);
			 LCD_str("enter choice");
			  choice=keyscan();
			 switch(choice)
			 {
			   case '1': LCD_cmd(0x01);
                         LCD_str("pancard");
			             delay_ms(1000);
						 LCD_cmd(0x01);
						  LCD_cmd(0x80);
						  LCD_str("name: VECTOR");
						  LCD_cmd(0xc0);
						  LCD_str("dob: 06/06/06");
						  delay_ms(1000);
						  LCD_cmd(0x01);
						  LCD_cmd(0x80);
						  LCD_str("addr:hyd 501510");
						  LCD_cmd(0xc0);
						  LCD_str("pan-V22HE9");
						  delay_ms(1000);
						  LCD_cmd(0x01);
			 			break;

			   case '2': LCD_cmd(0x01);
                         LCD_str("voting");
                        delay_s(1);
			             voting();
						 goto INSERT_ID;
						 //break;

			   case '3':LCD_cmd(0x01);
                        LCD_str("atm");
                        delay_ms(1000);
			             atm();
						 goto INSERT_ID;

			   default :LCD_cmd(0x01);
                        LCD_str("exit");
			            delay_ms(500);
						break;
			 
			 }	//END SWITCH;					
			} //IF END
			else if(strcmp(user_id,officer_id)==0)
	 		{
		 
			LCD_cmd(0x01); 
			delay_ms(100);		 
			LCD_str("Enter password:");
			LCD_cmd(0XC0);
			LCD_pwd();
			delay_ms(500);		
			if(strcmp(cur_pwd,USER_pwd)==0)
		     {
		     LCD_cmd(0x01); 
			 delay_ms(100);
			 LCD_cmd(0x80);						 
			 LCD_str("correct password");
			 delay_ms(500);
			 LCD_cmd(0x01);
			 LCD_cmd(0x80);
    		 LCD_str("2.reset");
				 do
				 {
				 	ch=keyscan();
				 }while(ch!='2');
            	 if(ch=='2')//disply voting count on to LCD ch='1';
				 {
				 //cnt=0;
                   i2c_eeprom_write(0xa0,0x0100,0);
                   LCD_cmd(0x01);
				  delay_ms(1000);
		   		 	LCD_str("reset done");
                   delay_ms(1000);
				    LCD_cmd(0x01);
				 }
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

void voting(void)
{         
      if (i2c_eeprom_read(0xa0,0x0100)==1)
      { 
        LCD_cmd(0x01);
        LCD_str("vote alrdy done");
        delay_ms(1000);
        LCD_cmd(0x01);
      	return;
       }

        else {
			  char ch;
	                	LCD_cmd(0x01);	
						LCD_cmd(0x80);
						LCD_cmd(0xc0);
						LCD_cmd(0x01);
						delay_ms(100);
						LCD_str("P1-");
						CGRAM_BAT();
						LCD_cmd(0x83);
						LCD_char(0);
						LCD_cmd(0x88);//bug
						LCD_str("P2-");	
						Store_ROBO();
						LCD_cmd(0x8c);
						LCD_char(1);	
						LCD_cmd(0xc0);
						LCD_str("P3-");
						CGRAM_HEART();
						LCD_cmd(0xc3);
						LCD_char(2);
						LCD_cmd(0xc8);
						LCD_str("P4-");	
						CGRAM_SMILE();															    
						LCD_cmd(0xcc);
						LCD_char(3);	
						delay_ms(3000);
						LCD_cmd(0x01);
						delay_ms(100);
						LCD_str("Enter your choice");
						//LCD_cmd(0xc0);
						ch=keyscan();
						if(ch=='1')
						{
							i2c_eeprom_write(0xa0,0x0100,1);
							//cnt++;
							LCD_cmd(0X01);
							delay_ms(100);
                            LCD_cmd(0X80);
							LCD_str("VOTING DONE");
							delay_ms(1000);
						//	goto INSERT_ID;
						}
						else if(ch=='2')
						{
							i2c_eeprom_write(0xa0,0x0100,1);
							//cnt++;
							LCD_cmd(0X01);
							delay_ms(100);
							LCD_str("VOTING DONE");
							delay_ms(1000);
						}
						else if(ch=='3')
						{
							i2c_eeprom_write(0xa0,0x0100,1);
							//cnt++;
							LCD_cmd(0X01);
							delay_ms(100);
							LCD_str("VOTING DONE");
							delay_ms(1000);
						}
						else if(ch=='4')
						{
							i2c_eeprom_write(0xa0,0x0100,1);
							//cnt++;
							LCD_cmd(0X01);
							delay_ms(100);
							LCD_str("VOTING DONE");
							delay_ms(1000);
						}			
              }
 }

void atm(void)
{  int s=0,p=0;
  unsigned char c;
  LCD_cmd(0x01);
  LCD_cmd(0x80);
  LCD_str("Enter pin:");
  LCD_cmd(0XC0);
  LCD_pwd();
  delay_ms(1000);		
if(strcmp(cur_pwd,USER_pwd)==0)
  {
  LCD_cmd(0x01);
  LCD_str("welcome to sbi");
  delay_ms(900);
  LCD_cmd(0x01);
  LCD_cmd(0x80);
  LCD_str("name: vishwa");
  LCD_cmd(0xc0);
  LCD_str("1.B 2.W  3.D 4.E");
  delay_ms(2000);
  LCD_cmd(0x01);
  LCD_cmd(0x80);
  LCD_str("enter choice");
  delay_ms(100);
  c=keyscan();
  delay_ms(100);
 while(1)
 {
  switch(c)
  {
    case '1':LCD_cmd(0x01);
	          LCD_cmd(0x80);
	         LCD_str("balnace enq:");
  			  LCD_cmd(0xc0);
                LCD_cmd(0x01);
        		delay_ms(500);
			x=i2c_eeprom_read(0xA0,0x0000);
    		y=i2c_eeprom_read(0xA0,0x0001);
   			money=(y<<8)|x;
    		u32LCD(money);
			delay_s(1);
		  	LCD_cmd(0x01);
            break;

	 case '2': LCD_cmd(0x01);
	           LCD_cmd(0x80);
			   LCD_str("withdraw amt");
			   LCD_cmd(0xc0);
			   ATM();
			    LCD_cmd(0x01);
			   if(cash%100==0)
			   {
	               x=i2c_eeprom_read(0xA0,0x0000);
	               y=i2c_eeprom_read(0xA0,0x0001);
	               money=(y<<8)|x;
	               s=money-cash;
				   if(s>0)
				   {
				       money=money-cash;
				       i2c_eeprom_write(0xa0,0x0000,(money) & 0xff);
		               i2c_eeprom_write(0xa0,0x0001,(money>>8) & 0xff);
		              	
				   }
				   else
				   {
					   LCD_cmd(0x01);
					   LCD_cmd(0x01);
					   LCD_str("insff balance");
					   delay_ms(1000);
					   LCD_cmd(0x01);
				   }

			   }
			   else
			   {
			     LCD_cmd(0x01);
				 LCD_str("enter crt amt");
				 delay_ms(2000);
				 LCD_cmd(0x01);
			   }
			  
			   break;

	 case '3': LCD_cmd(0x01);
	           LCD_cmd(0x80);
			   LCD_str("deposit amt");
			   LCD_cmd(0xc0);
			   ATM();
               x=i2c_eeprom_read(0xA0,0x0000);
               y=i2c_eeprom_read(0xA0,0x0001);
                money=(y<<8)|x;
				//u32LCD(money);
				delay_ms(500);
				p=money+cash;
               if(p <= 65000)
			   {
			   money=money+cash;
			   delay_ms(500);
               i2c_eeprom_write(0xa0,0x0000,(money) & 0xff);
               i2c_eeprom_write(0xa0,0x0001,(money>>8) & 0xff);
			   LCD_cmd(0x01);
			   LCD_str("thank you");
			   delay_ms(1000);
			   LCD_cmd(0x01);
			   }
			   else
			   {
			     LCD_cmd(0x01);
				 LCD_str("limit reached");
				 delay_ms(2000);
				 LCD_cmd(0x01);
				 }
			   break;
	 default:  break;
	 } //switch end
	 break;
  }
	}	// end of if
    	else
				{
					LCD_cmd(0x01);
					delay_ms(100);
					LCD_str("WRONG PASSWORD");
					delay_ms(2000);
					
				}   
}
