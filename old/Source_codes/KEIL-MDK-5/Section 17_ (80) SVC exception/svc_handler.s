 ;This code only extracts MSP Or PSP value into RO BY testing LR register */	
	EXPORT SVC_Handler 
	AREA SVC_Area, CODE, READONLY
	IMPORT SVC_Handler_C ; This is the SVC exception handler 
SVC_Handler
    TST LR,#4            ; Check the LR bit position 2 , to test which Stack pointer was in use 
	                     ;during stacking operation 
	ITE EQ
	MRSEQ R0,MSP         ; if LR bit2 is 0, then copy MSP to RO
	MRSNE R0,PSP         ; if LR bit2 is 1 , then copy PSP TO R0

    B      SVC_Handler_C         ; Call C function for further processing 
    END
    