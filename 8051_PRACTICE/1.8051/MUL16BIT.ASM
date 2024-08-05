
;Multiplication of 2, 16-bit numbers

NUM1 EQU  0XFFFF
NUM2 EQU  0XFFFF


CSEG AT 0

;NUM1=0XFFFF, NUM1>>8= 0XFFFF>>8 =0X00FF;If we assign 16 bit number to 8 bit register
;Lower byte will assign & higher byte will ignore
MOV R0,#NUM1>>8	;HB of NUM1
MOV R1,#NUM1	;LB of NUM1

MOV R2,#NUM2>>8	;HB of NUM2
MOV R3,#NUM2	;LB of NUM2


MOV A,R1	;LB of NUM1
MOV B,R3	;LB of NUM2

MUL AB		; Multiply 2 lOWER bYTES AS STEP1

MOV 43H,A	; Will get 16 bit Result. LB of Result is in A moving into 43H
MOV 42H,B	; HB of Result is in B moving into 42H

MOV A,R0	;HB of NUM1
MOV B,R3	;LB of NUM2

MUL AB		; Multiply HB & LB AS STEP2

ADD A,42H	; ADD previous result with Present result
MOV 42H,A	; Again store into same address

MOV A,B		; Another 8 bit result move into A	
ADDC A,#00H	; Add carry b'coz of previous addition with another 8 bit result which is in A 
MOV 41H,A	; Store Updated Result in 41H

MOV A,R1	;LB of NUM1
MOV B,R2	;HB of NUM2

MUL AB		; Multiply LB & HB AS STEP3

ADD A,42H	; ADD previous result with present result
MOV 42H,A	; updated Result move into address

MOV A,B		; Another 8 bit result move into A
ADDC A,41H	; Add carry b'coz of previous addition with another 8 bit result which is in A  
MOV 41H,A	; Store Result into address

MOV 20H.0,C	; B'coz of previous addition, carry generated that is moved into 20H


MOV A,R0	;HB of NUM1
MOV B,R2	;HB of NUM2

MUL AB		; Multiply LB & HB AS STEP4

ADD A,41H	; ADD previous result which is in 41h with present result
MOV 41H,A	; updated Result move into same address

MOV A,B		; Another 8 bit result move into A
ADDC A,20H	; Add carry b'coz of previous addition with another 8 bit result which is in A with previous carry
MOV 40H,A	; updated Result move into address

END




