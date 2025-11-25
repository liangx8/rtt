#ifndef CONF_H_JDDUE88ER
#define CONF_H_JDDUE88ER
#include "mcu_conf.h"
#include "esc_test.h"
// max 232ms at 72000000
#define MS(ms) ((unsigned long)((unsigned long)CPUCLK * 1000UL) * ms)
#define TASK_NUM 2

#endif
