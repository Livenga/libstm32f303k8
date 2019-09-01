#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>

#include "io.h"


#define GPIOA_ADDR ((void *)0x48000000)
#define GPIOB_ADDR ((void *)0x48000400)

#define GPIOA ((volatile gpio_t *)GPIOA_ADDR)
#define GPIOB ((volatile gpio_t *)GPIOB_ADDR)

typedef struct _gpio_t gpio_t;
struct _gpio_t {
  __IO uint32_t MODER;   // 0x00
  __IO uint32_t OTYPER;  // 0x04
  __IO uint32_t OSPEEDR; // 0x08
  __IO uint32_t PUPDR;   // 0x0C
  __IO uint32_t IDR;     // 0x10
  __IO uint32_t ODR;     // 0x14
  __IO uint32_t BSRR;    // 0x18
  __IO uint32_t LCKR;    // 0x1C
  __IO uint32_t AFRL;    // 0x20
  __IO uint32_t AFRH;    // 0x24
  __IO uint32_t BRR;     // 0x28
};


// GPIO mode
#define GPIO_MODE_INPUT              (0b00)
#define GPIO_MODE_OUTPUT             (0b01)
#define GPIO_MODE_ALTERNATE_FUNCTION (0b10)
#define GPIO_MODE_ANALOG             (0b11)

#define gpio_set_mode(p_gpio, n, mode) \
  p_gpio->MODER = ((p_gpio->MODER & ~GPIO_MODER_MODER##n) | ((mode & 0b11) << (n * 2)))


// GPIO speed
#define GPIO_OSPEED_LOW    (0b00)
#define GPIO_OSPEED_MEDIUM (0b01)
#define GPIO_OSPEED_HIGH   (0b11)
#define gpio_set_ospeed(p_gpio, n, mode) \
  p_gpio->OSPEEDR = ((p_gpio->OSPEEDR & ~GPIO_OSPEEDR_OSPEEDR#n) | ((mode & 0b11) << (n * 2)))

// On
#define gpio_on(p_gpio, n) \
  p_gpio->ODR |= (1 << n)

// Off
#define gpio_off(p_gpio, n) \
  p_gpio->ODR &= ~(1 << n)


/** GPIO port mode register(GPIOx_MODER)
 * Offset: 0x00
 */
#define GPIO_MODER_MODER15 (0xc0000000)
#define GPIO_MODER_MODER14 (0x30000000)
#define GPIO_MODER_MODER13 (0x0c000000)
#define GPIO_MODER_MODER12 (0x03000000)
#define GPIO_MODER_MODER11 (0x00c00000)
#define GPIO_MODER_MODER10 (0x00300000)
#define GPIO_MODER_MODER9  (0x000c0000)
#define GPIO_MODER_MODER8  (0x00030000)
#define GPIO_MODER_MODER7  (0x0000c000)
#define GPIO_MODER_MODER6  (0x00003000)
#define GPIO_MODER_MODER5  (0x00000c00)
#define GPIO_MODER_MODER4  (0x00000300)
#define GPIO_MODER_MODER3  (0x000000c0)
#define GPIO_MODER_MODER2  (0x00000030)
#define GPIO_MODER_MODER1  (0x0000000c)
#define GPIO_MODER_MODER0  (0x00000003)


/** GPIO port output type register(GPIOx_OTYPER)
 * Offset: 0x04
 * Reset value: 0x0000 0000
 */
#define GPIO_OTYPER_OT15 (0x00008000)
#define GPIO_OTYPER_OT14 (0x00004000)
#define GPIO_OTYPER_OT13 (0x00002000)
#define GPIO_OTYPER_OT12 (0x00001000)
#define GPIO_OTYPER_OT11 (0x00000800)
#define GPIO_OTYPER_OT10 (0x00000400)
#define GPIO_OTYPER_OT9  (0x00000200)
#define GPIO_OTYPER_OT8  (0x00000100)
#define GPIO_OTYPER_OT7  (0x00000080)
#define GPIO_OTYPER_OT6  (0x00000040)
#define GPIO_OTYPER_OT5  (0x00000020)
#define GPIO_OTYPER_OT4  (0x00000010)
#define GPIO_OTYPER_OT3  (0x00000008)
#define GPIO_OTYPER_OT2  (0x00000004)
#define GPIO_OTYPER_OT1  (0x00000002)
#define GPIO_OTYPER_OT0  (0x00000001)


/** GPIO port output speed register(GPIOx_OSPEEDR)
 * Offset: 0x08
 * Reset value: 0x0000 0000
 */
#define GPIO_OSPEEDR_OSPEEDR15 (0xc0000000)
#define GPIO_OSPEEDR_OSPEEDR14 (0x30000000)
#define GPIO_OSPEEDR_OSPEEDR13 (0x0c000000)
#define GPIO_OSPEEDR_OSPEEDR12 (0x03000000)
#define GPIO_OSPEEDR_OSPEEDR11 (0x00c00000)
#define GPIO_OSPEEDR_OSPEEDR10 (0x00300000)
#define GPIO_OSPEEDR_OSPEEDR9  (0x000c0000)
#define GPIO_OSPEEDR_OSPEEDR8  (0x00030000)
#define GPIO_OSPEEDR_OSPEEDR7  (0x0000c000)
#define GPIO_OSPEEDR_OSPEEDR6  (0x00003000)
#define GPIO_OSPEEDR_OSPEEDR5  (0x00000c00)
#define GPIO_OSPEEDR_OSPEEDR4  (0x00000300)
#define GPIO_OSPEEDR_OSPEEDR3  (0x000000c0)
#define GPIO_OSPEEDR_OSPEEDR2  (0x00000030)
#define GPIO_OSPEEDR_OSPEEDR1  (0x0000000c)
#define GPIO_OSPEEDR_OSPEEDR0  (0x00000003)


/** GPIO alternate function low register(GPIOx_AFRL)
 * Offset: 0x20
 * Reset value: 0x0000 0000
 */
#define GPIO_AFRL_AFR7 (0xf0000000)
#define GPIO_AFRL_AFR6 (0x0f000000)
#define GPIO_AFRL_AFR5 (0x00f00000)
#define GPIO_AFRL_AFR4 (0x000f0000)
#define GPIO_AFRL_AFR3 (0x0000f000)
#define GPIO_AFRL_AFR2 (0x00000f00)
#define GPIO_AFRL_AFR1 (0x000000f0)
#define GPIO_AFRL_AFR0 (0x0000000f)


/** GPIO alternate function high register(GPIOx_AFRH)
 * Offset: 0x24
 * Reset value: 0x0000 0000
 */
#define GPIO_AFRH_AFR15 (0xf0000000)
#define GPIO_AFRH_AFR14 (0x0f000000)
#define GPIO_AFRH_AFR13 (0x00f00000)
#define GPIO_AFRH_AFR12 (0x000f0000)
#define GPIO_AFRH_AFR11 (0x0000f000)
#define GPIO_AFRH_AFR10 (0x00000f00)
#define GPIO_AFRH_AFR9  (0x000000f0)
#define GPIO_AFRH_AFR8  (0x0000000f)

#endif
