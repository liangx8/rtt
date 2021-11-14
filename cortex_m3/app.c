/*
1 定义堆栈 stack1
2 用task_stack_init初始化堆栈
3 __set_PSP 设定PSP的值为stack1 被初始化后的值
4 rtt_init() 设定SVCall 和 PendSV的中断优先级为最低

注意：
分进程的堆栈要控制好。溢出是程序崩溃的主要原因
释放cpu控制权
主进程用myield
分进程用tyield
*/

#include <stm32f1xx.h>
#include "task.h"
#include "ledpin.h"

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
    __set_PSP((uint32_t)p);
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
