#include<reg51.h>

idata unsigned char ch,buff[25];
char j=0,tx_flag=0,flag=0;
char rx_flag=0;

void UART_Init(void)
{
 	SCON=0x50;
  	TMOD=0X20;
  	TH1=253;
  	TR1=1;
	IE=0x91;
}
/*
char UART_Rx_char()
{
	while(RI!=1);
	RI=0;
	return SBUF;
}
*/
void serial_int(void) interrupt 4
{
	if(TI==1)
	{
		tx_flag=1;
		TI=0;	
	}
	else if(RI)
	{
		ch = SBUF;
		if(ch==0x0D)
		{
			buff[j]='\0';
			flag=1;
			j=0;
		}
		else
		{
			buff[j++]=ch;
		}
		RI=0;
	}
}



