	.data
L0 : 	.WORD 0
L1 : 	.WORD 20
L2 : 	.WORD 20
	.text
	ADDI R1 R0 #30
	WRITE R1 0
	STORE R1 L0
	HALT
