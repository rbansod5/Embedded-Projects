/** compiler directives **/
#include<reg52.h>


/** global variables declaration **/
bit r_flag,t_flag;
unsigned char ch=0,k,rec_buff[25];


/** serial interrupt routine **/
void serial_int(void) interrupt 4
{
	if(TI == 1)	//if TI flag set
	{	
		t_flag = 1;
		TI = 0;	//clear TI bit for identifying next character sending
	}
	else if(RI==1) //if RI flag set
	{
		ch = SBUF;	//collect the received data byte
		if(ch == '$')
		{
			r_flag=1;	//used for identifing the end of the string entry		
			rec_buff[k] = '\0';
			//strcpy(main_buff,rec_buff);
			k=0;
		}
		else 
			rec_buff[k++] = ch;	//svae the collected byte in to buffer
		RI = 0;	//claer RI bit to identify the next byte receive		
	}
}

/** uart initialization **/
void uart_init(void)
{
	TMOD = 0X20;	//timer1, mode2 (auto reloaded mode)
	SCON = 0X50;	//select standard UART mode (mode1) 
					//serial mode1, 8-bi data,1 stop bit,1 start bit 
	TH1 = 0XFD;		//9600 baudrate selection
	TR1 = 1;		//timer1 on
	IE = 0X90;		//enable serial port interrupt
}

/** sending one character through uart **/
void uart_tx(unsigned char dat)
{
	t_flag = 0;	//clear t_flag variable
	SBUF = dat;	//place one byte data into SBUF register
	while(t_flag == 0);	//waiting for transmit complete
}

/** send string through uart*/
void uart_string(unsigned char *str)
{
	while(*str)	//sending character by character till null
		uart_tx(*str++);	//sending one character through uart
}





