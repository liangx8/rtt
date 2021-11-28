/*
timer1 PWM output
timer2 RCP measure RCP duty
timer3 commutation counter
USART1 using
 */

#ifndef CONFIG_3498624_H
#define CONFIG_3498624_H

#define RCC_AHBENR_VALUE (RCC_AHBENR_GPIOAEN \
                        | RCC_AHBENR_GPIOBEN \
                        | RCC_AHBENR_GPIOCEN \
                        | RCC_AHBENR_GPIOFEN \
                        | RCC_AHBENR_FLITFEN \
                        | RCC_AHBENR_SRAMEN );//先使能外设IO PORTa,b,c,f时钟, SRAM 时钟

#define RCC_APB2ENR_VALUE RCC_APB2ENR_USART1EN | RCC_APB2ENR_TIM1EN | RCC_APB2ENR_SYSCFGCOMPEN;
#define RCC_APB1ENR_VALUE RCC_APB1ENR_TIM2EN | RCC_APB1ENR_TIM3EN

/*
 * PA1 comparator+
 * PA0,PA4,PA5 comparator- MODER设置为模拟输入，禁止所有的上下拉电阻
 * PA6 设置位AF 功能。
 */
// reference PAGE 161 GPIOx AFR0
// datasheet PAGE 37 

/*
 * PA13/14 不能改,必须保留缺省值，否则会导致单片机无法被编程
 */

#define XYA (0b010101 << 16) | (0b10 << 12)
//         test123(PA8 9 10) ,  V_sample
#define GPIOA_MODER_VALUE (0b101010 << 26) | (0b10 << 22) | (0b1111 << 8) | (0b1111) | XYA
//                           | | |              |           ^^^^^^^^^^^^    ^^^^^^^
//                           | | |              |           |               `------ PA0/1 in/out analog
//                           | | |              |           `---------------------- PA4/5 in/out analog
//                           | | |              `---------------  PA11 compare out
//                           | | `------------------------------- PA13 SWDIO(default setting)
//                           | `--------------------------------- PA14 SWCLK(default setting)
//                           `----------------------------------- PA15 TIM2_CH1 rcp_signal
// B6/7 应该被设置位alternate function MODER = 10 (page 149)
// page 157

//#define GPIOB_OTYPER_VALUE (0b10 << 6)
//                            |`------------------------PB 6 USART1_TX PP
//                            `-------------------------PB 7 USART1_RX OD
// 在网上看到一些帖说RX要设置为 INPUT FLOAT MODER=0b00，先用自己理解的模式， TX 用 AF PP, RX 用 AF OD
// idle状态下，RX是高电平, TX是低电平(因为把TX关闭了)
// page 158

/* a15(rcp) AF + OD*/
#define GPIOA_PUPDR_VALUE (0b00 << 20) | (0b00 << 30)
//#define GPIOB_PUPDR_VALUE (0b0000 << 12) // | (0b01 << 26) 
//                                             `--------PB13                            
//                          | `-------------------------PB 6 float
//                          `---------------------------PB 7 float

#define  GPIOA_AFR1_VALUE  0b0010<<28 | (0b0111 <<12)
//                          rcp AF
/*
              1         1 0
              5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 */
#define xyb 0b00010101010100000000000000010101
#define GPIOB_MODER_VALUE xyb | (0b1010 << 12) 
//                               ^^^^^^^^^^^^
//                                 | |
//                                 | `------------------------ PB 6 USART1_TX AF
//                                 `-------------------------- PB 7 USART1_RX AF
#define GPIOB_PUPDR_VALUE (0b01 << 30)
#define GPIOF_MODER_VALUE 0b0001<<12
// PF6,7                    ^^^^

#define GPIOF_PUPDR_VALUE 0b01<<14
// PF7 (t5)




#endif
/*
新电路板
output: ++++++++++++++++++++++++++++++++++++++++++
out + PP
an      pb0
ap      pb1
bn      pb2
bp      pb10
cn      pb11
cp      pb12

LED1    pb13
LED2    pb14

CPOut   PA11

test1   PA10
test2   PA9
test3   PA8

test4   PB15

test5   PF7
test6   PF6

input: ++++++++++++++++++++++++++++++++++++++++++++++++++++
Fc      pa0
Fb      pa4
Fa      pa5
Fabc    pa1

V_sample    PA6

RCP     PA15            digital input           AF + OD

CPOut   PA11

test1   PA10
test2   PA9
test3   PA8

*/
