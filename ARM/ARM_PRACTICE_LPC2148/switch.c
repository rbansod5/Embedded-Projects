#include<lpc21xx.h>
#include"delay.h"
#include"defines.h"
#include"types.h"
main()
{
	u8 cnt=0;
	WRITEBYTE(IODIR0,0,0xff);
	while(1)
	{
	if(READBIT(IOPIN0,8)==0)
	{

	cnt++;

	WRITEBYTE(IOPIN0,0,cnt^0x0f);
	while(READBIT(IOPIN0,8)==0);
	}
	}
	}
