#ifndef _NVIC_H
#define _NVIC_H

#include <stdint.h>
#include "io.h"


#define NVIC_ADDRESS (void *)0xe000e100
#define NVIC ((volatile nvic_t *)NVIC_ADDRESS)

typedef struct _nvic_t nvic_t;
struct _nvic_t {
  __IO uint32_t ISER[8];

  __RO uint32_t reserved0[24];

  __IO uint32_t ICER[8];

  __RO uint32_t reserved1[24];

  __IO uint32_t ISPR[8];
  
  __RO uint32_t reserved2[24];

  __IO uint32_t ICPR[8];

  __RO uint32_t reserved3[24];

  __IO uint32_t IABR[8];
  
  __RO uint32_t reserved4[56];

  __IO uint32_t IPR[60];
  
  __RO uint32_t reserved5[580];

  __IO uint32_t STIP;
};


/** Interrupt set-enable register x(NVIC_ISERx)
 * Offset: 0x100 + 0x04 * x(x = 0 to 7)
 * Reset value: 0x0000 0000
 */
#define NVIC_ISER_SETENA (0xffffffff)

/** Interrupt clear-enable register x(NVIC_ICERx)
 * Offset: 0x180 + 0x04 * x(x = 0 to 7)
 * Reset value: 0x0000
 */
#define NVIC_ICER_CLRENA (0xffffffff)

/** Interrupt set-pending register x(NVIC_ISPRx)
 * Offset: 0x200 + 0x04 * x (x = 0 to 7)
 * Reset value: 0x0000 0000
 */
#define NVIC_ISPR_SETPEND (0xffffffff)

/** Interrupt clear-pending register x(NVIC_ICPRx)
 * Offset: 0x280 + 0x04 * x (x = 0 to 7)
 * Reset value: 0x0000 0000
 */
#define NVIC_ICPR_CLRPEND (0xffffffff)

/** Interrupt active bit register x(NVIC_IABRx)
 * Offset: 0x300 + 0x04 * x (x = 0 to 7)
 * Reset value: 0x0000 0000
 */
#define NVIC_IABR_ACTIVE (0xffffffff)

/** interrupt priority register x(NVIC_IPRx)
 * Offset: 0x400 + 0x04 * x (x = 0 to 59)
 * Reset value: 0x0000 0000
 */
#define NVIC_IPR_IP (0xffffffff)

/* Mapping of IP[N] fields in NVIC_IPRx registers
 *
 *            |31        24|23        16|15         8|7          0|
 * NVIC_IPR59 | IP[239]    | IP[238]    | IP[237]    | IP[236]    |
 *            |            |            |            |            |
 * NVIC_IPRx  | IP[4x + 3] | IP[4x + 2] | IP[4x + 1] | IP[4x + 0] |
 *            |            |            |            |            |
 * NVIC_IPR0  | IP[3]      | IP[2]      | IP[1]      | IP[0]      |
 */


/** Software trigger interrupt register(NVIC_STIP)
 * Offset: 0xE00
 * Reset value: 0x0000 0000
 */
#define NVIC_STIP_INTID (0x000001ff)



typedef enum {
  WWDG                   = 0, // Window Watchdog interrupt
  PVD,                // = 1 PVD through EXTI line 16 detection interrup
  TAMPER_STAMP,       // = 2, Tamper and timeStamp interrupts through the EXTI lin 19,
  RTC_WKUP,           // = 3, RTC wakeup timer interrupts through the EXTI line 20
  FLASH,              // = 4,  Flash global interrupt
  RCC,                // = 5, RCC global interrupt
  EXTI0,              // = 6, EXTI Line0 interrupt
  EXTI1,              // = 7, EXTI Line1 interrupt
  EXTI2_TS,           // = 8, EXTI Line2 and Touch sensing interrupts
  EXTI3,              // = 9, EXTI Line3
  EXTI4,              // = 10, EXTI Line4
  DMA1_CHANNEL1,      // = 11, DMA1 channel 1 interrupt
  DMA1_CHANNEL2,      // = 12, DMA1 channel 2 interrupt
  DMA1_CHANNEL3,      // = 13, DMA1 channel 3 interrupt
  DMA1_CHANNEL4,      // = 14, DMA1 channel 4 interrupt
  DMA1_CHANNEL5,      // = 15, DMA1 channel 5 interrupt
  DMA1_CHANNEL6,      // = 16, DMA1 channel 6 interrupt
  DMA1_CHANNEL7,      // = 17, DMA1 channel 7 interrupt
  ADC1_2,             // = 18, ADC1 and ADC2 global interrupt
  CAN_TX,             // = 19, CAN_TX interrupts
  CAN_RX0,            // = 20, CAN_RX0 interrupts
  CAN_RX1,            // = 21, CAN_RX1 interrupts
  CAN_SCE,            // = 22, CAN_SCE interrupts
  EXTI9_5,            // = 23, EXTI Line[9:5] interrupts
  TIM1_BRK_TIM15,     // = 24, TIM1 Break/TIM15 global interrupts
  TIM1_UP_TIM16,      // = 25, TIM1 Up/TIM16 global interrupts
  TIM1_TRG_COM_TIM17, // = 26, TIM1 trigger and commutation/TIM17 interrupts
  TIM1_CC,            // = 27, TIM1 capture compare interrupt
  TIM2,               // = 28, TIM2 global interrupt
  TIM3,               // = 29, TIM3 global interrupt
  I2C1_EV                = 31, // I2C1 event interrupt & EXTI Line23 interrupt
  I2C1_ER,            // = 32, I2C1 error interrupt
  SPI1                   = 35, // SPI1 global interrupt
  USART1                 = 37, // USART1 global interrupt & EXTI Line 25
  USART2,             // = 38, USART1 global interrupt & EXTI Line 26
  USART3,             // = 39, USART1 global interrupt & EXTI Line 28
  EXTI15_10,          // = 40, EXTI Line[15:10] interrupts
  RTC_ALARM,          // = 41, RTC alarm interrupt
  TIM6_DAC1,          // = 54, TIM6 global and DAC1 underrun interrupts
  TIM7_DAC2,          // = 55, TIM7 global and DAC2 underrun interrupts
  COMP2,              // = 64, COMP2 interrupt combined with EXTI Lines 22 interrupt
  COMP4_6,            // = 65, COMP4 & COMP6 interrupt combined with EXTI Lines 30 and 32 interrupts respectively.
  FPU                 // = 81, Floating point interrupt
} IRQn_t;

/* src/nvic.c */
extern void
nvic_enable_IRQ(IRQn_t n);
extern void
nvic_disable_IRQ(IRQn_t n);

extern void
nvic_clear_pending_IRQ(IRQn_t n);
extern uint32_t
nvic_get_pending_IRQ(IRQn_t n);

extern void
nvic_set_priority(IRQn_t n, uint32_t priority);
extern uint32_t
nvic_get_priority(IRQn_t n);


#endif
