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
    MOV r0, #10
    ADD r0, r0, #3
    ADD r0, r0, #7

    END
