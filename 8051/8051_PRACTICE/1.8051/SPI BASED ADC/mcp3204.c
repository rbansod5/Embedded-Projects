#include "types.h"
#include <reg51.h>

sbit clk=P3^0;
sbit dout=P3^1;
sbit din=P3^2;
sbit _cs=P3^3;

f32 Read1_ADC_MCP3204(u8 channelNo)
{
   u8 i;
   u16 adcVal=0;
   f32 analogReading=0.0;
 
   _cs=clk=dout=din=1; //initialized to all high from 8051 master point of view

   _cs=0; //master make _cs low to activate/select slave and start communication
   //din=1; //as initialized
   clk=0; clk=1; //master issues 1st clock cycle to send start bit '1' across Din

   //din=1; //continued as high as initialized
   clk=0; clk=1; //master issue 2nd clock cycle  to send single-ended mode of conversion
                 //bit '1' across din
   //din=1; //continues as high as initialized
   clk=0; clk=1; //master issues 3rd clock cycle to send D2 don't care channel selection
                 //bit 
                           //    channelNo
                           //           d1 d0
   din=((channelNo>>1)&1); //0 = 000000 0  0
                           //1 = 000000 0  1
                           //2 = 000000 1  0
                           //3 = 000000 1  1   
   clk=0; clk=1; //master issues 4th clock cycle to send D1 channel selection bit

   din=channelNo&1;
   clk=0; clk=1; //master issues 5th clock cycle to send D0 channel selection bit,
                 //& as well start sampling analog signal across that selected
                 //channel
   clk=0; clk=1; //master issue 6th clock cycle to continue and end analog signal sampling
   clk=0; clk=1;  //master issue 7th clock cycle for mcp3204 to output NULL bit across dout
                 //as an indication that sampling  & holding of analog signal completed
   
   for(i=0;i<12;i++)
   {
     clk=0;
     if(dout) //check the serial digital data msb to lsb order
       adcVal|=(1<<(11-i)); //update digital data in correction position of variable
     clk=1; 
   }

   _cs=1; //master make _cs end to deactivate/deselect slave and stop communication

   //now processing on digital data collected in adcVal using Resolution expression
   analogReading=adcVal*(5.0/4096);
  
   return analogReading;
}
