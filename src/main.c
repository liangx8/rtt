#include <stdint.h>
#include <at32f421_conf.h>
#include <bitband.h>
#include "../rtt/task.h"


void adelay(uint32_t);
void mcu_init(void);
void tasks_init(void);
void comm(uint32_t full,uint32_t idx);
uint32_t pwm_duty(uint32_t duty);
void ana_comm(void);
void ana_transfer(uint32_t dgr);
#define MIN_DUTY 2000
int main(void)
{
    mcu_init();
    tasks_init();
    __enable_irq();
    ana_comm();
    uint32_t dgr=0;
    while (1)
    {
        if (TMR6->ists & (1 << TMR_ISTS_OVFIF_pos)){
            TMR6->ists = 0;
            if(dgr==360){
                dgr=0;
            } else {
                dgr++;
            }
            ana_transfer(dgr);
            if(GPIOA->idt & GPIO_PINS_11){
                GPIOA->scr=GPIO_PINS_11 << 16;
            }else{
                GPIOA->scr=GPIO_PINS_11;
            }
        }
        myield();
    }
}
void _init(void)
{
}
void SysTick_Handler(void)
{
}