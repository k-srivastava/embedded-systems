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
    LDR r1, =VALUE1
    LDR r2, [r1]

    LDR r3, =VALUE2
    STR r4, [r3]

    MOV r5, #0  ; sum
    MOV r6, #0  ; carry

    MOV r7, r4  ; counter

Loop
    CMP r7, #0
        BEW Final

    ADDS r5, r5, r2
    ADC r6, r6, #0

    SUBS r7, r7, #1
    BNE Loop

Final
    LDR r8, =RESULT
    STR r6, [r8]  ; store the carry
    STR r5, [r8, #4]  ; store the product

STOP
    B STOP

VALUE1 DCD 0x4
VALUE2 DCD 0x2

    AREA mydata, DATA, READWRITE
RESULT DCD 0x0
    END
