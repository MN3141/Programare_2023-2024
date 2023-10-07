	.ORIG #3050	
	and R0,R0,#0
	and R1,R1,#0
	and R2,R2,#0	;R2 clona a lui R0
	add R0,R0,#6
	add R2,R2,#6
Inmult	add R1,R1,R2
	add R0,R0,#-1
	BRp Inmult
	halt
.end