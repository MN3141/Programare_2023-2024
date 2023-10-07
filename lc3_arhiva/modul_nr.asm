	.ORIG x3000
	LD R1,NR
	BRzp x0002
	NOT R1,R1
	ADD R1,R1,#1
	HALT
NR 	.FILL #-2 ; se afla la adresa 0x3005
	.END