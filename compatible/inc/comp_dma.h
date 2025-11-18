#ifndef COMP_DMA_H_URY8ER734
#define COMP_DMA_H_URY8ER734
#include <stdint.h>
#include "comp_io.h"

typedef struct _comp_dma_channel_typedef{
    __IO uint32_t CCR;          /*!< DMA channel x configuration register        */
    __IO uint32_t CNDTR;        /*!< DMA channel x number of data register       */
    __IO uint32_t CPAR;         /*!< DMA channel x peripheral address register   */
    __IO uint32_t CMAR;         /*!< DMA channel x memory address register       */
    uint32_t reserved[16];
} COMP_DMA_CHANNEL_TypeDef;
typedef struct _comp_dma_typedef{
    __IO uint32_t ISR;          /*!< DMA interrupt status register,               Address offset: 0x00 */
    __IO uint32_t IFCR;         /*!< DMA interrupt flag clear register,           Address offset: 0x04 */
    COMP_DMA_CHANNEL_TypeDef  CH1;
    COMP_DMA_CHANNEL_TypeDef  CH2;
    COMP_DMA_CHANNEL_TypeDef  CH3;
    COMP_DMA_CHANNEL_TypeDef  CH4;
    COMP_DMA_CHANNEL_TypeDef  CH5;
    COMP_DMA_CHANNEL_TypeDef  CH6;
    COMP_DMA_CHANNEL_TypeDef  CH7;
} COMP_DMA_TypeDef;
#define DMA_ISR_GIF1_pos            0
#define DMA_ISR_TCIF1_pos           1
#define DMA_ISR_HTIF1_pos           2
#define DMA_ISR_TEIF1_pos           3
#define DMA_ISR_GIF2_pos            4
#define DMA_ISR_TCIF2_pos           5
#define DMA_ISR_HTIF2_pos           6
#define DMA_ISR_TEIF2_pos           7
#define DMA_ISR_GIF3_pos            8
#define DMA_ISR_TCIF3_pos           9
#define DMA_ISR_HTIF3_pos           10
#define DMA_ISR_TEIF3_pos           11
#define DMA_ISR_GIF4_pos            12
#define DMA_ISR_TCIF4_pos           13
#define DMA_ISR_HTIF4_pos           14
#define DMA_ISR_TEIF4_pos           15
#define DMA_ISR_GIF5_pos            16
#define DMA_ISR_TCIF5_pos           17
#define DMA_ISR_HTIF5_pos           18
#define DMA_ISR_TEIF5_pos           19
#define DMA_ISR_GIF6_pos            20
#define DMA_ISR_TCIF6_pos           21
#define DMA_ISR_HTIF6_pos           22
#define DMA_ISR_TEIF6_pos           23
#define DMA_ISR_GIF7_pos            24
#define DMA_ISR_TCIF7_pos           25
#define DMA_ISR_HTIF7_pos           26
#define DMA_ISR_TEIF7_pos           27
#define DMA_IFCR_CGIF1_pos          0
#define DMA_IFCR_CTCIF1_pos         1
#define DMA_IFCR_CHTIF1_pos         2
#define DMA_IFCR_CTEIF1_pos         3
#define DMA_IFCR_CGIF2_pos          4
#define DMA_IFCR_CTCIF2_pos         5
#define DMA_IFCR_CHTIF2_pos         6
#define DMA_IFCR_CTEIF2_pos         7
#define DMA_IFCR_CGIF3_pos          8
#define DMA_IFCR_CTCIF3_pos         9
#define DMA_IFCR_CHTIF3_pos         10
#define DMA_IFCR_CTEIF3_pos         11
#define DMA_IFCR_CGIF4_pos          12
#define DMA_IFCR_CTCIF4_pos         13
#define DMA_IFCR_CHTIF4_pos         14
#define DMA_IFCR_CTEIF4_pos         15
#define DMA_IFCR_CGIF5_pos          16
#define DMA_IFCR_CTCIF5_pos         17
#define DMA_IFCR_CHTIF5_pos         18
#define DMA_IFCR_CTEIF5_pos         19
#define DMA_IFCR_CGIF6_pos          20
#define DMA_IFCR_CTCIF6_pos         21
#define DMA_IFCR_CHTIF6_pos         22
#define DMA_IFCR_CTEIF6_pos         23
#define DMA_IFCR_CGIF7_pos          24
#define DMA_IFCR_CTCIF7_pos         25
#define DMA_IFCR_CHTIF7_pos         26
#define DMA_IFCR_CTEIF7_pos         27

#define DMA_CHANNEL_CCR_MEM2MEM_pos 14
#define DMA_CHANNEL_CCR_PL_pos      12 
#define DMA_CHANNEL_CCR_MSIZE_pos   10 
#define DMA_CHANNEL_CCR_PSIZE_pos   8 
#define DMA_CHANNEL_CCR_MINC_pos    7
#define DMA_CHANNEL_CCR_PINC_pos    6
#define DMA_CHANNEL_CCR_CIRC_pos    5
#define DMA_CHANNEL_CCR_DIR_pos     4
#define DMA_CHANNEL_CCR_TEIE_pos    3
#define DMA_CHANNEL_CCR_HTIE_pos    2
#define DMA_CHANNEL_CCR_TCIE_pos    1
#define DMA_CHANNEL_CCR_EN_pos      0

#endif
