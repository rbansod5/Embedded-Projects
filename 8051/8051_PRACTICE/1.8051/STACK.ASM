

CSEG AT 0

/*STACK OPERATIONS ARE
PUSH ADDR;TO INSERT THE DATA INTO STACK
POP ADDR ; TO RETRIEVE THE DATA FROM STACK INTO REQUIRED MEMORY LOCATION*/

mov 30h,#45h; 45h is a data is moving into 30h address
mov 40h,#12h
;MOV 08H,30H
PUSH 30H;sp=07h Whatever the value in 30h iram address it's moved into stack
	;In stack n number of addresses.So, in which address it is storing
		;By def. SP=07h . Because of PUSH operation SP+1 = 07+1=08.  @08h address, value is 
		;stored
;MOV @SP+1,30H
/*D.OP is representing stack area
s.op representing RAM area
S.OP address will not change*/
		

PUSH 40H;sp=08h
;MOV @SP+1,40H
;sp=09h<--- whatever the value in 40h it's moved
POP 30H  ;  SP value acts as Stack address
	 ; In that stack address whatever the data it's moved into 40h address
	  ;SP<==SP-1=08h 
POP 40H
END

