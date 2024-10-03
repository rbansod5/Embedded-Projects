char uart0_buf[];
char uart1_buf[];
char uart2_buf[];

/* pototype  section */
void init_serial0 (void); 									// Initil UART-0
void init_serial1 (void);
void init_serial2 (void);
void putchar0 (int ch);  										// Put Char to UART-0
void putchar1 (int ch);
void putchar2 (int ch);
int getchar0 (void);
int getchar1 (void);
int getchar2 (void);
void print_uart0(void);  										// Get Char From UART-0
void print_uart1(void);
void print_uart2(void);


