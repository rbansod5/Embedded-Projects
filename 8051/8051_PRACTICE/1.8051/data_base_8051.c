#include<reg52.h>
#include"delay.h"
#include"uart.h"
#include"lcd.h"
#include<string.h>

        typedef struct student
        {
                int roll;
                char ch[20];
                int num;
        }stu;
int main()
{		char *p;
char i;
char j;
        stu x;
        i=x.roll=2;
        p=strcpy(x.ch,"rahul");
        j=x.num=9421896167;
		 initlcd();
  	  while(1)
	  {
	 strlcd(x.ch);
	 strlcd("rahul");
	 delay_ms(1000);
 	   }
}





