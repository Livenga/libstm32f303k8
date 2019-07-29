#ifndef _ADVANCED_CONTORL_TIMERS1_8_20_H
#define _ADVANCED_CONTORL_TIMERS1_8_20_H

#include <stdint.h>
#include "io.h"


#define TIM1_ADDR ((void *)0x40012c00)
//#define TIM2_ADDR ((void *)0x40000000)

#define TIM1 ((volatile advanced_control_timer1_8_20_t *)TIM1_ADDR)


typedef struct _advanced_control_timer1_8_20_t advanced_control_timer1_8_20_t;
struct _advanced_control_timer1_8_20_t {
  __IO uint32_t CR1;   // 0x00
  __IO uint32_t CR2;   // 0x04
  __IO uint32_t SMCR;  // 0x08
  __IO uint32_t DIER;  // 0x0C
  __IO uint32_t SR;    // 0x10
  __IO uint32_t EGR;   // 0x14
  __IO uint32_t CCMR1; // 0x18
  __IO uint32_t CCMR2; // 0x1C
  __IO uint32_t CCER;  // 0x20
  __IO uint32_t CNT;   // 0x24
  __IO uint32_t PSC;   // 0x28
  __IO uint32_t ARR;   // 0x2C
  __IO uint32_t RCR;   // 0x30
  __IO uint32_t CCR1;  // 0x34
  __IO uint32_t CCR2;  // 0x38
  __IO uint32_t CCR3;  // 0x3C
  __IO uint32_t CCR4;  // 0x40
  __IO uint32_t BDTR;  // 0x44
  __IO uint32_t DCR;   // 0x48
  __IO uint32_t DMAR;  // 0x4C
  __IO uint32_t OR;    // 0x50
  __IO uint32_t CCMR3; // 0x54
  __IO uint32_t CCR5;  // 0x58
  __IO uint32_t CCR6;  // 0x5C
};



/** TIM1/TIM8/TIM20 control register 1 (TIMx_CR1)
 * Offset: 0x00
 * Reset value: 0x0000 0000
 */
#define TIM1_CR1_UIFREMAP (0x00000800)
#define TIM1_CR1_CKD      (0x00000300)
#define TIM1_CR1_ARPE     (0x00000080)
#define TIM1_CR1_CMS      (0x00000060)
#define TIM1_CR1_DIR      (0x00000010)
#define TIM1_CR1_OPM      (0x00000008)
#define TIM1_CR1_URS      (0x00000004)
#define TIM1_CR1_UDIS     (0x00000002)
#define TIM1_CR1_CEN      (0x00000001)


/** TIM1/TIM8/TIM20 control register 2 (TIMx_CR2)
 * Offset: 0x04
 * Reset value: 0x0000 0000
 */
#define TIM1_CR_MMS2  (0x00700000)
#define TIM1_CR_OIS6  (0x00040000)
#define TIM1_CR_OIS5  (0x00010000)
#define TIM1_CR_OIS4  (0x00004000)
#define TIM1_CR_OIS3N (0x00002000)
#define TIM1_CR_OIS3  (0x00001000)
#define TIM1_CR_OIS2N (0x00000800)
#define TIM1_CR_OIS2  (0x00000400)
#define TIM1_CR_OIS1N (0x00000200)
#define TIM1_CR_OIS1  (0x00000100)
#define TIM1_CR_TI1S  (0x00000080)
#define TIM1_CR_MMS   (0x00000070)
#define TIM1_CR_CCDS  (0x00000008)
#define TIM1_CR_CCUS  (0x00000004)
#define TIM1_CR_CCPC  (0x00000001)


/** TIM1/TIM8/TIM20 slave mode control register(TIMx_SMCR)
 * Offset: 0x08
 * Reset value: 0x0000 0000
 */
#define TIM1_SMCR_SMS3   (0x00010000)
#define TIM1_SMCR_ETP    (0x00008000)
#define TIM1_SMCR_ECE    (0x00004000)
#define TIM1_SMCR_ETPS   (0x00003000)
#define TIM1_SMCR_ETF    (0x00000f00)
#define TIM1_SMCR_MSM    (0x00000080)
#define TIM1_SMCR_TS     (0x00000070)
#define TIM1_SMCR_OCCS   (0x00000008)
#define TIM1_SMCR_SMS2_0 (0x00000007)


/** TIM1/TIM8/TIM20 DMA/interrult enable register(TIMx_DIER)
 * Offset: 0x0C
 * Reset value: 0000 0000
 */
#define TIM1_DIER_TDE   (0x00004000)
#define TIM1_DIER_COMDE (0x00002000)
#define TIM1_DIER_CC4DE (0x00001000)
#define TIM1_DIER_CC3DE (0x00000800)
#define TIM1_DIER_CC2DE (0x00000400)
#define TIM1_DIER_CC1DE (0x00000200)
#define TIM1_DIER_UDE   (0x00000100)
#define TIM1_DIER_BIE   (0x00000080)
#define TIM1_DIER_TIE   (0x00000040)
#define TIM1_DIER_COMIE (0x00000020)
#define TIM1_DIER_CC4IE (0x00000010)
#define TIM1_DIER_CC3IE (0x00000008)
#define TIM1_DIER_CC2IE (0x00000004)
#define TIM1_DIER_CC1IE (0x00000002)
#define TIM1_DIER_UIE   (0x00000001)


/** TIM1/TIM8/TIM20 status register(TIMx_SR)
 * Offset: 0x10
 * Reset value: 0x0000 0000
 */
#define TIM1_SR_CC6IF (0x00020000)
#define TIM1_SR_CC5IF (0x00010000)
#define TIM1_SR_CC4OF (0x00001000)
#define TIM1_SR_CC3OF (0x00000800)
#define TIM1_SR_CC2OF (0x00000400)
#define TIM1_SR_CC1OF (0x00000200)
#define TIM1_SR_B2IF  (0x00000100)
#define TIM1_SR_BIF   (0x00000080)
#define TIM1_SR_TIF   (0x00000040)
#define TIM1_SR_COMIF (0x00000020)
#define TIM1_SR_CC4IF (0x00000010)
#define TIM1_SR_CC3IF (0x00000008)
#define TIM1_SR_CC2IF (0x00000004)
#define TIM1_SR_CC1IF (0x00000002)
#define TIM1_SR_UIF   (0x00000001)



/** TIM1/TIM8/TIM20 event generation register(TIMx_EGR)
 * Offset: 0x14
 * Reset value: 0x0000 0000
 */
#define TIM1_EGR_B2G  (0x00000100)
#define TIM1_EGR_BG   (0x00000080)
#define TIM1_EGR_TG   (0x00000040)
#define TIM1_EGR_COMG (0x00000020)
#define TIM1_EGR_CC4G (0x00000010)
#define TIM1_EGR_CC3G (0x00000008)
#define TIM1_EGR_CC2G (0x00000004)
#define TIM1_EGR_CC1G (0x00000002)
#define TIM1_EGR_UG   (0x00000001)


/** TIM1/TIM8/TIM20 capture/compare mode register 1(TIMx_CCMR1)
 * Offset: 0x18
 * Reset value: 0x0000 0000
 */
#define TIM1_CCMR1_OC2M3   (0x01000000)
#define TIM1_CCMR1_OC1M3   (0x00010000)
#define TIM1_CCMR1_OC2CE   (0x00008000)
#define TIM1_CCMR1_OC2M2_0 (0x00007000)
#define TIM1_CCMR1_OC2PE   (0x00000800)
#define TIM1_CCMR1_OC2FE   (0x00000400)
#define TIM1_CCMR1_OC2S    (0x00000300)
#define TIM1_CCMR1_OC1CE   (0x00000080)
#define TIM1_CCMR1_OC1M2_0 (0x00000070)

#define TIM1_CCMR1_OC1PE   (0x00000008)
#define TIM1_CCMR1_OC1FE   (0x00000004)

#define TIM1_CCMR1_IC2F    (0x0000f000)
#define TIM1_CCMR1_IC2PSC  (0x00000c00)

#define TIM1_CCMR1_IC1F    (0x000000f0)
#define TIM1_CCMR1_IC1PSC  (0x0000000c)

#define TIM1_CCMR1_CC1S    (0x00000003)


/** TIM1/TIM8/TIM20 capture/compare mode register 2(TIMx_CCMR2)
 * Offset: 0x1C
 * Reset value: 0x0000 0000
 */
#define TIM1_CCMR2_OC4M3   (0x01000000)
#define TIM1_CCMR2_OC3M3   (0x00010000)
#define TIM1_CCMR2_OC4CE   (0x00008000)
#define TIM1_CCMR2_OC4M2_0 (0x00007000)
#define TIM1_CCMR2_OC4PE   (0x00000800)
#define TIM1_CCMR2_OC4FE   (0x00000400)
#define TIM1_CCMR2_CC4S    (0x00000300)
#define TIM1_CCMR2_OC3CE   (0x00000080)
#define TIM1_CCMR2_OC3M2_0 (0x00000070)
#define TIM1_CCMR2_OC3PE   (0x00000008)
#define TIM1_CCMR2_OC3FE   (0x00000004)
#define TIM1_CCMR2_CC3S    (0x00000003)

#define TIM1_CCR2_IC4F     (0x0000f000)
#define TIM1_CCR2_IC4PSC   (0x00000c00)
#define TIM1_CCR2_IC3F     (0x000000f0)
#define TIM1_CCR2_IC3PSC   (0x0000000c)


/** TIM1/TIM8/TIM20 capture/compare enable regsiter(TIMx_CCER)
 * Offset: 0x20
 * Reset value: 0x0000 0000
 */
#define TIM1_CCER_CC6P  (0x00200000)
#define TIM1_CCER_CC6E  (0x00100000)
#define TIM1_CCER_CC5P  (0x00020000)
#define TIM1_CCER_CC5E  (0x00010000)
#define TIM1_CCER_CC4NP (0x00008000)
#define TIM1_CCER_CC4P  (0x00002000)
#define TIM1_CCER_CC4E  (0x00001000)
#define TIM1_CCER_CC3NP (0x00000800)
#define TIM1_CCER_CC3NE (0x00000400)
#define TIM1_CCER_CC3P  (0x00000200)
#define TIM1_CCER_CC3E  (0x00000100)
#define TIM1_CCER_CC2NP (0x00000080)
#define TIM1_CCER_CC2NE (0x00000040)
#define TIM1_CCER_CC2P  (0x00000020)
#define TIM1_CCER_CC2E  (0x00000010)
#define TIM1_CCER_CC1NP (0x00000008)
#define TIM1_CCER_CC1NE (0x00000004)
#define TIM1_CCER_CC1P  (0x00000002)
#define TIM1_CCER_CC1E  (0x00000001)


/** TIM1/TIM8/TIM20 counter(TIMx_CNT)
 * Offset: 0x24
 * Reset value: 0x0000 0000
 */
#define TIM1_CNT_UIFCPY (0x80000000)
#define TIM1_CNT_CNT    (0x0000ffff)


/** TIM1/TIM8/TIM20 prescaler(TIMx_PSC)
 * Offset: 0x28
 * Reset value: 0x0000 0000
 */
#define TIM1_PSC_PSC (0x0000ffff)


/** TIM1/TIM8/TIM20 auto-reload register(TIMx_ARR)
 * Offset: 0x2C
 * Reset value: 0x0000 0000
 */
#define TIM1_ARR_ARR (0x0000ffff)


/** TIM1/TIM8/TIM20 repetition counter register(TIMx_RCR)
 * Offset: 0x30
 * Reset value: 0x0000 0000
 */
#define TIM1_RCR_REP (0x0000ffff)


/** TIM1/TIM8/TIM20 capture/compare register 1(TIMx_CCR1)
 * Offset: 0x34
 * Reset value: 0x0000 0000
 */
#define TIM1_CCR1_CCR1 (0x0000ffff)


/** TIM1/TIM8/TIM20 capture/compare register 2(TIMx_CCR2)
 * Offset: 0x38
 * Reset value: 0x0000 0000
 */
#define TIM1_CCR2_CCR2 (0x0000ffff)


/** TIM1/TIM8/TIM20 capture/compare register 3(TIMx_CCR3)
 * Offset: 0x3C
 * Reset value: 0x0000 0000
 */
#define TIM1_CCR3_CCR3 (0x0000ffff)


/** TIM1/TIM8/TIM20 capture/compare register 4(TIMx_CCR4)
 * Offset: 0x40
 * Reset value: 0x0000 0000
 */
#define TIM1_CCR4_CCR4 (0x0000ffff)


/** TIM1/TIM8/TIM20 break and dead-time register(TIMx_BDTR)
 * Offset: 0x44
 * Reset value: 0x0000 0000
 */
#define TIM1_BDTR_BK2P (0x02000000)
#define TIM1_BDTR_BK2E (0x01000000)
#define TIM1_BDTR_BK2F (0x00f00000)
#define TIM1_BDTR_BKF  (0x000f0000)
#define TIM1_BDTR_MOE  (0x00008000)
#define TIM1_BDTR_AOE  (0x00004000)
#define TIM1_BDTR_BKP  (0x00002000)
#define TIM1_BDTR_BKE  (0x00001000)
#define TIM1_BDTR_OSSR (0x00000800)
#define TIM1_BDTR_OSSI (0x00000400)
#define TIM1_BDTR_LOCK (0x00000300)
#define TIM1_BDTR_DTG  (0x000000ff)


/** TIM1/TIM8/TIM20 DMA control register(TIMx_DCR)
 * Offset: 0x48
 * Reset value: 0x0000 0000
 */
#define TIM1_DCR_DBL (0x00001f00)
#define TIM1_DCR_DBA (0x0000001f)


/** TIM1/TIM8/TIM20 DMA address for full transfer(TIMx_DMAR)
 * Offset: 0x4C
 * Reset value: 0x0000 0000
 */
#define TIM1_DMAR_DMAB (0xffffffff)


/** TIM1/TIM8/TIM20 option register(TIMx_OR)
 * Offset: 0x50
 * Reset value: 0x0000 0000
 */
#define TIM1_OR_TIM1_ETR_ADC4_RMP  (0x0000000c)
#define TIM1_OR_TIM8_ETR_ADC3_RMP  (0x0000000c)
#define TIM1_OR_TIM20_ETR_ADC4_RMP (0x0000000c)

#define TIM1_OR_TIM1_ETR_ADC1_RMP  (0x00000003)
#define TIM1_OR_TIM8_ETR_ADC2_RMP  (0x00000003)
#define TIM1_OR_TIM20_ETR_ADC3_RMP (0x00000003)


/** TIM1/TIM8/TIM20 capture/compare mode register 3(TIMx_CCMR3)
 * Offset: 0x54
 * Reset value: 0x0000 0000
 */
#define TIM1_CCMR3_OC6M3   (0x01000000)
#define TIM1_CCMR3_OC5M3   (0x00010000)
#define TIM1_CCMR3_OC6CE   (0x00008000)
#define TIM1_CCMR3_OC6M2_0 (0x00007000)
#define TIM1_CCMR3_OC6PE   (0x00000800)
#define TIM1_CCMR3_OC6FE   (0x00000400)
#define TIM1_CCMR3_OC5CE   (0x00000080)
#define TIM1_CCMR3_OC5M2_0 (0x00000070)
#define TIM1_CCMR3_OC5PE   (0x00000008)
#define TIM1_CCMR3_OC5FE   (0x00000004)


/** TIM1/TIM8/TIM20 capture/compare register 5(TIMx_CCR5)
 * Offset: 0x58
 * Reset value: 0x0000 0000
 */
#define TIM1_CCR5_GC5CE (0x80000000)
#define TIM1_CCR5_GC5C2 (0x40000000)
#define TIM1_CCR5_GC5C1 (0x20000000)
#define TIM1_CCR5_CCR5  (0x0000ffff)


/** TIM1/TIM8/TIM20 capture/compare register 6(TIMx_CCR6)
 * Offset: 0x5C
 * Reset value: 0x0000
 */
#define TIM1_CCR6_CCR6 (0x0000ffff)
#endif
