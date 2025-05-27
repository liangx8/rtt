.syntax unified
@.cpu cortex-m4
@.fpu softvfp
@.thumb
.global PendSV_Handler,SVC_Handler

.equ GPIOA, 0x48000000

.func   PendSV_Handler
.thumb_func
.type PendSV_Handler, %function
.align
PendSV_Handler:
.if 0
@判断是使用那个堆栈寄存器
    cpsid i
    mov r0,lr
    add r1,r0,#7
    bne 1f
    @lr值是0xfffffff9,中断前使用ＭＳＰ,环境保存只需直接push
    push {r4-r11}
    @回复ＰＳＰ中的堆栈
    mrs r0,psp
    ldmia r0!,{r4-r11}
    msr psp,r0
    cpsie i
    @return 后使用ＰＳＰ
    ldr r0,=0xfffffffd
    bx r0

1:
    add r0,#3
    bne 2f
    @ lr值是0xfffffffd,中断前使用ＰＳＰ,环境保存需要读出ＰＳＰ中的值
    mrs r0,psp
    stmdb r0!,{r4-r11}
    @ r0保存到当前的context中
    bl switch_and_save_context
    msr psp,r0
    pop {r4-r11}
    cpsie i
    @返回ＭＳＰ的环境
    ldr r0,=0xfffffff9
    bx r0
2:
    cpsie i
    bx lr
.endif
    mrs r0,psp
    stmdb r0!,{r4-r11}
    @ r0保存到当前的context中
    bl switch_and_save_context
    msr psp,r0
    pop {r4-r11}
    cpsie i
    @返回ＭＳＰ的环境
    ldr r0,=0xfffffff9
    bx r0
.align
.size PendSV_Handler, . - PendSV_Handler
.endfunc


.func   SVC_Handler
.thumb_func
.type SVC_Handler, %function
.align
SVC_Handler:
    push {r4-r11}
    @回复ＰＳＰ中的堆栈
    mrs r0,psp
    ldmia r0!,{r4-r11}
    msr psp,r0
    cpsie i
    @return 后使用ＰＳＰ
    ldr r0,=0xfffffffd
    bx r0
.align
.size SVC_Handler, . - SVC_Handler
.endfunc
