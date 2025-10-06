/**
  ******************************************************************************
  * @file    system_stm32mp1xx.c
  * @author  MCD Application Team  
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer System Source File
  *          for STM32MP1xx devices.
  ******************************************************************************
  */

#include <stdint.h>

/* Minimal defines for basic compilation */
#define FLASH_BASE 0x08000000UL
#define SRAM_BASE  0x10000000UL

/* System Clock Frequency (Core Clock) */
uint32_t SystemCoreClock = 200000000; /* 200 MHz default */

/**
  * @brief  Setup the microcontroller system.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
  /* Basic system initialization - minimal implementation */
  /* Vector table is already set by startup code */
  
  /* Configure system clocks if needed */
  /* This is a minimal implementation for compilation */
}

/**
  * @brief  Update SystemCoreClock according to Clock Register Values
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate(void)
{
  /* SystemCoreClock update not implemented for this example */
  SystemCoreClock = 200000000; /* Fixed at 200 MHz for now */
}