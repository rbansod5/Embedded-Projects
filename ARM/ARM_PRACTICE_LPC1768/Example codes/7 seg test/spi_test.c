				 /*SPI1-P0.6->SS[GPIO ], P0.7->SCK[15 14->10], 
P0.8->MISO[17 16->10], P0.9->MOSI[19 18->10]*/

#include<lpc17xx.h>
void spi_data(unsigned int d);
void delay(unsigned int a);

int main()
{
LPC_SC->PCLKSEL0=(3<<20);
LPC_PINCON->PINSEL0|=(1<<15)|(1<<17)|(1<<19);
LPC_PINCON->PINSEL0&=~((1<<14)|(1<<16)|(1<<18));
LPC_GPIO0->FIODIR|=(1<<6);


LPC_SSP1->CR0=(0xF<<0)|(1<<6)|(1<<7);
LPC_SSP1->CR1=(1<<1);
LPC_SSP1->CPSR=24;

spi_data(0x090F);
spi_data(0x0A0F);
spi_data(0x0B03);
spi_data(0x0C01);
spi_data(0x0F01);
delay(500);
spi_data(0x0F00);

 while(1)
 {
spi_data(0x0101);
delay(100);
spi_data(0x0207);
delay(100);
spi_data(0x0306);
delay(100);
spi_data(0x0408);

spi_data(0x01FF);
delay(100);
spi_data(0x02FF);
delay(100);
spi_data(0x03FF);
delay(100);
spi_data(0x04FF);
}
}																	 

void spi_data(unsigned int d)
{
LPC_SSP1->DR=d;
LPC_GPIO0->FIOCLR=(1<<6);
while(!(LPC_SSP1->SR&(1<<0)));
LPC_GPIO0->FIOSET=(1<<6);
}

void delay(unsigned int a)
{
unsigned int i,j;

	for(i=0;i<a;i++)
	for(j=0;j<2000;j++);
}