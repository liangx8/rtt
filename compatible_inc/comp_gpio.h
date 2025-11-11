#ifndef COMP_GPIO_H_KDWE9934JJ
#define  COMP_GPIO_H_KDWE9934JJ
#include <stdint.h>
#include "comp_io.h"
typedef struct _comp_gpio_typedef
{
  __IO uint32_t MODER;        /*!< GPIO port mode register,                     Address offset: 0x00      */
  __IO uint32_t OTYPER;       /*!< GPIO port output type register,              Address offset: 0x04      */
  __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,             Address offset: 0x08      */
  __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,        Address offset: 0x0C      */
  __IO uint32_t IDR;          /*!< GPIO port input data register,               Address offset: 0x10      */
  __IO uint32_t ODR;          /*!< GPIO port output data register,              Address offset: 0x14      */
  __IO uint32_t BSRR;         /*!< GPIO port bit set/reset register,            Address offset: 0x1A      */
  __IO uint32_t LCKR;         /*!< GPIO port configuration lock register,       Address offset: 0x1C      */
  __IO uint32_t AFRL;         /*!< GPIO alternate function low register,        Address offset: 0x20      */
  __IO uint32_t AFRH;         /*!< GPIO alternate function high register,       Address offset: 0x24      */
  __IO uint32_t BRR;          /*!< GPIO bit reset register,                     Address offset: 0x28      */
} COMP_GPIO_TypeDef;
#endif