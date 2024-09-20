



CSEG AT 0

MOV PSW,#08H	;	BANK1 WILL SELECT	;MOV(1)+PSW(0D0H(1))+08H(1)
MOV R0,#45H					;MOV & R0(1)+45H(1)


MOV PSW,#10H
MOV R0,#45H


END


/*


	HN					LN

PSW.7	PSW.6	PSW.5	PSW.4	PSW.3	PSW.2	PSW.1	PSW.0
0	0	0	0	1	0	0	0	
D7	D6	D5	D4	D3	D2	D1	D0			- BANK1
8	4	2	1	8	4	2	1
								
		0		1X8+0X4+0X2+0X1
		0		8				H	*/	


/*	HN					LN

PSW.7	PSW.6	PSW.5	PSW.4	PSW.3	PSW.2	PSW.1	PSW.0
0	0	0	1	0	0	0	0	
D7	D6	D5	D4	D3	D2	D1	D0			- BANK2
8	4	2	1	8	4	2	1
								
		0+0+0+1X1		0
		
		   1			0			H	/0X10	*/
