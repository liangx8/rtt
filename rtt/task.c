
#include "task.h"


struct rttTCB tcb_list[TASK_NUM]; // 0x2000 0000
struct rttTCB *ptr_tcb;           // 0x2000 0008

stack_t * create_stack_frame(const void *func,void *arguments,stack_t *top)
//stack_t * create_stack_frame(const void *func,void *arguments,stack_t *top)
{
    top --;
    *top    = 0x01000000 ;  /* PSR */
    top--;
    *top    = (stack_t)func;         /* PC*/
    top--;
    //*top    = 0xffffffff ;  /* LR,因为被运行的任务不能有返回，因此LR值被忽略*/
    top -= 5;                 /* r12,r3,r2 and r1*/
    *top    = (stack_t)arguments ;   /* r0 */
    top -= 8;                 /* r11,r10,r9,r8,r7,r6,r5,r4 */
    return top;
}
stack_t *switch_and_save_context(stack_t *top)
{
    // 修改ptr_tcb的类型为rttTCB
    ptr_tcb->top=top;
    ptr_tcb++;
    if(ptr_tcb == &tcb_list[TASK_NUM]){
        ptr_tcb=&tcb_list[0];
    }
    return ptr_tcb->top;
}
void dec_tick(void)
{

    for(uint32_t ix=0;ix<TASK_NUM;ix++){
        uint32_t cnt=tcb_list[ix].counter;
        if(cnt){
            tcb_list[ix].counter=cnt-1;
        }
    }
}
void rtt_init(void)
{
    portSCB->SHP[7] =0xff; // priority of system handler SVCALL
    portSCB->SHP[10]=0xff; // priority of system handler PendingSV
    portSCB->SHP[11]=0xff; // priority of system handler SysTick
}