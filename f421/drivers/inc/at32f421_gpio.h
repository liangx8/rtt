/**
  **************************************************************************
  * @file     at32f421_gpio.h
  * @brief    at32f421 gpio header file
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

/**
  porta iomux table
  --------------------------------------------------------------------------------------------------------------------------------
  pin name     |    mux0     |    mux1     |     mux2     |    mux3     |    mux4      |   mux5      |    mux6      |   mux7       |
  --------------------------------------------------------------------------------------------------------------------------------
  pa0           |             |  usart2_cts |             |             |  i2c2_scl    |  tmr1_etr    |             |  comp_out    |
  --------------------------------------------------------------------------------------------------------------------------------
  pa1           |  eventout   |  usart2_rts |             |             |  i2c2_sda    |  tmr15_ch1c |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa2           |  tmr15_ch1   |  usart2_tx   |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa3           |  tmr15_ch2   |  usart2_rx   |             |             |              |  i2s2_mck   |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa4           |  spi1_nss   |  usart2_ck   |             |             |  tmr14_ch1    |             |             |              |
               |  i2s1_ws     |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa5           |  spi1_sck   |             |             |             |              |             |             |              |
               |  i2s1_ck     |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa6           |  spi1_miso  |  tmr3_ch1   |  tmr1_bkin  | i2s2_mck    |              |  tmr16_ch1  |  eventout   |  comp_out    |
               |  i2s1_mck   |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa7           |  spi1_mosi  |  tmr3_ch2   |  tmr1_ch1c   |             |  tmr14_ch1    |  tmr17_ch1  |  eventout    |              |
               |  i2s1_sd    |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa8           |  clkout     |  usart1_ck   |  tmr1_ch1   |   eventout   |  usart2_tx    |             |             |  i2c2_scl    |
  --------------------------------------------------------------------------------------------------------------------------------
  pa9           | tmr15_bkin   |  usart1_tx  |   tmr1_ch2   |             |  i2c1_scl    |  clkout      |             |  i2c2_smba   |
  --------------------------------------------------------------------------------------------------------------------------------
  pa10         | tmr17_bkin  |  usart1_rx  |  tmr1_ch3   |             |  i2c1_sda    |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa11         | eventout     | usart1_cts   |  tmr1_ch4   |             |  i2c1_smba   |  i2c2_scl    |             |  comp_out    |
  ----------------------------- --------------------------------------------------------------------------------------------------
  pa12         | eventout     |  usart1_rts |  tmr1_etr   |             |              |  i2c2_sda    |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa13         | swdio       |  ir_out     |              |             |              |             |   spi2_miso |              |
               |             |             |             |             |              |             |   i2s2_mck  |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa14         | swclk       |  usart2_tx   |            |              |              |             |   spi2_mosi |              |
               |             |             |            |              |              |             |   i2s2_sd   |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pa15         | spi1_nss    |  usart2_rx   |            |              |              |             |   spi2_nss  |              |
               | i2s1_ws     |             |            |  eventout    |              |             |   i2s2_ws   |              |
  --------------------------------------------------------------------------------------------------------------------------------
  */

/**
  portb iomux table
  --------------------------------------------------------------------------------------------------------------------------------
  pin name     |    mux0     |    mux1     |     mux2     |    mux3     |    mux4      |   mux5      |    mux6      |   mux7       |
  --------------------------------------------------------------------------------------------------------------------------------
  pb0           |   eventout   |   tmr3_ch3   |   tmr1_ch2c |  usart2_rx   |              |             |  i2s1_mck    |               |
  --------------------------------------------------------------------------------------------------------------------------------
  pb1           |   tmr14_ch1 |   tmr3_ch4   |   tmr1_ch3c |             |              |             |  spi2_sck   |              |
               |             |             |             |             |              |             |  i2s2_ck    |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb2           |             |             |   tmr3_etr  |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb3           |   spi1_sck  |   eventout   |             |             |              |             |  spi2_sck   |              |
               |   i2s1_ck   |             |             |             |              |             |  i2s2_ck    |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb4           |   spi1_miso |   tmr3_ch1   |   eventout  |             |              | tmr17_bkin  |  spi2_miso  |  i2c2_sda    |
               |   i2s1_mck  |             |             |             |              |             |  spi2_mck    |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb5          |   spi1_mosi |   tmr3_ch2  |  tmr16_bkin | i2c1_smba   |              |             |  spi2_mosi  |              |
               |   i2s1_sd   |             |             |             |              |             |  i2s2_sd    |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb6          |   usart1_tx |   i2c1_scl  |  tmr16_ch1c |             |              |             |  i2s1_mck   |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb7          |   usart1_rx |   i2c1_sda  |  tmr17_ch1c |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb8          |             |   i2c1_scl  |  tmr16_ch1  |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb9          |   ir_out    |   i2c1_sda  |  tmr17_ch1  |  eventout   |              |             |  i2s1_mck   |   spi2_nss   |
               |             |             |             |             |              |             |             |   i2s2_ws    |
  --------------------------------------------------------------------------------------------------------------------------------
  pb10         |             |   i2c2_scl  |             |             |              |             |             |   spi2_sck   |
               |             |             |             |             |              |             |             |   i2s2_ck    |
  --------------------------------------------------------------------------------------------------------------------------------
  pb11         |   eventout  |   i2c2_sda  |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb12         |   spi2_nss  |   eventout  |  tmr1_bkin  |             |              |  tmr15_bkin |             |   i2c2_smba  |
               |   i2s2_ws   |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb13         |   spi2_sck  |             |  tmr1_ch1c  |             |              |  i2c2_scl   |             |              |
               |   i2s2_ck   |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb14         |   spi2_miso |  tmr15_ch1  |  tmr1_ch2c  |             |              |  i2c2_sda   |             |              |
               |   i2s2_mck  |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pb15         |   spi2_mosi |  tmr15_ch2  |  tmr1_ch3c  | tmr15_ch1c  |              |             |             |              |
               |   i2s2_sd   |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
*/

/**
  portf iomux table
  --------------------------------------------------------------------------------------------------------------------------------
  pin name     |    mux0     |    mux1     |     mux2     |    mux3     |    mux4      |   mux5      |    mux6      |   mux7       |
  --------------------------------------------------------------------------------------------------------------------------------
  pf0          |             |   i2c1_sda  |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pf0          |             |   i2c1_scl  |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pf6          |  i2c2_scl   |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
  pf7          |  i2c2_sda   |             |             |             |              |             |             |              |
  --------------------------------------------------------------------------------------------------------------------------------
*/


/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32F421_GPIO_H
#define __AT32F421_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif


/* includes ------------------------------------------------------------------*/
#include "at32f421.h"

/** @addtogroup AT32F421_periph_driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */

/** @defgroup GPIO_pins_number_definition
  * @{
  */

#define GPIO_PINS_0                      0x0001 /*!< gpio pins number 0 */
#define GPIO_PINS_1                      0x0002 /*!< gpio pins number 1 */
#define GPIO_PINS_2                      0x0004 /*!< gpio pins number 2 */
#define GPIO_PINS_3                      0x0008 /*!< gpio pins number 3 */
#define GPIO_PINS_4                      0x0010 /*!< gpio pins number 4 */
#define GPIO_PINS_5                      0x0020 /*!< gpio pins number 5 */
#define GPIO_PINS_6                      0x0040 /*!< gpio pins number 6 */
#define GPIO_PINS_7                      0x0080 /*!< gpio pins number 7 */
#define GPIO_PINS_8                      0x0100 /*!< gpio pins number 8 */
#define GPIO_PINS_9                      0x0200 /*!< gpio pins number 9 */
#define GPIO_PINS_10                     0x0400 /*!< gpio pins number 10 */
#define GPIO_PINS_11                     0x0800 /*!< gpio pins number 11 */
#define GPIO_PINS_12                     0x1000 /*!< gpio pins number 12 */
#define GPIO_PINS_13                     0x2000 /*!< gpio pins number 13 */
#define GPIO_PINS_14                     0x4000 /*!< gpio pins number 14 */
#define GPIO_PINS_15                     0x8000 /*!< gpio pins number 15 */
#define GPIO_PINS_ALL                    0xFFFF /*!< gpio all pins */

/**
  * @}
  */

/** @defgroup GPIO_exported_types
  * @{
  */

/**
  * @brief gpio mode select
  */
typedef enum
{
  GPIO_MODE_INPUT                        = 0x00, /*!< gpio input mode */
  GPIO_MODE_OUTPUT                       = 0x01, /*!< gpio output mode */
  GPIO_MODE_MUX                          = 0x02, /*!< gpio mux function mode */
  GPIO_MODE_ANALOG                       = 0x03  /*!< gpio analog in/out mode */
} gpio_mode_type;

/**
  * @brief gpio output drive strength select
  */
typedef enum
{
  GPIO_DRIVE_STRENGTH_STRONGER           = 0x01, /*!< stronger sourcing/sinking strength */
  GPIO_DRIVE_STRENGTH_MODERATE           = 0x02  /*!< moderate sourcing/sinking strength */
} gpio_drive_type;

/**
  * @brief gpio output type
  */
typedef enum
{
  GPIO_OUTPUT_PUSH_PULL                  = 0x00, /*!< output push-pull */
  GPIO_OUTPUT_OPEN_DRAIN                 = 0x01  /*!< output open-drain */
} gpio_output_type;

/**
  * @brief gpio pull type
  */
typedef enum
{
  GPIO_PULL_NONE                         = 0x00, /*!< floating for input, no pull for output */
  GPIO_PULL_UP                           = 0x01, /*!< pull-up */
  GPIO_PULL_DOWN                         = 0x02  /*!< pull-down */
} gpio_pull_type;

/**
  * @brief gpio init type
  */
typedef struct
{
  uint32_t                               gpio_pins;            /*!< pins number selection */
  gpio_output_type                       gpio_out_type;        /*!< output type selection */
  gpio_pull_type                         gpio_pull;            /*!< pull type selection */
  gpio_mode_type                         gpio_mode;            /*!< mode selection */
  gpio_drive_type                        gpio_drive_strength;  /*!< drive strength selection */
} gpio_init_type;

/**
  * @brief gpio pins source type
  */
typedef enum
{
  GPIO_PINS_SOURCE0                      = 0x00, /*!< gpio pins source number 0 */
  GPIO_PINS_SOURCE1                      = 0x01, /*!< gpio pins source number 1 */
  GPIO_PINS_SOURCE2                      = 0x02, /*!< gpio pins source number 2 */
  GPIO_PINS_SOURCE3                      = 0x03, /*!< gpio pins source number 3 */
  GPIO_PINS_SOURCE4                      = 0x04, /*!< gpio pins source number 4 */
  GPIO_PINS_SOURCE5                      = 0x05, /*!< gpio pins source number 5 */
  GPIO_PINS_SOURCE6                      = 0x06, /*!< gpio pins source number 6 */
  GPIO_PINS_SOURCE7                      = 0x07, /*!< gpio pins source number 7 */
  GPIO_PINS_SOURCE8                      = 0x08, /*!< gpio pins source number 8 */
  GPIO_PINS_SOURCE9                      = 0x09, /*!< gpio pins source number 9 */
  GPIO_PINS_SOURCE10                     = 0x0A, /*!< gpio pins source number 10 */
  GPIO_PINS_SOURCE11                     = 0x0B, /*!< gpio pins source number 11 */
  GPIO_PINS_SOURCE12                     = 0x0C, /*!< gpio pins source number 12 */
  GPIO_PINS_SOURCE13                     = 0x0D, /*!< gpio pins source number 13 */
  GPIO_PINS_SOURCE14                     = 0x0E, /*!< gpio pins source number 14 */
  GPIO_PINS_SOURCE15                     = 0x0F  /*!< gpio pins source number 15 */
} gpio_pins_source_type;

/**
  * @brief  gpio muxing function selection type
  */
typedef enum
{
  GPIO_MUX_0                             = 0x00, /*!< gpio muxing function selection 0 */
  GPIO_MUX_1                             = 0x01, /*!< gpio muxing function selection 1 */
  GPIO_MUX_2                             = 0x02, /*!< gpio muxing function selection 2 */
  GPIO_MUX_3                             = 0x03, /*!< gpio muxing function selection 3 */
  GPIO_MUX_4                             = 0x04, /*!< gpio muxing function selection 4 */
  GPIO_MUX_5                             = 0x05, /*!< gpio muxing function selection 5 */
  GPIO_MUX_6                             = 0x06, /*!< gpio muxing function selection 6 */
  GPIO_MUX_7                             = 0x07, /*!< gpio muxing function selection 7 */
} gpio_mux_sel_type;

/**
  * @brief type define gpio register all
  */
typedef struct
{
  /**
    * @brief gpio mode register, offset:0x00
    */
    __IO uint32_t cfgr;
  /**
    * @brief gpio output type register, offset:0x04
    */
    __IO uint32_t omode;
  /**
    * @brief gpio output driver register, offset:0x08
    */
    __IO uint32_t odrvr;
  /**
    * @brief gpio pull up/down register, offset:0x0C
    */
    __IO uint32_t pull;
  /**
    * @brief gpio input data register, offset:0x10
    */
    __IO uint32_t idt;
  /**
    * @brief gpio output data register, offset:0x14
    */
    __IO uint32_t odt;
  /**
    * @brief gpio scr register, offset:0x18
    */
    __IO uint32_t scr;
  /**
    * @brief gpio wpr register, offset:0x1C
    */
    __IO uint32_t wpr;
  /**
    * @brief gpio muxl register, offset:0x20
    */
    __IO uint32_t muxl;
  /**
    * @brief gpio muxh register, offset:0x24
    */
    __IO uint32_t muxh;
  /**
    * @brief gpio clr register, offset:0x28
    */
    __IO uint32_t clr;
  /**
    * @brief gpio reserved1 register, offset:0x2C~0x38
    */
    __IO uint32_t reserved1[4];
  /**
    * @brief gpio hdrv register, offset:0x3C
    */
    __IO uint32_t hdrv;
} gpio_type;

#define GPIOA                            ((gpio_type *) GPIOA_BASE)
#define GPIOB                            ((gpio_type *) GPIOB_BASE)
#define GPIOC                            ((gpio_type *) GPIOC_BASE)
#define GPIOF                            ((gpio_type *) GPIOF_BASE)

#if 0
/** @defgroup GPIO_exported_functions
  * @{
  */
void gpio_reset(gpio_type *gpio_x);
void gpio_init(gpio_type *gpio_x, gpio_init_type *gpio_init_struct);
void gpio_default_para_init(gpio_init_type *gpio_init_struct);
flag_status gpio_input_data_bit_read(gpio_type *gpio_x, uint16_t pins);
uint16_t gpio_input_data_read(gpio_type *gpio_x);
flag_status gpio_output_data_bit_read(gpio_type *gpio_x, uint16_t pins);
uint16_t gpio_output_data_read(gpio_type *gpio_x);
void gpio_bits_set(gpio_type *gpio_x, uint16_t pins);
void gpio_bits_reset(gpio_type *gpio_x, uint16_t pins);
void gpio_bits_write(gpio_type *gpio_x, uint16_t pins, confirm_state bit_state);
void gpio_port_write(gpio_type *gpio_x, uint16_t port_value);
void gpio_pin_wp_config(gpio_type *gpio_x, uint16_t pins);
void gpio_pins_huge_driven_config(gpio_type *gpio_x, uint16_t pins, confirm_state new_state);
void gpio_pin_mux_config(gpio_type *gpio_x, gpio_pins_source_type gpio_pin_source, gpio_mux_sel_type gpio_mux);
/**
  * @}
  */
#endif

#ifdef __cplusplus
}
#endif

#endif
