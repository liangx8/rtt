#ifndef COMP_TMR_H_KDDUE889ER
#define  COMP_TMR_H_KDDUE889ER
#include <stdint.h>
#include "comp_io.h"
typedef struct
{
    __IO uint32_t CR1;          /*!< TIM control register 1,              Address offset: 0x00 */
    __IO uint32_t CR2;          /*!< TIM control register 2,              Address offset: 0x04 */
    __IO uint32_t SMCR;         /*!< TIM slave Mode Control register,     Address offset: 0x08 */
    __IO uint32_t DIER;         /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
    __IO uint32_t SR;           /*!< TIM status register,                 Address offset: 0x10 */
    __IO uint32_t EGR;          /*!< TIM event generation register,       Address offset: 0x14 */
    __IO uint32_t CCMR1;        /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
    __IO uint32_t CCMR2;        /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
    __IO uint32_t CCER;         /*!< TIM capture/compare enable register, Address offset: 0x20 */
    __IO uint32_t CNT;          /*!< TIM counter register,                Address offset: 0x24 */
    __IO uint32_t PSC;          /*!< TIM prescaler register,              Address offset: 0x28 */
    __IO uint32_t ARR;          /*!< TIM auto-reload register,            Address offset: 0x2C */
    __IO uint32_t RCR;          /*!< TIM repetition counter register,     Address offset: 0x30 */
    __IO uint32_t CCR1;         /*!< TIM capture/compare register 1,      Address offset: 0x34 */    
    __IO uint32_t CCR2;         /*!< TIM capture/compare register 2,      Address offset: 0x38 */    
    __IO uint32_t CCR3;         /*!< TIM capture/compare register 3,      Address offset: 0x3C */
    __IO uint32_t CCR4;         /*!< TIM capture/compare register 4,      Address offset: 0x40 */
    __IO uint32_t BDTR;         /*!< TIM break and dead-time register,    Address offset: 0x44 */
    __IO uint32_t DCR;          /*!< TIM DMA control register,            Address offset: 0x48 */
    __IO uint32_t DMAR;         /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
    __IO uint32_t OR;           /*!< TIM option register,                 Address offset: 0x50 */
} COMP_TIM_TypeDef;
#define TIM_CR1_CKD_pos      8 
#define TIM_CR1_ARPE_pos     7
#define TIM_CR1_CMS_pos      5
#define TIM_CR1_DIR_pos      4
#define TIM_CR1_OPM_pos      3
#define TIM_CR1_URS_pos      2
#define TIM_CR1_UDIS_pos     1
#define TIM_CR1_CEN_pos      0

#define TIM_CR2_OIS4_pos     14
#define TIM_CR2_OIS3N_pos    13
#define TIM_CR2_OIS3_pos     12
#define TIM_CR2_OIS2N_pos    11
#define TIM_CR2_OIS2_pos     10
#define TIM_CR2_OIS1N_pos    9
#define TIM_CR2_OIS1_pos     8
#define TIM_CR2_TI1S_pos     7
#define TIM_CR2_MMS_pos      4 
#define TIM_CR2_CCDS_pos     3
#define TIM_CR2_CCUS_pos     2
#define TIM_CR2_CCPC_pos     0

#define TIM_DIER_TDE_pos    14
#define TIM_DIER_COMDE_pos  13
#define TIM_DIER_CC4DE_pos  12
#define TIM_DIER_CC3DE_pos  11
#define TIM_DIER_CC2DE_pos  10
#define TIM_DIER_CC1DE_pos  9
#define TIM_DIER_UDE_pos    8
#define TIM_DIER_BIE_pos    7
#define TIM_DIER_TIE_pos    6
#define TIM_DIER_COMIE_pos  5
#define TIM_DIER_CC4IE_pos  4
#define TIM_DIER_CC3IE_pos  3
#define TIM_DIER_CC2IE_pos  2
#define TIM_DIER_CC1IE_pos  1
#define TIM_DIER_UIE_pos    0

#define TIM_SR_UIF_Pos            (0U)
#define TIM_SR_UIF_Msk            (0x1UL << TIM_SR_UIF_Pos)                     /*!< 0x00000001 */
#define TIM_SR_UIF                TIM_SR_UIF_Msk                               /*!<Update interrupt Flag */
#define TIM_SR_CC1IF_Pos          (1U)
#define TIM_SR_CC1IF_Msk          (0x1UL << TIM_SR_CC1IF_Pos)                   /*!< 0x00000002 */
#define TIM_SR_CC1IF              TIM_SR_CC1IF_Msk                             /*!<Capture/Compare 1 interrupt Flag */
#define TIM_SR_CC2IF_Pos          (2U)
#define TIM_SR_CC2IF_Msk          (0x1UL << TIM_SR_CC2IF_Pos)                   /*!< 0x00000004 */
#define TIM_SR_CC2IF              TIM_SR_CC2IF_Msk                             /*!<Capture/Compare 2 interrupt Flag */
#define TIM_SR_CC3IF_Pos          (3U)
#define TIM_SR_CC3IF_Msk          (0x1UL << TIM_SR_CC3IF_Pos)                   /*!< 0x00000008 */
#define TIM_SR_CC3IF              TIM_SR_CC3IF_Msk                             /*!<Capture/Compare 3 interrupt Flag */
#define TIM_SR_CC4IF_Pos          (4U)
#define TIM_SR_CC4IF_Msk          (0x1UL << TIM_SR_CC4IF_Pos)                   /*!< 0x00000010 */
#define TIM_SR_CC4IF              TIM_SR_CC4IF_Msk                             /*!<Capture/Compare 4 interrupt Flag */
#define TIM_SR_COMIF_Pos          (5U)
#define TIM_SR_COMIF_Msk          (0x1UL << TIM_SR_COMIF_Pos)                   /*!< 0x00000020 */
#define TIM_SR_COMIF              TIM_SR_COMIF_Msk                             /*!<COM interrupt Flag */
#define TIM_SR_TIF_Pos            (6U)
#define TIM_SR_TIF_Msk            (0x1UL << TIM_SR_TIF_Pos)                     /*!< 0x00000040 */
#define TIM_SR_TIF                TIM_SR_TIF_Msk                               /*!<Trigger interrupt Flag */
#define TIM_SR_BIF_Pos            (7U)
#define TIM_SR_BIF_Msk            (0x1UL << TIM_SR_BIF_Pos)                     /*!< 0x00000080 */
#define TIM_SR_BIF                TIM_SR_BIF_Msk                               /*!<Break interrupt Flag */
#define TIM_SR_CC1OF_Pos          (9U)
#define TIM_SR_CC1OF_Msk          (0x1UL << TIM_SR_CC1OF_Pos)                   /*!< 0x00000200 */
#define TIM_SR_CC1OF              TIM_SR_CC1OF_Msk                             /*!<Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos          (10U)
#define TIM_SR_CC2OF_Msk          (0x1UL << TIM_SR_CC2OF_Pos)                   /*!< 0x00000400 */
#define TIM_SR_CC2OF              TIM_SR_CC2OF_Msk                             /*!<Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos          (11U)
#define TIM_SR_CC3OF_Msk          (0x1UL << TIM_SR_CC3OF_Pos)                   /*!< 0x00000800 */
#define TIM_SR_CC3OF              TIM_SR_CC3OF_Msk                             /*!<Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos          (12U)
#define TIM_SR_CC4OF_Msk          (0x1UL << TIM_SR_CC4OF_Pos)                   /*!< 0x00001000 */
#define TIM_SR_CC4OF              TIM_SR_CC4OF_Msk                             /*!<Capture/Compare 4 Overcapture Flag */

#define TIM_EGR_UG_Pos            (0U)
#define TIM_EGR_UG_Msk            (0x1UL << TIM_EGR_UG_Pos)                     /*!< 0x00000001 */
#define TIM_EGR_UG                TIM_EGR_UG_Msk                               /*!<Update Generation */
#define TIM_EGR_CC1G_Pos          (1U)
#define TIM_EGR_CC1G_Msk          (0x1UL << TIM_EGR_CC1G_Pos)                   /*!< 0x00000002 */
#define TIM_EGR_CC1G              TIM_EGR_CC1G_Msk                             /*!<Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos          (2U)
#define TIM_EGR_CC2G_Msk          (0x1UL << TIM_EGR_CC2G_Pos)                   /*!< 0x00000004 */
#define TIM_EGR_CC2G              TIM_EGR_CC2G_Msk                             /*!<Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos          (3U)
#define TIM_EGR_CC3G_Msk          (0x1UL << TIM_EGR_CC3G_Pos)                   /*!< 0x00000008 */
#define TIM_EGR_CC3G              TIM_EGR_CC3G_Msk                             /*!<Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos          (4U)
#define TIM_EGR_CC4G_Msk          (0x1UL << TIM_EGR_CC4G_Pos)                   /*!< 0x00000010 */
#define TIM_EGR_CC4G              TIM_EGR_CC4G_Msk                             /*!<Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos          (5U)
#define TIM_EGR_COMG_Msk          (0x1UL << TIM_EGR_COMG_Pos)                   /*!< 0x00000020 */
#define TIM_EGR_COMG              TIM_EGR_COMG_Msk                             /*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos            (6U)
#define TIM_EGR_TG_Msk            (0x1UL << TIM_EGR_TG_Pos)                     /*!< 0x00000040 */
#define TIM_EGR_TG                TIM_EGR_TG_Msk                               /*!<Trigger Generation */
#define TIM_EGR_BG_Pos            (7U)
#define TIM_EGR_BG_Msk            (0x1UL << TIM_EGR_BG_Pos)                     /*!< 0x00000080 */
#define TIM_EGR_BG                TIM_EGR_BG_Msk                               /*!<Break Generation */
#endif