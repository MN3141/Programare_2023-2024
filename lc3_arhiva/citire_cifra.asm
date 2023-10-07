	.ORIG x3000
	TRAP x20	
	ADD R1,R0,#0
	ADD R1,R1,#-16
	ADD R1,R1,#-16
	ADD R1,R1,#-16 ;citire cifra
;----------------------------------
	AND R2,R2,#0
	ADD R2,R2,#1
	ADD R1,R1,#-1
	BRp xFFFD	
	HALT
	.END