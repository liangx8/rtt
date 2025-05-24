
#include "conf.h"
#include "../rtt/task.h"
#define STACK_MIN_SIZE 16
#define STACK_SIZE     24
void task2(uint32_t) __attribute__ ((naked));
void task2(uint32_t x)
{
    while(1){
        for(uint32_t ix=0;ix<20000;ix++){
        }
        if(GPIOA->idt & GPIO_PINS_10){
            GPIOA->clr=GPIO_PINS_10;
        } else {
            GPIOA->scr=GPIO_PINS_10;
        }
    }
}
void task1(uint32_t) __attribute__ ((naked));
void task1(uint32_t x)
{
    while(1){
        for(uint32_t ix=0;ix<20000;ix++){
        }
        if(GPIOA->idt & GPIO_PINS_11){
            GPIOA->clr=GPIO_PINS_11;
        } else {
            GPIOA->scr=GPIO_PINS_11;
        }
    }
}
/*
以下代码作为一个模板
*/
// task的配置设定
stack_t stack1[STACK_SIZE];
stack_t stack2[STACK_SIZE];
extern struct rttTCB tcb_list[];
extern struct rttTCB *ptr_tcb;
stack_t * create_stack_frame(const void *func,void *arguments,stack_t *top);
void tasks_init(void)
{

    tcb_list[0].top=create_stack_frame(task1,(void *)10,&stack1[STACK_SIZE]);
    tcb_list[0].counter=0;
    ptr_tcb=&tcb_list[0];
    __set_PSP((uint32_t)(ptr_tcb->top));
    tcb_list[1].top=create_stack_frame(task2,(void *)10,&stack2[STACK_SIZE]);
    tcb_list[1].counter=0;
    rtt_init();
}