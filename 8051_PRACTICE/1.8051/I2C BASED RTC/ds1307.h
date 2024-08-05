                         /* ds1307.h */
#ifndef __DS1307_H__
#define __DS1307_H__

#include "types.h"
u8 AsciiToHexBCD(u8 t1,u8 t2);
u8 HexBCDtoAsciiUNibble(u8);
u8 HexBCDtoAsciiLNibble(u8);
u8 Dec2HexBCD(u8 );
u8 HexBCD2Dec(u8 );

void setTime(u8 *);
u8 * getTime(void);
void setHrs(u8);
u8 getHrs(void);
void setMins(u8);
u8 getMins(void);
void setSecs(u8);
u8 getSecs(void);

void setCalendar(u8 *); // "MON/25/05/2021"
u8 * getCalendar(void);
void setDay(u8*);
u8* getDay(void);
void setDate(u8);
u8 getDate(void);
void setMonth(u8);
u8 getMonth(void);
void setYear(u8);
u8 getYear(void);


//add more declarations as & when required 

#endif
