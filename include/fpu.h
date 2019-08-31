#ifndef _FPU_H
#define _FPU_H

#include <stdint.h>
#include "io.h"


#define FPU_CPACR_ADDRESS ((volatile void *)0xe000ed88)
#define FPU_CPACR         *(volatile uint32_t *)FPU_CPACR_ADDRESS

#define FPU_ADDRESS ((volatile void *)0xe000ef34)
#define FPU         ((volatile fpu_t *)FPU_ADDRESS)

typedef struct _fpu_t fpu_t;
struct _fpu_t {
  __IO uint32_t FPCCR;

  union {
    __IO uint32_t FPCAR;
    __IO uint32_t FPSCR;
  };

  __IO uint32_t FPDSCR;
};


/** Coprocessor Access Control Register
 * Address:     0xE000ED88
 * Reset value: 0x0000 0000
 */
#define FPU_CPACR_CP10 (0x00300000)
#define FPU_CPACR_CP11 (0x00c00000)

#define FPU_CPACR_CP_ACCESS_DENIED     (0b00)
#define FPU_CPACR_CP_PRIVILEGED_ACCESS (0b01)
#define FPU_CPACR_CP_FULL_ACCESS       (0b10)


/** Floating-point Context Control Register
 * Address: 0xE000EF34
 * Reset value: 0xC000 0000
 */
#define FPU_FPCCR_ASPEN  (0x80000000)
#define FPU_FPCCR_LSPEN  (0x40000000)
#define FPU_FPCCR_MONRDY (0x00000100)
#define FPU_FPCCR_BFRDY  (0x00000040)
#define FPU_FPCCR_MMRDY  (0x00000020)
#define FPU_FPCCR_HFRDY  (0x00000010)
#define FPU_FPCCR_THREAD (0x00000008)
#define FPU_FPCCR_USER   (0x00000002)
#define FPU_FPCCR_LSPACT (0x00000001)


/** Floating-point Context Address Register
 * Address: 0xE000EF38
 * Reset value: -
 */
#define FPU_FPCAR_ADDRESS (0xfffffff8)


/** Floating-point Status Control Register
 * Address: 0xE000EF38
 * Reset value: -
 */
#define FPU_FPSCR_N     (0x80000000)
#define FPU_FPSCR_Z     (0x40000000)
#define FPU_FPSCR_C     (0x20000000)
#define FPU_FPSCR_V     (0x10000000)
#define FPU_FPSCR_AHP   (0x04000000)
#define FPU_FPSCR_DN    (0x02000000)
#define FPU_FPSCR_FZ    (0x01000000)
#define FPU_FPSCR_RMODE (0x00c00000)
#define FPU_FPSCR_IDC   (0x00000080)
#define FPU_FPSCR_IXC   (0x00000010)
#define FPU_FPSCR_UFC   (0x00000008)
#define FPU_FPSCR_OFC   (0x00000004)
#define FPU_FPSCR_DZC   (0x00000002)
#define FPU_FPSCR_IOC   (0x00000001)

/** Floating-point Default Status Control Register
 * Address: 0xE000EF3C
 * Reset value: 0x0000 0000
 */
#define FPU_FPDSCR_AHP   (0x04000000)
#define FPU_FPDSCR_DN    (0x02000000)
#define FPU_FPDSCR_FZ    (0x01000000)
#define FPU_FPDSCR_RMODE (0x00c00000)

#endif
