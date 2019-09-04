#ifndef _USART_H
#define _USART_H


#include <stdint.h>
#include "io.h"


#define USART1_ADDR ((volatile void *)0x40013800)
#define USART2_ADDR ((volatile void *)0x40004400)
#define USART3_ADDR ((volatile void *)0x40004800)

#define USART1 ((usart_t *)USART1_ADDR)
#define USART2 ((usart_t *)USART2_ADDR)
#define USART3 ((usart_t *)USART3_ADDR)

typedef struct _usart_t usart_t;

struct _usart_t {
  __IO uint32_t CR1;  // 0x00
  __IO uint32_t CR2;  // 0x04
  __IO uint32_t CR3;  // 0x08
  __IO uint32_t BRR;  // 0x0C
  __IO uint32_t GTPR; // 0x10
  __IO uint32_t RTOR; // 0x14
  __IO uint32_t RQR;  // 0x18
  __RO uint32_t ISR;  // 0x1C
  __IO uint32_t ICR;  // 0x20
  __RO uint32_t RDR;  // 0x24
  __IO uint32_t TDR;  // 0x28
};


/** Control register 1(USART_CR1)
 * Offset: 0x00
 * Reset value: 0x0000 0000
 */
#define USART_CR1_M1     (0x10000000)
#define USART_CR1_EOBIE  (0x08000000)
#define USART_CR1_RTOIE  (0x04000000)
#define USART_CR1_DEAT   (0x03e00000)
#define USART_CR1_DEDT   (0x001f0000)
#define USART_CR1_OVER8  (0x00008000)
#define USART_CR1_CMIE   (0x00004000)
#define USART_CR1_MME    (0x00002000)
#define USART_CR1_M0     (0x00001000)
#define USART_CR1_WAKE   (0x00000800)
#define USART_CR1_PCE    (0x00000400)
#define USART_CR1_PS     (0x00000200)
#define USART_CR1_PEIE   (0x00000100)
#define USART_CR1_TXEIE  (0x00000080)
#define USART_CR1_TCIE   (0x00000040)
#define USART_CR1_RXNEIE (0x00000020)
#define USART_CR1_IDLEIE (0x00000010)
#define USART_CR1_TE     (0x00000008)
#define USART_CR1_RE     (0x00000004)
#define USART_CR1_UESM   (0x00000002)
#define USART_CR1_UE     (0x00000001)


/** Control register 2(USART_CR2)
 * Offset: 0x04
 * Reset value: 0x0000 0000
 */
#define USART_CR2_ADD      (0xff000000)
#define USART_CR2_RTOEN    (0x00800000)
#define USART_CR2_ABRMOD   (0x00600000)
#define USART_CR2_ABREN    (0x00100000)
#define USART_CR2_MSBFIRST (0x00080000)
#define USART_CR2_DATAINV  (0x00040000)
#define USART_CR2_TXINV    (0x00020000)
#define USART_CR2_RXINV    (0x00010000)
#define USART_CR2_SWAP     (0x00008000)
#define USART_CR2_LINEN    (0x00004000)
#define USART_CR2_STOP     (0x00003000)
#define USART_CR2_CLKEN    (0x00000800)
#define USART_CR2_CPOL     (0x00000400)
#define USART_CR2_CPHA     (0x00000200)
#define USART_CR2_LBCL     (0x00000100)
#define USART_CR2_LBDIE    (0x00000040)
#define USART_CR2_LBDL     (0x00000020)
#define USART_CR2_ADDM7    (0x00000010)


/** Control register 3(USART_CR3)
 * Offset: 0x08
 * Reset value: 0x0000 0000
 */
#define USART_CR3_WUFIE   (0x00400000)
#define USART_CR3_WUS     (0x00300000)
#define USART_CR3_SCARCNT (0x000e0000)
#define USART_CR3_DEP     (0x00008000)
#define USART_CR3_DEM     (0x00004000)
#define USART_CR3_DDRE    (0x00002000)
#define USART_CR3_OVRDIS  (0x00001000)
#define USART_CR3_ONEBIT  (0x00000800)
#define USART_CR3_CTSIE   (0x00000400)
#define USART_CR3_CTSE    (0x00000200)
#define USART_CR3_RTSE    (0x00000100)
#define USART_CR3_DMAT    (0x00000080)
#define USART_CR3_DMAR    (0x00000040)
#define USART_CR3_SCEN    (0x00000020)
#define USART_CR3_NACK    (0x00000010)
#define USART_CR3_HDSEL   (0x00000008)
#define USART_CR3_IRLP    (0x00000004)
#define USART_CR3_IREN    (0x00000002)
#define USART_CR3_EIE     (0x00000001)


/** Baudrate register(USART_BRR)
 * Offset: 0x0C
 * Reset value: 0x0000 0000
 */
#define USART_BRR_BRR (0x0000ffff)


/** Guard time and prescaler register(USART_GTPR)
 * Offset: 0x10
 * Reset value: 0x0000 0000
 */
#define USART_GTPR_GT  (0x0000ff00)
#define USART_GTPR_PSC (0x000000ff)


/** Receiver timeout register(USART_RTOR)
 * Offset: 0x14
 * Reset value: 0x0000 0000
 */
#define USART_RTOR_BLEN (0x0f000000)
#define USART_RTOR_RTO  (0x00ffffff)


/** Request register(USART_RQR)
 * Offset: 0x18
 * Reset value: 0x0000 0000
 */
#define USART_RQR_TXFRQ (0x00000010)
#define USART_RQR_RXFRQ (0x00000008)
#define USART_RQR_MMRQ  (0x00000004)
#define USART_RQR_SBKRQ (0x00000002)
#define USART_RQR_ABRRQ (0x00000001)


/** Interrupt and status register(USART_ISR)
 * Offset: 0x1C
 * Reset value: 0x0020 00c0
 */
#define USART_ISR_REACK (0x00400000)
#define USART_ISR_TEACK (0x00200000)
#define USART_ISR_WUF   (0x00100000)
#define USART_ISR_RWU   (0x00080000)
#define USART_ISR_SBKF  (0x00040000)
#define USART_ISR_CMF   (0x00020000)
#define USART_ISR_BUSY  (0x00010000)
#define USART_ISR_ABRF  (0x00008000)
#define USART_ISR_ABRE  (0x00004000)
#define USART_ISR_EOBF  (0x00001000)
#define USART_ISR_RTOF  (0x00000800)
#define USART_ISR_CTS   (0x00000400)
#define USART_ISR_CTSIF (0x00000200)
#define USART_ISR_LBDF  (0x00000100)
#define USART_ISR_TXE   (0x00000080)
#define USART_ISR_TC    (0x00000040)
#define USART_ISR_RXNE  (0x00000020)
#define USART_ISR_IDLE  (0x00000010)
#define USART_ISR_ORE   (0x00000008)
#define USART_ISR_NF    (0x00000004)
#define USART_ISR_FE    (0x00000002)
#define USART_ISR_PE    (0x00000001)


/** Interrupt flag clear register(USART_ICR)
 * Offset: 0x20
 * Reset value: 0x0000 0000
 */
#define USART_ICR_WUCF   (0x00100000)
#define USART_ICR_CMCF   (0x00020000)
#define USART_ICR_EOBCF  (0x00000100)
#define USART_ICR_RTOCF  (0x00000800)
#define USART_ICR_CTSCF  (0x00000200)
#define USART_ICR_LBDCF  (0x00000100)
#define USART_ICR_TCCF   (0x00000040)
#define USART_ICR_IDLECF (0x00000010)
#define USART_ICR_ORECF  (0x00000008)
#define USART_ICR_NCF    (0x00000004)
#define USART_ICR_FECF   (0x00000002)
#define USART_ICR_PECF   (0x00000001)


/** Receive data register(USART_RDR)
 * Offset: 0x24
 * Reset value: 0x0000 0000
 */
#define USART_RDR_RDR (0x000000ff)


/** Transmit data register(USART_TDR)
 * Offset: 0x28
 * Reset value
 */
#define USART_TDR_TDR (0x000000ff)
#endif
