#include <stdint.h>
#include <at32f421_conf.h>
#include <bitband.h>
void adelay(uint32_t);
void mcu_init(void);
int main(void)
{
    mcu_init();
    while (1)
    {
        if (TMR6->ists & (1 << TMR_ISTS_OVFIF_pos))
        {
            TMR6->ists = 0;
            if (GPIOA->idt & GPIO_PINS_9)
            {
                GPIOA->scr = GPIO_PINS_9 << 16;
            }
            else
            {
                GPIOA->scr = GPIO_PINS_9;
            }
        }
    }
}
void _init(void)
{
}
