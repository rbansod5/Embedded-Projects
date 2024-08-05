/*second highest number in led al ah*/

#include<LPC21XX.H>
#include"types.h"
#include"delay.h"
#include"defines.h"
int main()
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {		
        u32 i,max,s1max;
        u32 arr[10]={2,70,6,10,6,8,90,3,2,2};
        max=s1max=arr[0];
		SETBYTE(IODIR0,0,0xff);
		while(1)
		{
        for(i=1;i<10;i++)
        {
                if(arr[i]>max)
                {
                        s1max=max;
                        
                        max=arr[i];
                       
                }
           
                
        }
		delay_s(2);
		WRITEBYTE(IOPIN0,0,s1max^0x0f);
}}


