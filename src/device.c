#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/utils.h"
#include "../include/device.h"

#define DEC2HEX(dec) \
  ((dec > 9) ? ('A' + (dec - 10)) : '0' + dec)


static uint8_t
_hex_unique_device_id[32];


uint8_t *
get_unique_device_id(void) {
  int i, j;

  char *p_str;
  p_str = (char *)_hex_unique_device_id;


  //xmemset((void *)_hex_unique_device_id, '\0', sizeof(uint8_t) * 32);
  memset((void *)_hex_unique_device_id, '\0', sizeof(uint8_t) * 32);


  for(i = 0; i < 3; ++i) {
    uint32_t _val = *(UNIQUE_DEVICE_IDR + i);

    for(j = 0; j < 8; ++j) {
      uint8_t _shift = 32 - (4 * (j + 1));
      char _c = DEC2HEX((char)((_val >> _shift) & 0x0f));

      *p_str++ = _c;
    }

    if(i != 2) {
      *p_str++ = '-';
    }
  }

  return (uint8_t *)_hex_unique_device_id;
}
