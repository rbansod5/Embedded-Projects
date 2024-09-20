/*LEDs-> P1.19 to P1.26
	Buzzer-> P1.27
	Relay->  P1.28*/

#include<lpc17xx.h>
void delay(unsigned int a);
int main()
{

LPC_GPIO1->FIODIR=(0X3FF<<19);

	while(1)
	{
	LPC_GPIO1->FIOSET=(0X3FF<<19);
	 delay(500);
	LPC_GPIO1->FIOCLR=(0X3FF<<19);
	 delay(500);
	}

}

void delay(unsigned int a)
{
unsigned int i,j;

	for(i=0;i<a;i++)
	for(j=0;j<3000;j++);

}
