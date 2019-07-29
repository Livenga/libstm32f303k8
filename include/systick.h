#ifndef _SYSTICK_H
#define _SYSTICK_H

#include <stdint.h>
#include "io.h"


#define SYSTICK_ADDR ((void *)0xe000e010)
#define SYSTICK ((volatile systick_t *)SYSTICK_ADDR)

typedef struct _systick_t systick_t;
struct _systick_t {
  __IO uint32_t CTRL;
  __IO uint32_t LOAD;
  __IO uint32_t VAL;
  __IO uint32_t CALIB;
};


/** SysTick control and status register(STK_CTRL)
 * Offset: 0x00
 * Reset value: 0x0000 0000
 */
#define STK_CTRL_COUNTFLAG (0x00010000)
#define STK_CTRL_CLKSOURCE (0x00000004)
#define STK_CTRL_TICKINT   (0x00000002)
#define STK_CTRL_ENABLE    (0x00000001)

/** SysTick reload value register(STK_LOAD)
 * Offset: 0x04
 * Reset value: 0x0000 0000
 */
#define STK_LOAD_RELOAD (0x00ffffff)


/** SysTick current value register(STK_VAL)
 * Offset: 0x08
 * Reset value: 0x0000 0000
 */
#define STK_VAL_CURRENT (0x00ffffff)


/** SysTick calibration value register(STK_CALIB)
 * Offset: 0x0C
 * Reset value: 0x0000 0000
 */
#define STK_CALIB_NOREF (0x80000000)
#define STK_CALIB_SKEW  (0x40000000)
#define STK_CALIB_TENMS (0x00ffffff)
#endif
