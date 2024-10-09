IF(id==c_id)
{
ch=keyscan();
 switch(ch);
 {
 case '1': goto vote;
          break;
 case '2': pan();
           break;
 case '3': atm();
           break;
 }
}
void pan (void)
{
  char name,dob,adder,pan_num,
  name ="vishal";
  dob="06/06/06";
  adder="hyd,bnreddy,501510";
  pan_nnum="0102030405"
  	i2cDevWrite(0xa0,0x0100,name);
	i2cDevWrite(0xa0,0x0200,dob);
	i2cDevWrite(0xa0,0x0300,adder);
	i2cDevWrite(0xa0,0x0400,pan_num);
}

void atm(void)
{
  struct atm
  {
   int n;
   char enq[10]=15800,
   int with=n-enq,//(enq=n-enq)
   char dip[10]=n+enq; //(dip=n+dip)
    struct atm *p;
  }ATM;
     lcd_disp(1-enq ,2-with,3-dipos )
	ch=keyacn;
  switch(ch)
  {
  case '1':display(enq);
           break;
  case '2':lcd_display(enter the amount)
           p->n=LCD_pwd;
		   disp(with)//dirctely use n-enq with out n in structure
		   // update the avaliable balncy in enq
		   break;
  case '3':	lcd_display(enter the amount)
		   p->n=LCD_pwd;
		   disp(dip)//dirctely use n-enq with out n in structure
		   // update the avaliable balncy in enq
		   break;
  defult :break;
  }

}


			  /*

									  				 if(ch=='1')
				 {	int i1,i2,i3,i4;
				      i1=cnt1,i2=cnt2,i3=cnt3,i4=cnt4; 
					LCD_cmd(0x01);
				    delay_ms(100);
					LCD_cmd(0x80);
					LCD_str("1:");
					LCD_char(i1);
					//LCD_str("votes");
					LCD_cmd(0x85);
					LCD_str("2:");
					LCD_char(i2);
				    LCD_cmd(0xc0);
					LCD_str("3:");
					LCD_char(i3);
				//	LCD_str("votes");
					LCD_cmd(0xc5);
					LCD_str("4:");
					LCD_char(i4);
					delay_ms(2000);//change timne
				 }
			*/
             u32LCD((int)x);
              delay_s(1);
              delay_ms(2000);
              y=i2c_eeprom_read(0xA0,0x0201);
              LCD_cmd(0x01);
              u32LCD((int)y);
              delay_s(1);
              delay_ms(2000);
              money = (((y<<8) | x)&0xffff);
              LCD_cmd(0x01);
              u32LCD(money);
              delay_s(1);
              delay_ms(2000);



			  
void i2c_eeprom_page_write(u8 slaveAddr,u8 wBuffStartAddr,u8 *p,u8 nBytes)

{

  u8 i;

  i2c_start();	

  i2c_write(slaveAddr);    //slaveAddr + w

	i2c_write(wBuffStartAddr);  //wBuffStartAddr

	for(i=0;i<nBytes;i++)

	{

	   i2c_write(p[i]);             //wBuffAddr

	}

	i2c_stop();

	delay_ms(10);

}			 


void i2c_eeprom_seq_read(u8 slaveAddr,u8 rBuffStartAddr,u8 *p,u8 nBytes)

{

	u8 i;

	i2c_start();	

  i2c_write(slaveAddr); //slaveAddr + w

	i2c_write(rBuffStartAddr);    //rBuffAddr

	i2c_restart();	

	i2c_write(slaveAddr|1); //slaveAddr + r

	for(i=0;i<nBytes-1;i++)

	{

    p[i]=i2c_masterack();	

	}

	p[i]=i2c_nack();

	i2c_stop();

}


              
