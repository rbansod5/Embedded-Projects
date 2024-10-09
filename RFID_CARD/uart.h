#ifndef _UART0_H_
#define _UART0_H_ 

void Init_UART0(void);
void UART0_Tx_char(unsigned char);
unsigned char UART0_Rx_char(void);
void UART0_Tx_str(char *);
void UART0_Tx_int(signed int);
void UART0_Tx_float(float,char);


#endif
