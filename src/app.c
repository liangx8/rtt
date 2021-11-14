#include <stm32f1xx.h>
#include "task.h"
#include "ledpin.h"
#include "config.h"

stack_t stack1[16];
void task1(uint32_t) __attribute__ ((naked));
void task1(uint32_t x) 
{
    while (1){
        int i;
        for(i=x;i !=0;i--){
            tyield();
        }
        LED_PORT->BSRR = LED1;
        for(i=x;i !=0;i--){
            tyield();
        }
        LED_PORT->BRR = LED1;
    }
}

void app_loop(void)
{
    stack_t *p = task_stack_init(task1, (void *)0x16000, &stack1[16]);
    __asm volatile(
        "msr    psp,%0" ::"r"(p));
    rtt_init();
    while (1)
    {
        int x;
        for (x = 0x60000; x != 0; x--)
        {
            myield();
        }
        LED_PORT->BRR = LED2;
        for (x = 0x60000; x != 0; x--)
        {
            myield();
        }
        LED_PORT->BSRR = LED2;
    }
}
