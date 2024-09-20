SET RVCT40INC=C:\Keil\ARM\RV31\INC
SET RVCT40LIB=C:\Keil\ARM\RV31\LIB
SET CPU_TYPE=LPC1768
SET CPU_VENDOR=NXP (founded by Philips)
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00000000
"C:\Keil\ARM\BIN40\ArmCC" --Via ".\hex\iotest.__i"
"C:\Keil\ARM\BIN40\ArmAsm" --Via ".\hex\startup_lpc17xx._ia"
"C:\Keil\ARM\BIN40\ArmCC" --Via ".\hex\system_lpc17xx.__i"
"C:\Keil\ARM\BIN40\ArmLink" --Via ".\HEX\LED_TOGGLE.lnp"
C:\Keil\ARM\BIN40\fromelf.exe ".\HEX\LED_TOGGLE.axf" --i32combined --output ".\HEX\LED_TOGGLE.hex"
fromelf --bin "LED_TOGGLE.axf" --output "LED_TOGGLE.bin"
