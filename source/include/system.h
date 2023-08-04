#include "stm32f303x8.h"
#include <stdint.h>
#include <stdlib.h>


void SystemInit(void);












/** PERIPHERALS ******************************************************************************************************************
// ADC1, ADC2
ISR                    // ADC Interrupt and Status Register,                 Address offset: 0x00 
IER                    // ADC Interrupt Enable Register,                     Address offset: 0x04 
CR                     // ADC control register,                              Address offset: 0x08 
CFGR                   // ADC Configuration register,                        Address offset: 0x0C 
RESERVED0              // Reserved, 0x010                                                         
SMPR1                  // ADC sample time register 1,                        Address offset: 0x14 
SMPR2                  // ADC sample time register 2,                        Address offset: 0x18 
RESERVED1              // Reserved, 0x01C                                                         
TR1                    // ADC watchdog threshold register 1,                 Address offset: 0x20 
TR2                    // ADC watchdog threshold register 2,                 Address offset: 0x24 
TR3                    // ADC watchdog threshold register 3,                 Address offset: 0x28 
RESERVED2              // Reserved, 0x02C                                                         
SQR1                   // ADC regular sequence register 1,                   Address offset: 0x30 
SQR2                   // ADC regular sequence register 2,                   Address offset: 0x34 
SQR3                   // ADC regular sequence register 3,                   Address offset: 0x38 
SQR4                   // ADC regular sequence register 4,                   Address offset: 0x3C 
DR                     // ADC regular data register,                         Address offset: 0x40 
RESERVED3              // Reserved, 0x044                                                         
RESERVED4              // Reserved, 0x048                                                         
JSQR                   // ADC injected sequence register,                    Address offset: 0x4C 
RESERVED5[4]           // Reserved, 0x050 - 0x05C                                                 
OFR1                   // ADC offset register 1,                             Address offset: 0x60 
OFR2                   // ADC offset register 2,                             Address offset: 0x64 
OFR3                   // ADC offset register 3,                             Address offset: 0x68 
OFR4                   // ADC offset register 4,                             Address offset: 0x6C 
RESERVED6[4]           // Reserved, 0x070 - 0x07C                                                 
JDR1                   // ADC injected data register 1,                      Address offset: 0x80 
JDR2                   // ADC injected data register 2,                      Address offset: 0x84 
JDR3                   // ADC injected data register 3,                      Address offset: 0x88 
JDR4                   // ADC injected data register 4,                      Address offset: 0x8C 
RESERVED7[4]           // Reserved, 0x090 - 0x09C                                                 
AWD2CR                 // ADC  Analog Watchdog 2 Configuration Register,     Address offset: 0xA0 
AWD3CR                 // ADC  Analog Watchdog 3 Configuration Register,     Address offset: 0xA4 
RESERVED8              // Reserved, 0x0A8                                                         
RESERVED9              // Reserved, 0x0AC                                                         
DIFSEL                 // ADC  Differential Mode Selection Register,         Address offset: 0xB0 
CALFACT                // ADC  Calibration Factors,                          Address offset: 0xB4 
// ADC12_COMMON
CSR                    // ADC Common status register,                  Address offset: ADC1/3 base address + 0x300 
RESERVED               // Reserved, ADC1/3 base address + 0x304                                                    
CCR                    // ADC common control register,                 Address offset: ADC1/3 base address + 0x308 
CDR                    // ADC common regular data register for dual AND triple modes, Address offset: ADC1/3 base address + 0x30C 

// CAN
MCR                    //CAN master control register,         Address offset: 0x00          
MSR                    //CAN master status register,          Address offset: 0x04          
TSR                    //CAN transmit status register,        Address offset: 0x08          
RF0R                   //CAN receive FIFO 0 register,         Address offset: 0x0C          
RF1R                   //CAN receive FIFO 1 register,         Address offset: 0x10          
IER                    //CAN interrupt enable register,       Address offset: 0x14          
ESR                    //CAN error status register,           Address offset: 0x18          
BTR                    //CAN bit timing register,             Address offset: 0x1C          
RESERVED0[88]          //Reserved, 0x020 - 0x17F                                            
sTxMailBox[3]          //CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC 
sFIFOMailBox[2]        //CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC 
RESERVED1[12]          //Reserved, 0x1D0 - 0x1FF                                            
FMR                    //CAN filter master register,          Address offset: 0x200         
FM1R                   //CAN filter mode register,            Address offset: 0x204         
RESERVED2              //Reserved, 0x208                                                    
FS1R                   //CAN filter scale register,           Address offset: 0x20C         
RESERVED3              //Reserved, 0x210                                                    
FFA1R                  //CAN filter FIFO assignment register, Address offset: 0x214         
RESERVED4               //Reserved, 0x218                                                    
FA1R                    //CAN filter activation register,      Address offset: 0x21C         
RESERVED5[8]            //Reserved, 0x220-0x23F                                              
sFilterRegister[28]     //CAN Filter Register,                 Address offset: 0x240-0x31C   
// CAN Tx Mailbox
TIR                     //CAN TX mailbox identifier register 
TDTR                    //CAN mailbox data length control and time stamp register 
TDLR                    //CAN mailbox data low register 
TDHR                    //CAN mailbox data high register 
// CAN FIFO Mailbox
RIR                     //CAN receive FIFO mailbox identifier register *
RDTR                    //CAN receive FIFO mailbox data length control a
RDLR                    //CAN receive FIFO mailbox data low register 
RDHR                    //CAN receive FIFO mailbox data high register 
// CAN Filter Register
FR1                     //CAN Filter bank register 1 
FR2                     //CAN Filter bank register 1 

// COMP2, COMP4, COMP6
CSR                     //COMP control and status register, Address offset: 0x00 

// CRC
DR                      //CRC Data register,                           Address offset: 0x00 
IDR                     //CRC Independent data register,               Address offset: 0x04 
RESERVED0               //Reserved,                                                    0x05 
RESERVED1               //Reserved,                                                    0x06 
CR                      //CRC Control register,                        Address offset: 0x08 
RESERVED2               //Reserved,                                                    0x0C 
INIT                    //Initial CRC value register,                  Address offset: 0x10 
POL                     //CRC polynomial register,                     Address offset: 0x14 

// DAC1, DAC2
CR                      //DAC control register,                                    Address offset: 0x00 
SWTRIGR                 //DAC software trigger register,                           Address offset: 0x04 
DHR12R1                 //DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 
DHR12L1                 //DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C 
DHR8R1                  //DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 
DHR12R2                 //DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 
DHR12L2                 //DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 
DHR8R2                  //DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C 
DHR12RD                 //Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 
DHR12LD                 //DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 
DHR8RD                  //DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 
DOR1                    //DAC channel1 data output register,                       Address offset: 0x2C 
DOR2                    //DAC channel2 data output register,                       Address offset: 0x30 
SR                      //DAC status register,                                     Address offset: 0x34 

// DBGMCU
IDCODE                  //MCU device ID code,               Address offset: 0x00 
CR                      //Debug MCU configuration register, Address offset: 0x04 
APB1FZ                  //Debug MCU APB1 freeze register,   Address offset: 0x08 
APB2FZ                  //Debug MCU APB2 freeze register,   Address offset: 0x0C 

// DMA1
ISR                     //DMA interrupt status register,                            Address offset: 0x00 
IFCR                    //DMA interrupt flag clear register,                        Address offset: 0x04 
// DMA_Channel1, DMA_Channel2, DMA_Channel3, DMA_Channel4, DMA_Channel5, DMA_Channel6, DMA_Channel7
CCR                     //DMA channel x configuration register                                           
CNDTR                   //DMA channel x number of data register                                          
CPAR                    //DMA channel x peripheral address register                                      
CMAR                    //DMA channel x memory address register                                          

// EXTI
IMR                     //EXTI Interrupt mask register,                             Address offset: 0x00 
EMR                     //EXTI Event mask register,                                 Address offset: 0x04 
RTSR                    //EXTI Rising trigger selection register ,                  Address offset: 0x08 
FTSR                    //EXTI Falling trigger selection register,                  Address offset: 0x0C 
SWIER                   //EXTI Software interrupt event register,                   Address offset: 0x10 
PR                      //EXTI Pending register,                                    Address offset: 0x14 
RESERVED1               //Reserved, 0x18                                                                
RESERVED2               //Reserved, 0x1C                                                                
IMR2                    //EXTI Interrupt mask register,                            Address offset: 0x20 
EMR2                    //EXTI Event mask register,                                Address offset: 0x24 
RTSR2                   //EXTI Rising trigger selection register,                  Address offset: 0x28 
FTSR2                   //EXTI Falling trigger selection register,                 Address offset: 0x2C 
SWIER2                  //EXTI Software interrupt event register,                  Address offset: 0x30 
PR2                     //EXTI Pending register,                                   Address offset: 0x34 

// FLASH
ACR                     //FLASH access control register,              Address offset: 0x00 
KEYR                    //FLASH key register,                         Address offset: 0x04 
OPTKEYR                 //FLASH option key register,                  Address offset: 0x08 
SR                      //FLASH status register,                      Address offset: 0x0C 
CR                      //FLASH control register,                     Address offset: 0x10 
AR                      //FLASH address register,                     Address offset: 0x14 
RESERVED                //Reserved, 0x18                                                   
OBR                     //FLASH Option byte register,                 Address offset: 0x1C 
WRPR                    //FLASH Write register,                       Address offset: 0x20 
// OB
RDP                     //FLASH option byte Read protection,             Address offset: 0x00 
USER                    //FLASH option byte user options,                Address offset: 0x02 
Data0                   //FLASH option byte Data0 options,               Address offset: 0x04 
Data1                   //FLASH option byte Data1 options,               Address offset: 0x06 
WRP0                    //FLASH option byte write protection 0,          Address offset: 0x08 
WRP1                    //FLASH option byte write protection 1,          Address offset: 0x0C 

// GPIOA, GPIOB, GPIOC, GPIOD, GPIOF
MODER                   //GPIO port mode register,               Address offset: 0x00      
OTYPER                  //GPIO port output type register,        Address offset: 0x04      
OSPEEDR                 //GPIO port output speed register,       Address offset: 0x08      
PUPDR                   //GPIO port pull-up/pull-down register,  Address offset: 0x0C      
IDR                     //GPIO port input data register,         Address offset: 0x10      
ODR                     //GPIO port output data register,        Address offset: 0x14      
BSRR                    //GPIO port bit set/reset register,      Address offset: 0x18      
LCKR                    //GPIO port configuration lock register, Address offset: 0x1C      
AFR[2]                  //GPIO alternate function registers,     Address offset: 0x20-0x24 
BRR                     //GPIO bit reset register,               Address offset: 0x28 

// I2C
CR1                     //I2C Control register 1,            Address offset: 0x00 
CR2                     //I2C Control register 2,            Address offset: 0x04 
OAR1                    //I2C Own address 1 register,        Address offset: 0x08 
OAR2                    //I2C Own address 2 register,        Address offset: 0x0C 
TIMINGR                 //I2C Timing register,               Address offset: 0x10 
TIMEOUTR                //I2C Timeout register,              Address offset: 0x14 
ISR                     //I2C Interrupt and status register, Address offset: 0x18 
ICR                     //I2C Interrupt clear register,      Address offset: 0x1C 
PECR                    //I2C PEC register,                  Address offset: 0x20 
RXDR                    //I2C Receive data register,         Address offset: 0x24 
TXDR                    //I2C Transmit data register,        Address offset: 0x28 

// IWDG
KR                      //IWDG Key register,       Address offset: 0x00 
PR                      //IWDG Prescaler register, Address offset: 0x04 
RLR                     //IWDG Reload register,    Address offset: 0x08 
SR                      //IWDG Status register,    Address offset: 0x0C 
WINR                    //IWDG Window register,    Address offset: 0x10 

// OPAMP, OPAMP2
CSR                     //OPAMP control and status register,            Address offset: 0x00 

// PWR
CR                      //PWR power control register,        Address offset: 0x00 
CSR                     //PWR power control/status register, Address offset: 0x04 

// SYSCFG
CFGR1                   //SYSCFG configuration register 1,                      Address offset: 0x00 
RCR                     //SYSCFG CCM SRAM protection register,               Address offset: 0x04 
EXTICR[4]               //SYSCFG external interrupt configuration registers, Address offset: 0x14-0x08 
CFGR2                   //SYSCFG configuration register 2,                      Address offset: 0x18 
RESERVED0               //Reserved,                                                           0x1C 
RESERVED1               //Reserved,                                                          0x20 
RESERVED2               //Reserved,                                                          0x24 
RESERVED4               //Reserved,                                                          0x28 
RESERVED5               //Reserved,                                                          0x2C 
RESERVED6               //Reserved,                                                          0x30 
RESERVED7               //Reserved,                                                          0x34 
RESERVED8               //Reserved,                                                          0x38 
RESERVED9               //Reserved,                                                          0x3C 
RESERVED10              //Reserved,                                                          0x40 
RESERVED11              //Reserved,                                                          0x44 
RESERVED12              //Reserved,                                                          0x48 
RESERVED13              //Reserved,                                                          0x4C 
CFGR3                   //SYSCFG configuration register 3,                    Address offset: 0x50 

// RCC
CR                      //RCC clock control register,                                  Address offset: 0x00 
CFGR                    //RCC clock configuration register,                            Address offset: 0x04 
CIR                     //RCC clock interrupt register,                                Address offset: 0x08 
APB2RSTR                //RCC APB2 peripheral reset register,                          Address offset: 0x0C 
APB1RSTR                //RCC APB1 peripheral reset register,                          Address offset: 0x10 
AHBENR                  //RCC AHB peripheral clock register,                           Address offset: 0x14 
APB2ENR                 //RCC APB2 peripheral clock enable register,                   Address offset: 0x18 
APB1ENR                 //RCC APB1 peripheral clock enable register,                   Address offset: 0x1C 
BDCR                    //RCC Backup domain control register,                          Address offset: 0x20 
CSR                     //RCC clock control & status register,                         Address offset: 0x24 
AHBRSTR                 //RCC AHB peripheral reset register,                           Address offset: 0x28 
CFGR2                   //RCC clock configuration register 2,                          Address offset: 0x2C 
CFGR3                   //RCC clock configuration register 3,                          Address offset: 0x30 

// RTC
TR                      //RTC time register,                                        Address offset: 0x00 
DR                      //RTC date register,                                        Address offset: 0x04 
CR                      //RTC control register,                                     Address offset: 0x08 
ISR                     //RTC initialization and status register,                   Address offset: 0x0C 
PRER                    //RTC prescaler register,                                   Address offset: 0x10 
WUTR                    //RTC wakeup timer register,                                Address offset: 0x14 
RESERVED0               //Reserved, 0x18                                                                 
ALRMAR                  //RTC alarm A register,                                     Address offset: 0x1C 
ALRMBR                  //RTC alarm B register,                                     Address offset: 0x20 
WPR                     //RTC write protection register,                            Address offset: 0x24 
SSR                     //RTC sub second register,                                  Address offset: 0x28 
SHIFTR                  //RTC shift control register,                               Address offset: 0x2C 
TSTR                    //RTC time stamp time register,                             Address offset: 0x30 
TSDR                    //RTC time stamp date register,                             Address offset: 0x34 
TSSSR                   //RTC time-stamp sub second register,                       Address offset: 0x38 
CALR                    //RTC calibration register,                                 Address offset: 0x3C 
TAFCR                   //RTC tamper and alternate function configuration register, Address offset: 0x40 
ALRMASSR                //RTC alarm A sub second register,                          Address offset: 0x44 
ALRMBSSR                //RTC alarm B sub second register,                          Address offset: 0x48 
RESERVED7               //Reserved, 0x4C                                                                 
BKP0R                   //RTC backup register 0,                                    Address offset: 0x50 
BKP1R                   //RTC backup register 1,                                    Address offset: 0x54 
BKP2R                   //RTC backup register 2,                                    Address offset: 0x58 
BKP3R                   //RTC backup register 3,                                    Address offset: 0x5C 
BKP4R                   //RTC backup register 4,                                    Address offset: 0x60 

// SPI1
CR1                     //SPI Control register 1,                              Address offset: 0x00 
CR2                     //SPI Control register 2,                              Address offset: 0x04 
SR                      //SPI Status register,                                 Address offset: 0x08 
DR                      //SPI data register,                                   Address offset: 0x0C 
CRCPR                   //SPI CRC polynomial register,                         Address offset: 0x10 
RXCRCR                  //SPI Rx CRC register,                                 Address offset: 0x14 
TXCRCR                  //SPI Tx CRC register,                                 Address offset: 0x18 

// TIM1, TIM2, TIM3, TIM6, TIM7, TIM15, TIM16, TIM17
CR1                     //TIM control register 1,              Address offset: 0x00 
CR2                     //TIM control register 2,              Address offset: 0x04 
SMCR                    //TIM slave mode control register,     Address offset: 0x08 
DIER                    //TIM DMA/interrupt enable register,   Address offset: 0x0C 
SR                      //TIM status register,                 Address offset: 0x10 
EGR                     //TIM event generation register,       Address offset: 0x14 
CCMR1                   //TIM capture/compare mode register 1, Address offset: 0x18 
CCMR2                   //TIM capture/compare mode register 2, Address offset: 0x1C 
CCER                    //TIM capture/compare enable register, Address offset: 0x20 
CNT                     //TIM counter register,                Address offset: 0x24 
PSC                     //TIM prescaler,                       Address offset: 0x28 
ARR                     //TIM auto-reload register,            Address offset: 0x2C 
RCR                     //TIM repetition counter register,     Address offset: 0x30 
CCR1                    //TIM capture/compare register 1,      Address offset: 0x34 
CCR2                    //TIM capture/compare register 2,      Address offset: 0x38 
CCR3                    //TIM capture/compare register 3,      Address offset: 0x3C 
CCR4                    //TIM capture/compare register 4,      Address offset: 0x40 
BDTR                    //TIM break and dead-time register,    Address offset: 0x44 
DCR                     //TIM DMA control register,            Address offset: 0x48 
DMAR                    //TIM DMA address for full transfer,   Address offset: 0x4C 
OR                      //TIM option register,                 Address offset: 0x50 
CCMR3                   //TIM capture/compare mode register 3, Address offset: 0x54 
CCR5                    //TIM capture/compare register5,       Address offset: 0x58 
CCR6                    //TIM capture/compare register 4,      Address offset: 0x5C 

// TSC
CR                      //TSC control register,                                     Address offset: 0x00 
IER                     //TSC interrupt enable register,                            Address offset: 0x04 
ICR                     //TSC interrupt clear register,                             Address offset: 0x08 
ISR                     //TSC interrupt status register,                            Address offset: 0x0C 
IOHCR                   //TSC I/O hysteresis control register,                      Address offset: 0x10 
RESERVED1               //Reserved,                                                 Address offset: 0x14 
IOASCR                  //TSC I/O analog switch control register,                   Address offset: 0x18 
RESERVED2               //Reserved,                                                 Address offset: 0x1C 
IOSCR                   //TSC I/O sampling control register,                        Address offset: 0x20 
RESERVED3               //Reserved,                                                 Address offset: 0x24 
IOCCR                   //TSC I/O channel control register,                         Address offset: 0x28 
RESERVED4               //Reserved,                                                 Address offset: 0x2C 
IOGCSR                  //TSC I/O group control status register,                    Address offset: 0x30 
IOGXCR[8]               //TSC I/O group x counter register,                         Address offset: 0x34-50 

// USART1, USART2, USART3
CR1                     //USART Control register 1,                 Address offset: 0x00 
CR2                     //USART Control register 2,                 Address offset: 0x04 
CR3                     //USART Control register 3,                 Address offset: 0x08 
BRR                     //USART Baud rate register,                 Address offset: 0x0C 
GTPR                    //USART Guard time and prescaler register,  Address offset: 0x10 
RTOR                    //USART Receiver Time Out register,         Address offset: 0x14 
RQR                     //USART Request register,                   Address offset: 0x18 
ISR                     //USART Interrupt and status register,      Address offset: 0x1C 
ICR                     //USART Interrupt flag Clear register,      Address offset: 0x20 
RDR                     //USART Receive Data register,              Address offset: 0x24 
RESERVED1               //Reserved, 0x26                                                 
TDR                     //USART Transmit Data register,             Address offset: 0x28 
RESERVED2               //Reserved, 0x2A                                                 

// WWDG
CR                      //WWDG Control register,       Address offset: 0x00 
CFR                     //WWDG Configuration register, Address offset: 0x04 
SR                      //WWDG Status register,        Address offset: 0x08 
*********************************************************************************************************************************/