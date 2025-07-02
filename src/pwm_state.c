/*
AL CH3C B1
AH CH3  A10
BL CH2C B0
BH CH2  A9
CL CH1C A7
CH CH1  A8
普通换相
ＡＢ
ＡＣ
ＢＣ
ＢＡ
ＣＡ
ＣＢ
FOC换相
ＡＢＣ＾
ＡＣＢ＿
ＢＣＡ＾
ＢＡＣ＿
ＣＡＢ＾
ＣＢＡ＿

*/
#include <at32f421_conf.h>
#include "esc_test.h"
#define CM_BASE (TMR_CM_COBEN | TMR_CM_COIEN)
#define FORCE_LO (TMR_CM_FORCE_L | CM_BASE)
#define FORCE_HI (TMR_CM_FORCE_H | CM_BASE)
#define PWMA     (TMR_CM_PWMA | CM_BASE)
#define PWMB     (TMR_CM_PWMB | CM_BASE)
#define CM_OFF 0
// 无ＰＷＭ开，对应通道Ｐ端用FORCE_HI,Ｎ端用FORCE_LO
#define CCTRL_ON   (TMR_CCTRL_CEN | TMR_CCTRL_CCEN)
// ２端全关
#define CCTRL_OFF  (TMR_CCTRL_CEN | TMR_CCTRL_CCEN | TMR_CCTRL_CCP)


#define CCTRL_NPWM (TMR_CCTRL_CCEN)

#define CM(ch1,ch2,ch3) cm1=ch1 | (ch2 <<8);cm2=ch3
#define CCTRL(ch1,ch2,ch3) cctrl=ch1 | (ch2 << 4) | (ch3 << 8)

/**
 * @brief 换相设置
 * @param full 0 有效功率，1 满功率
 * @param idx 0~5
 */
void comm(uint32_t full,uint32_t idx)
{
    uint32_t cm1,cm2,cctrl;
    if(full){
        switch (idx)
        {
        case 0:
        //AB CH3 CH2C
            CCTRL(CCTRL_OFF,CCTRL_ON,CCTRL_ON);
            CM(CM_OFF,FORCE_LO,FORCE_HI);
            break;
        case 1:
        //AC CH3 CH1C
            CCTRL(CCTRL_ON,CCTRL_OFF,CCTRL_ON);
            CM(FORCE_LO,CM_OFF,FORCE_HI);
            break;
        case 2:
        // BC CH2 CH1C
            CCTRL(CCTRL_ON,CCTRL_ON,CCTRL_OFF);
            CM(FORCE_LO,FORCE_HI,CM_OFF);
            break;
        case 3:
        // BA CH2 CH3C
            CCTRL(CCTRL_OFF,CCTRL_ON,CCTRL_ON);
            CM(CM_OFF,FORCE_HI,FORCE_LO);
            break;
        case 4:
        // CA CH1 CH3C
            CCTRL(CCTRL_ON,CCTRL_OFF,CCTRL_ON);
            CM(FORCE_HI,CM_OFF,FORCE_LO);
            break;
        case 5:
        // CB CH1 CH2C
            CCTRL(CCTRL_ON,CCTRL_ON,CCTRL_OFF);
            CM(FORCE_HI,FORCE_LO,CM_OFF);
            break;
        default:
            CCTRL(CCTRL_NPWM,CCTRL_NPWM,CCTRL_NPWM);
            CM(PWMA,PWMA,PWMA);
        }
    } else {
        switch (idx)
        {
        case 0:
            //AB CH3 CH2C
            CCTRL(CCTRL_OFF,CCTRL_NPWM,CCTRL_ON);
            CM(FORCE_LO,PWMA,FORCE_HI);
            break;
        case 1:
            //AC CH3 CH1C
            CCTRL(CCTRL_NPWM,CCTRL_OFF,CCTRL_ON);
            CM(PWMA,FORCE_LO,FORCE_HI);
            break;
        case 2:
        // BC CH2 CH1C
            CCTRL(CCTRL_NPWM,CCTRL_ON,CCTRL_OFF);
            CM(PWMA,FORCE_HI,FORCE_LO);
            break;
        case 3:
        // BA CH2 CH3C
            CCTRL(CCTRL_OFF,CCTRL_ON,CCTRL_NPWM);
            CM(FORCE_LO,FORCE_HI,PWMA);
            break;
        case 4:
        // CA CH1 CH3C
            CCTRL(CCTRL_ON,CCTRL_OFF,CCTRL_NPWM);
            CM(FORCE_HI,FORCE_LO,PWMA);
            break;
        case 5:
        // CB CH1 CH2C
            CCTRL(CCTRL_ON,CCTRL_NPWM,CCTRL_OFF);
            CM(FORCE_HI,PWMA,FORCE_LO);
            break;
        default:
            CCTRL(CCTRL_NPWM,CCTRL_NPWM,CCTRL_NPWM);
            CM(PWMA,PWMA,PWMA);

        }
        
    }
    TMR1->cm1=cm1;
    TMR1->cm2=cm2;
    TMR1->cctrl=cctrl;

}
void ana_comm(void)
{
    TMR1->cctrl=(CCTRL_ON) | (CCTRL_ON<<4) | (CCTRL_ON << 8);
    TMR1->cm1=PWMA | (PWMA << 8);
    TMR1->cm2=PWMA;
    TMR1->swevt = TMR_SWEVT_HALLSWTR;
}
extern const uint16_t sin180[];

void ana_transfer(uint32_t dgr)
{

    uint16_t dgr1=dgr+120;
    if(dgr1>=180)dgr1=dgr1-180;
    uint16_t dgr2=dgr1+120;
    if(dgr2>=180)dgr2=dgr2-180;
    TMR1->c1dt=sin180[dgr];
    TMR1->c2dt=sin180[dgr1];
    TMR1->c3dt=sin180[dgr2];
}

uint32_t pwm_duty(uint32_t duty)
{
    if(duty>=PWM_TOP){
        duty=PWM_TOP-1;
    }
    TMR1->c1dt = duty;
    TMR1->c2dt = duty;
    TMR1->c3dt = duty;
    return duty;
}

