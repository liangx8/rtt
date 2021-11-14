.syntax unified
.text

/*
.func PendSV_handler1
.thumb_func
.type PendSV_handler1, %function
.align
PendSV_handler1:
    cpsid   i
    mrs     r0,psp
    stmdb   r0!,{r4-r11}
    msr     psp,r0
    pop     {r4-r11}
    ldr     lr,=0xfffffff9
    cpsie   i
    bx      lr
    .align
    .size PendSV_handler1, . - PendSV_handler1
    .endfunc
.func SVCall_handler
.thumb_func
.type SVCall_handler, %function
.align
SVCall_handler:
    cpsid   i
    push    {r4-r11}
    mrs     r0,psp
    ldmia   r0!,{r4-r11}
    msr     psp,r0

    ldr     lr,=0xfffffffd
    cpsie   i
    bx      lr
    .size SVCall_handler, .-SVCall_handler
    .endfunc
    .align


*/
