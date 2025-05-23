#include <stdint.h>
#include <at32f421_conf.h>
#include <bitband.h>
void adelay(uint32_t);
void mcu_init(void);
int main(void)
{
    mcu_init();
    while(1){
        adelay(0xfffff0);
#if 0
        //BITBAND(GPIOA->odt)->bit[8]=1;
        GPIOA->scr=GPIO_PINS_8;
        adelay(0xffff);
        BITBAND(GPIOA->odt)->bit[8]=0;
#else
        GPIOA->scr=GPIO_PINS_8;
        adelay(0xfffff0);
        GPIOA->scr=GPIO_PINS_8<<16;
#endif
    }
}
void _init(void)
{

}

