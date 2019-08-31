#ifndef _SYSTEM_CONTORL_BLOCK_H
#define _SYSTEM_CONTORL_BLOCK_H

#include <stdint.h>
#include "io.h"

#define ACTLR_ADDRESS                (void *)0xe000e008
#define SYSTEM_CONTROL_BLOCK_ADDRESS (void *)0xe000ed00

#define ACTLR (volatile uint32_t *)ACTLR_ADDRESS
#define SYSTEM_CONTROL_BLOCK ((volatile system_control_block_t *)SYSTEM_CONTROL_BLOCK_ADDRESS)


typedef struct _system_control_block_t system_control_block_t;
struct _system_control_block_t {
  __RO uint32_t CPUID;     // 0x00
  __IO uint32_t ICSR;      // 0x04
  __IO uint32_t VTOR;      // 0x08
  __IO uint32_t AIRCR;     // 0x0C

  __IO uint32_t SCR;       // 0x10
  __IO uint32_t CCR;       // 0x14
  __IO uint32_t SHPR1;     // 0x18
  __IO uint32_t SHPR2;     // 0x1C

  __IO uint32_t SHPR3;     // 0x20
  __IO uint32_t SHCRS;     // 0x24
  __IO uint32_t CFSR;      // 0x28
  __IO uint32_t HFSR;      // 0x2C

  __RO uint32_t reserved0; // 0x30

  __IO uint32_t MMAR;      // 0x34
  __IO uint32_t BFAR;      // 0x38
  __IO uint32_t AFSR;      // 0x3C
};



/** CPUID Base Register
 * Offset: 0x00
 */
#define SCB_CPUID_IMPLEMENTER (0xff000000)
#define SCB_CPUID_VARIANT     (0x00f00000)
#define SCB_CPUID_CONSTANT    (0x000f0000)
#define SCB_CPUID_PARTNO      (0x0000fff0)
#define SCB_CPUID_REVISION    (0x0000000f)

/** Interrupt Control and State Register
 * Offset: 0x04
 */
#define SCB_ICSR_NMIPENDSET  (0x80000000)
#define SCB_ICSR_PENDSVSET   (0x10000000)
#define SCB_ICSR_PENDSVCLR   (0x08000000)
#define SCB_ICSR_PENDSTSET   (0x04000000)
#define SCB_ICSR_PENDSTCLR   (0x02000000)
#define SCB_ICSR_RESERVED_FOR_DEBUG_USE (0x00800000)
#define SCB_ICSR_ISRPENDING  (0x00400000)
#define SCB_ICSR_VECTPENDING (0x0003f000)
#define SCB_ICSR_RETTOBASE   (0x00000800)
#define SCB_ICSR_VECTACTIVE  (0x000000ff)

/** Vector Table Offset Register
 * Offset: 0x08
 */
#define SCB_ICSR_VTOR_TBLOFF (0x0ffffff8)



/** System handler Control and State Register
 * Offset: 0x24
 * Reset Value: 0x0000 0000
 */

// UsageFaulte enable bit
#define SCB_SHCRS_USGFAULTENA    (0x00040000)
// BusFault enable bit
#define SCB_SHCRS_BUSFAULTENA    (0x00020000)
// MemManage enable bit
#define SCB_SHCRS_MEMFAULTENA    (0x00010000)
// SVCall pending bit
#define SCB_SHCRS_SVCALLPENDED   (0x00008000)
// BusFault exception pending bit
#define SCB_SHCRS_BUSFAULTPENDED (0x00004000)
// MemManage exception pending bit
#define SCB_SHCRS_MEMFAULTPENDED (0x00002000)
// UsageFault exception pending bit
#define SCB_SHCRS_USGFAULTPENDED (0x00001000)
// SisTick exception active bit
#define SCB_SHCRS_SYSTICKACT     (0x00000800)
// PendSV exception active bit
#define SCB_SHCRS_PENDSVACT      (0x00000400)
// Debug monitor active bit
#define SCB_SHCRS_MONITORACT     (0x00000100)
// SVCall active bit
#define SCB_SHCRS_SVCALLACT      (0x00000080)
// UsageFault exception active bit
#define SCB_SHCRS_USGFAULTACT    (0x00000008)
// BusFault exception active bit
#define SCB_SHCRS_BUSFAULTACT    (0x00000002)
// MemManage exception active bit
#define SCB_SHCRS_MEMFAULTACT    (0x00000001)


/** Configurable Fault Status Register
 * Offset: 0x28
 * Reset Value: 0x0000 0000
 */
#define SCB_CFSR_UFSR  (0xffff0000)
#define SCB_CFSR_BFSR  (0x0000ff00)
#define SCB_CFSR_MMFSR (0x000000ff)

// MemManage Fault Address Register(MMFAR) valid flag
#define SCB_CFSR_MMFSR_MMARVALID (0x00000080)
// MemManage fault occurred during flpating-point lazy state preservation flag
#define SCB_CFSR_MMFSR_MLSPERR   (0x00000020)
// MemManage fault on stacking for exception entry
#define SCB_CFSR_MMFSR_MSTKERR   (0x00000010)
// MemManage fault on unstacking for a retrn from exception
#define SCB_CFSR_MMFSR_MUNSTKERR (0x00000008)
// Data access violation flag
#define SCB_CFSR_MMFSR_DACCVIOL  (0x00000002)
// Instrction access violation flag
#define SCB_CFSR_MMFSR_IACCVIOL  (0x00000001)


// BusFault Address Register(BFAR) valid flag
#define SCB_CFSR_BFSR_BFARVALID   (0x00008000)
//
#define SCB_CFSR_BFSR_LSPERR      (0x00002000)
// BusFault on stacking for exception entry
#define SCB_CFSR_BFSR_STKERR      (0x00001000)
// BusFault on unstacking for a return from exception
#define SCB_CFSR_BFSR_UNSTKERR    (0x00000800)
// Imprecise data bus error
#define SCB_CFSR_BFSR_IMPRECISERR (0x00000400)
// Precise data bus error
#define SCB_CFSR_BFSR_PRECISERR   (0x00000200)
// Instruction bus error
#define SCB_CFSR_BFSR_IBUSERR     (0x00000100)


// Divide by zero UsageFault
#define SCB_CFSR_UFSR_DIVBYZERO  (0x02000000)
// Unaligned access UsageFault
#define SCB_CFSR_UFSR_UNALIGNED  (0x01000000)
// No coprocessor UsageFault
#define SCB_CFSR_UFSR_NOCP       (0x00080000)
// Invalid PC load UsageFault
#define SCB_CFSR_UFSR_INVPC      (0x00040000)
// Invalid State UsageFault
#define SCB_CFSR_UFSR_INVSTATE   (0x00020000)
// Undefined instruction UsageFault
#define SCB_CFSR_UFSR_UNDEFINSTR (0x00010000)


/** HardFault Status Register
 * Offset: 0x2C
 * Reset Value: 0x0000 0000
 */
// Reserved for Debug use
#define SCB_HFSR_DEBUGEVT (0x80000000)
// Indicates a forced hard fault
#define SCB_HFSR_FORCED   (0x40000000)
// Indicates a BusFault on vector table read during exception processing
#define SCB_HFSR_VECTTBL  (0x00000002)
#endif
