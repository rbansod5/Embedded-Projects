
CSEG AT 0; It is also Assembler directive which is used to point the ROM address to store our program
	 ; This statement means our code will store from 0th memory loaction
	 ; It is an absolute assembler directive 

MOV A,#45H;2bytes


MOV R0,#34H;MOV&R0(1)+34H(1)=2BYTES;34H is a data moved into R0

END  ; It is an Assembler directive. Ends the application/Program
	;After END if we wrote any instructions, those are not to be considered
