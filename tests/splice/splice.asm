	.data
L0 : 	.WORD 128
L1 : 	.WORD 1
L2 : 	.WORD 0
L3 : 	.WORD 0
	.text
	ADDI R1 R0 #0
	ADDI R2 R0 #31
L5 : 	BEQ L4
	SHLI R1 R1 #1
	ADDI R1 R1 #1
	SUBI R2 R2 #1
	BT L5
L4 : 	NOTB R2 R1 #0
	LOAD R3 L0
	ANDB R2 R2 R3
	STORE R3 L0
	LOAD R4 L1
	ANDB R1 R1 R4
	STORE R4 L1
	ORB R5 R2 R1
	ADD R1 R0 R5
	WRITE R1 0
	STORE R1 L2
	ADDI R1 R0 #0
	ADDI R5 R0 #2
L7 : 	BEQ L6
	SHLI R1 R1 #1
	ADDI R1 R1 #1
	SUBI R5 R5 #1
	BT L7
L6 : 	NOTB R5 R1 #0
	LOAD R3 L0
	ANDB R5 R5 R3
	STORE R3 L0
	LOAD R4 L1
	ANDB R1 R1 R4
	STORE R4 L1
	ORB R4 R5 R1
	ADD R1 R0 R4
	WRITE R1 0
	STORE R1 L3
	HALT
