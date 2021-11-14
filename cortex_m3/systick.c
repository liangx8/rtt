#include <stm32f1xx.h>
#include "bitband.h"
void SysTick_handler(void)
{
  BITBAND(GPIOB->ODR)->bit[12] ++;
}

