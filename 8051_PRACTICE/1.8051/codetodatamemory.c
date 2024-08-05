code unsigned char a[] = "INDIA";

data unsigned char a1[6];
xdata unsigned char a2[6];
bdata unsigned char a3[6];

//data - data memory - 08h
//xdata - external data memory - 00h
//bdata - bit addressable data memory area - 0x20

main()
{
	unsigned char i;
		
	for(i=0x00;i<19;i++)
	{
		a1[i] = a[i]; 
		a2[i] = a[i];
		a3[i] = a[i];
	}
	while(1);
}
