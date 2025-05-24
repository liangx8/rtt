/*
使用systick中断切换任务时，需要区分是从主
*/
#include <stdint.h>
#include "task.h"
void PendSV_Handler(void) __attribute__((naked));
void PendSV_Handler(void)
{
    
    __asm volatile ("cpsid i" ::: "memory");
// 高与cortex-m3
#if defined(__thumb2__)
    // data: psp => r0, 指定r0作为堆栈，因为在中断中。缺省使用MSP，
    __asm volatile ("mrs r0, psp" ::: );
    __asm volatile(
        "stmdb   r0!,{r4-r11}\n"
        "bl switch_and_save_context\n"
        // data: r0 => psp
        "msr     psp,r0\n"
        // 恢复 SVCall_handler中保存的环境(msp)
        "pop     {r4-r11}\n"
    );
#elif defined(__thumb__)
// cortex-m0
    // data: psp => r0
    __asm volatile ("mrs r0, psp" ::: );
    __asm volatile(
        "sub    r0,#16\n"
        "stmia  r0!,{r4-r7}\n"
        "mov    r4,r8\n"
        "mov    r5,r9\n"
        "mov    r6,r10\n"
        "mov    r7,r11\n"
        "sub    r0,#32\n"
        "msr    psp,r0\n"
        "stmia  r0!,{r4-r7}\n"
        "pop    {r4-r7}\n"
        "mov  r8,r4\n"
        "mov  r9,r5\n"
        "mov  r10,r6\n"
        "mov  r11,r7\n"
        "pop    {r4-r7}"

    );
#endif
    // return to thread mode, use MSP after return
    __asm volatile ("cpsie i\n"
        "ldr    r0,=0xfffffff9\n"
        "bx     r0\n"
    );
}

void SVC_Handler(void) __attribute__((naked));
void SVC_Handler(void) {
    __asm volatile ("cpsid i" ::: "memory");
    //在中断中，因此在使用msp
    __asm volatile ("mrs r0, psp" ::: );
#ifdef __thumb2__
    __asm volatile (
        "push       {r4-r11}\n"
        "ldmia      r0!,{r4-r11}\n"
    );
#elif  defined(__thumb__) 
    __asm volatile ( 
        "push {r4-r7}\n"
        "mov  r4,r8\n"
        "mov  r5,r9\n"
        "mov  r6,r10\n"
        "mov  r7,r11\n"
        "push {r4-r7}\n"
        "ldmia r0!,{r4-r7}\n"
        "mov  r8,r4\n"
        "mov  r9,r5\n"
        "mov  r10,r6\n"
        "mov  r11,r7\n"
        "ldmia r0!,{r4-r7}\n"
    );
#endif
    // return to thread mode, use PSP after return
    __asm volatile (
        "msr   psp,r0\n"
        "cpsie i\n"
        "ldr        r0,=0xfffffffd\n"
        "bx r0\n"
    );
}
void test_pin(void);
void SysTick_Handler(void)
{
    uint32_t val;
    asm("mov %0,lr":"=r"(val));
    
    // 主线程使用msp,lr中的值为0xfffffff9
    // 主线程使用psp,lr中的值为0xfffffffd
    if(val == 0xfffffff9){
        //使用msp
        test_pin();
        SVC_Handler();
        return;
    }
    if(val== 0xfffffffd){
        // tyield();
        PendSV_Handler();
        return;
    }
}
