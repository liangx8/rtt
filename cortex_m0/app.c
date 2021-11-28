#include <stm32f0xx.h>
#include "task.h"
#include "macro_io.h"

static inline uint32_t t_delay(uint32_t base,uint32_t len)
{
    while(1){
        uint32_t cur=SysTick->VAL;
        uint32_t val=(base-cur) & 0xffffff;
        if(val > len){
            return cur;
        }
        tyield();
    }
}
stack_t ta1_stack[16];
void ta1(uint32_t) __attribute__ ((naked));
void ta1(uint32_t x) 
{
    uint32_t base=SysTick->VAL;
    while(1)
    {
        base= t_delay(base,MS(10));
    }
}

void app_init(void) __attribute__ ((naked));
void app_init(void)
{
    SysTick_Config(0x1000000);
    stack_t *p=task_stack_init(ta1,(void *)MS(500),&ta1_stack[16]);
    __ASM volatile ("MSR psp, %0\n" : : "r" (p) : "memory");
    rtt_init();
    while(1){
        myield();
        T2_OFF;

    }
}
