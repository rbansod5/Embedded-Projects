 #include<reg52.h>
 #include"i2c.h"
 #include"delay.h"


extern  rec[12];
int main()	  
{
//  unsigned char dataa[12];
   while(1)
   {
  ser_init();
  i2c_send_string(0x00," DYNAMITE");
  i2c_read_string(0x00);
  tx_str(rec);
  }

}