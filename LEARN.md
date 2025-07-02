# CRM
## CFG
  CLKOUT_SEL 选择内部时钟输出到CLKOUT pin
## 设置120主频
1. 内部时钟，PLL时钟源使用HICK4M和30 PLL倍频
1. 外部时钟，PLL时钟源使用HEXT或者２分频的HEXT,
1. PLL时钟源以及倍频设置必须在PLL使能前完成
1. PLL倍频设置中，14和15倍频之间有一个数值跳极
1. FLASH读周期需要设置位相应的值到寄存器FLASH->psr，以适应高主频
## 设置APB1/2设备的时钟源
  １分频时，直接使用设置的主频。如果是非１分频时，将会使用２倍主频。所以设置１分频和设置２分频结果是一样的
# 在线调试
  要使用官网下载的openocd,否则会提示找不到at32f421xx的驱动
# GPIO
## CFGR IOMCx (x=0~15)
- 00 输入(缺省值)
- 01 通用输出
- 10 复用功能
- 11 模拟
## OMODE OMx (15~31无意义，x=0~15)
- 0 推挽
- 1 开漏
## ODRVR ODRVy (y=0~15)
- x0 适中电流
- 01 较大电流
- 11 适中电流
## PULL PULLy (y=0~15)，如果是设置了IOMC=01,此寄存器无意义
- 00,11 无意义
- 01 上拉
- 10 下拉
## IDT 引脚电平值(31~16 无意义,15~0对应引脚)
## ODT 设置引脚电平(31~16 无意义,15~0对应引脚)
## SCR
- 31~16 1,对应引脚置低电平,0 无动作
    - 15~0  1,对应引脚置高电平,0 无动作
## WPR 引脚电平修改保护
- WPSEQ 16 写保护使能位操作按照以下方式操作4次，写'1'->写'0'->写'1'->读，操作期间 WPEN 位值不可修改。
- WPEN[15:0] 0无保护，1写保护
## IOMUX L/H 占４位选择复用功能
- ０～７选择MUX0~MUX7
## CLR (31~16 不用)
- 0 无动作
- 1 置低对应引脚电平
## HDRV

# TIMER
## TIMER1
### CMx (x=1,2)
    每8位定义一个通道
* CxOSEN [7] (Channel Output Switch enable) 必须设0
* CxOCTRL[6:4] (Channel Output Control)
    - 000 断开CxORAW到CxOUT的连接
    - 001 当CVAL == CxDT时CxORAW=1
    - 010 当CVAL == CxDT时CxORAW=0
    - 011 当CVAL == CxDT时 切换CxORAW
    - 100 CxORAW 低
    - 101 CxORAW 高
    - 110 PWMA
    - 111 PWMB
* CxOBEN[3] (Channel Output Buffer enable)
* CxOIEN[2] (Channel Output immediately enable)
* CxC[1:0](Channel Configure)
    - 00 输出
    - 01,10,11 输入设定
### CCTRL 1,2,3通道用4位，4通道用2位
* CxCP[3]  通道补端极性
* CxCEN[2] 通道补端使能
* CxP[1]   通道端极性
* CxEN[0]  通道端使能
### BRK 
* OEN[15]
* AONE[14]
* BRKV[13]
* BRKEN[12]
* FCSOEN[11]
* FCSODIS[10]
* WPC[9:8]
* DTC[7:0]