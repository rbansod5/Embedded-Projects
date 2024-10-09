#include <LPC214x.h>
#include "delay.h"
#include "lcd.h"
#include "keypad.h"
#include "typ.h"
#include "i2c.h"
#include "uart.h"

#include <string.h>

void voting(void);
void ATM(void);
void atm(void);
int cash,bal,money;
unsigned char x,y;//for atm
char cnt1=0,cnt2=1,cnt3=2,cnt4=3; //for voting
extern char USER_pwd[10];
char cur_pwd[10]="1234",cur_id[15]="12540752",officer_id[15]="01157435",user_id[15];
 char buff[20],choice;
extern unsigned char i,ch,flag;
int main()
{   char ch;
   init_i2c();
	LCD_Init();
    Init_UART0();

//	int i=0;
/* i2c_eeprom_write(0xa0,0x0010,((cnt1)&0xff));
    i2c_eeprom_write(0xa0,0x0020,((cnt2)&0xff));
	i2c_eeprom_write(0xa0,0x0030,((cnt3)&0xff));
	i2c_eeprom_write(0xa0,0x0040,((cnt4)&0xff));*/
	//i2c_eeprom_write(0xa0,0x0200,(money) & 0xff);
    //i2c_eeprom_write(0xa0,0x0201,(money>>8) & 0xff);


	//initialization
	//delay_ms(500);
/*	u32LCD(i2c_eeprom_read(0xa0,0x0010));
    u32LCD(i2c_eeprom_read(0xa0,0x0020));
	u32LCD(i2c_eeprom_read(0xa0,0x0030));  */
     x=i2c_eeprom_read(0xA0,0x0200);
    y=i2c_eeprom_read(0xA0,0x0201);
   money=(y<<8)|x;
    u32LCD(money);

	//u32LCD(i2c_eeprom_read(0xa0,0x0040));
   // LCD_cmd(0x01);
   // delay_ms(500);
  // u32LCD(i2c_eeprom_read(0xa0,0x0100));
	delay_s(1);

    atm();
	while(1)
	{
	INSERT_ID:
	  	LCD_cmd(0x80);//GOTO LINE 1
	    LCD_str("Waiting for card");
  		i=0;
		flag=0;
		delay_ms(500);
 		while(flag != 2);	 // WATING FOR RFID CARD;
		LCD_cmd(0x01);				   //CLR SCREEN
		LCD_str("Card received");
		delay_ms(500);
		LCD_cmd(0xC0);
 		LCD_str(buff);	 //DISPLAING CARD NUM;
 		delay_s(1);
		for(i=0;i<=9;i++)
					user_id[i]=buff[i];
			//comparing recieved id with pre-existing id's
			if(strcmp(user_id,cur_id)==0)
			{	  
			  LCD_cmd(0x01);
			LCD_cmd(0x080);
			LCD_str("1.pancrd");
			LCD_cmd(0x88);//spliting the screen in to half
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
		//if officer id is scanned then		 
		LCD_cmd(0x01); 
		delay_ms(100);		 
		 //checking officer password
		//compare it with pre-officer password
		//if match		
			LCD_str("Enter password:");
			LCD_cmd(0XC0);
			LCD_pwd();
			delay_ms(500);		
			//if match
		//display all partys votes			
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
				  //cnt1=0;cnt2=0;cnt3=0;cnt4=0;
                   LCD_cmd(0x01);
				  delay_ms(100);
		   		 	LCD_str("reset done");
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
      if (i2c_eeprom_read(0xA0,0x0100) == 1)
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
							//increase the count value of party ch
						if(ch=='1')
						{
							i2c_eeprom_write(0xa0,0x0100,1);
							LCD_cmd(0X01);
							delay_ms(100);
                            LCD_cmd(0X80);
							LCD_str("VOTING DONE");
							delay_ms(200);
						//	goto INSERT_ID;
						}
						else if(ch=='2')
						{
							i2c_eeprom_write(0xa0,0x0100,1);
							LCD_cmd(0X01);
							delay_ms(100);
							LCD_str("VOTING DONE");
							delay_ms(200);
							//goto INSERT_ID;
						}
						else if(ch=='3')
						{
							i2c_eeprom_write(0xa0,0x0100,1);
							LCD_cmd(0X01);
							delay_ms(100);
							LCD_str("VOTING DONE");
							delay_ms(200);
						//	goto INSERT_ID;
						}
						else if(ch=='4')
						{
							i2c_eeprom_write(0xa0,0x0100,1);
							LCD_cmd(0X01);
							delay_ms(100);
							LCD_str("VOTING DONE");
							delay_ms(200);
						//	goto INSERT_ID;
						}			
              }
 }

void atm(void)
{
  unsigned char c,x,y;
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
  switch(c)
  {
    case '1':LCD_cmd(0x01);
	          LCD_cmd(0x80);
	         LCD_str("balnace enq:");
  			  LCD_cmd(0xc0);
               /*
              x=i2c_eeprom_read(0xA0,0x0200);
              LCD_cmd(0x01);
               u32LCD((int)x);
              delay_s(1);
              delay_ms(2000);
              y=i2c_eeprom_read(0xA0,0x0201);
              LCD_cmd(0x01);
              u32LCD((int)y);
              delay_s(1);
              delay_ms(2000);
              money = (((y<<8) | x)&0xffff);
              LCD_cmd(0x01);
              u32LCD(money);
              delay_s(1);
              delay_ms(2000);
              */
              delay_ms(500);
             x=i2c_eeprom_read(0xA0,0x0200);
              y=i2c_eeprom_read(0xA0,0x0201);
              money = ((((y<<8)&0xff00) | (x&0xff)) && 0xffff);
              u32LCD(money);
              delay_s(1);
			 // u32LCD(i2c_eeprom_read(0xa0,0x0200));
			  delay_ms(2000);
			  LCD_cmd(0x01);
              delay_s(1);
			  break;

	 case '2': LCD_cmd(0x01);
	           LCD_cmd(0x80);
			   LCD_str("withdraw amt");
			   LCD_cmd(0xc0);
			   ATM();
               x=i2c_eeprom_read(0xA0,0x0200);
               y=i2c_eeprom_read(0xA0,0x0201);
              money=(y<<8)|x;
              money=money-cash;
               	i2c_eeprom_write(0xa0,0x0200,(money) & 0xff);
                 i2c_eeprom_write(0xa0,0x0201,(money>>8) & 0xff);

			  // bal=i2c_eeprom_read(0xa0,0x0100);
			  // bal-=cash;
			   //i2c_eeprom_write(0xa0,0x0100,bal);
			   bal=0;
			   break;

	 case '3': LCD_cmd(0x01);
	           LCD_cmd(0x80);
			   LCD_str("deposit amt");
			   LCD_cmd(0xc0);
			   ATM();
                x=i2c_eeprom_read(0xA0,0x0200);
               y=i2c_eeprom_read(0xA0,0x0201);
              money=(y<<8)|x;
              money=money+cash;
               	i2c_eeprom_write(0xa0,0x0200,(money) & 0xff);
                 i2c_eeprom_write(0xa0,0x0201,(money>>8) & 0xff);

			 //  bal=i2c_eeprom_read(0xa0,0x0200);
			  // bal+=cash;
			  // i2c_eeprom_write(0xa0,0x0201,bal);
			   bal=0;
			   break;
	 default:  break;
	 } //switch end
	}	// end of if
    	else
				{
					LCD_cmd(0x01);
					delay_ms(100);
					LCD_str("WRONG PASSWORD");
					delay_ms(2000);
					
				}   
}
