;INIT
	.orig x3000
	and r0,r0 #0
	ld r1,NR
	ld r2,CHAR
;----------------------
;MAIN
	and r1,r1,#1
	add r0,r0,r1
	add r0,r0 r2
	out ;trap x23
	halt
;----------------------
;LABELS
	NR .FILL #7
	CHAR .FILL #48
;----------------------
	.end