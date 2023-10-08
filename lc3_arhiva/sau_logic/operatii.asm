;INIT
;----------------
.orig x3000
AND r0,r0,#0
AND r1,r1,#0
AND r2,r2,#0
ld r1,VAL1
ld r2,VAL2
;----------------
;NAND
;----------------
lea r0,text0
TRAP x22
AND r0,r1,r2
NOT r0,r0
TRAP x21
HALT
;LABELS
;----------------
VAL1 .FILL xffff
VAL2 .FILL x0008
text0 .STRINGZ "NAND:"
text1 .STRINGZ "OR:"
text2 .STRINGZ "XOR:"

.END