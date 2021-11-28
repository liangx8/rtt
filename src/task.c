
#include "task.h"

stack_t * task_stack_init(void *func,void *arguments,stack_t *top)
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
void rtt_init(void)
{
    portSCB->SHP_PRI_11=0xff;
    portSCB->SHP_PRI_14=0xff;
}