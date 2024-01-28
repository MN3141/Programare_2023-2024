;program preluat din:https://electrobinary.blogspot.com/2020/03/8086-programs-dos-interrupts.html
	.MODEL SMALL
	.DATA
	DMSG0 DB 10,13,'SUNDAY   ','$'
	DMSG1 DB 10,13,'MONDAY   ','$'
	DMSG2 DB 10,13,'TUESDAY  ','$'
	DMSG3 DB 10,13,'WEDNESDAY','$'
	DMSG4 DB 10,13,'THURSDAY ','$'
	DMSG5 DB 10,13,'FRIDAY   ','$'
	DMSG6 DB 10,13,'SATURDAY ','$'

	.CODE
START: 	MOV AX, @DATA
	        MOV DS, AX

	        MOV AH, 2AH   	; To get System Date
	        INT 21H
	        CMP AL, 00H    	; Day is in AL
	        JNE NXT1
	        MOV DX, OFFSET DMSG0
	        CALL DISP
NXT1:	CMP AL, 01H    	; Day is in AL
	        JNE NXT2
	        MOV DX, OFFSET DMSG1
	        CALL DISP
NXT2:	CMP AL, 02H    	; Day is in AL
	        JNE NXT3
	        MOV DX, OFFSET DMSG2
	        CALL DISP
NXT3:	CMP AL, 03H    	; Day is in AL
	        JNE NXT4
	        MOV DX, OFFSET DMSG3
	        CALL DISP
NXT4:	CMP AL, 04H    	; Day is in AL
	        JNE NXT5
	        MOV DX, OFFSET DMSG4
	        CALL DISP
NXT5:	CMP AL, 05H    	; Day is in AL
	        JNE NXT6
	        MOV DX, OFFSET DMSG5
	        CALL DISP
NXT6:	CMP AL, 06H    	; Day is in AL
	        JNE TERMI
	        MOV DX, OFFSET DMSG6
	        CALL DISP

; To terminate the Program
TERMI:	MOV AH, 4CH    	; To Terminate the Program
	        INT 21H

; Display Part
DISP 	PROC
	        MOV AH, 09H    	; To Print in DOS
	        INT 21H
	        RET
DISP 	ENDP     	; End Display Procedure
	        END START      	; End of MAIN
                HLT