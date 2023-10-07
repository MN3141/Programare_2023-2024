;	A^B=(A & ~B) | (~A & B)
	.ORIG x3000
	LD R1,VAL1 ;incarcare valori
	LD R2,VAL2
;-------------------------------
	NOT R2,R2
	AND R4,R1,R2 ;R4=(R1 & ~R2)
;-------------------------------
	NOT R2,R2
	NOT R1,R1
	AND R5,R1,R2 ;R5=(~R1 & R2)
;-------------------------------
	NOT R4,R4
	NOT R5,R5
	AND R3,R4,R5
	NOT R3,R3 ;R3=R4 | R5
;-------------------------------
	HALT
VAL1 .FILL x0001 ;VAL1 si VAL2 sunt doar valori de proba
VAL2 .FILL x0000
	.END
	