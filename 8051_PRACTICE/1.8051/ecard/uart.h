#ifndef UART_H
#define UART_H

void UART_Init(void);
void UART_Txchar(unsigned char ch);
unsigned char UART_Rxchar(void);
void UART_Str(unsigned char *str);
void UART_Int(unsigned int n);
void UART_Float(float f,unsigned char ndp);
void UART_RxTx_String();

#endif

