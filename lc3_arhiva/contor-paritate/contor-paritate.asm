;|----------------------|
;|R0-Input/Output	|
;|R1-NUMBER		|
;|R2 used for masking	|
;|R3 used for verifying |
;|R4 counter		|
;|R5 used for loop	|
;|----------------------|
;INIT
	.orig x3000
	ld r1,NUM
	and r2,r2,#0
	add r2,r2,#1
	and r4,r4,#0
	ld r5,NUM2
;--------------------------------------------
;MAIN
LOOP and r3,r1,r2
	 brz NULL
	 add r4,r4,#1;the counter goes up
NULL add r2,r2,r2;the number is doubled
	 add r5,r5,#-1
	brp LOOP
	lea r0,TEXT
	puts
	ld r2,CHAR
	add r0,r2,r4
	out ;trap x21
	halt
;--------------------------------------------
;LABELS
	NUM .fill #3
	NUM2 .fill #16
	CHAR .fill #48
	TEXT .stringz "THE NUMBER OF 1s is:"
;--------------------------------------------
	.end