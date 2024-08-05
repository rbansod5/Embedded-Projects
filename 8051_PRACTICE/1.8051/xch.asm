



CSEG AT 0


MOV 30H,#45H
MOV 40H,#12H


/*Possibilities:

XCH A,ADDR
XCH A,Rn=n=0-7
XCH A,@Ri = i=0/1*/

MOV A,30H;one of the i/p move into Accumulator for supported syntax;A<==45H

XCH A,40H;A<==12H   40H<==45H

MOV 30H,A;30H<==12H

/*	  MOVX	      
EXTERNAL   ---->  A ;MOVX A,@DPTR

   XCH
A <---> IRAM ADDRESS ; XCH A,30H
	  MOVX
EXTERNAL <======  A  ; MOVX @DPTR ,A


*/

END
