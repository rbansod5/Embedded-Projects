#include <LPC21xx.H>

	#define LED (1 << 17)
	#define BUZ	(1 << 11)
 	#define RS   (1<<10)
	#define RW   (1<<12)
	#define EN   (1<<13)
	#define LCD_DATA  (0xFF<<16)
	
	void interrupt_init(void);
	void delay(int count);
	void LCD_command (unsigned char a);

	void LCD_init(void)
{
	IODIR0 |= EN|RS|RW|LCD_DATA;
	//LCD_command(0x02);		//reset the lcd display
	LCD_command(0X38); 		//intializes the 16x2 ,5x7 LCD matrix  8-bit mode
	LCD_command(0X0F); 		//  display on cursor blinking
  	LCD_command(0X01); 		//clear screen ,cursor home
	LCD_command(0X80);		//Start with first line


}
void LCD_command (unsigned char a)
{
	IOPIN0 = a<<16;
	IOCLR0 = RS;
	IOCLR0 = RW;
	IOSET0 = EN;
	delay(100);
	IOCLR0 = EN;
	delay(100);

}
void LCD_data(unsigned char a)	 
{
	IOPIN0 = a << 16;
	IOCLR0 = RW;
	IOSET0 = RS;
	IOSET0 = EN;
	delay(100);
	IOCLR0 = EN;
	delay(100);

}

void LCD_display(char *str)
{
//	int pos = 0;
	while(*str)
	{
		{
			LCD_data(*str);
		}
		str++;
		delay(50);
//		pos++
	}
}
	
	void ext_int3(void)__irq
	{
	   
		IOSET0 |= BUZ;
		IOSET1 |= LED;
		delay(100);
		IOCLR0 |= BUZ;
		IOCLR1 |= LED;
		delay(100);
		LCD_command(0x01);
			EXTINT = 1 << 3;
		LCD_display("IN ISR ");
	
		VICVectAddr = 0;
	}
	
	int main()
	{
	    IODIR0 |= BUZ ;
		IODIR1 |= LED;
		PINSEL1 = 0x00000000;
		interrupt_init();
		LCD_init();
		LCD_display("External_Interrupt");
		delay(3000);
	    
	    while(1)
		{
			
			LCD_command(0x01);
		  LCD_display("In while 1");
			delay(1000);
		}
	}
	 	
		
	void interrupt_init(void)
	{
	//	PINSEL0 |= (0<< 28)|(1 << 29);	 //port p0.14  bits 28 and 29
	//	PINSEL0 |= (1 << 18)|(1 << 19);	   //port p0.9 bits 18 and 19
		PINSEL1 |= (1 << 29) | (0 << 28);	//Port P0.30 bits 28 and 29 
	
		VICIntSelect = (0 << 17);
		VICVectCntl0 = (1 << 5) | 17;
		VICVectAddr0 = (long)ext_int3;
		EXTMODE = 1<<3;
		EXTPOLAR = 1<<3;
		VICIntEnable |= (1 << 17);	  
	
		//	EXTINT |= 0X02;
		//VICVectAddr = 0;
	}

	void delay(int count)
	{
		int i,j;
		for(i =0;i < count;i++)
			for(j = 0;j < 5000;j++);
	}
	
	
	
	
