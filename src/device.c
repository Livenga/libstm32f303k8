#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/utils.h"

static uint8_t _unique_device_id[32];

uint8_t *
get_unique_device_id(void) {
  xmemset((void *)_unique_device_id, '\0', sizeof(uint8_t) * 32);

  return (uint8_t *)_unique_device_id;
}
