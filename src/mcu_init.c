#include "conf.h"
#include <bitband.h>
//#define USE_HEXT8_DIV2
#define USE_HICK
void crm_init(void)
{
    FLASH->psr=FLASH_PSR_DEFAULT_VAL | FLASH_WAIT_CYCLE_3;
    //CRM->cfg=CRM_SCLK_HICK << CRM_CFG_SCLKSEL_pos;
#ifdef USE_HEXT8
    // 外部8M时钟不分频
    BITBAND(CRM->ctrl)->bit[CRM_CTRL_HEXTEN_pos]=1;
    while((CRM->ctrl & (1<< CRM_CTRL_HEXTSTBL_pos))==0);
    const uint32_t CFG_VAL=(1 << CRM_CFG_PLLRCS_pos) 
                        | ((CRM_PLL_MULT_15 & 0xf) << CRM_CFG_PLLMULT_L_pos) 
                        | (((CRM_PLL_MULT_15 & 0x30) >>4) << CRM_CFG_PLLMULT_H_pos);
    CRM->cfg = CFG_VAL;
#endif
#ifdef USE_HEXT8_DIV2
    BITBAND(CRM->ctrl)->bit[CRM_CTRL_HEXTEN_pos]=1;
    while((CRM->ctrl & (1<< CRM_CTRL_HEXTSTBL_pos))==0);
    // 外部8M时钟源2分频
    const uint32_t CFG_VAL=(1 << CRM_CFG_PLLRCS_pos) 
                        | (1 << CRM_CFG_PLLHEXTDIV_pos)
                        | ((CRM_PLL_MULT_30 & 0xf) << CRM_CFG_PLLMULT_L_pos)
                        | (((CRM_PLL_MULT_30 & 0x30)>>4) << CRM_CFG_PLLMULT_H_pos);
    CRM->cfg = CFG_VAL;
#endif
#ifdef USE_HICK
    // cfg.PLLRCS=00 使用内部高频时钟48M /6 / 2=4M
    const uint32_t CFG_VAL=  ((CRM_PLL_MULT_30 & 0xf) << CRM_CFG_PLLMULT_L_pos) 
//                            | (CRM_APB_DIV_2<<CRM_CFG_APB1DIV_pos)
                            | (((CRM_PLL_MULT_30 & 0x30)>> 4)  << CRM_CFG_PLLMULT_H_pos);
    CRM->cfg=CFG_VAL;
#endif
    // 使用常规配置ＰＬＬ，这个寄存器的其他值都不用管
    CRM->pll=0;
    BITBAND(CRM->ctrl)->bit[CRM_CTRL_PLLEN_pos]=1;
    while((CRM->ctrl& (1<<CRM_CTRL_PLLSTBL_pos))==0);
    // SELECT PLL
    // 手册说，PLL使能后，PLL的设定不会被修改
    CRM->misc2=CRM_MISC2_AUTO_STEP_EN_ON | 0x0d;
    CRM->cfg=CFG_VAL | (CRM_SCLK_PLL << CRM_CFG_SCLKSEL_pos);
    // BITBAND(CRM->cfg)->bit[CRM_CFG_SCLKSEL_pos]=0;
    // BITBAND(CRM->cfg)->bit[CRM_CFG_SCLKSEL_pos+1]=1;
    while(((CRM->cfg >> 2)& 0x03) !=CRM_SCLK_PLL);
    // auto step enable off
    CRM->misc2= 0x0d;
}
// A13,A14的值要保持复用功能打开，用于烧录程序
// 在GPIOA设置时，要把以下３个缺省值加上
#define GPIOA_CFGR_DEFAULT  0x28000000
#define GPIOA_ODRVR_DEFAULT 0x0c000000
#define GPIOA_PULL_DEFAULT  0x24000000
void gpio_init(void)
{
#ifdef GPIOA_CFGR_VALUE
    GPIOA->cfgr=GPIOA_CFGR_DEFAULT | GPIOA_CFGR_VALUE;
#endif
#ifdef GPIOA_OMODE_VALUE
    GPIOA->omode=GPIOA_OMODE_VALUE
#endif
#ifdef GPIOA_ODRVR_VALUE
    GPIOA->omode=GPIOA_ODRVR_DEFAULT | GPIOA_ODRVR_VALUE;
#endif
#ifdef GPIOA_PULL_VALUE
    GPIOA->pull=GPIOA_PULL_DEFAULT | GPIOA_PULL_VALUE;
#endif
#ifdef GPIOA_MUXH_VALUE
    GPIOA->muxh=GPIOA_MUXH_VALUE;
#endif
#ifdef GPIOA_MUXL_VALUE
    GPIOA->muxl=GPIOA_MUXL_VALUE;
#endif
GPIOA->odt=GPIOA_ODT_VALUE;

#ifdef GPIOB_CFGR_VALUE
    GPIOB->cfgr=GPIOB_CFGR_VALUE;
#endif
#ifdef GPIOB_MUXH_VALUE
    GPIOB->muxh=GPIOB_MUXH_VALUE;
#endif
#ifdef GPIOB_MUXL_VALUE
    GPIOB->muxl=GPIOB_MUXL_VALUE;
#endif
GPIOB->odt=GPIOB_ODT_VALUE;
}
// 127 => 1us,超过127将会加倍,当前0x40相当与500ns
#define DEADTIME_GAP 0x40
void timer_init(void)
{
/*****************************************************************************************
 *  TIMER 6
 *****************************************************************************************/
    TMR6->pr=CPUCLK * 1000000 / 180 / 50;
    //TMR6->pr=0xffff; // 10Hz
    TMR6->ctrl1=(1<<TMR_CTRL1_PRBEN_pos) | (1<<TMR_CTRL1_OVFS_pos) | (1 << TMR_CTRL1_TMREN_pos);
/*****************************************************************************************
 *  TIMER 1
 *****************************************************************************************/
    TMR1->pr=PWM_TOP;
    TMR1->ctrl1=(1<<TMR_CTRL1_PRBEN_pos)
                | (1 << TMR_CTRL1_TMREN_pos)
                | (1 << TMR_CTRL1_OVFS_pos);
    TMR1->ctrl2=(1<<TMR_CTRL2_CBCTRL_pos);
    TMR1->brk=(1<<TMR_BRK_AOEN_pos) | (1 << TMR_BRK_FCSOEN_pos) | DEADTIME_GAP;
    // 关闭全部TIMER1的中断
    TMR1->iden=0;
}
void mcu_init(void)
{
    crm_init();
    gpio_init();
    timer_init();

    SysTick_Config(MS(5));
}
