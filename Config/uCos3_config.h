#ifndef UCOS3_CONFIG_H
#define UCOS3_CONFIG_H

/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 0x07

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 4

enum
{
  OS_CANOPEN_TASK_PRIO = 5,
  OS_GMAC_TASK_PRIO,
  OS_USB_TASK_PRIO,
  OS_LED_TASK_PRIO,
  OS_MAX_TASK_PRIO = 50
};

#define OS_GMAC_TASK_STACKSZ      512
#define OS_USB_TASK_STACKSZ       512
#define OS_LED_TASK_STACKSZ       512

#endif // UCOS3_CONFIG_H
