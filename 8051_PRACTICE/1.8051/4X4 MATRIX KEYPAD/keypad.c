#include<reg51.h>
sbit r0=P2^0;
sbit r1=P2^1;
sbit r2=P2^2;
sbit r3=P2^3;
sbit c0=P2^4;
sbit c1=P2^5;
sbit c2=P2^6;
sbit c3=P2^7;
char row_val,col_val;
char code Key_Val[][4]={'1','2','3',
				        '4','5','6',
						'7','8','9',
						'#','0','*'};
void Row_Init(void)
{
	r0=r1=r2=r3=0;
}
bit IsKeyPress(void)
{
	return(c0&c1&c2&c3);
}
char KeyValue(void)
{
	Row_Init();
	while((c0&c1&c2&c3));//waiting for key Pressing

	r0=0;r1=r2=r3=1;
	if(!(c0&c1&c2&c3))
	{
		row_val=0;	
		goto col_check;			
	}
	r1=0;r0=r2=r3=1;
	if(!(c0&c1&c2&c3))
	{
		row_val=1;	
		goto col_check;		
	}
	r2=0;r0=r1=r3=1;
	if(!(c0&c1&c2&c3))
	{
		row_val=2;	
		goto col_check;		
	}
	r3=0;r0=r1=r2=1;
	if(!(c0&c1&c2&c3))
		row_val=3;	
		
col_check:
	if(c0==0)
		col_val=0;
	else if(c1==0)
		col_val=1;
	else if(c2==0)
		col_val=2;
	else	
		col_val=3;
	while(!(c0&c1&c2&c3));//waiting for key release
	return(Key_Val[row_val][col_val]);
}
