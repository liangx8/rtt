/**
  **************************************************************************
  * @file     at32f421_crm.h
  * @brief    at32f421 crm header file
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32F421_CRM_H
#define __AT32F421_CRM_H

#ifdef __cplusplus
extern "C" {
#endif


/* includes ------------------------------------------------------------------*/
#include "at32f421.h"



/** @addtogroup CRM
  */



/** 
  * @brief crm interrupt
  */

#define CRM_LICK_STABLE_INT              ((uint32_t)0x00000100) /*!< low speed internal clock stable interrupt */
#define CRM_LEXT_STABLE_INT              ((uint32_t)0x00000200) /*!< low speed external crystal stable interrupt */
#define CRM_HICK_STABLE_INT              ((uint32_t)0x00000400) /*!< high speed internal clock stable interrupt */
#define CRM_HEXT_STABLE_INT              ((uint32_t)0x00000800) /*!< high speed external crystal stable interrupt */
#define CRM_PLL_STABLE_INT               ((uint32_t)0x00001000) /*!< phase locking loop stable interrupt */
#define CRM_CLOCK_FAILURE_INT            ((uint32_t)0x00800000) /*!< clock failure interrupt */

/**
  * @brief crm pll mult_x
  */
typedef enum
{
  CRM_PLL_MULT_2                         = 0,  /*!< pll multiplication factor 2 */
  CRM_PLL_MULT_3                         = 1,  /*!< pll multiplication factor 3 */
  CRM_PLL_MULT_4                         = 2,  /*!< pll multiplication factor 4 */
  CRM_PLL_MULT_5                         = 3,  /*!< pll multiplication factor 5 */
  CRM_PLL_MULT_6                         = 4,  /*!< pll multiplication factor 6 */
  CRM_PLL_MULT_7                         = 5,  /*!< pll multiplication factor 7 */
  CRM_PLL_MULT_8                         = 6,  /*!< pll multiplication factor 8 */
  CRM_PLL_MULT_9                         = 7,  /*!< pll multiplication factor 9 */
  CRM_PLL_MULT_10                        = 8,  /*!< pll multiplication factor 10 */
  CRM_PLL_MULT_11                        = 9,  /*!< pll multiplication factor 11 */
  CRM_PLL_MULT_12                        = 10, /*!< pll multiplication factor 12 */
  CRM_PLL_MULT_13                        = 11, /*!< pll multiplication factor 13 */
  CRM_PLL_MULT_14                        = 12, /*!< pll multiplication factor 14 */
  CRM_PLL_MULT_15                        = 13, /*!< pll multiplication factor 15 */
  CRM_PLL_MULT_16                        = 15, /*!< pll multiplication factor 16 */
  CRM_PLL_MULT_17                        = 16, /*!< pll multiplication factor 17 */
  CRM_PLL_MULT_18                        = 17, /*!< pll multiplication factor 18 */
  CRM_PLL_MULT_19                        = 18, /*!< pll multiplication factor 19 */
  CRM_PLL_MULT_20                        = 19, /*!< pll multiplication factor 20 */
  CRM_PLL_MULT_21                        = 20, /*!< pll multiplication factor 21 */
  CRM_PLL_MULT_22                        = 21, /*!< pll multiplication factor 22 */
  CRM_PLL_MULT_23                        = 22, /*!< pll multiplication factor 23 */
  CRM_PLL_MULT_24                        = 23, /*!< pll multiplication factor 24 */
  CRM_PLL_MULT_25                        = 24, /*!< pll multiplication factor 25 */
  CRM_PLL_MULT_26                        = 25, /*!< pll multiplication factor 26 */
  CRM_PLL_MULT_27                        = 26, /*!< pll multiplication factor 27 */
  CRM_PLL_MULT_28                        = 27, /*!< pll multiplication factor 28 */
  CRM_PLL_MULT_29                        = 28, /*!< pll multiplication factor 29 */
  CRM_PLL_MULT_30                        = 29, /*!< pll multiplication factor 30 */
  CRM_PLL_MULT_31                        = 30, /*!< pll multiplication factor 31 */
  CRM_PLL_MULT_32                        = 31, /*!< pll multiplication factor 32 */
  CRM_PLL_MULT_33                        = 32, /*!< pll multiplication factor 33 */
  CRM_PLL_MULT_34                        = 33, /*!< pll multiplication factor 34 */
  CRM_PLL_MULT_35                        = 34, /*!< pll multiplication factor 35 */
  CRM_PLL_MULT_36                        = 35, /*!< pll multiplication factor 36 */
  CRM_PLL_MULT_37                        = 36, /*!< pll multiplication factor 37 */
  CRM_PLL_MULT_38                        = 37, /*!< pll multiplication factor 38 */
  CRM_PLL_MULT_39                        = 38, /*!< pll multiplication factor 39 */
  CRM_PLL_MULT_40                        = 39, /*!< pll multiplication factor 40 */
  CRM_PLL_MULT_41                        = 40, /*!< pll multiplication factor 41 */
  CRM_PLL_MULT_42                        = 41, /*!< pll multiplication factor 42 */
  CRM_PLL_MULT_43                        = 42, /*!< pll multiplication factor 43 */
  CRM_PLL_MULT_44                        = 43, /*!< pll multiplication factor 44 */
  CRM_PLL_MULT_45                        = 44, /*!< pll multiplication factor 45 */
  CRM_PLL_MULT_46                        = 45, /*!< pll multiplication factor 46 */
  CRM_PLL_MULT_47                        = 46, /*!< pll multiplication factor 47 */
  CRM_PLL_MULT_48                        = 47, /*!< pll multiplication factor 48 */
  CRM_PLL_MULT_49                        = 48, /*!< pll multiplication factor 49 */
  CRM_PLL_MULT_50                        = 49, /*!< pll multiplication factor 50 */
  CRM_PLL_MULT_51                        = 50, /*!< pll multiplication factor 51 */
  CRM_PLL_MULT_52                        = 51, /*!< pll multiplication factor 52 */
  CRM_PLL_MULT_53                        = 52, /*!< pll multiplication factor 53 */
  CRM_PLL_MULT_54                        = 53, /*!< pll multiplication factor 54 */
  CRM_PLL_MULT_55                        = 54, /*!< pll multiplication factor 55 */
  CRM_PLL_MULT_56                        = 55, /*!< pll multiplication factor 56 */
  CRM_PLL_MULT_57                        = 56, /*!< pll multiplication factor 57 */
  CRM_PLL_MULT_58                        = 57, /*!< pll multiplication factor 58 */
  CRM_PLL_MULT_59                        = 58, /*!< pll multiplication factor 59 */
  CRM_PLL_MULT_60                        = 59, /*!< pll multiplication factor 60 */
  CRM_PLL_MULT_61                        = 60, /*!< pll multiplication factor 61 */
  CRM_PLL_MULT_62                        = 61, /*!< pll multiplication factor 62 */
  CRM_PLL_MULT_63                        = 62, /*!< pll multiplication factor 63 */
  CRM_PLL_MULT_64                        = 63  /*!< pll multiplication factor 64 */
} crm_pll_mult_type;

/**
  * @brief crm pll fref_x
  */
typedef enum
{
  CRM_PLL_FREF_4M                         = 0,  /*!< pll refrence clock between 3.9 mhz and 5 mhz */
  CRM_PLL_FREF_6M                         = 1,  /*!< pll refrence clock between 5.2 mhz and 6.25 mhz */
  CRM_PLL_FREF_8M                         = 2,  /*!< pll refrence clock between 7.8125 mhz and 8.33 mhz */
  CRM_PLL_FREF_12M                        = 3,  /*!< pll refrence clock between 8.33 mhz and 12.5 mhz */
  CRM_PLL_FREF_16M                        = 4,  /*!< pll refrence clock between 15.625 mhz and 20.83 mhz */
  CRM_PLL_FREF_25M                        = 5   /*!< pll refrence clock between 20.83 mhz and 31.255 mhz */
} crm_pll_fref_type;

/**
  * @brief crm pll clock source
  */
typedef enum
{
  CRM_PLL_SOURCE_HICK                    = 0x00, /*!< high speed internal clock as pll reference clock source */
  CRM_PLL_SOURCE_HEXT                    = 0x01, /*!< high speed external crystal as pll reference clock source */
  CRM_PLL_SOURCE_HEXT_DIV                = 0x02  /*!< high speed external crystal div as pll reference clock source */
} crm_pll_clock_source_type;

/**
  * @brief crm pll fr
  */
typedef enum
{
  CRM_PLL_FR_1                           = 0x00, /*!< pll post-division div1 */
  CRM_PLL_FR_2                           = 0x01, /*!< pll post-division div2 */
  CRM_PLL_FR_4                           = 0x02, /*!< pll post-division div4 */
  CRM_PLL_FR_8                           = 0x03, /*!< pll post-division div8 */
  CRM_PLL_FR_16                          = 0x04, /*!< pll post-division div16 */
  CRM_PLL_FR_32                          = 0x05  /*!< pll post-division div32 */
} crm_pll_fr_type;

/**
  * @brief crm clock source
  */
typedef enum
{
  CRM_CLOCK_SOURCE_HICK                  = 0x00, /*!< high speed internal clock */
  CRM_CLOCK_SOURCE_HEXT                  = 0x01, /*!< high speed external crystal */
  CRM_CLOCK_SOURCE_PLL                   = 0x02, /*!< phase locking loop */
  CRM_CLOCK_SOURCE_LEXT                  = 0x03, /*!< low speed external crystal */
  CRM_CLOCK_SOURCE_LICK                  = 0x04  /*!< low speed internal clock */
} crm_clock_source_type;

/**
  * @brief crm ahb division
  */
typedef enum
{
  CRM_AHB_DIV_1                          = 0x00, /*!< sclk div1 to ahbclk */
  CRM_AHB_DIV_2                          = 0x08, /*!< sclk div2 to ahbclk */
  CRM_AHB_DIV_4                          = 0x09, /*!< sclk div4 to ahbclk */
  CRM_AHB_DIV_8                          = 0x0A, /*!< sclk div8 to ahbclk */
  CRM_AHB_DIV_16                         = 0x0B, /*!< sclk div16 to ahbclk */
  CRM_AHB_DIV_64                         = 0x0C, /*!< sclk div64 to ahbclk */
  CRM_AHB_DIV_128                        = 0x0D, /*!< sclk div128 to ahbclk */
  CRM_AHB_DIV_256                        = 0x0E, /*!< sclk div256 to ahbclk */
  CRM_AHB_DIV_512                        = 0x0F  /*!< sclk div512 to ahbclk */
} crm_ahb_div_type;

/**
  * @brief crm apb division
  */
typedef enum
{
  CRM_APB_DIV_1                         = 0x00, /*!< ahbclk div1 to apb1clk */
  CRM_APB_DIV_2                         = 0x04, /*!< ahbclk div2 to apb1clk */
  CRM_APB_DIV_4                         = 0x05, /*!< ahbclk div4 to apb1clk */
  CRM_APB_DIV_8                         = 0x06, /*!< ahbclk div8 to apb1clk */
  CRM_APB_DIV_16                        = 0x07  /*!< ahbclk div16 to apb1clk */
} crm_apb_div_type;


/**
  * @brief crm adc division
  */
typedef enum
{
  CRM_ADC_DIV_2                          = 0x00, /*!< apb2clk div2 to adcclk */
  CRM_ADC_DIV_4                          = 0x01, /*!< apb2clk div4 to adcclk */
  CRM_ADC_DIV_6                          = 0x02, /*!< apb2clk div6 to adcclk */
  CRM_ADC_DIV_8                          = 0x03, /*!< apb2clk div8 to adcclk */
  CRM_ADC_DIV_12                         = 0x05, /*!< apb2clk div12 to adcclk */
  CRM_ADC_DIV_16                         = 0x07  /*!< apb2clk div16 to adcclk */
} crm_adc_div_type;

/**
  * @brief crm ertc clock
  */
typedef enum
{
  CRM_ERTC_CLOCK_NOCLK                   = 0x00, /*!< no clock as ertc clock source */
  CRM_ERTC_CLOCK_LEXT                    = 0x01, /*!< low speed external crystal as ertc clock source */
  CRM_ERTC_CLOCK_LICK                    = 0x02, /*!< low speed internal clock as ertc clock source */
  CRM_ERTC_CLOCK_HEXT_DIV                = 0x03  /*!< high speed external crystal div as ertc clock source */
} crm_ertc_clock_type;

/**
  * @brief crm hick 48mhz division
  */
typedef enum
{
  CRM_HICK48_DIV6                        = 0x00, /*!< high speed internal clock (48 mhz) div6 */
  CRM_HICK48_NODIV                       = 0x01  /*!< high speed internal clock (48 mhz) no div */
} crm_hick_div_6_type;

/**
  * @brief crm sclk select
  */
typedef enum
{
  CRM_SCLK_HICK                          = 0x00, /*!< select high speed internal clock as sclk */
  CRM_SCLK_HEXT                          = 0x01, /*!< select high speed external crystal as sclk */
  CRM_SCLK_PLL                           = 0x02  /*!< select phase locking loop clock as sclk */
} crm_sclk_type;

/**
  * @brief crm clkout select
  */
typedef enum
{
  CRM_CLKOUT_NOCLK                       = 0x00, /*!< output no clock to clkout pin */
  CRM_CLKOUT_LICK                        = 0x02, /*!< output low speed internal clock to clkout pin */
  CRM_CLKOUT_LEXT                        = 0x03, /*!< output low speed external crystal to clkout pin */
  CRM_CLKOUT_SCLK                        = 0x04, /*!< output system clock to clkout pin */
  CRM_CLKOUT_HICK                        = 0x05, /*!< output high speed internal clock to clkout pin */
  CRM_CLKOUT_HEXT                        = 0x06, /*!< output high speed external crystal to clkout pin */
  CRM_CLKOUT_PLL_DIV_2                   = 0x07, /*!< output phase locking loop clock div2 to clkout pin */
  CRM_CLKOUT_PLL_DIV_4                   = 0x0C, /*!< output phase locking loop clock div4 to clkout pin */
  CRM_CLKOUT_ADC                         = 0x0E  /*!< output adcclk to clkout pin */
} crm_clkout_select_type;

/**
  * @brief crm clkout division
  */
typedef enum
{
  CRM_CLKOUT_DIV_1                       = 0x00, /*!< clkout div1 */
  CRM_CLKOUT_DIV_2                       = 0x08, /*!< clkout div2 */
  CRM_CLKOUT_DIV_4                       = 0x09, /*!< clkout div4 */
  CRM_CLKOUT_DIV_8                       = 0x0A, /*!< clkout div8 */
  CRM_CLKOUT_DIV_16                      = 0x0B, /*!< clkout div16 */
  CRM_CLKOUT_DIV_64                      = 0x0C, /*!< clkout div64 */
  CRM_CLKOUT_DIV_128                     = 0x0D, /*!< clkout div128 */
  CRM_CLKOUT_DIV_256                     = 0x0E, /*!< clkout div256 */
  CRM_CLKOUT_DIV_512                     = 0x0F  /*!< clkout div512 */
} crm_clkout_div_type;

/**
  * @brief crm auto step mode
  */
typedef enum
{
  CRM_AUTO_STEP_MODE_DISABLE             = 0x00, /*!< disable auto step mode */
  CRM_AUTO_STEP_MODE_ENABLE              = 0x03  /*!< enable auto step mode */
} crm_auto_step_mode_type;

/**
  * @brief crm hick as system clock frequency select
  */
typedef enum
{
  CRM_HICK_SCLK_8MHZ                     = 0x00, /*!< fixed 8 mhz when hick is selected as sclk */
  CRM_HICK_SCLK_48MHZ                    = 0x01  /*!< 8 mhz or 48 mhz depend on hickdiv when hick is selected as sclk */
} crm_hick_sclk_frequency_type;

/**
  * @brief crm clocks freqency structure
  */
typedef struct
{
  uint32_t sclk_freq; /*!< system clock frequency */
  uint32_t ahb_freq;  /*!< ahb bus clock frequency */
  uint32_t apb2_freq; /*!< apb2 bus clock frequency */
  uint32_t apb1_freq; /*!< apb1 bus clock frequency */
  uint32_t adc_freq;  /*!< adc clock frequency */
} crm_clocks_freq_type;

/**
  * @brief type define crm register all
  */
typedef struct
{
  /**
    * @brief crm ctrl register, offset:0x00
    */
    __IO uint32_t ctrl;

  /**
    * @brief crm cfg register, offset:0x04
    */
    __IO uint32_t cfg;
  /**
    * @brief crm clkint register, offset:0x08
    */
    __IO uint32_t clkint;
  /**
    * @brief crm apb2rst register, offset:0x0C
    */
    __IO uint32_t apb2rst;
  /**
    * @brief crm apb1rst register, offset:0x10
    */
    __IO uint32_t apb1rst;
  /**
    * @brief crm ahben register, offset:0x14
    */
    __IO uint32_t ahben;
  /**
    * @brief crm apb2en register, offset:0x18
    */
    __IO uint32_t apb2en;
  /**
    * @brief crm apb1en register, offset:0x1C
    */
    __IO uint32_t apb1en;
  /**
    * @brief crm bpdc register, offset:0x20
    */
    __IO uint32_t bpdc;
  /**
    * @brief crm ctrlsts register, offset:0x24
    */
    __IO uint32_t ctrlsts;
  /**
    * @brief crm ahbrst register, offset:0x28
    */
    __IO uint32_t ahbrst;
  /**
    * @brief crm pll register, offset:0x2C
    */
    __IO uint32_t pll;
  /**
    * @brief crm misc1 register, offset:0x30
    */
    __IO uint32_t misc1;
  /**
    * @brief crm reserved2 register, offset:0x50~0x34
    */
    __IO uint32_t reserved2[8];
  /**
    * @brief crm misc2 register, offset:0x54
    */
    __IO uint32_t misc2;
} crm_type;


#ifdef CLK_SCFGCMPRST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2RST_0                   (1<<0)
#else
#define CRM_APB2RST_0                   0
#endif
#ifdef CLK_EXINTRST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2RST_1                   (1<<1)
#else
#define CRM_APB2RST_1                   0
#endif
#ifdef CLK_ADCRST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2RST_9                   (1<<9)
#else
#define CRM_APB2RST_9                   0
#endif
#ifdef CLK_TMR1RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2RST_11                  (1<<11)
#else
#define CRM_APB2RST_11                  0
#endif
#ifdef CLK_SPI1RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2RST_12                  (1<<12)
#else
#define CRM_APB2RST_12                  0
#endif
#ifdef CLK_USART1RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2RST_14                  (1<<14)
#else
#define CRM_APB2RST_14                  0
#endif
#ifdef CLK_TMR15RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2RST_16                  (1<<16)
#else
#define CRM_APB2RST_16                  0
#endif
#ifdef CLK_TMR16RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2RST_17                  (1<<17)
#else
#define CRM_APB2RST_17                  0
#endif
#ifdef CLK_TMR17RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2RST_18                  (1<<18)
#else
#define CRM_APB2RST_18                  0
#endif
#ifdef _VALUABLE
#define CRM_APB2RST_VALUE ( CRM_APB2RST_0 |\
 CRM_APB2RST_1 |\
 CRM_APB2RST_9 |\
 CRM_APB2RST_11 |\
 CRM_APB2RST_12 |\
 CRM_APB2RST_14 |\
 CRM_APB2RST_16 |\
 CRM_APB2RST_17 |\
 CRM_APB2RST_18)
#undef _VALUABLE
#endif

#ifdef CLK_TMR3RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1RST_1                   (1<<1)
#else
#define CRM_APB1RST_1                   0
#endif
#ifdef CLK_TMR6RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1RST_4                   (1<<4)
#else
#define CRM_APB1RST_4                   0
#endif
#ifdef CLK_TMR14RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1RST_8                   (1<<8)
#else
#define CRM_APB1RST_8                   0
#endif
#ifdef CLK_WWDTRST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1RST_11                  (1<<11)
#else
#define CRM_APB1RST_11                  0
#endif
#ifdef CLK_SPI2RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1RST_14                  (1<<14)
#else
#define CRM_APB1RST_14                  0
#endif
#ifdef CLK_USART2RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1RST_17                  (1<<17)
#else
#define CRM_APB1RST_17                  0
#endif
#ifdef CLK_I2C1RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1RST_21                  (1<<21)
#else
#define CRM_APB1RST_21                  0
#endif
#ifdef CLK_I2C2RST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1RST_22                  (1<<22)
#else
#define CRM_APB1RST_22                  0
#endif
#ifdef CLK_PWCRST
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1RST_28                  (1<<28)
#else
#define CRM_APB1RST_28                  0
#endif
#ifdef _VALUABLE
#define CRM_APB1RST_VALUE ( CRM_APB1RST_1 |\
 CRM_APB1RST_4 |\
 CRM_APB1RST_8 |\
 CRM_APB1RST_11 |\
 CRM_APB1RST_14 |\
 CRM_APB1RST_17 |\
 CRM_APB1RST_21 |\
 CRM_APB1RST_22 |\
 CRM_APB1RST_28)
#undef _VALUABLE
#endif

#ifdef CLK_DAM1EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_AHBEN_0                     (1<<0)
#else
#define CRM_AHBEN_0                     0
#endif
#ifdef CLK_SRAMEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_AHBEN_2                     (1<<2)
#else
#define CRM_AHBEN_2                     0
#endif
#ifdef CLK_FLASHEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_AHBEN_4                     (1<<4)
#else
#define CRM_AHBEN_4                     0
#endif
#ifdef CLK_CRCEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_AHBEN_6                     (1<<6)
#else
#define CRM_AHBEN_6                     0
#endif
#ifdef CLK_GPIOAEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_AHBEN_17                    (1<<17)
#else
#define CRM_AHBEN_17                    0
#endif
#ifdef CLK_GPIOBEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_AHBEN_18                    (1<<18)
#else
#define CRM_AHBEN_18                    0
#endif
#ifdef CLK_GPIOCEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_AHBEN_19                    (1<<19)
#else
#define CRM_AHBEN_19                    0
#endif
#ifdef CLK_GPIOFEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_AHBEN_22                    (1<<22)
#else
#define CRM_AHBEN_22                    0
#endif
#ifdef _VALUABLE
#define CRM_AHBEN_VALUE ( CRM_AHBEN_0 |\
 CRM_AHBEN_2 |\
 CRM_AHBEN_4 |\
 CRM_AHBEN_6 |\
 CRM_AHBEN_17 |\
 CRM_AHBEN_18 |\
 CRM_AHBEN_19 |\
 CRM_AHBEN_22)
#undef _VALUABLE
#endif

#ifdef CLK_SCFGCMPEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2EN_0                    (1<<0)
#else
#define CRM_APB2EN_0                    0
#endif
#ifdef CLK_ADC1EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2EN_9                    (1<<9)
#else
#define CRM_APB2EN_9                    0
#endif
#ifdef CLK_TMR1EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2EN_11                   (1<<11)
#else
#define CRM_APB2EN_11                   0
#endif
#ifdef CLK_SPI1EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2EN_12                   (1<<12)
#else
#define CRM_APB2EN_12                   0
#endif
#ifdef CLK_USART1EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2EN_14                   (1<<14)
#else
#define CRM_APB2EN_14                   0
#endif
#ifdef CLK_TMR15EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2EN_16                   (1<<16)
#else
#define CRM_APB2EN_16                   0
#endif
#ifdef CLK_TMR16EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2EN_17                   (1<<17)
#else
#define CRM_APB2EN_17                   0
#endif
#ifdef CLK_TMR17EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB2EN_18                   (1<<18)
#else
#define CRM_APB2EN_18                   0
#endif
#ifdef _VALUABLE
#define CRM_APB2EN_VALUE ( CRM_APB2EN_0 |\
 CRM_APB2EN_9 |\
 CRM_APB2EN_11 |\
 CRM_APB2EN_12 |\
 CRM_APB2EN_14 |\
 CRM_APB2EN_16 |\
 CRM_APB2EN_17 |\
 CRM_APB2EN_18)
#undef _VALUABLE
#endif

#ifdef CLK_TMR3EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1EN_1                    (1<<1)
#else
#define CRM_APB1EN_1                    0
#endif
#ifdef CLK_TMR6EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1EN_4                    (1<<4)
#else
#define CRM_APB1EN_4                    0
#endif
#ifdef CLK_TMR14EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1EN_8                    (1<<8)
#else
#define CRM_APB1EN_8                    0
#endif
#ifdef CLK_WWDTEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1EN_11                   (1<<11)
#else
#define CRM_APB1EN_11                   0
#endif
#ifdef CLK_SPI2EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1EN_14                   (1<<14)
#else
#define CRM_APB1EN_14                   0
#endif
#ifdef CLK_USART2EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1EN_17                   (1<<17)
#else
#define CRM_APB1EN_17                   0
#endif
#ifdef CLK_I2C1EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1EN_21                   (1<<21)
#else
#define CRM_APB1EN_21                   0
#endif
#ifdef CLK_I2C2EN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1EN_22                   (1<<22)
#else
#define CRM_APB1EN_22                   0
#endif
#ifdef CLK_PWCEN
#ifndef _VALUABLE
#define _VALUABLE 1
#endif
#define CRM_APB1EN_28                   (1<<28)
#else
#define CRM_APB1EN_28                   0
#endif
#ifdef _VALUABLE
#define CRM_APB1EN_VALUE ( CRM_APB1EN_1 |\
 CRM_APB1EN_4 |\
 CRM_APB1EN_8 |\
 CRM_APB1EN_11 |\
 CRM_APB1EN_14 |\
 CRM_APB1EN_17 |\
 CRM_APB1EN_21 |\
 CRM_APB1EN_22 |\
 CRM_APB1EN_28)
#undef _VALUABLE
#endif
// use it when target fequence higher than 108Mhz
#define CRM_MISC2_AUTO_STEP_EN_ON          0b110000

#define CRM                              ((crm_type *) CRM_BASE)

#if 0

void crm_reset(void);
void crm_lext_bypass(confirm_state new_state);
void crm_hext_bypass(confirm_state new_state);
flag_status crm_flag_get(uint32_t flag);
flag_status crm_interrupt_flag_get(uint32_t flag);
error_status crm_hext_stable_wait(void);
void crm_hick_clock_trimming_set(uint8_t trim_value);
void crm_hick_clock_calibration_set(uint8_t cali_value);
void crm_periph_clock_enable(crm_periph_clock_type value, confirm_state new_state);
void crm_periph_reset(crm_periph_reset_type value, confirm_state new_state);
void crm_periph_sleep_mode_clock_enable(crm_periph_clock_sleepmd_type value, confirm_state new_state);
void crm_clock_source_enable(crm_clock_source_type source, confirm_state new_state);
void crm_flag_clear(uint32_t flag);
void crm_ertc_clock_select(crm_ertc_clock_type value);
void crm_ertc_clock_enable(confirm_state new_state);
void crm_ahb_div_set(crm_ahb_div_type value);
void crm_apb1_div_set(crm_apb1_div_type value);
void crm_apb2_div_set(crm_apb2_div_type value);
void crm_adc_clock_div_set(crm_adc_div_type div_value);
void crm_clock_failure_detection_enable(confirm_state new_state);
void crm_battery_powered_domain_reset(confirm_state new_state);
void crm_pll_config(crm_pll_clock_source_type clock_source, crm_pll_mult_type mult_value);
void crm_pll_config2(crm_pll_clock_source_type clock_source, uint16_t pll_ns, uint16_t pll_ms, crm_pll_fr_type pll_fr);
void crm_sysclk_switch(crm_sclk_type value);
crm_sclk_type crm_sysclk_switch_status_get(void);
void crm_clocks_freq_get(crm_clocks_freq_type *clocks_struct);
void crm_clock_out_set(crm_clkout_select_type clkout);
void crm_interrupt_enable(uint32_t crm_int, confirm_state new_state);
void crm_auto_step_mode_enable(confirm_state new_state);
void crm_hick_divider_select(crm_hick_div_6_type value);
void crm_hick_sclk_frequency_select(crm_hick_sclk_frequency_type value);
void crm_clkout_div_set(crm_clkout_div_type clkout_div);


 #endif



#ifdef __cplusplus
}
#endif

#endif
