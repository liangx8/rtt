#ifndef COMP_I2C_H_KDER9934JJ
#define  COMP_I2C_H_KDER9934JJ
#include <stdint.h>
#include "comp_io.h"
typedef struct _comp_i2c_typedef{
__IO uint32_t CR1;
__IO uint32_t CR2;
__IO uint32_t OAR1;
__IO uint32_t OAR2;
__IO uint32_t TIMINGR;
__IO uint32_t TIMEOUTR;
__IO uint32_t ISR;
__IO uint32_t ICR;
__IO uint32_t PECR;
__IO uint32_t RXDR;
__IO uint32_t TXDR;
} COMP_I2C_TypeDef;

#define I2C_CR1_PE_pos                    0
#define I2C_CR1_TXIE_pos                  1
#define I2C_CR1_RXIE_pos                  2
#define I2C_CR1_ADDRIE_pos                3
#define I2C_CR1_NACKIE_pos                4
#define I2C_CR1_STOPIE_pos                5
#define I2C_CR1_TCIE_pos                  6
#define I2C_CR1_ERRIE_pos                 7
#define I2C_CR1_DNF_pos                   8
#define I2C_CR1_ANFOFF_pos                12
#define I2C_CR1_TXDMAEN_pos               14
#define I2C_CR1_RXDMAEN_pos               15
#define I2C_CR1_SBC_pos                   16
#define I2C_CR1_NOSTRETCH_pos             17
#define I2C_CR1_WUPEN_pos                 18
#define I2C_CR1_GCEN_pos                  19
#define I2C_CR1_SMBHEN_pos                20
#define I2C_CR1_SMBDEN_pos                21
#define I2C_CR1_ALERTEN_pos               22
#define I2C_CR1_PECEN_pos                 23

#define I2C_CR2_SADD_pos                  0
#define I2C_CR2_RD_WRN_pos                10
#define I2C_CR2_ADD10_pos                 11
#define I2C_CR2_HEAD10R_pos               12
#define I2C_CR2_START_pos                 13
#define I2C_CR2_STOP_pos                  14
#define I2C_CR2_NACK_pos                  15
#define I2C_CR2_NBYTES_pos                16
#define I2C_CR2_RELOAD_pos                24
#define I2C_CR2_AUTOEND_pos               25
#define I2C_CR2_PECBYTE_pos               26
#define I2C_OAR1_OA1_pos                  0

#define I2C_OAR1_OA1MODE_pos              10
#define I2C_OAR1_OA1EN_pos                15
#define I2C_OAR2_OA2_pos                  1
#define I2C_OAR2_OA2MSK_pos               8
#define I2C_OAR2_OA2EN_pos                15

#define I2C_TIMIMGR_SCLL_pos              0
#define I2C_TIMIMGR_SCLH_pos              8
#define I2C_TIMIMGR_SDADEL_pos            16
#define I2C_TIMIMGR_SCLDEL_pos            20
#define I2C_TIMIMGR_PRESC_pos             28

#define I2C_TIMEOUTR_TIMEOUTA_pos         0
#define I2C_TIMEOUTR_TIDLE_pos            12
#define I2C_TIMEOUTR_TIMOUTEN_pos         15
#define I2C_TIMEOUTR_TIMEOUTB_pos         16
#define I2C_TIMEOUTR_TEXTEN_pos           31

#define I2C_ISR_TXE_pos                   0
#define I2C_ISR_TXIS_pos                  1
#define I2C_ISR_RXNE_pos                  2
#define I2C_ISR_ADDR_pos                  3
#define I2C_ISR_NACKF_pos                 4
#define I2C_ISR_STOPF_pos                 5
#define I2C_ISR_TC_pos                    6
#define I2C_ISR_TCR_pos                   7
#define I2C_ISR_BERR_pos                  8
#define I2C_ISR_ARLO_pos                  9
#define I2C_ISR_OVR_pos                   10
#define I2C_ISR_PECERR_pos                11
#define I2C_ISR_TIMEOUT_pos               12
#define I2C_ISR_ALERT_pos                 13
#define I2C_ISR_BUSY_pos                  15
#define I2C_ISR_DIR_pos                   16
#define I2C_ISR_ADDCODE_pos               17

#define I2C_ICR_Res_pos                   0
#define I2C_ICR_ADDRCF_pos                3
#define I2C_ICR_NACKCF_pos                4
#define I2C_ICR_STOPCF_pos                5
#define I2C_ICR_BERRCF_pos                8
#define I2C_ICR_ARLOCF_pos                9
#define I2C_ICR_OVRCF_pos                 10
#define I2C_ICR_PECCF_pos                 11
#define I2C_ICR_TIMOUTCF_pos              12
#define I2C_ICR_ALERTCF_pos               13
#endif