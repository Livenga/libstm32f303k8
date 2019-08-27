#ifndef _DEVICE_H
#define _DEVICE_H

#include <stdint.h>

#define UNIQUE_DEVICE_IDR_ADDR ((volatile void *)0x1ffff7ac)
#define UNIQUE_DEVICE_IDR      ((volatile const uint32_t *)UNIQUE_DEVICE_IDR_ADDR)

#define FLASH_SIZE_DATAR       ((volatile void *)0x1ffff7cc)

extern uint8_t *
get_unique_device_id(void);

#endif
