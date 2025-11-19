/*
AL CH3C B1
AH CH3  A10
BL CH2C B0
BH CH2  A9
CL CH1C A7
CH CH1  A8
*/
#pragma once

#define PWM_FEQENCE 16000

#define GPIOA_ODT_VALUE 0b1111100001111111
#define GPIOB_ODT_VALUE 0b1111111111111100
#define PWM_TOP (CPUCLK * 1000000 / PWM_FEQENCE)
// 设置a7~a10,b0,b1为复用功能
// a11,a12 推挽
#define GPIOA_CFGR_VALUE (0b010110101010 << 14)
#define GPIOB_CFGR_VALUE (0b1010 << 0)
#define GPIOA_MUXL_VALUE (GPIO_MUX_2 << 28)
//                        A7
#define GPIOA_MUXH_VALUE (GPIO_MUX_2) | (GPIO_MUX_2 << 4) | (GPIO_MUX_2 << 8)
//                        A8             A9                  A10
#define GPIOB_MUXL_VALUE (GPIO_MUX_2) | (GPIO_MUX_2 << 4)

#define SIN_POWER 0.2f
#define SIN_NUTRAL (unsigned)((PWM_TOP>>1) * SIN_POWER)