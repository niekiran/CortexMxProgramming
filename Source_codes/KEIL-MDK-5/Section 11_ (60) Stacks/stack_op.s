
	AREA    STACK_OP, CODE, READONLY
    EXPORT do_stack_operations
do_stack_operations
    MOV R0,#0x11
	MOV R1,#0X22
	MOV R2,#0X33
    PUSH {R0-R2}     ; PUSH the contents of RO,R1,R2
	MRS R0,CONTROL ; Read the Contents of CONTROL register
	ORR R0,R0,#0X02 ; set the SPSEL bit to 1, to select PSP
	MSR CONTROL,R0  ; Write back to the CONTROL register 
	MRS R0,MSP
	MSR PSP,R0      ; Initialize the PSP
	POP  {R0-R2}    ; POP back 

    BX   lr           ; Return.
    END