


;MOVE DATA FROM ACCUMULATOR TO ADDRESS OF 30H USING R0 REGISTER(INDIRECT)
/*CSEG AT 0
MOV A,#0X34	;2BYTES
MOV R0,#30H	;2BYTES
MOV @R0,A	;1BYTE;whatever the data in R0 that data becomes as address 
		; when we are using @symbol

END*/

;MOVE THE DATA FROM IRAM 30H TO XRAM of 1234H address

MOV 30H,#67H
MOV A,30H
MOV DPTR,#1234H;here dptr is representing xram address
MOVX @DPTR,A;Whatever the value in A it's moved into XRAM:@1234h location


END

/*
p has address with another variable
eg:p=1000
*p it points to the data which is in 1000*/
