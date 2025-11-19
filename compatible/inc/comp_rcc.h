#ifndef COMP_RCC_H_JDFJEWE897
#define COMP_RCC_H_JDFJEWE897
#include <stdint.h>
#include "comp_io.h"

typedef struct
{
  uint32_t revers1[3];                                                                     /* Address offset: 0x00 */
  __IO uint32_t APB2RSTR;   /*!< RCC APB2 peripheral reset register,                          Address offset: 0x0C */
  __IO uint32_t APB1RSTR;   /*!< RCC APB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHBENR;     /*!< RCC AHB peripheral clock register,                           Address offset: 0x14 */
  __IO uint32_t APB2ENR;    /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 */
  __IO uint32_t APB1ENR;    /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C */
  uint32_t revers2[2];      /*!< RCC Backup domain control register,                         Address offset: 0x20 */
  __IO uint32_t AHBRSTR;    /*!< RCC AHB peripheral reset register,                           Address offset: 0x28 */
} COMP_RCC_TypeDef;
#endif
