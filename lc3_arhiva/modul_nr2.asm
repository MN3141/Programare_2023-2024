;Se dau x si y(aflate la adresa 0x3120,respectiv 0x3121).Se cere:
;-sa determinati valoarea absoluta pt x si y in 0x3112,0x3113;
;-sa calculati diferenta lor in 0x3114
;-sa verificati care numar are valoarea absoluta mai mare
;	si sa semnalati in 0x3115 astfel:
;		1-daca modulul lui x e mai mare
;		2- daca modulul lui y e mai mare
;		0- daca sunt egale
	.ORIG x3000
	AND R4,R4,#0 ; ultimul subpunct
	LDI R1,NR1 ;folosim LDI pt a sari la adresa lui x
	BRzp 0x0002
	NOT R1,R1
	ADD R1,R1,#1 ;R1<- -R1,pt R1<0
	LDI R2,NR2
	BRzp x0002
	NOT R2,R2
	ADD R2,R2,#1
	STI R1,modNR1 ;stocam modul de x
	STI R2,modNR2
	NOT R3,R2
	ADD R3,R3,#1
	ADD R3,R1,R3
	STI R3,DIF
	BRp CAZ1
	BRn CAZ2
STOCARE STI R4,COMPARMOD ;daca nu sare la CAZ1 sau CAZ2 inseamna egalitate implicit
	HALT
NR1	.FILL 0x3120 ;din cate am observat doar cifrele si literele 
NR2	.FILL 0x3121 ;sunt acceptate pt etichete
modNR1	.FILL 0x3112
modNR2	.FILL 0x3113
DIF	.FILL 0x3114
CAZ1 ADD R4,R4,#1
	BRnzp STOCARE
CAZ2 ADD R4,R4,#2
	BRnzp STOCARE
COMPARMOD .FILL 0x3115
	.END
