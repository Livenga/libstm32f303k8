.file "startup.s"

.cpu cortex-m4
.thumb


// Global
.global startup
.global irq_vector


.section .text.startup
.weak startup
.type startup, %function

// メモリの初期化
.global startup

startup:
  bl init_mem
  bl main

default_handler:
inf_loop:
  bl inf_loop


.section .vector, "a", %progbits
.type irq_vector, %object
.size irq_vector, .-irq_vector


irq_vector:
  .word estack
  .word startup
  .word NMI_handler
  .word hard_fault_handler
  .word MemManage_handler
  .word BusFault_handler
  .word UsageFault_handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVCall_handler
  .word 0
  .word 0
  .word PendSV_handler
  .word SysTick_handler
  .word WWDG_handler
  .word PVD_handler
  .word TAMPER_STAMP_handler
  .word RTC_WKUP_handler
  .word FLASH_handler
  .word RCC_handler
  .word EXTI0_handler
  .word EXTI1_handler
  .word EXTI2_TS_handler
  .word EXTI3_handler
  .word EXTI4_handler
  .word DMA1_Channel1_handler
  .word DMA1_Channel2_handler
  .word DMA1_Channel3_handler
  .word DMA1_Channel4_handler
  .word DMA1_Channel5_handler
  .word DMA1_Channel6_handler
  .word DMA1_Channel7_handler
  .word ADC1_2_handler
  .word CAN_TX_handler
  .word CAN_RX0_handler
  .word CAN_RX1_handler
  .word CAN_SCE_handler
  .word EXTI9_5_handler
  .word TIM1_BRK_TIM15_handler
  .word TIM1_UP_TIM16_handler
  .word TIM1_TRG_COM_TIM17_handler
  .word TIM1_CC_handler
  .word TIM2_handler
  .word TIM3_handler
  .word 0
  .word I2C1_EV_handler
  .word I2C1_ER_handler
  .word 0
  .word 0
  .word SPI1_handler
  .word 0
  .word USART1_handler
  .word USART2_handler
  .word USART3_handler
  .word EXTI15_10_handler
  .word RTC_Alarm_handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word TIM6_DAC1_handler
  .word TIM7_DAC2_handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word COMP2_handler
  .word COMP4_6_handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word FPU_handler


.weak NMI_handler
.thumb_set NMI_handler, default_handler

.weak hard_fault_handler
.thumb_set hard_fault_handler, default_handler

.weak MemManage_handler
.thumb_set MemManage_handler, default_handler

.weak BusFault_handler
.thumb_set BusFault_handler, default_handler

.weak UsageFault_handler
.thumb_set UsageFault_handler, default_handler

.weak SVCall_handler
.thumb_set SVCall_handler, default_handler

.weak PendSV_handler
.thumb_set PendSV_handler, default_handler

.weak SysTick_handler
.thumb_set SysTick_handler, default_handler

.weak WWDG_handler
.thumb_set WWDG_handler, default_handler

.weak PVD_handler
.thumb_set PVD_handler, default_handler

.weak TAMPER_STAMP_handler
.thumb_set TAMPER_STAMP_handler, default_handler

.weak RTC_WKUP_handler
.thumb_set RTC_WKUP_handler, default_handler

.weak FLASH_handler
.thumb_set FLASH_handler, default_handler

.weak RCC_handler
.thumb_set RCC_handler, default_handler

.weak EXTI0_handler
.thumb_set EXTI0_handler, default_handler

.weak EXTI1_handler
.thumb_set EXTI1_handler, default_handler

.weak EXTI2_TS_handler
.thumb_set EXTI2_TS_handler, default_handler

.weak EXTI3_handler
.thumb_set EXTI3_handler, default_handler

.weak EXTI4_handler
.thumb_set EXTI4_handler, default_handler

.weak DMA1_Channel1_handler
.thumb_set DMA1_Channel1_handler, default_handler

.weak DMA1_Channel2_handler
.thumb_set DMA1_Channel2_handler, default_handler

.weak DMA1_Channel3_handler
.thumb_set DMA1_Channel3_handler, default_handler

.weak DMA1_Channel4_handler
.thumb_set DMA1_Channel4_handler, default_handler

.weak DMA1_Channel5_handler
.thumb_set DMA1_Channel5_handler, default_handler

.weak DMA1_Channel6_handler
.thumb_set DMA1_Channel6_handler, default_handler

.weak DMA1_Channel7_handler
.thumb_set DMA1_Channel7_handler, default_handler

.weak ADC1_2_handler
.thumb_set ADC1_2_handler, default_handler

.weak CAN_TX_handler
.thumb_set CAN_TX_handler, default_handler

.weak CAN_RX0_handler
.thumb_set CAN_RX0_handler, default_handler

.weak CAN_RX1_handler
.thumb_set CAN_RX1_handler, default_handler

.weak CAN_SCE_handler
.thumb_set CAN_SCE_handler, default_handler

.weak EXTI9_5_handler
.thumb_set EXTI9_5_handler, default_handler

.weak TIM1_BRK_TIM15_handler
.thumb_set TIM1_BRK_TIM15_handler, default_handler

.weak TIM1_UP_TIM16_handler
.thumb_set TIM1_UP_TIM16_handler, default_handler

.weak TIM1_TRG_COM_TIM17_handler
.thumb_set TIM1_TRG_COM_TIM17_handler, default_handler

.weak TIM1_CC_handler
.thumb_set TIM1_CC_handler, default_handler

.weak TIM2_handler
.thumb_set TIM2_handler, default_handler

.weak TIM3_handler
.thumb_set TIM3_handler, default_handler

.weak I2C1_EV_handler
.thumb_set I2C1_EV_handler, default_handler

.weak I2C1_ER_handler
.thumb_set I2C1_ER_handler, default_handler

.weak SPI1_handler
.thumb_set SPI1_handler, default_handler

.weak USART1_handler
.thumb_set USART1_handler, default_handler

.weak USART2_handler
.thumb_set USART2_handler, default_handler

.weak USART3_handler
.thumb_set USART3_handler, default_handler

.weak EXTI15_10_handler
.thumb_set EXTI15_10_handler, default_handler

.weak RTC_Alarm_handler
.thumb_set RTC_Alarm_handler, default_handler

.weak TIM6_DAC1_handler
.thumb_set TIM6_DAC1_handler, default_handler

.weak TIM7_DAC2_handler
.thumb_set TIM7_DAC2_handler, default_handler

.weak COMP2_handler
.thumb_set COMP2_handler, default_handler

.weak COMP4_6_handler
.thumb_set COMP4_6_handler, default_handler

.weak FPU_handler
.thumb_set FPU_handler, default_handler
