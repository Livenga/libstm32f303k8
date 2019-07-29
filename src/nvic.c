#include <stdio.h>
#include <stdint.h>

#include "../include/nvic.h"


struct position_t {
  int index;
  int shift;
};

#define _get_position(n, div) \
  (struct position_t){.index = n / div, .shift = n % div}


void
nvic_enable_IRQ(IRQn_t n) {
  struct position_t p = _get_position(n, 32);
  *(NVIC->ISER + p.index) |= (1 << p.shift);
}

void
nvic_disable_IRQ(IRQn_t n) {
  struct position_t p = _get_position(n, 32);
  *(NVIC->ICER + p.index) |= (1 << p.shift);
}


void
nvic_set_pending_IRQ(IRQn_t n) {
  struct position_t p = _get_position(n, 32);
  *(NVIC->ISPR + p.index) |= (1 << p.shift);
}

void
nvic_clear_pending_IRQ(IRQn_t n) {
  struct position_t p = _get_position(n, 32);
  *(NVIC->ICPR + p.index) |= (1 << p.shift);
}

uint32_t
nvic_get_pending_IRQ(IRQn_t n) {
  struct position_t p = _get_position(n, 32);
  return (*(NVIC->ISPR + p.index) >> p.shift) & 1;
}


void
nvic_set_priority(IRQn_t n, uint32_t priority) {
  struct position_t p = _get_position(n, 4);
  *(NVIC->IPR + p.index) =
    (*(NVIC->IPR + p.index) & (0xff << (p.shift * 8)))
    | (priority << p.shift * 8);
}

uint32_t
nvic_get_priority(IRQn_t n) {
  struct position_t p = _get_position(n, 4);
  return (*(NVIC->IPR + p.index) >> (p.shift * 8)) & 0xff;
}
