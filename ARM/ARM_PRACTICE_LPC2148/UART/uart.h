//uart.h
#include "types.h"
void InitUART0(void);
void U0TXCHAR(u8);
void U0TXSTR(u8 *p);
void U0TXU32(u32);
void U0TXS32(s32);
void U0TXF32(f32, u8);
u8 U0RXCHAR(void);
s8* U0RXSTR(void);

