#ifndef _ADC_H
#define _ADC_H

#include <stdint.h>
#include "io.h"

#define ADC1_ADDR       ((void *)0x50000000)
#define ADC2_ADDR       ((void *)0x50000100)
#define ADC_COMMON_ADDR ((void *)0x50000300)


#define ADC1       ((volatile adc_t *)ADC1_ADDR)
#define ADC2       ((volatile adc_t *)ADC2_ADDR)
#define ADC_COMMON ((volatile adc_common_t *)ADC_COMMON_ADDR)



typedef struct _adc_t adc_t;
typedef struct _adc_common_t adc_common_t;

struct _adc_t {
  __IO uint32_t ISR;          // 0x00
  __IO uint32_t IER;          // 0x04
  __IO uint32_t CR;           // 0x08
  __IO uint32_t CFGR;         // 0x0C

  __RO uint32_t reserved0;    // 0x10

  __IO uint32_t SMPR1;        // 0x14
  __IO uint32_t SMPR2;        // 0x18

  __RO uint32_t reserved1;    // 0x1C

  __IO uint32_t TR1;          // 0x20
  __IO uint32_t TR2;          // 0x24
  __IO uint32_t TR3;          // 0x28
  
  __RO uint32_t reserved2;    // 0x2C

  __IO uint32_t SQR1;         // 0x30
  __IO uint32_t SQR2;         // 0x34
  __IO uint32_t SQR3;         // 0x38
  __IO uint32_t SQR4;         // 0x3C
  __RO uint32_t DR;           // 0x40

  __RO uint32_t reserved3[2]; // 0x44 - 0x48

  __IO uint32_t JSQR;         // 0x4C

  __RO uint32_t reserved4[4]; // 0x50 - 0x5C

  __IO uint32_t OFR1;         // 0x60
  __IO uint32_t OFR2;         // 0x64
  __IO uint32_t OFR3;         // 0x68
  __IO uint32_t OFR4;         // 0x6C

  __RO uint32_t reserved5[4]; // 0x70 - 0x7C

  __IO uint32_t JDR1;         // 0x80
  __IO uint32_t JDR2;         // 0x84
  __IO uint32_t JDR3;         // 0x88
  __IO uint32_t JDR4;         // 0x8C
  
  __RO uint32_t reserved6[4]; // 0x90 - 0x9C

  __IO uint32_t AWD2CR;       // 0xA0
  __IO uint32_t AWD3CR;       // 0xA4
  
  __RO uint32_t reserved7[2]; // 0xA8 - 0xAC

  __IO uint32_t DIFSEL;       // 0xb0
  __IO uint32_t CALFACT;      // 0xb4
};

struct _adc_common_t {
  __RO uint32_t CSR;
  __RO uint32_t reserved;
  __IO uint32_t CCR;
  __RO uint32_t CDR;
};



/** ADC interrupt and status register (ADCx_ISR, x=1..4)
 * Offset: 0x00
 * Reset value: 0x0000 0000
 */
#define ADC_ISR_JQOVF (0x00000400)
#define ADC_ISR_AWD3  (0x00000200)
#define ADC_ISR_AWD2  (0x00000100)
#define ADC_ISR_AWD1  (0x00000080)
#define ADC_ISR_JEOS  (0x00000040)
#define ADC_ISR_JEOC  (0x00000020)
#define ADC_ISR_OVR   (0x00000010)
#define ADC_ISR_EOS   (0x00000008)
#define ADC_ISR_EOC   (0x00000004)
#define ADC_ISR_EOSMP (0x00000002)
#define ADC_ISR_ADRDY (0x00000001)


/** ADC interrupt enable register(ADCx_IER, x=1..4)
 * Offset: 0x04
 * Reset value: 0x0000 0000
 */
#define ADC_IER_JQOVFIE (0x00000400)
#define ADC_IER_AWD3IE  (0x00000200)
#define ADC_IER_AWD2IE  (0x00000100)
#define ADC_IER_AWD1IE  (0x00000080)
#define ADC_IER_JEOSIE  (0x00000040)
#define ADC_IER_JEOCIE  (0x00000020)
#define ADC_IER_OVRIE   (0x00000010)
#define ADC_IER_EOSIE   (0x00000008)
#define ADC_IER_EOCIE   (0x00000004)
#define ADC_IER_EOSMPIE (0x00000002)
#define ADC_IER_ADRDYIE (0x00000001)


/** ADC control register(ADCx_CR, x=1..4)
 * Offset: 0x08
 * Reset value: 0x0000 0000
 */
#define ADC_CR_ADCAL    (0x80000000)
#define ADC_CR_ADCALDIF (0x40000000)
#define ADC_CR_ADVREGEN (0x30000000)
#define ADC_CR_JADSTP   (0x00000020)
#define ADC_CR_ADSTP    (0x00000010)
#define ADC_CR_JADSTART (0x00000008)
#define ADC_CR_ADSTART  (0x00000004)
#define ADC_CR_ADDIS    (0x00000002)
#define ADC_CR_ADEN     (0x00000001)

#define ADC_CR_ADVREGEN_INTERMEDIATE (0x00000000)
#define ADC_CR_ADVREGEN_ENABLE       (0x10000000)
#define ADC_CR_ADVREGEN_DISABLE      (0x20000000)


/** ADC configuration register(ADCx_CFGR, x=1..4)
 * Offset: 0x0C
 * Reset value: 0x0000 0000
 */
#define ADC_CFGR_AWD1CH  (0x7c000000)
#define ADC_CFGR_JAUTO   (0x02000000)
#define ADC_CFGR_JAWD1EN (0x01000000)
#define ADC_CFGR_AWD1EN  (0x00800000)
#define ADC_CFGR_AWD1SGL (0x00400000)
#define ADC_CFGR_JQM     (0x00200000)
#define ADC_CFGR_JDISCEN (0x00100000)
#define ADC_CFGR_DISCNUM (0x000e0000)
#define ADC_CFGR_DISCEN  (0x00010000)
#define ADC_CFGR_AUTDLY  (0x00004000)
#define ADC_CFGR_CONT    (0x00002000)
#define ADC_CFGR_OVRMOD  (0x00001000)
#define ADC_CFGR_EXTEN   (0x00000c00)
#define ADC_CFGR_EXTSEL  (0x000003c0)
#define ADC_CFGR_ALIGN   (0x00000020)
#define ADC_CFGR_RES     (0x00000018)
#define ADC_CFGR_DMACFG  (0x00000002)
#define ADC_CFGR_DMAEN   (0x00000001)


/** ADC sample time register 1 (ADC_SMPR1, x=1..4)
 * Offset: 0x14
 * Reset value: 0x0000 0000
 */
#define ADC_SMPR1_SMP9 (0x38000000)
#define ADC_SMPR1_SMP8 (0x07000000)
#define ADC_SMPR1_SMP7 (0x00e00000)
#define ADC_SMPR1_SMP6 (0x001c0000)
#define ADC_SMPR1_SMP5 (0x00038000)
#define ADC_SMPR1_SMP4 (0x00007000)
#define ADC_SMPR1_SMP3 (0x00000e00)
#define ADC_SMPR1_SMP2 (0x000001c0)
#define ADC_SMPR1_SMP1 (0x00000038)


/** ADC sample time register 2 (ADC_SMPR2, x=1..4)
 * Offset: 0x18
 * Reset value: 0x0000 0000
 */
#define ADC_SMPR2_SMP18 (0x07000000)
#define ADC_SMPR2_SMP17 (0x00e00000)
#define ADC_SMPR2_SMP16 (0x001c0000)
#define ADC_SMPR2_SMP15 (0x00038000)
#define ADC_SMPR2_SMP14 (0x00007000)
#define ADC_SMPR2_SMP13 (0x00000e00)
#define ADC_SMPR2_SMP12 (0x000001c0)
#define ADC_SMPR2_SMP11 (0x00000038)
#define ADC_SMPR2_SMP10 (0x00000007)


/** ADC watchdog threshold register 1 (ADCx_TR1, x=1..4)
 * Offset: 0x20
 * Reset vlaue: 0x0fff 0000
 */
#define ADC_TR1_HT1 (0x0fff0000)
#define ADC_TR1_LT1 (0x00000fff)


/** ADC watchdog threshold register 2 (ADCx_TR2, x=1..4)
 * Offset: 0x24
 * Reset vlaue: 0x0fff 0000
 */
#define ADC_TR2_HT2 (0x0fff0000)
#define ADC_TR2_LT2 (0x00000fff)


/** ADC watchdog threshold register 3 (ADCx_TR3, x=1..4)
 * Offset: 0x28
 * Reset vlaue: 0x0fff 0000
 */
#define ADC_TR3_HT3 (0x0fff0000)
#define ADC_TR3_LT3 (0x00000fff)


/** ADC regular sequence register 1(ADCx_SQR1, x=1..4)
 * Offset: 0x30
 * Reset value: 0x0000 0000
 */
#define ADC_SQR1_SQ4 (0x1f000000)
#define ADC_SQR1_SQ3 (0x007c0000)
#define ADC_SQR1_SQ2 (0x0001f000)
#define ADC_SQR1_SQ1 (0x000007c0)
#define ADC_SQR1_L   (0x0000000f)


/** ADC regular sequence register 2(ADCx_SQR2, x=1..4)
 * Offset: 0x34
 * Reset value: 0x0000 0000
 */
#define ADC_SQR2_SQ9 (0x1f000000)
#define ADC_SQR2_SQ8 (0x007c0000)
#define ADC_SQR2_SQ7 (0x0001f000)
#define ADC_SQR2_SQ6 (0x000007c0)
#define ADC_SQR2_SQ5 (0x0000001f)


/** ADC regular sequence register 3(ADCx_SQR3, x=1..4)
 * Offset: 0x38
 * Reset value: 0x0000 0000
 */
#define ADC_SQR3_SQ14 (0x1f000000)
#define ADC_SQR3_SQ13 (0x007c0000)
#define ADC_SQR3_SQ12 (0x0001f000)
#define ADC_SQR3_SQ11 (0x000007c0)
#define ADC_SQR3_SQ10 (0x0000001f)


/** ADC regular sequence register 4(ADCx_SQR4, x=1..4)
 * Offset: 0x3C
 * Reset value: 0x0000 0000
 */
#define ADC_SQR4_SQ16 (0x000007c0)
#define ADC_SQR4_SQ15 (0x0000001f)


/** ADC regular Data Register (ADCx_DR, x=1..4)
 * Offset: 0x40
 * Reset value: 0x0000 0000
 */
#define ADC_DR_RDATA (0x0000ffff)


/** ADC injected sequence register(ADCx_JSQR,x=1..4)
 * Offset: 0x4C
 * Reset value: 0x0000 0000
 */
#define ADC_JSQR_JSQ4    (0x7c000000)
#define ADC_JSQR_JSQ3    (0x01f00000)
#define ADC_JSQR_JSQ2    (0x0007c000)
#define ADC_JSQR_JSQ1    (0x00001f00)
#define ADC_JSQR_JEXTEN  (0x000000c0)
#define ADC_JSQR_JEXTSEL (0x0000007c)
#define ADC_JSQR_JL      (0x00000003)


/** ADC offset register(ADCx_OFRy,x=1..4, y=1..4)
 * Offset: 0x06, 0x64, 0x68, 0x6C
 * Reset value: 0x0000 0000
 */
#define ADC_OFR_OFFSET_EN (0x80000000)
#define ADC_OFR_OFFSET_CH (0x7c000000)
#define ADC_OFR_OFFSET    (0x00000fff)


/** ADC inject data register(ADCx_JDRy,x=1..4, y=1..4)
 * Offset: 0x80 - 0x8C
 * Reset value: 0x0000 0000
 */
#define ADC_JDR_JDATA (0x0000ffff)


/** ADC Analog Watchdog 2 Configuration Register(ADCx_AWD2CR, x=1..4)
 * Offset: 0xA0
 * Reset value: 0x0000 0000
 */
#define ADC_AWD2CR_AWD2CH (0x0007fffe)


/** ADC Analog Watchdog 3 Configuration Register(ADCx_AWD3CR, x=1..4)
 * Offset: 0xA4
 * Reset value: 0x0000 0000
 */
#define ADC_AWD3CR_AWD3CH (0x0007fffe)


/** ADC Differential Mode Selection Register(ADCx_DIFSEL, x=1..4)
 * Offset: 0xB0
 * Reset value: 0x0000 0000
 */
#define ADC_DIFSEL_DIFSEL (0x0007fffe)


/** ADC Calibration Factors(ADCx_CALFACT, x=1..4)
 * Offset: 0xB4
 * Reset Value: 0x0000 0000
 */
#define ADC_CALFACT_CALFACT_D (0x007f0000)
#define ADC_CALFACT_CALFACT_S (0x0000007f)



/** ADC Common status register(ADCx_CSR, x=12 or 34)
 * Offset: 0x00
 * Reset value: 0x0000 0000
 */
#define ADC_CSR_JQOVF_SLV (0x04000000)
#define ADC_CSR_AWD3_SLV  (0x02000000)
#define ADC_CSR_AWD2_SLV  (0x01000000)
#define ADC_CSR_AWD1_SLV  (0x00800000)
#define ADC_CSR_JEOS_SLV  (0x00400000)
#define ADC_CSR_JEOC_SLV  (0x00200000)
#define ADC_CSR_OVR_SLV   (0x00100000)
#define ADC_CSR_EOS_SLV   (0x00080000)
#define ADC_CSR_EOC_SLV   (0x00040000)
#define ADC_CSR_EOSMP_SLV (0x00020000)
#define ADC_CSR_ADRDY_SLV (0x00010000)
#define ADC_CSR_JQOVF_MST (0x00000400)
#define ADC_CSR_AWD3_MST  (0x00000200)
#define ADC_CSR_AWD2_MST  (0x00000100)
#define ADC_CSR_AWD1_MST  (0x00000080)
#define ADC_CSR_JEOS_MST  (0x00000040)
#define ADC_CSR_JEOC_MST  (0x00000020)
#define ADC_CSR_OVR_MST   (0x00000010)
#define ADC_CSR_EOS_MST   (0x00000008)
#define ADC_CSR_EOC_MST   (0x00000004)
#define ADC_CSR_EOSMP_MST (0x00000002)
#define ADC_CSR_ADRDY_MST (0x00000001)


/** ADC common control register (ADCx_CCR, x=12 or 34)
 * Offset: 0x08
 * Reset value: 0x0000 0000
 */
#define ADC_CCR_VBATEN (0x01000000)
#define ADC_CCR_TSEN   (0x00800000)
#define ADC_CCR_VREFEN (0x00400000)
#define ADC_CCR_CKMODE (0x00030000)
#define ADC_CCR_MDMA   (0x0000c000)
#define ADC_CCR_DMACFG (0x00002000)
#define ADC_CCR_DELAY  (0x00000f00)
#define ADC_CCR_DUAL   (0x0000001f)

#define ADC_CCR_CKMODE_CK_ADCX    (0x00000000)
#define ADC_CCR_CKMODE_HCLK_PER_1 (0x00010000)
#define ADC_CCR_CKMODE_HCLK_PER_2 (0x00020000)
#define ADC_CCR_CKMODE_HCLK_PER_4 (0x00030000)


/** ADC common regular data register for dual mode(ADCx_CDR, x = 12 or 34)
 * Offset: 0x0C
 * Reset value: 0x0000 0000
 */
#define ADC_CDR_RDATA_SLV (0xffff0000)
#define ADC_CDR_RDATA_MST (0x0000ffff)
#endif
