#include <stm32f1xx.h>
#include "bitband.h"
#include "ledpin.h"
void adelay(uint32_t);
void start_echo(void)
{
    int xx;
    for(xx=0;xx<10;xx++){
        BITBAND(GPIOB->ODR)->bit[12]++;
        LED_PORT->BSRR = (LED_B << 16) | LED1 | LED2 | LED3 |LED4;
        adelay(0x180000);
        LED_PORT->BSRR = LED_B | ((LED1 | LED2 | LED3 |LED4) << 16);
        adelay(0x180000);
    }

}