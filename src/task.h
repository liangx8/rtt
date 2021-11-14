#ifndef TASK_H_JFKE234JKD
#define TASK_H_JFKE234JKD
#include <stdint.h>
typedef struct
{
  volatile uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  volatile uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  uint32_t unused1;                         /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  uint32_t unused2;                         /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  uint32_t unused3;                         /*!< Offset: 0x010 (R/W)  System Control Register */
  uint32_t unused4;                         /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  uint32_t SHP_PRI4_6;                      /*!< Offset: 0x0018 Pri 4 ~ 6*/
  uint8_t  unused5[3];                      /*!< Offset: 0x001C*/
  volatile uint8_t  SHP_PRI_11;             /*pri 11*/
  uint16_t unused6;                         /*!< Offset: 0x0020*/
  volatile uint8_t  SHP_PRI_14;
} portSCB_Type;

#define portSCB     ( (volatile portSCB_Type * ) 0xe000ed00 )


typedef int stack_t;
/*Task control block*/
stack_t* task_stack_init(void *func,void *arguments,stack_t *stack_top);
void rtt_init(void);

#define tyield() portSCB->ICSR= (1 << 28)
#define myield() __asm volatile ("svc #100")


#endif
