.syntax unified
.text
.global PendSV_handler,SVCall_handler

.func PendSV_handler
.thumb_func
.type PendSV_handler, %function
.align
PendSV_handler:
    cpsid   i
    mrs     r0,psp
    stmdb   r0!,{r4-r11}
    msr     psp,r0
    pop     {r4-r11}
    ldr     lr,=0xfffffff9
    cpsie   i
    bx      lr
    .align
    .size PendSV_handler, . - PendSV_handler
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
    /* 返回thread mode,从PSP出栈，返回后使用PSP */
    ldr     lr,=0xfffffffd
    cpsie   i
    bx      lr
    .size SVCall_handler, .-SVCall_handler
    .endfunc
    .align


