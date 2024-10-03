
#include <LPC21xx.H>                       /* LPC21xx definitions  */

/********************************************************************************
Function Declaration
********************************************************************************/

void delay(void);

/********************************************************************************
Main function
********************************************************************************/

int main()
{

	IO1DIR = 0xFFFFFFFF;    
	




	while(1)
	{
					//forward-WAVE DRIVE STEPPING SEQUENCE
		IOPIN1 = 0x00020000;								//Make port bits low
		IOCLR1 = 0xFFFDFFFF;
		delay();
		IOSET1 = 0x00040000;								//Make port bits low
		IOCLR1 = 0xFFFBFFFF;
		delay();
		IOSET1 = 0x00080000;								//Make port bits low
		IOCLR1 = 0xFFF7FFFF;
		delay();
		IOSET1 = 0x00100000;								//Make port bits low
		IOCLR1 = 0xFFEFFFFF;
		delay();
		
		
}

}

void delay(void)
{
	int i;
	char k;
	for(k=0;k<=10;k++)
	{
		for(i=0;i<=2000;i++) ;
	}
}
