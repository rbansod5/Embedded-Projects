/* DPTR: Data pointer is a 16-bit register which is used to hold the address of XRAM/ROM(Internal& External)
char *PTR="HAI';*/
CSEG AT 100H
PTR:DB 'HAI'	;C:100H=>'H' C:101H=>'A'   C:102H=>'I'
;DB is an assembler directive which is used to define the data in code section
/**(PTR+0)===>@(A+DPTR) ==A holds index number and DPTR holds ROM address 
*(PTR+1)
*(PTR+2)*/
/*INDEXED METHOD, INDEX SHOULD BE ZERO & ADDRESS SHOULD BE INCREMENTED TO GET THE ELEMENTS 
WHICH ARE IN CONSECUTIVE MEMORY LOCATIONS*/
CSEG AT 0
MOV DPTR,#100H	;MOV & DPTR(1) + 01H(1) + 00H(1)=3BYTES
MOV A,#0	;MOV &A(1)+0(1)=2B
MOVC A,@A+DPTR	;A=0 DPTR=100H   ,  C:@0+100H Address whatever the data is there
		;it's moved into D.OP of A
		;1BYTE
MOV 30H,A	;2BYTE

;To get the 2nd byte
MOV  A,#01h	;2B

MOVC A,@A+DPTR	;A=1 DPTR=100H   ,  C:@1+100H Address whatever the data is there
		;it's moved into D.OP of A

MOV 31H,A

;To get the 3rd byte
MOV  A,#02h

MOVC A,@A+DPTR	;A=02H DPTR=100H   ,  C:@2+100H Address whatever the data is there
		;it's moved into D.OP of A

MOV 32H,A


END


