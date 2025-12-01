
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions for STM32MP157 Cortex-M4
 *----------------------------------------------------------*/

/* MCU and clock settings */
#define configCPU_CLOCK_HZ                  ( SystemCoreClock )
#define configTICK_RATE_HZ                  ( ( TickType_t ) 1000 )

/* Task settings */
#define configMAX_PRIORITIES                ( 7 )
#define configMINIMAL_STACK_SIZE            ( ( unsigned short ) 256 )
#define configTOTAL_HEAP_SIZE               ( ( size_t ) ( 64 * 1024 ) ) /* Adjust based on RAM */
#define configMAX_TASK_NAME_LEN             ( 16 )
#define configUSE_16_BIT_TICKS              0

/* Scheduler settings */
#define configUSE_PREEMPTION                1
#define configUSE_TIME_SLICING              1
#define configIDLE_SHOULD_YIELD             1

/* Hooks */
#define configUSE_IDLE_HOOK                 0
#define configUSE_TICK_HOOK                 0
#define configCHECK_FOR_STACK_OVERFLOW      2
#define configUSE_MALLOC_FAILED_HOOK        1

/* Software timers */
#define configUSE_TIMERS                    1
#define configTIMER_TASK_PRIORITY           ( 3 )
#define configTIMER_QUEUE_LENGTH            ( 10 )
#define configTIMER_TASK_STACK_DEPTH        ( 512 )

/* Memory allocation */
#define configSUPPORT_STATIC_ALLOCATION     0
#define configSUPPORT_DYNAMIC_ALLOCATION    1

/* Optional features */
#define configUSE_MUTEXES                   1
#define configUSE_RECURSIVE_MUTEXES         1
#define configUSE_COUNTING_SEMAPHORES       1
#define configUSE_TASK_NOTIFICATIONS        1

/* Co-routines (usually disabled for Cortex-M) */
#define configUSE_CO_ROUTINES               0

/* Interrupt priorities for Cortex-M4 */
#define configPRIO_BITS                     __NVIC_PRIO_BITS
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY      0xF
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5
#define configKERNEL_INTERRUPT_PRIORITY              ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY         ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Run-time stats and trace */
#define configGENERATE_RUN_TIME_STATS       0
#define configUSE_TRACE_FACILITY            0

/* MPU and FPU support */
#define configENABLE_MPU                    1
#define configENABLE_FPU                    1

/* Assert macro */
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* API inclusion */
#define INCLUDE_vTaskPrioritySet            1
#define INCLUDE_uxTaskPriorityGet           1
#define INCLUDE_vTaskDelete                 1
#define INCLUDE_vTaskSuspend                1
#define INCLUDE_vTaskDelay                  1
#define INCLUDE_xTaskDelayUntil             1
#define INCLUDE_xTaskGetSchedulerState      1
#define INCLUDE_xTaskGetCurrentTaskHandle   1
#define INCLUDE_xTaskGetIdleTaskHandle      1
#define INCLUDE_xTimerPendFunctionCall      1
#define INCLUDE_xSemaphoreGetMutexHolder    1

#endif /* FREERTOS_CONFIG_H */
