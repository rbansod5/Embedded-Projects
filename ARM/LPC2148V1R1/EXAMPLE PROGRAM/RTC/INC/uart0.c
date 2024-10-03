/******************************/
/* Initial UART1 = 9600,N,8,1 */
/* VPB(pclk) = 60.00 MHz      */
/******************************/
void init_serial0 (void)  
{
  PINSEL0 &= 0xFFFFFFF0;									// Reset P0.8,P0.9 Pin Config
  PINSEL0 |= 0x00000001;									// Select P0.0 = TxD(UART1)
  PINSEL0 |= 0x00000004;									// Select P0.1 = RxD(UART1)

  U0LCR &= 0xFC;											// Reset Word Select(1:0)
  U0LCR |= 0x03;											// Data Bit = 8 Bit
  U0LCR &= 0xFB;											// Stop Bit = 1 Bit
  U0LCR &= 0xF7;											// Parity = Disable
  U0LCR &= 0xBF;											// Disable Break Control
  U0LCR |= 0x80;											// Enable Programming of Divisor Latches

  // U1DLM:U1DLL = 60.00 MHz / [16 x Baud]
  //             = 60.00 MHz / [16 x 9600]
  //             = 390.6 = 391 = 0187H
  U0DLM = 0x00;												// Program Divisor Latch(391) for 9600 Baud
  U0DLL = 0x5D;

  U0LCR &= 0x7F;											// Disable Programming of Divisor Latches

  U0FCR |= 0x01;											// FIF0 Enable
  U0FCR |= 0x02;											// RX FIFO Reset
  U0FCR |= 0x04;											// TX FIFO Reset
  U0FCR &= 0x3F;                       
}

/****************************/
/* Write character to UART0 */
/****************************/
void putchar0 (int ch)  
{                  
  if (ch == '\n')  
  {
    while (!(U0LSR & 0x20));								// Wait TXD Buffer Empty
    U0THR = 0x0D;                          					// Write CR
  } 
  while (!(U0LSR & 0x20)); 									// Wait TXD Buffer Empty
  U0THR = ch;						    			// Write Character
}

/*****************************/
/* Read character from UART0 */
/*****************************/
int getchar0 (void)  
{                    
  while (!(U0LSR & 0x01));	 								// Wait RXD Receive Data Ready
  return (U0RBR);											// Get Receice Data & Return
}


/***************************/
/* Print String to UART[0] */
/***************************/
void print_uart0(void)
{
  char *p;													// Pointer Buffer
  p = uart0_buf;											// UART Buffer
 
  do 														// Get char & Print Until null
  {
    putchar0(*p); 											// Write char to UART
    p++;													// Next char
  }
  while(*p != '\0');										// End of ASCII (null)
 
  return;
}


