main()
{
	//superloop architecture
	while(1)
	{
	
	}

}
/*
startup code includes:
memory initilization (internal data memory (lower 128 bytes (0x00-0x7F)) filled with 0x00)
stack initilization (sp=0x07)
transfers control to main function (LJMP to main)
interrupts initilization
*/
/*
startup code infomation:
location    opcode   Mnemonic operands
            followed 
            by 
            operands
--------------------------------------------
C:0x0000    020003   LJMP     C:0003
C:0x0003    787F     MOV      R0,#0x7F
C:0x0005    E4       CLR      A
C:0x0006    F6       MOV      @R0,A
C:0x0007    D8FD     DJNZ     R0,C:0006
C:0x0009    758107   MOV      SP(0x81),#0x07
C:0x000C    02000F   LJMP     main(C:000F)
C:0x000F    80FE     SJMP     main(C:000F)
---------------------------------------------
*/
