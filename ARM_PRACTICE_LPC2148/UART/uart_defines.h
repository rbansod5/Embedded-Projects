//uart_defines.h
//u0LCR sfr defines
#define _8BITS 3
#define WORD_LEN _8BITS
#define DLAB_BIT 7
//u0LCR SFR defines
#define DR_BIT 0
#define THRE_BIT 5
#define TEMT_BIT 6
#define BAUD 9600
#define FOSC 12000000
#define CCLK (FOSC*5)
#define PCLK CCLK/4
#define DIVISOR (PCLK/(16*BAUD))
#define TxD0_PIN_EN 0x00000001
#define RxD0_PIN_EN 0X00000004
#define Tx_LED 6//p0.6
#define Rx_LED 7//P0.7
