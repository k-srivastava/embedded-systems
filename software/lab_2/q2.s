    AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
	LDR r0, =SRC
	LDR r1, =DST

	MOV r2, #-1
	MOV r9, #0
	MOV r10, #-1

FILL_LOOP
	ADD r10, r10, #1
	STR r9, [r0, r10]

	ADD r9, r9, #1

	CMP r10, #9
		BLS FILL_LOOP
	BLS LOOP

LOOP
	ADD r2, r2, #1

	LDR r3, [r0, r2]
	STR r3, [r1, r2]

	CMP r2, #9
		BLS LOOP
	BLS STOP

STOP
	B STOP

	AREA mydata, DATA, READWRITE
SRC DCD 0x0
DST DCD 0xFF
	END
