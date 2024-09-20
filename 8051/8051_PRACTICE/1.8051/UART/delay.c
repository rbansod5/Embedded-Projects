void delay_ms(unsigned int ms)
{
	unsigned int i;
	for (;ms>0;ms--)
		for(i=0;i<126;i++);
}
