/**************************************************************************//**
 * @file     stm32f4xx.h
 * @brief    CMSIS Cortex-M# Core Peripheral Access Layer Header File for
 *           Device stm32f4xx
 * @version  V5.00
 * @date     10. January 2018
 ******************************************************************************/
/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef stm32f4xx_H      /* ToDo: replace 'stm32f4xx' with your device name */
#define stm32f4xx_H

#ifdef __cplusplus
extern "C" {
#endif

/* ToDo: replace '<Vendor>' with vendor name; add your doxyGen comment   */
/** @addtogroup <Vendor>
  * @{
  */


/* ToDo: replace 'stm32f4xx' with device name; add your doxyGen comment   */
/** @addtogroup stm32f4xx
  * @{
  */


/** @addtogroup Configuration_of_CMSIS
  * @{
  */



/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum IRQn
{

/* ToDo: use this Cortex interrupt numbers if your device is a Cortex-M3 / Cortex-M4 / Cortex-M7 device */
  Reset_IRQn                = -15,              /*!< -15  Reset Vector, invoked on Power up and warm reset                     */
  NonMaskableInt_IRQn       = -14,              /*!< -14  Non maskable Interrupt, cannot be stopped or preempted               */
  HardFault_IRQn            = -13,              /*!< -13  Hard Fault, all classes of Fault                                     */
  MemoryManagement_IRQn     = -12,              /*!< -12  Memory Management, MPU mismatch, including Access Violation
                                                          and No Match                                                         */
  BusFault_IRQn             = -11,              /*!< -11  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                                          related Fault                                                        */
  UsageFault_IRQn           = -10,              /*!< -10  Usage Fault, i.e. Undef Instruction, Illegal State Transition        */
  SVCall_IRQn               =  -5,              /*!< -5 System Service Call via SVC instruction                                */
  DebugMonitor_IRQn         =  -4,              /*!< -4 Debug Monitor                                                          */
  PendSV_IRQn               =  -2,              /*!< -2 Pendable request for system service                                    */
  SysTick_IRQn              =  -1,              /*!< -1 System Tick Timer                                                      */

/* ===========================================  stm32f4xx Specific Interrupt Numbers  ========================================= */
/* ToDo: add here your device specific external interrupt numbers
         according the interrupt handlers defined in startup_Device.s
         eg.: Interrupt for Timer#1       TIM1_IRQHandler   ->   TIM1_IRQn */
  WWDG_IRQn                   = 0,
  PVD_IRQn                    = 1,
  TAMP_STAMP_IRQn             = 2,
  RTC_WKUP_IRQn               = 3,
  FLASH_IRQn                  = 4,
  RCC_IRQn                    = 5,
  EXTI0_IRQn                  = 6,
  EXTI1_IRQn                  = 7,
  EXTI2_IRQn                  = 8,
  EXTI3_IRQn                  = 9,
  EXTI4_IRQn                  = 10,
  DMA1_Stream0_IRQn           = 11,
  DMA1_Stream1_IRQn           = 12,
  DMA1_Stream2_IRQn           = 13,
  DMA1_Stream3_IRQn           = 14,
  DMA1_Stream4_IRQn           = 15,
  DMA1_Stream5_IRQn           = 16,
  DMA1_Stream6_IRQn           = 17,
  ADC_IRQn                    = 18,
  CAN1_TX_IRQn                = 19,
  CAN1_RX0_IRQn               = 20,
  CAN1_RX1_IRQn               = 21,
  CAN1_SCE_IRQn               = 22,
  EXTI9_5_IRQn                = 23,
  TIM1_BRK_TIM9_IRQn          = 24,
  TIM1_UP_TIM10_IRQn          = 25,
  TIM1_TRG_COM_TIM11_IRQn     = 26,
  TIM1_CC_IRQn                = 27,
  TIM2_IRQn                   = 28,
  TIM3_IRQn                   = 29,
  TIM4_IRQn                   = 30,
  I2C1_EV_IRQn                = 31,
  I2C1_ER_IRQn                = 32,
  I2C2_EV_IRQn                = 33,
  I2C2_ER_IRQn                = 34,
  SPI1_IRQn                   = 35,
  SPI2_IRQn                   = 36,
  USART1_IRQn                 = 37,
  USART2_IRQn                 = 38,
  USART3_IRQn                 = 39,
  EXTI15_10_IRQn              = 40,
  RTC_Alarm_IRQn              = 41,
  OTG_FS_WKUP_IRQn            = 42,
  TIM8_BRK_TIM12_IRQn         = 43,
  TIM8_UP_TIM13_IRQn          = 44,
  TIM8_TRG_COM_TIM14_IRQn     = 45,
  TIM8_CC_IRQn                = 46,
  DMA1_Stream7_IRQn           = 47,
  FSMC_IRQn                   = 48,
  SDIO_IRQn                   = 49,
  TIM5_IRQn                   = 50,
  SPI3_IRQn                   = 51,
  UART4_IRQn                  = 52,
  UART5_IRQn                  = 53,
  TIM6_DAC_IRQn               = 54,
  TIM7_IRQn                   = 55,
  DMA2_Stream0_IRQn           = 56,
  DMA2_Stream1_IRQn           = 57,
  DMA2_Stream2_IRQn           = 58,
  DMA2_Stream3_IRQn           = 59,
  DMA2_Stream4_IRQn           = 60,
  ETH_IRQn                    = 61,
  ETH_WKUP_IRQn               = 62,
  CAN2_TX_IRQn                = 63,
  CAN2_RX0_IRQn               = 64,
  CAN2_RX1_IRQn               = 65,
  CAN2_SCE_IRQn               = 66,
  OTG_FS_IRQn                 = 67,
  DMA2_Stream5_IRQn           = 68,
  DMA2_Stream6_IRQn           = 69,
  DMA2_Stream7_IRQn           = 70,
  USART6_IRQn                 = 71,
  I2C3_EV_IRQn                = 72,
  I2C3_ER_IRQn                = 73,
  OTG_HS_EP1_OUT_IRQn         = 74,
  OTG_HS_EP1_IN_IRQn          = 75,
  OTG_HS_WKUP_IRQn            = 76,
  OTG_HS_IRQn                 = 77,
  DCMI_IRQn                   = 78,
  RNG_IRQn                    = 80,
  FPU_IRQn                    = 81
} IRQn_Type;



/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ===========================  Configuration of the Arm Cortex-M4 Processor and Core Peripherals  =========================== */
/* ToDo: set the defines according your Device */
/* ToDo: define the correct core revision
         __CM0_REV if your device is a Cortex-M0 device
         __CM3_REV if your device is a Cortex-M3 device
         __CM4_REV if your device is a Cortex-M4 device
         __CM7_REV if your device is a Cortex-M7 device */
#define __CM4_REV                 0x0201    /*!< Core Revision r2p1 */
/* ToDo: define the correct core features for the stm32f4xx */
#define __MPU_PRESENT             1         /*!< Set to 1 if MPU is present */
#define __VTOR_PRESENT            1         /*!< Set to 1 if VTOR is present */
#define __NVIC_PRIO_BITS          4         /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1         /*!< Set to 1 if FPU is present */
#define __FPU_DP                  0         /*!< Set to 1 if FPU is double precision FPU (default is single precision FPU) */
#define __ICACHE_PRESENT          0         /*!< Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT          0         /*!< Set to 1 if D-Cache is present */
#define __DTCM_PRESENT            0         /*!< Set to 1 if DTCM is present */


/** @} */ /* End of group Configuration_of_CMSIS */


/* ToDo: include the correct core_cm#.h file
         core_cm0.h if your device is a CORTEX-M0 device
         core_cm3.h if your device is a CORTEX-M3 device
         core_cm4.h if your device is a CORTEX-M4 device
         core_cm7.h if your device is a CORTEX-M4 device */
#include "core_cm4.h"                           /*!< Arm Cortex-M# processor and core peripherals */
/* ToDo: include your system_stm32f4xx.h file
         replace 'stm32f4xx' with your device name */
#include "system_stm32f4xx.h"                    /*!< stm32f4xx System */


/* ========================================  Start of section using anonymous unions  ======================================== */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripherals
  * @{
  */

/* ToDo: add here your device specific peripheral access structure typedefs
         following is an example for a timer */

/* =========================================================================================================================== */
/* ================                                            TMR                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Timer (TMR)
  */

typedef struct
{                                               /*!< (@ 0x40000000) TIM Structure                                              */
  __IOM uint32_t   TimerLoad;                   /*!< (@ 0x00000004) Timer Load                                                 */
  __IM  uint32_t   TimerValue;                  /*!< (@ 0x00000008) Timer Counter Current Value                                */
  __IOM uint32_t   TimerControl;                /*!< (@ 0x0000000C) Timer Control                                              */
  __OM  uint32_t   TimerIntClr;                 /*!< (@ 0x00000010) Timer Interrupt Clear                                      */
  __IM  uint32_t   TimerRIS;                    /*!< (@ 0x00000014) Timer Raw Interrupt Status                                 */
  __IM  uint32_t   TimerMIS;                    /*!< (@ 0x00000018) Timer Masked Interrupt Status                              */
  __IM  uint32_t   RESERVED[1];
  __IOM uint32_t   TimerBGLoad;                 /*!< (@ 0x00000020) Background Load Register                                   */
} TMR_TypeDef;

/*@}*/ /* end of group stm32f4xx_Peripherals */


/* =========================================  End of section using anonymous unions  ========================================= */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/* ToDo: add here your device peripherals base addresses
         following is an example for timer */
/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

/* Peripheral and SRAM base address */
#define STM32F4XX_FLASH_BASE       (0x00000000UL)                              /*!< (FLASH     ) Base Address */
#define STM32F4XX_SRAM_BASE        (0x20000000UL)                              /*!< (SRAM      ) Base Address */
#define STM32F4XX_PERIPH_BASE      (0x40000000UL)                              /*!< (Peripheral) Base Address */

/* Peripheral memory map */
#define STM32F4XXTIM0_BASE         (STM32F4XX_PERIPH_BASE)          /*!< (Timer0    ) Base Address */
#define STM32F4XXTIM1_BASE         (STM32F4XX_PERIPH_BASE + 0x0800) /*!< (Timer1    ) Base Address */
#define STM32F4XXTIM2_BASE         (STM32F4XX_PERIPH_BASE + 0x1000) /*!< (Timer2    ) Base Address */

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/* ToDo: add here your device peripherals pointer definitions
         following is an example for timer */
/** @addtogroup Device_Peripheral_declaration
  * @{
  */

#define STM32F4XX_TIM0        ((STM32F4XX_TMR_TypeDef *) STM32F4XXTIM0_BASE)
#define STM32F4XX_TIM1        ((STM32F4XX_TMR_TypeDef *) STM32F4XXTIM0_BASE)
#define STM32F4XX_TIM2        ((STM32F4XX_TMR_TypeDef *) STM32F4XXTIM0_BASE)


/** @} */ /* End of group stm32f4xx */

/** @} */ /* End of group <Vendor> */

#ifdef __cplusplus
}
#endif

#endif  /* stm32f4xx_H */
