    .syntax unified
    .text
    .global adelay



    .func   adelay
    .thumb_func
    .type adelay, %function
    .align
adelay:
1:
    subs    r0,#1
    bcs     1b
    bx      lr
   .align
    .size adelay, . - adelay
    .endfunc
