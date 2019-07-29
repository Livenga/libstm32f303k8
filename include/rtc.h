#ifndef _RTC_H
#define _RTC_H

#include <stdint.h>
#include "io.h"


#define RTC_ADDR ((void *)0x40002800)
#define RTC ((volatile rtc_t *)RTC_ADDR)


typedef struct _rtc_t rtc_t;
struct _rtc_t {
  __IO uint32_t TR;       // 0x00
  __IO uint32_t DR;       // 0x04
  __IO uint32_t CR;       // 0x08
  __IO uint32_t ISR;      // 0x0C
  __IO uint32_t PRER;     // 0x10
  __IO uint32_t WUTR;     // 0x14

  __RO uint32_t reserved0; // 0x18

  __IO uint32_t ALRMAR;   // 0x1C
  __IO uint32_t ALRMBR;   // 0x20
  __IO uint32_t WPR;      // 0x24
  __RO uint32_t SSR;      // 0x28
  __IO uint32_t SHIFTR;   // 0x2C
  __RO uint32_t TSTR;     // 0x30
  __RO uint32_t TSDR;     // 0x34
  __IO uint32_t TSSSR;    // 0x38
  __IO uint32_t CALR;     // 0x3C
  __IO uint32_t TAFCR;    // 0x40
  __IO uint32_t ALRMASSR; // 0x44
  __IO uint32_t ALRMBSSR; // 0x48

  __RO uint32_t reserved1; // 0x4C

  __IO uint32_t BKPR[16]; // 0x50 - 0x8C
};


/** RTC time register(RTC_TR)
 * Offset: 0x00
 * Reset value: 0x0000 0000
 */
#define RTC_TR_PM  (0x00400000)
#define RTC_TR_HT  (0x00300000)
#define RTC_TR_HU  (0x000f0000)
#define RTC_TR_MNT (0x00007000)
#define RTC_TR_MNU (0x00000f00)
#define RTC_TR_ST  (0x00000070)
#define RTC_TR_SU  (0x0000000f)


/** RTC data register(RTC_DR)
 * Offset: 0x04
 * Reset value: 0x0000 2101
 */
#define RTC_DR_YT  (0x00f00000)
#define RTC_DR_YU  (0x000f0000)
#define RTC_DR_WDU (0x0000e000)
#define RTC_DR_MT  (0x00001000)
#define RTC_DR_MU  (0x00000f00)
#define RTC_DR_DT  (0x00000030)
#define RTC_DR_DU  (0x0000000f)


/** RTC control register(RTC_CR)
 * Offset: 0x08
 * Reset value: 0x0000 0000
 */
#define RTC_CR_COE     (0x00800000)
#define RTC_CR_OSEL    (0x00600000)
#define RTC_CR_POL     (0x00100000)
#define RTC_CR_COSEL   (0x00080000)
#define RTC_CR_BKP     (0x00040000)
#define RTC_CR_SUB1H   (0x00020000)
#define RTC_CR_ADD1H   (0x00010000)
#define RTC_CR_TSIE    (0x00008000)
#define RTC_CR_WUTIE   (0x00004000)
#define RTC_CR_ALRBIE  (0x00002000)
#define RTC_CR_ALRAIE  (0x00001000)
#define RTC_CR_TSE     (0x00000800)
#define RTC_CR_WUTE    (0x00000400)
#define RTC_CR_ALRBE   (0x00000200)
#define RTC_CR_ALRAE   (0x00000100)
#define RTC_CR_FMT     (0x00000040)
#define RTC_CR_BYPSHAD (0x00000020)
#define RTC_CR_REFCKON (0x00000010)
#define RTC_CR_TSEDGE  (0x00000008)
#define RTC_CR_WUCKSEL (0x00000007)


/** RTC initialization and status register(RTC_ISR)
 * Offset: 0x0C
 * Reset value: 0x0000 0007
 */
#define RTC_ISR_RECALPF (0x00010000)
#define RTC_ISR_TAMP3F  (0x00008000)
#define RTC_ISR_TAMP2F  (0x00004000)
#define RTC_ISR_TAMP1F  (0x00002000)
#define RTC_ISR_TSOVF   (0x00001000)
#define RTC_ISR_TSF     (0x00000800)
#define RTC_ISR_WUTF    (0x00000400)
#define RTC_ISR_ALRBF   (0x00000200)
#define RTC_ISR_ALRAF   (0x00000100)
#define RTC_ISR_INIT    (0x00000080)
#define RTC_ISR_INITF   (0x00000040)
#define RTC_ISR_RSF     (0x00000020)
#define RTC_ISR_INITS   (0x00000010)
#define RTC_ISR_SHPF    (0x00000008)
#define RTC_ISR_WUTWF   (0x00000004)
#define RTC_ISR_ALRBWF  (0x00000002)
#define RTC_ISR_ALRAWF  (0x00000001)


/** RTC prescaler register(RTC_PRER)
 * Offset: 0x10
 * Reset value: 0x007f 00ff
 */
#define RTC_PRER_PREDIV_A (0x007f0000)
#define RTC_PRER_PREDIV_S (0x00007fff)


/** RTC wakeup timer register(RTC_WUTR)
 * Offset: 0x14
 * Reset value: 0x0000 ffff
 */
#define RTC_WUTR_WUT (0x0000ffff)


/** RTC alarm A register(RTC_ALRMAR)
 * Offset: 0x1C
 * Reset value: 0x0000 0000
 */
#define RTC_ALRMAR_MSK4  (0x80000000)
#define RTC_ALRMAR_WDSEL (0x40000000)
#define RTC_ALRMAR_DT    (0x30000000)
#define RTC_ALRMAR_DU    (0x0f000000)
#define RTC_ALRMAR_MSK3  (0x00800000)
#define RTC_ALRMAR_PM    (0x00400000)
#define RTC_ALRMAR_HT    (0x00300000)
#define RTC_ALRMAR_HU    (0x000f0000)
#define RTC_ALRMAR_MSK2  (0x00008000)
#define RTC_ALRMAR_MNT   (0x00007000)
#define RTC_ALRMAR_MNU   (0x00000f00)
#define RTC_ALRMAR_MSK1  (0x00000080)
#define RTC_ALRMAR_ST    (0x00000070)
#define RTC_ALRMAR_SU    (0x0000000f)


/** RTC alarm B register(RTC_ALRMBR)
 * Offset: 0x20
 * Reset value: 0x0000 0000
 */
#define RTC_ALRMBR_MSK4  (0x80000000)
#define RTC_ALRMBR_WDSEL (0x40000000)
#define RTC_ALRMBR_DT    (0x30000000)
#define RTC_ALRMBR_DU    (0x0f000000)
#define RTC_ALRMBR_MSK3  (0x00800000)
#define RTC_ALRMBR_PM    (0x00400000)
#define RTC_ALRMBR_HT    (0x00300000)
#define RTC_ALRMBR_HU    (0x000f0000)
#define RTC_ALRMBR_MSK2  (0x00008000)
#define RTC_ALRMBR_MNT   (0x00007000)
#define RTC_ALRMBR_MNU   (0x00000f00)
#define RTC_ALRMBR_MSK1  (0x00000080)
#define RTC_ALRMBR_ST    (0x00000070)
#define RTC_ALRMBR_SU    (0x0000000f)


/** RTC write protection register(RTC_WPR)
 * Offset: 0x24
 * Reset value: 0x0000 0000
 */
#define RTC_WPR_KEY (0x000000ff)


/** RTC sub second register(RTC_SSR)
 * Offset: 0x28
 * Reset value: 0x0000 0000
 */
#define RTC_SSR_SS (0x0000ffff)


/** RTC shift control register(RTC_SHIFTR)
 * Offset: 0x2C
 * Reset value: 0x0000 0000
 */
#define RTC_SHIFTR_ADD1S (0x80000000)
#define RTC_SHIFTR_SUBFS (0x00007fff)


/** RTC timestamp time register(RTC_TSTR)
 * Offset: 0x30
 * Reset value: 0x0000 0000
 */
#define RTC_TSTR_PM  (0x00400000)
#define RTC_TSTR_HT  (0x00300000)
#define RTC_TSTR_HU  (0x000f0000)
#define RTC_TSTR_MNT (0x00007000)
#define RTC_TSTR_MNU (0x00000f00)
#define RTC_TSTR_ST  (0x00000070)
#define RTC_TSTR_SU  (0x0000000f)


/** RTC timestamp date register(RTC_TSDR)
 * Offset: 0x34
 * Reset value: 0x0000 0000
 */
#define RTC_TSDR_WDU (0x0000e000)
#define RTC_TSDR_MT  (0x00001000)
#define RTC_TSDR_MU  (0x00000f00)
#define RTC_TSDR_DT  (0x00000030)
#define RTC_TSDR_DU  (0x0000000f)


/** RTC time-stamp sub second register(RTC_TSSSR)
 * Offset: 0x38
 * Reset value: 0x0000 0000
 */
#define RTC_TSSSR_SS (0x0000ffff)


/** RTC calibration register(RTC_CALR)
 * Offset: 0x3C
 * Reset value: 0x0000 0000
 */
#define RTC_CALR_CALP   (0x00008000)
#define RTC_CALR_CALW8  (0x00004000)
#define RTC_CALR_CALW16 (0x00002000)
#define RTC_CALR_CALM   (0x000001ff)


/** RTC tamper and alternate function configuration register(RTC_TAFCR)
 * Offset: 0x40
 * Reset value: 0x0000 0000
 */
#define RTC_TAFCR_PC15MODE  (0x00800000)
#define RTC_TAFCR_PC15VALUE (0x00400000)
#define RTC_TAFCR_PC14MODE  (0x00200000)
#define RTC_TAFCR_PC14VALUE (0x00100000)
#define RTC_TAFCR_PC13MODE  (0x00080000)
#define RTC_TAFCR_PC13VALUE (0x00040000)
#define RTC_TAFCR_TAMPPUDIS (0x00008000)
#define RTC_TAFCR_TAMPPRCH  (0x00006000)
#define RTC_TAFCR_TAMPFLT   (0x00001800)
#define RTC_TAFCR_TAMPFREQ  (0x00000700)
#define RTC_TAFCR_TAMPTS    (0x00000080)

#define RTC_TAFCR_TAMP3TRG  (0x00000040)
#define RTC_TAFCR_TAMP3E    (0x00000020)

#define RTC_TAFCR_TAMP2TRG  (0x00000010)
#define RTC_TAFCR_TAMP2E    (0x00000008)
#define RTC_TAFCR_TAMPIE    (0x00000004)
#define RTC_TAFCR_TAMP1TRG  (0x00000002)
#define RTC_TAFCR_TAMP1E    (0x00000001)


/** RTC alarm A sub second register(RTC_ALRMASSR)
 * Offset: 0x44
 * Reset value: 0x0000 0000
 */
#define RTC_ALRMASSR_MASKSS (0x0f000000)
#define RTC_ALRMASSR_SS     (0x00007fff)


/** RTC alarm B sub second register(RTC_ALRMBSSR)
 * Offset: 0x48
 * Reset value: 0x0000 0000
 */
#define RTC_ALRMBSSR_MASKSS (0x0f000000)
#define RTC_ALRMBSSR_SS     (0x00007fff)


/** RTC backup register(RTC_BKPxR)
 * Offset:0x50 - 0x8C
 * Reset value: 0x0000 0000
 */
#define RTC_BKPR_BKP (0xffffffff)
#endif
