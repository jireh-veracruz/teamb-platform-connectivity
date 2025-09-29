
.syntax unified
.cpu cortex-m4
.thumb

.global  Reset_Handler
.global  _estack

.section .isr_vector, "a", %progbits
.type  g_pfnVectors, %object
g_pfnVectors:
  .word _estack                /* Initial Stack Pointer */
  .word Reset_Handler          /* Reset Handler */
  .word NMI_Handler            /* NMI Handler */
  .word HardFault_Handler      /* Hard Fault Handler */
  .word MemManage_Handler      /* MPU Fault Handler */
  .word BusFault_Handler       /* Bus Fault Handler */
  .word UsageFault_Handler     /* Usage Fault Handler */
  .word 0                      /* Reserved */
  .word 0                      /* Reserved */
  .word 0                      /* Reserved */
  .word 0                      /* Reserved */
  .word SVC_Handler            /* SVCall Handler */
  .word DebugMon_Handler       /* Debug Monitor Handler */
  .word 0                      /* Reserved */
  .word PendSV_Handler         /* PendSV Handler */
  .word SysTick_Handler        /* SysTick Handler */

  /* Add IRQ handlers below as needed */
  .word Default_Handler        /* IRQ0 */
  .word Default_Handler        /* IRQ1 */
  /* ... */

.section .text.Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
  /* Call system init and main */
  bl  SystemInit
  bl  main
  b   .

/* Default handlers */
.section .text.Default_Handler
.type Default_Handler, %function
Default_Handler:
  b .

/* Weak aliases */
.weak NMI_Handler
.weak HardFault_Handler
.weak MemManage_Handler
.weak BusFault_Handler
.weak UsageFault_Handler
.weak SVC_Handler
.weak DebugMon_Handler
.weak PendSV_Handler
.weak SysTick_Handler

NMI_Handler:          b .
HardFault_Handler:    b .
MemManage_Handler:    b .
BusFault_Handler:     b .
UsageFault_Handler:   b .
SVC_Handler:          b .
DebugMon_Handler:     b .
PendSV_Handler:       b .
SysTick_Handler:      b .

.size Reset_Handler, . - Reset_Handler
.size Default_Handler, . - Default_Handler
