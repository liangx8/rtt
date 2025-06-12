/*
AL CH3C B1
AH CH3  A10
BL CH2C B0
BH CH2  A9
CL CH1C A7
CH CH1  A8
*/
#pragma once

#define PWM_FEQENCE 8000
// 设置a7~a10,b0,b1为复用功能
#define GPIOA_CFGR_VALUE (0b10101010 << 14)
#define GPIOB_CFGR_VALUE (0b0101 << 0)
#define GPIOA_MUXL_VALUE (GPIO_MUX_2 << 28)
//                        A7
#define GPIOA_MUXH_VALUE (GPIO_MUX_2) | (GPIO_MUX_2 << 4) | (GPIO_MUX_2 << 8)
//                        A8             A9                  A10
#define GPIOB_MUXL_VALUE (GPIO_MUX_2) | (GPIO_MUX_2 << 4)

