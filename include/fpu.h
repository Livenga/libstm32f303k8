#ifndef _FPU_H
#define _FPU_H

#include <stdint.h>
#include "io.h"


#define FP_CPACR_ADDRESS ((volatile void *)0xe000ed88)
#define FP_CPACR *(volatile uint32_t *)FP_CPACR_ADDRESS


#endif
