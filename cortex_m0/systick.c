#include <stm32f0xx.h>
#include "macro_io.h"

void SysTick_handler(void)
{
    if (STATUS(LED2_PORT, LED2_MASK)) {
        LED2_OFF;
    } else {
        LED2_ON; 
    }
}
