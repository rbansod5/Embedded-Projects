#include<lpc21xx.h>
#define READBIT(data,bit) (data=((data>>bit)&1))
#define WRITEBYTE(data,bitpos,bit)(data=(data&(~255<<bitpos))|(bit<<bitpos))
typedef unsigned char u8;
#define divisor (14745600/(16*9600))
void init(void)
{
	PINSEL0=0x05;
	U0LCR=0x82;
	U0DLL=divisor;
	U0DLM=divisor>>8;
	U0LCR=0X02;
}

void txchar(unsigned char sdata)
{
	U0THR=sdata;
	while(READBIT(U0LSR,6)==0);
}

u8 rxchar(void)
{
	while(READBIT(U0LSR,0)==0);
	return U0RBR;
}
u8 *puts(u8 *p)
{
	while(*p)
	{
		txchar(*p++);
	}
	return p;
}
void gets(u8 *str)
{
	int i=0;
	u8 ch;
	while((ch=rxchar())!='\t')
	{
		txchar(ch);
		str[i++]=ch;
	}
	str[i]='\0';

}
void upper(u8 *s)
{
	int i=0;
	if(s[i]>=97&&s[i]<=122)
	{
		s[i]-=32;
	}
	i++;
	while(s[i])
	{
		if(s[i]==32)
		{
			s[i-1]-=32;
			s[i+1]-=32;
		}
		i++;
	}
	if(s[i]=='\0')
	{
		s[i-1]-=32;
	}
	puts(s);
	puts("\n\r");
} 
int main()
{
//	unsigned char flag=0;
	u8 a[100],b[100],c[100];
	init();
	l1:
	 		puts("enter the string1\n\r");
		gets(a);
		puts("\n\r");
		puts("enter the string2\n\r");
		gets(b);
		puts("\n\r");
		puts("enter the string3\n\r");
		gets(c);
		puts("\n\r");
		puts("enter pin 12 restart");
		puts("\n\r");
	while(1)
	{
	  	 while(READBIT(IOPIN0,12)==1)
		 {
	 	 
		if(READBIT(IOPIN0,8)==0)
		{
			upper(a);
			while(READBIT(IOPIN0,8)==0);
			 
		}
		if(READBIT(IOPIN0,9)==0)
		{
			upper(b);
		 	   	while(READBIT(IOPIN0,9)==0);
		}
		if(READBIT(IOPIN0,10)==0)
		{
			upper(c);
		 		while(READBIT(IOPIN0,10)==0);
		}
		
	//	puts("\n\r");
		
		}
		puts("11 for restart");
			puts("\n\r");
		if(READBIT(IOPIN0,11)==0)
		goto l1;
	}
}



