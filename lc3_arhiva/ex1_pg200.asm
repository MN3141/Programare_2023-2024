.ORIG x3000
L1 LEA R1, L1
AND R2, R2, x0
ADD R2, R2, x2
LD R3, P1
JSR L2
BRnzp NEXT
L2 LDR R0, R1, x16
ST R7, SAVER7
OUT ; aceasta intrerupere modifica valoarea lui R7,de aceea trb sa ne folosim de SAVER7!
LD R7, SAVER7
ADD R3,R3,-1
BRz GLUE
ADD R1, R1,R2
BRnzp L2
GLUE RET
NEXT LEA R1, L1
ADD R1, R1, #1
LD R3, P1
ADD R3, R3, #-7
JSR L2
HALT
P1 .FILL x12
.STRINGZ "SLaArMbUaLtToIrAiNFIe!rriCcaizt!ea!"
SAVER7 .BLKW 1
.END