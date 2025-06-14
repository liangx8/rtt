#include <stdint.h>
#include <at32f421_conf.h>
#include <bitband.h>
#include "../rtt/task.h"


void adelay(uint32_t);
void mcu_init(void);
void tasks_init(void);
int main(void)
{
    mcu_init();
    tasks_init();
    __enable_irq();
    while (1)
    {
        if (TMR6->ists & (1 << TMR_ISTS_OVFIF_pos))
        {
            TMR6->ists = 0;
            if (GPIOA->idt & GPIO_PINS_9)
            {
                GPIOA->scr = (GPIO_PINS_9) << 16;
            }
            else
            {
                GPIOA->scr = (GPIO_PINS_9);
            }
        }
        myield();
    }
}
#define TEST_PIN GPIO_PINS_8
void test_pin(void)
{
    if (GPIOA->idt & TEST_PIN)
    {
        GPIOA->scr = (TEST_PIN) << 16;
    }
    else
    {
        GPIOA->scr = (TEST_PIN);
    }
}
void _init(void)
{
}
