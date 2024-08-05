#define LCD_DATA P1

sbit RS=P3^7;
sbit RW=P3^6;
sbit EN=P3^5;


void cmdlcd(char cmd);
	

void datalcd(char dat);

void initlcd(void);


void strlcd(char *str );


void integerlcd(int num );

void BuildCgram(void);
