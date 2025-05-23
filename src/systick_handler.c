#include "at32f421_conf.h"
void SysTick_Handler(void)
{
    if(GPIOA->idt & GPIO_PINS_8){
        GPIOA->scr=GPIO_PINS_8 << 16;
    }else {
        GPIOA->scr=GPIO_PINS_8;
    }

}