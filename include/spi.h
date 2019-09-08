#ifndef _SPI_H
#define _SPI_H

#include <stdint.h>
#include "io.h"


#define SPI1_ADDRESS ((volatile void *)0x40013000)
#define SPI1 ((spi_t *)SPI1_ADDRESS)


typedef struct _spi_t spi_t;
struct _spi_t {
  __IO uint32_t CR1;     // 0x00
  __IO uint32_t CR2;     // 0x04
  __IO uint32_t SR;      // 0x08
  __IO uint32_t DR;      // 0x0C
  __IO uint32_t CRCPR;   // 0x10
  __RO uint32_t RXCRCR;  // 0x14
  __RO uint32_t TXCRCR;  // 0x18
  __IO uint32_t I2SCFGR; // 0x1C
  __IO uint32_t I2SPR;   // 0x20
};


/** SPI control register(SPIx_CR1)
 * Offset: 0x00
 * Reset value: 0x0000
 */
#define SPI_CR1_BIDIMODE (0x00008000)
#define SPI_CR1_BIDIOE   (0x00004000)
#define SPI_CR1_CRCEN    (0x00002000)
#define SPI_CR1_CRCNEXT  (0x00001000)
#define SPI_CR1_CRCL     (0x00000800)
#define SPI_CR1_RXONLY   (0x00000400)
#define SPI_CR1_SSM      (0x00000200)
#define SPI_CR1_SSI      (0x00000100)
#define SPI_CR1_LSBFIRST (0x00000080)
#define SPI_CR1_SPE      (0x00000040)
#define SPI_CR1_BR       (0x00000038)
#define SPI_CR1_MSTR     (0x00000004)
#define SPI_CR1_CPOL     (0x00000002)
#define SPI_CR1_CPHA     (0x00000001)


/** SPI control register 2(SPIx_CR2)
 * Offset: 0x04
 * Reset value: 0x0700
 */
#define SPI_CR2_LDMA_TX (0x00004000)
#define SPI_CR2_LDMA_RX (0x00002000)
#define SPI_CR2_FRXTH   (0x00001000)
#define SPI_CR2_DS      (0x00000f00)
#define SPI_CR2_TXEIE   (0x00000080)
#define SPI_CR2_RXNEIE  (0x00000040)
#define SPI_CR2_ERRIE   (0x00000020)
#define SPI_CR2_FRF     (0x00000010)
#define SPI_CR2_NSSP    (0x00000008)
#define SPI_CR2_SSOE    (0x00000004)
#define SPI_CR2_TXDMAEN (0x00000002)
#define SPI_CR2_RXDMAEN (0x00000001)


/** SPI status register(SPIx_SR)
 * Offset: 0x08
 * Reset value: 0x0002
 */
#define SPI_SR_FTLVL  (0x00001800)
#define SPI_SR_FRLVL  (0x00000600)
#define SPI_SR_FRE    (0x00000100)
#define SPI_SR_BSY    (0x00000080)
#define SPI_SR_OVR    (0x00000040)
#define SPI_SR_MODF   (0x00000020)
#define SPI_SR_CRCERR (0x00000010)
#define SPI_SR_UDR    (0x00000008)
#define SPI_SR_CHSIDE (0x00000004)
#define SPI_SR_TXE    (0x00000002)
#define SPI_SR_RXNE   (0x00000001)


/** SPI data register(SPI_DR)
 * Offset: 0x0c
 * Reset value: 0x0000
 */
#define SPI_DR_DR (0x0000ffff)


/** SPI CRC polynomial register(SPIx_CRCPR)
 * Offset: 0x10
 * Reset value: 0x0007
 */
#define SPI_CRCPR_CRCPOLY (0x0000ffff)


/** SPI Rx CRC register(SPIx_RXCRCR)
 * Offset: 0x14
 * Reset value: 0x0000
 */
#define SPI_RXCRCR_RXCRC (0x0000ffff)


/** SPI Tx CRC register(SPIx_TXCRCR)
 * Offset: 0x18
 * Reset value: 0x0000
 */
#define SPI_TXCRCR_TXCRC (0x0000ffff)


/** SPIx_I2S configuration register(SPIx_I2SCFGR)
 * Offset: 0x1C
 * Reset value: 0x0000
 */
#define SPI_I2SCFGR_I2SMOD  (0x00000800)
#define SPI_I2SCFGR_I2SE    (0x00000400)
#define SPI_I2SCFGR_I2SCFG  (0x00000300)
#define SPI_I2SCFGR_PCMSYNC (0x00000080)
#define SPI_I2SCFGR_I2SSTD  (0x00000030)
#define SPI_I2SCFGR_CKPOL   (0x00000008)
#define SPI_I2SCFGR_DATLEN  (0x00000006)
#define SPI_I2SCFGR_CHLEN   (0x00000001)


/** SPIx_I2S prescaler register(SPIx_I2SPR)
 * Offset: 0x20
 * Reset value: 0b00000010(0x0002)
 */
#define SPI_I2SPR_MCKOE  (0x00000200)
#define SPI_I2SPR_ODD    (0x00000100)
#define SPI_I2SPR_I2SDIV (0x000000ff)
#endif
