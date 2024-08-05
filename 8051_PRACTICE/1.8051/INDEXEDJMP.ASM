

CSEG AT 100H

STR: DB 'HAI'	;DEFINE BYTES IN CODE SEGMENT AT 100H 

;100H - 'H' 101H - 'A'  102H - 'I'


CSEG AT 0	;WRITE PROGRAM FROM 0th Memory Location to execute

MOV DPTR,#STR	;Assign Code Address with variable name into DPTR
MOV R0,#30H	;Assign IRAM base address to indirect 8 bit register to store o/p
MOV R7,#3	;Store strlen in one register to iterate

ITER:		;label name
CLR A		;Using Pointer Method so, make index number as 0
MOVC A,@A+DPTR	;Get the data from code memory using DPTR in indirect way
MOV @R0,A	;Store each character in IRAM of consecutive addresses by using Indirect Register
INC DPTR	;To get each character inorder increment the code addresses
INC R0		;To store each character in IRAM memory locations in consecutive, increment RAM Address
DJNZ R7,ITER	;Iterate strlen times to get all characters

END
