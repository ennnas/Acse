	.data
L0 : 	.WORD 0
L1 : 	.WORD 5
L2 : 	.WORD 4
	.text
	ADDI R1 R0 #1
	WRITE R1 0
	ADDI R2 R1 #0
	STORE R1 L0
	BT L3
L5 : 	LOAD R3 L1
	ADD R1 R0 R3
	STORE R1 L0
	STORE R3 L1
	BT L4
L6 : 	LOAD R4 L2
	ADD R1 R0 R4
	STORE R1 L0
	STORE R4 L2
	BT L4
L7 : 	LOAD R3 L1
	LOAD R4 L2
	ADD R5 R3 R4
	STORE R4 L2
	STORE R3 L1
	ADD R1 R0 R5
	STORE R1 L0
	BT L4
L3 : 	SUBI R5 R2 #1
	BEQ L5
	SUBI R5 R2 #2
	BEQ L6
	BT L7
L4 : 	LOAD R1 L0
	WRITE R1 0
	STORE R1 L0
	HALT
