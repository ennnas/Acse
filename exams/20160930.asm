	.data
L0 : 	.WORD 0
L1 : 	.WORD 0
L2 : 	.WORD 0
	.text
	ADDI R1 R0 #7
	ADDI R2 R0 #2
	SUB R3 R1 R2
	STORE R2 L1
	STORE R1 L0
	SGT R3 0
	ANDB R3 R3 R3
	BEQ L4
	LOAD R1 L0
	ADD R3 R0 R1
	STORE R3 L2
	STORE R1 L0
	BT L3
L4 : 	LOAD R2 L1
	ADD R3 R0 R2
	STORE R3 L2
	STORE R2 L1
L3 : 	LOAD R3 L2
	WRITE R3 0
	STORE R3 L2
	ADDI R2 R0 #0
	BEQ L6
	ADDI R3 R0 #2
	STORE R3 L2
	BT L5
L6 : 	ADDI R3 R0 #3
	STORE R3 L2
L5 : 	LOAD R3 L2
	WRITE R3 0
	STORE R3 L2
	HALT