	.data
L0 : 	.WORD 0
L1 : 	.WORD 0
L2 : 	.WORD 0
L3 : 	.SPACE 16
	.text
	MOVA R1 L3
	ADDI R2 R0 #1
	ADD (R1) R0 R2
	MOVA R1 L3
	ADDI R1 R1 #1
	ADDI R2 R0 #4
	ADD (R1) R0 R2
	MOVA R1 L3
	ADDI R1 R1 #2
	ADDI R2 R0 #5
	ADD (R1) R0 R2
	MOVA R1 L3
	ADDI R1 R1 #3
	ADDI R2 R0 #6
	ADD (R1) R0 R2
	ADDI R1 R0 #0
	STORE R1 L2
	ADDI R2 R0 #2
L5 : 	ANDB R2 R2 R2
	BLT L4
	MOVA R3 L3
	ADD R3 R3 R2
	ADD R4 R0 (R3)
	ADDI R2 R2 #1
	MOVA R3 L3
	ADD R3 R3 R2
	ADD R5 R0 (R3)
	SUBI R2 R2 #2
	ADDI R3 R4 #0
	ADDI R4 R5 #0
	MULI R5 R4 #2
	STORE R4 L1
	ADD R6 R3 R5
	STORE R3 L0
	ADD R1 R1 R6
	STORE R1 L2
	BT L5
L4 : 	LOAD R1 L2
	WRITE R1 0
	ADDI R1 R0 #0
	STORE R1 L2
	ADDI R2 R0 #2
L7 : 	ANDB R2 R2 R2
	BLT L6
	MOVA R6 L3
	ADD R6 R6 R2
	ADD R5 R0 (R6)
	ADDI R2 R2 #1
	MOVA R6 L3
	ADD R6 R6 R2
	ADD R7 R0 (R6)
	SUBI R2 R2 #2
	ADDI R3 R5 #0
	STORE R3 L0
	ADDI R4 R7 #0
	STORE R4 L1
	ADDI R1 R1 #5
	STORE R1 L2
	BT L7
L6 : 	LOAD R1 L2
	WRITE R1 0
	STORE R1 L2
	HALT
