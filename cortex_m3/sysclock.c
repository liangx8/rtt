#include <stm32f1xx.h>
#include "bitband.h"

void RCC_DeInit(void)
{
    NVIC->ICER[0] =0xffffffff;
    NVIC->ICER[1] =0xffffffff;
    NVIC->ICER[2] =0xffffffff;
    RCC->APB2RSTR = 0x00000000;  //外设复位
    RCC->APB1RSTR = 0x00000000;
    RCC->AHBENR   = 0x00000014;  //flash时钟,闪存时钟使能.DMA时钟关闭
    RCC->APB2ENR  = 0x00000000;  //外设时钟关闭.
    RCC->APB1ENR  = 0x00000000;
    RCC->CR      |= 0x00000001;  //使能内部高速时钟HSION
    RCC->CFGR    &= 0xF8FF0000;  //复位SW[1:0],HPRE[3:0],PPRE1[2:0],PPRE2[2:0],ADCPRE[1:0],MCO[2:0]
    RCC->CR      &= 0xFEF6FFFF;  //复位HSEON,CSSON,PLLON
    RCC->CR      &= 0xFFFBFFFF;  //复位HSEBYP
    RCC->CFGR    &= 0xFF80FFFF;  //复位PLLSRC, PLLXTPRE, PLLMUL[3:0] and USBPRE
    RCC->CIR      = 0x00000000;  //关闭所有中断

}
#if CPUCLK==72000000
#define RCC_CFGR_VAL1 RCC_CFGR_PLLMULL9 | RCC_CFGR_PPRE1_DIV1 | RCC_CFGR_PLLSRC
void sysclock(void)
{
    uint32_t temp;
    RCC_DeInit();
    RCC->CFGR = RCC_CFGR_VAL1;
    BITBAND(RCC->CR)->bit[RCC_CR_HSEON_Pos]=1;
    while((RCC->CR & RCC_CR_HSERDY)==0);
    FLASH->ACR=0x12;//FLASH 2个延时周期
    BITBAND(RCC->CR)->bit[RCC_CR_PLLON_Pos]=1;
    while((RCC->CR & RCC_CR_PLLRDY)==0);
    RCC->CFGR = RCC_CFGR_VAL1 | RCC_CFGR_SW_PLL;
    temp=0;
    while(temp != RCC_CFGR_SW_PLL){
        temp=(RCC->CFGR >> RCC_CFGR_SWS_Pos) & 0x3;
    }
}
#else
void sysclock(void)
{
    RCC_DeInit();
    BITBAND(RCC->CR)->bit[RCC_CR_HSION_Pos]=1;

    while((RCC->CR & RCC_CR_HSIRDY) == 0); //等待内部时钟就绪
    //0-24M 等待0;24-48M 等待1;48-72M等待2;(非常重要!)
#if (CPUCLK==64000000)

    //PLL 输出16倍,APB1 总线不能超过 36Mhz,  PLLSRC = 0 ,选择HSI/2
    RCC->CFGR = RCC_CFGR_PLLMULL16 | RCC_CFGR_PPRE1_DIV2;
    FLASH->ACR|=0x12;//FLASH 2个延时周期
#elif (CPUCLK==36000000)
    RCC->CFGR = RCC_CFGR_PLLMULL9 ;
    FLASH->ACR|=0x11;//FLASH 1个延时周期
#else
#error "invaild value of CPUCLK "
#endif
    BITBAND(RCC->CR)->bit[RCC_CR_PLLON_Pos]=1;
    while((RCC->CR & RCC_CR_PLLRDY)==0);//等待PLL锁定
    RCC->CFGR|=0x00000002;//PLL作为系统时钟
    //BITBAND(RCC->CFGR)->bit[RCC_CFGR_SW_Pos+1]=1;
    // PLL 设置结果确认
    while(BITBAND(RCC->CFGR)->bit[RCC_CFGR_SWS_Pos+1]==0);

}
#endif