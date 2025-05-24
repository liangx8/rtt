#ifndef TASK_H_JFKE234JKD
#define TASK_H_JFKE234JKD
#include <stdint.h>
#include "conf.h"

#if 0
typedef struct
{
    volatile uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
    volatile uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
    uint32_t unused1;                         /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
    uint32_t unused2;                         /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
    uint32_t unused3;                         /*!< Offset: 0x010 (R/W)  System Control Register */
    uint32_t unused4;                         /*!< Offset: 0x014 (R/W)  Configuration Control Register */
    uint8_t SHP[12];                          /*!< Offset: 0x0018 Pri 4 ~ 6,7 ~9, 10~14*/
} portSCB_Type;

#define portSCB     ( (volatile portSCB_Type * ) 0xe000ed00 )
#else
#define portSCB SCB
#endif


typedef uint32_t stack_t;

typedef stack_t* stack_p;
/*Task control block*/
 struct rttTCB{
    stack_p top;
    // 此值为０时，当前进程会被调度进程分配运行时间,非０，调度进程会在每个节拍把这个值减１
    uint32_t counter;
};
void rtt_init(void);

#define tyield() portSCB->ICSR= (1 << 28)
#define myield() __asm volatile ("svc #0")




#endif
