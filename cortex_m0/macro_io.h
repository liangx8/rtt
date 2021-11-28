#ifndef MACRO_IO_H
#define MACRO_IO_H

#define ON(po,mask) po->BSRR= mask
#define OFF(po,mask) po->BRR = mask
#define STATUS(po,mask) (po->IDR & mask)


#define LED1_PORT GPIOB
#define LED2_PORT GPIOB
#define LED1_MASK GPIO_ODR_13
#define LED2_MASK GPIO_ODR_14

#define T1_PORT GPIOA
#define T2_PORT GPIOA
#define T3_PORT GPIOA
#define T4_PORT GPIOB
#define T5_PORT GPIOF
#define T6_PORT GPIOF

#define T1_MASK GPIO_ODR_10
#define T2_MASK GPIO_ODR_9
#define T3_MASK GPIO_ODR_8
#define T4_MASK GPIO_ODR_15
#define T5_MASK GPIO_ODR_7
#define T6_MASK GPIO_ODR_6


#define LED1_ON ON(LED1_PORT,LED1_MASK)
#define LED2_ON ON(LED2_PORT,LED2_MASK)

#define LED1_OFF OFF(LED1_PORT,LED1_MASK)
#define LED2_OFF OFF(LED2_PORT,LED2_MASK)

#define T1_ON ON(T1_PORT,T1_MASK)
#define T2_ON ON(T2_PORT,T2_MASK)
#define T3_ON ON(T3_PORT,T3_MASK)
#define T4_ON ON(T4_PORT,T4_MASK)
#define T5_ON ON(T5_PORT,T5_MASK)
#define T6_ON ON(T6_PORT,T6_MASK)

#define T1_OFF OFF(T1_PORT,T1_MASK)
#define T2_OFF OFF(T2_PORT,T2_MASK)
#define T3_OFF OFF(T3_PORT,T3_MASK)
#define T4_OFF OFF(T4_PORT,T4_MASK)
#define T5_OFF OFF(T5_PORT,T5_MASK)
#define T6_OFF OFF(T6_PORT,T6_MASK)




#endif
