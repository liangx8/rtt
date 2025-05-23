#include <at32f421_conf.h>
#include <bitband.h>
#define USE_HICK
void crm_init(void)
{
    FLASH->psr=FLASH_PSR_DEFAULT_VAL | FLASH_WAIT_CYCLE_3;
    CRM->cfg=CRM_SCLK_HICK << CRM_CFG_SCLKSEL_pos;
#ifdef USE_HEXT8
    // 外部8M时钟不分频
    const uint32_t CFG_VAL=(1 << CRM_CFG_PLLRCS_pos) | ((CRM_PLL_MULT_15 & 0xf) << CRM_CFG_PLLMULT_L_pos) | (((CRM_PLL_MULT_15 >> 4) & 0x3) << CRM_CFG_PLLMULT_H_pos);
    CRM->cfg = CFG_VAL;
#endif
#ifdef USE_HEXT8_DIV2
    // 外部8M时钟2分频
    const uint32_t CFG_VAL=(1 << CRM_CFG_PLLRCS_pos) |(1 << CRM_CFG_PLLHEXTDIV_pos) | ((CRM_PLL_MULT_30 & 0xf) << CRM_CFG_PLLMULT_L_pos) | (((CRM_PLL_MULT_30 >> 4) & 0x3) << CRM_CFG_PLLMULT_H_pos);
    CRM->cfg = CFG_VAL;
#endif
#ifdef USE_HICK
    // cfg.PLLRCS=00 使用内部高频时钟48M /6 / 2=4M
    uint32_t cfg_val=CRM->cfg;
    cfg_val = cfg_val & (~((0b11 << CRM_CFG_PLLMULT_H_pos)|(0b1111 << CRM_CFG_PLLMULT_L_pos)));
    // const uint32_t CFG_VAL=  ((CRM_PLL_MULT_30 & 0xf) << CRM_CFG_PLLMULT_L_pos) 
    //                         |(((CRM_PLL_MULT_30 & 0x30)>> 4)  << CRM_CFG_PLLMULT_H_pos);
    cfg_val = cfg_val | ((CRM_PLL_MULT_30 & 0xf) << CRM_CFG_PLLMULT_L_pos) 
                      | (((CRM_PLL_MULT_30 & 0x30)>> 4)  << CRM_CFG_PLLMULT_H_pos);
    CRM->cfg=cfg_val;
    BITBAND(CRM->cfg)->bit[CRM_CFG_PLLRCS_pos]=0;
    cfg_val=CRM->cfg;
#endif
    // 使用常规配置ＰＬＬ，这个寄存器的其他值都不用管
    CRM->pll=0;
    CRM->ctrl=(1<<CRM_CTRL_PLLEN_pos);
    while((CRM->ctrl& (1<<CRM_CTRL_PLLSTBL_pos))==0);
    // SELECT PLL
    // 手册说，PLL使能后，PLL的设定不会被修改
    CRM->misc2=CRM_MISC2_AUTO_STEP_EN_ON | 0x0d;
    cfg_val = cfg_val & (~(0b11));
    CRM->cfg=cfg_val | (CRM_SCLK_PLL << CRM_CFG_SCLKSEL_pos);
//    __NOP();__NOP();__NOP();__NOP();__NOP();
//    __NOP();__NOP();__NOP();__NOP();__NOP();
//    __NOP();__NOP();__NOP();__NOP();__NOP();
//    __NOP();__NOP();__NOP();__NOP();__NOP();
    uint32_t timeout_cnt=0;
    while(((CRM->cfg >> 2)& 0x03) !=CRM_SCLK_PLL){
        if(++timeout_cnt>100000){
            break;
        }
    }
    // auto step enable off
    CRM->misc2= 0x0d;
}
// A13,A14的值要保持复用功能打开，用于烧录程序
// 在GPIOA设置时，要把一下３个缺省值加上
#define GPIOA_CFGR_DEFAULT  0x28000000
#define GPIOA_ODRVR_DEFAULT 0x0c000000
#define GPIOA_PULL_DEFAULT  0x24000000
void gpio_init(void)
{
    CRM->ahben=(1 << CRM_AHBEN_GPIOAEN_pos);
    GPIOA->cfgr=GPIOA_CFGR_DEFAULT | (GPIO_MODE_OUTPUT << (GPIO_PINS_SOURCE8*2)) |(GPIO_MODE_OUTPUT << (GPIO_PINS_SOURCE9*2));
}
void mcu_init(void)
{
    crm_init();
    gpio_init();
}
