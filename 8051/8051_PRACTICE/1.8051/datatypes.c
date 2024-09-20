sfr P0 = 0x80;
sfr P1 = 0x90;
sfr P2 = 0xA0;
sfr P3 = 0xB0;

sbit VAR = P1^0;

bdata unsigned char ch = 0x80;

sbit bit7 = ch^7;


main()
{
	P0 = 0x55;
	P1 = 0x55;
	P2 = 0x55;
	P3 = 0x55;
	VAR = 0;
	bit7 = 0;
	while(1);
}
