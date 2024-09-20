//lcd.h
#include"types.h"
void WriteLCD(u8 Dat);
void CmdLCD(u8 Cmd);
void InitLCD(void);
void CharLCD(u8 C);
void StrLCD(u8 *s);
void U32LCD(u32 n);
void S32LCD(s32 n);
void F32LCD(f32 n,u8 nDp);
void BuildCGRAM(u8 *p,u8 nBytes);
//void BuildCGRAM(u8 *p,u8 nBytes);
void HexLCD(u32);
//void BinLCD(u32 n,u8 nBd);

void hexLCD (u32 n,u8 choice);
void OctLCD(u32 num);
