#include"delay.h"
#include"keypad.h"
/* Define Look-Up Table for key values for T.B KeyPad */
unsigned char keypad[4][4]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                 {13,14,15,0}};       


/* Declaration : row & coloumn */
unsigned char row=0,col=0;       
unsigned char keypress;

/* Coloumn Scan */

unsigned char colscan()
{
    return(C0&C1&C2&C3);
}


unsigned char keyscan()
{
    R0=R1=R2=R3=0;                //All rows as zeros
    C0=C1=C2=C3=1;                //All colomns are ones
    
    while(colscan());            // Wait for Key pressing
    
/* Row Checking : Give Probabilities on each ROW */
       
/* For Row0 */
        R0=0;R1=R2=R3=1;

        if(!colscan())            // Any key Pressed in ROW0
        {
            row=0;                 // ROW:0 value assigned to var.
            goto colcheck;        // Go for coloumn
        }

/* For Row1 */
        R1=0;R0=R2=R3=1;   

        if(!colscan())            // Any key Pressed in ROW1   
        {   
            row=1;                // ROW:1 value assigned to var.
            goto colcheck;        // Go for coloumn   
        }

/* For Row2 */
        R2=0;R1=R0=R3=1;

        if(!colscan())            // Any key Pressed in ROW2
        {
            row=2;                // ROW:2 value assigned to var.
            goto colcheck;        // Go for coloumn
        }

/* For Row3 */
        R3=0;R1=R2=R0=1;

        if(!colscan())            // Any key Pressed
        {
            row=3;                // ROW:3 value assigned to var.
            goto colcheck;        // Go for coloumn
        }

/* Coloumn Check*/
colcheck:
    if(C0==0)                    // Any key Pressed in COL0
        col=0;                    // COL:0 value assigned to var.   
    else if(C1==0)                // Any key Pressed in COL1
        col=1;                    // COL:1 value assigned to var.
    else if(C2==0)                // Any key Pressed in COL2
        col=2;                    // COL:2 value assigned to var.
    else if(C3==0)                // Any key Pressed in COL2
        col=3;                    // COL:3 value assigned to var.

    while(!colscan());            // Wait for key release
    delay_ms(100);
    return keypad[row][col];    // Return key Value   
}

 
