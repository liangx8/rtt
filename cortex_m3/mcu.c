/*
 * 实验板上的蓝色LED接B12 串到3.3v，高电平时灯灭，低电平灯亮
 */


/*
 * Output open-drain 工作方式在 PAGE 163有详细说明，
 *  0 N-MOS 激活，
 *  1 N-MOS 断开，端口即为Hi-z
 * P-MOS 永远不会激活，因此与DS18B20通信的端口应该设置这种模式
 */
#include <stm32f1xx.h>
/* 
 * PB3,PB4,PA15 上电是给JTAG功能用的，要作为IO使用，必须要禁止JTAG功能
 * partial remap TIM3 
 */
#define AFIO_MAPR_VALUE AFIO_MAPR_SWJ_CFG_1

#define GPIOB_CRL_VALUE GPIO_CRL_MODE3_0 | GPIO_CRL_MODE4_0 | GPIO_CRL_MODE5_0 | GPIO_CRL_MODE6_0
/*
 * B12 push pull out
 */
#define GPIOB_CRH_VALUE GPIO_CRH_MODE12_0
//#define GPIOC_CRL_VALUE 0
//#define GPIOC_CRH_VALUE 0

static inline void _rcc_init(void)
{
    RCC->AHBENR = 0;
    RCC->APB2ENR = RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPDEN | RCC_APB2ENR_IOPEEN | RCC_APB2ENR_AFIOEN;
    SysTick_Config(0xffffff);

}

void io_init(void)
{
    _rcc_init();
#ifdef GPIOA_CRL_VALUE
    GPIOA->CRL = GPIOA_CRL_VALUE;
#endif
#ifdef GPIOA_CRH_VALUE
    GPIOA->CRH = GPIOA_CRH_VALUE;
#endif

#ifdef GPIOA_ODR_VALUE
    GPIOA->ODR=GPIOA_ODR_VALUE;
#endif

#ifdef GPIOB_CRL_VALUE
    GPIOB->CRL = GPIOB_CRL_VALUE;
#endif
#ifdef GPIOB_CRH_VALUE
    GPIOB->CRH = GPIOB_CRH_VALUE;
#endif

#ifdef GPIOB_ODR_VALUE
    GPIOB->ODR=GPIOB_ODR_VALUE;
#endif

#ifdef GPIOC_CRL_VALUE
    GPIOC->CRL = GPIOC_CRL_VALUE;
#endif
#ifdef GPIOC_CRH_VALUE
    GPIOC->CRH = GPIOC_CRH_VALUE;
#endif

#ifdef GPIOD_CRL_VALUE
    GPIOD->CRL = GPIOD_CRL_VALUE;
#endif
#ifdef GPIOD_CRH_VALUE
    GPIOD->CRH = GPIOD_CRH_VALUE;
#endif

#ifdef AFIO_MAPR_VALUE
    AFIO->MAPR=AFIO_MAPR_VALUE ;
#endif
}
