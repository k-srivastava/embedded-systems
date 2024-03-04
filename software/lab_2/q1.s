    AREA    RESET, DATA, READONLY
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
    LDR r1, [r0]

    LDR r2, =DST
    STR r1, [r2]

SRC DCD 0x0

    AREA mydata, DATA, READWRITE
DST DCD 0x10

    END
