# CRM
## CFG
  CLKOUT_SEL 选择内部时钟输出到CLKOUT pin
## 设置120主频
  1. 内部时钟，PLL时钟源使用HICK4M和30 PLL倍频
  1. 外部时钟，PLL时钟源使用HEXT或者２分频的HEXT,
  1. PLL时钟源以及倍频设置必须在PLL使能前完成
  1. PLL倍频设置中，14和15倍频之间有一个数值跳极
  1. FLASH读周期需要设置位相应的值到寄存器FLASH->psr，以适应高主频