/* DPTR: Data pointer is a 16-bit register which is used to hold the address of XRAM/ROM(Internal& External)
*/
CSEG AT 100H
DB 'HAI'	;C:100H=>'H' C:101H=>'A'   C:102H=>'I'
;DB is an assembler directive which is used to define the data in code section

/*POINTER METHOD, INDEX SHOULD BE ZERO & ADDRESS SHOULD BE INCREMENTED TO GET THE ELEMENTS 
WHICH ARE IN CONSECUTIVE MEMORY LOCATIONS*/
CSEG AT 0
MOV DPTR,#100H	;MOV & DPTR(1) + 01H(1) + 00H(1)=3BYTES
MOV A,#0	;MOV &A(1)+0(1)=2B
MOVC A,@A+DPTR	;A=0 DPTR=100H   ,  C:@0+100H Address whatever the data is there
		;it's moved into D.OP of A
		;1BYTE
MOV 30H,A	;2BYTE

;To get the 2nd byte
MOV  A,#00h	;2B

MOV DPTR,#101H	;3B

;CLR A		; whatever the value in A it will clear. A=00h

;INC DPTR	;DPTR<== DPTR+1  ==>100H+1  ==> 101H

MOVC A,@A+DPTR	;A=0 DPTR=101H   ,  C:@0+101H Address whatever the data is there
		;it's moved into D.OP of A

MOV 31H,A

;To get the 3rd byte
MOV  A,#00h

MOV DPTR,#102H

;CLR A		; whatever the value in A it will clear. A=00h

;INC DPTR	;DPTR<== DPTR+1  ==>101H+1  ==> 102H

MOVC A,@A+DPTR	;A=0 DPTR=102H   ,  C:@0+102H Address whatever the data is there
		;it's moved into D.OP of A

MOV 32H,A


END



