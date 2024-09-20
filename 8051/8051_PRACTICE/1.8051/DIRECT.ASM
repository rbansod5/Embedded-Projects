



CSEG AT 0

MOV 30H,#45H	; In 30h address 45h data moved			;MOV(1)+30H(1)+45H(1)=3BYTES

MOV 40H,#35H

MOV 40H,30H	; In 40h address whatever the data in 30h is moved; 3BYTES

MOV A,40H	; In A whatver the data 40h address is moved	;MOV A(1) + 40H (1) = 2BYTES

MOV 50H,A	; Whatever the data in accumulator is moved into 50h address;MOV A(1)+50H(1)=2BYTES

MOV 00H,#45H	; Here 00h is the address of R0, 45h is data moved into R0


MOV R0,#45H
END
