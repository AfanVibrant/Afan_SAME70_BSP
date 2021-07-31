/****************************************************************************
 * Afan SAME70 rtos_config.h
 * Author : Afan Vibrant (AfanVibrant@outlook.com)
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef CONFIG_RTOS_CONFIG_H
#define CONFIG_RTOS_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "lwipopts.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* This identifies which task will be enabled:
 */

#define LWIP_TCPIP_TASK              1

#if LWIP_SNMP
#  define LWIP_SNMP_TASK             1
#endif

#if LWIP_HAVE_SLIPIF
#  define LWIP_SLIPIF_TASK           1
#endif

#define MICRO_PYTHON_TASK            1
#define LWIP_MODBUSTCP_TASK          1
#define ETH_IPSTACK_TASK             1
#define CAN_CANOPEN_TASK             1
#define USB_CDCACM_TASK              1
#define LED_BLIKING_TASK             1

/* This identifies tasks will be enabled:
 */

#ifdef LWIP_TCPIP_TASK
#  define LWIP_TCPIP_TASK_PRIO       11
#  define LWIP_TCPIP_TASK_MBOXSZ     (TCPIP_MBOX_SIZE + \
                                      DEFAULT_ACCEPTMBOX_SIZE + \
                                      DEFAULT_RAW_RECVMBOX_SIZE + \
                                      DEFAULT_UDP_RECVMBOX_SIZE + \
                                      DEFAULT_TCP_RECVMBOX_SIZE)
#  define LWIP_TCPIP_TASK_STKSZ      TCPIP_THREAD_STACKSIZE
#endif

#ifdef LWIP_SNMP_TASK
#  define LWIP_SNMP_TASK_PRIO        12
#  define LWIP_SNMP_TASK_MBOXSZ      0
#  define LWIP_SNMP_TASK_STKSZ       SNMP_STACK_SIZE
#endif

#ifdef LWIP_SLIPIF_TASK
#  define LWIP_SLIPIF_TASK_PRIO      13
#  define LWIP_SLIPIF_TASK_MBOXSZ    0
#  define LWIP_SLIPIF_TASK_STKSZ     SLIPIF_THREAD_STACKSIZE
#endif


#ifdef MICRO_PYTHON_TASK
#  define MPY_MPYTHON_TASK_PRIO      20
#  define MPY_MPYTHON_TASK_MBOXSZ    4
#  define MPY_MPYTHON_TASK_STKZE     8192
#endif

#ifdef LWIP_MODBUSTCP_TASK
#  define LWIP_MODBUSTCP_TASK_PRIO   14
#  define LWIP_MODBUSTCP_TASK_MBOXSZ 16
#  define LWIP_MODBUSTCP_TASK_STKZE  2048
#endif

#ifdef ETH_IPSTACK_TASK
#  define ETH_IPSTACK_TASK_PRIO      9
#  define ETH_IPSTACK_TASK_MBOXSZ    32
#  define ETH_IPSTACK_TASK_STKZE     2048
#endif

#ifdef CAN_CANOPEN_TASK
#  define CAN_CANOPEN_TASK_PRIO      8
#  define CAN_CANOPEN_TASK_MBOXSZ    32
#  define CAN_CANOPEN_TASK_STKZE     2048
#endif

#ifdef USB_CDCACM_TASK
#  define USB_CDCACM_TASK_PRIO       10
#  define USB_CDCACM_TASK_MBOXSZ     32
#  define USB_CDCACM_TASK_STKZE      2048
#endif

#ifdef LED_BLIKING_TASK
#  define LED_BLIKING_TASK_PRIO      50
#  define LED_BLIKING_TASK_MBOXSZ    0
#  define LED_BLIKING_TASK_STKZE     2048
#endif

/* Task related information statistic */

#define THREAD_PRIO_NONE             (-1)

#ifdef LWIP_TCPIP_TASK
#  define TCPIP_THREAD_USED          1
#  define TCPIP_THREAD_MBOXSZ        LWIP_TCPIP_TASK_MBOXSZ
#  define TCPIP_THREAD_STKSZ         LWIP_TCPIP_TASK_STKSZ
#else
#  define TCPIP_THREAD_USED          0
#  define TCPIP_THREAD_PRIO          THREAD_PRIO_NONE
#  define TCPIP_THREAD_MBOXSZ        0
#  define TCPIP_THREAD_STKSZ         0
#endif

#ifdef LWIP_SLIPIF_TASK
#  define SLIPIF_THREAD_USED         1
#  define SLIPIF_THREAD_MBOXSZ       LWIP_SLIPIF_TASK_MBOXSZ
#  define SLIPIF_THREAD_STKSZ        LWIP_SLIPIF_TASK_STKSZ
#else
#  define SLIPIF_THREAD_USED         0
#  define SLIPIF_THREAD_MBOXSZ       0
#  define SLIPIF_THREAD_STKSZ        0
#endif

#ifdef LWIP_SNMP_TASK
#  define SNMP_THREAD_USED           1
#  define SNMP_THREAD_MBOXSZ         LWIP_SNMP_TASK_MBOXSZ
#  define SNMP_THREAD_STKSZ          LWIP_SNMP_TASK_STKSZ
#else
#  define SNMP_THREAD_USED           0
#  define SNMP_THREAD_PRIO           THREAD_PRIO_NONE
#  define SNMP_THREAD_MBOXSZ         0
#  define SNMP_THREAD_STKSZ          0
#endif

#ifdef MICRO_PYTHON_TASK
#  define MPY_THREAD_USED            1
#  define MPY_THREAD_PRIO            MPY_MPYTHON_TASK_PRIO
#  define MPY_THREAD_MBOXSZ          MPY_MPYTHON_TASK_MBOXSZ
#  define MPY_THREAD_STKSZ           MPY_MPYTHON_TASK_STKZE
#else
#  define MPY_THREAD_USED            0
#  define MPY_THREAD_PRIO            THREAD_PRIO_NONE
#  define MPY_THREAD_MBOXSZ          0
#  define MPY_THREAD_STKSZ           0
#endif

#ifdef LWIP_MODBUSTCP_TASK
#  define MBTCP_THREAD_USED          1
#  define MBTCP_THREAD_PRIO          LWIP_MODBUSTCP_TASK_PRIO
#  define MBTCP_THREAD_MBOXSZ        LWIP_MODBUSTCP_TASK_MBOXSZ
#  define MBTCP_THREAD_STKSZ         LWIP_MODBUSTCP_TASK_STKZE
#else
#  define MBTCP_THREAD_USED          0
#  define SLIPIF_THREAD_PRIO         THREAD_PRIO_NONE
#  define MBTCP_THREAD_MBOXSZ        0
#  define MBTCP_THREAD_STKSZ         0
#endif

#ifdef ETH_IPSTACK_TASK
#  define IPSTACK_THREAD_USED        1
#  define IPSTACK_THREAD_PRIO        ETH_IPSTACK_TASK_PRIO
#  define IPSTACK_THREAD_MBOXSZ      ETH_IPSTACK_TASK_MBOXSZ
#  define IPSTACK_THREAD_STKSZ       ETH_IPSTACK_TASK_STKZE
#else
#  define IPSTACK_THREAD_USED        0
#  define IPSTACK_THREAD_PRIO        THREAD_PRIO_NONE
#  define IPSTACK_THREAD_MBOXSZ      0
#  define IPSTACK_THREAD_STKSZ       0
#endif

#ifdef CAN_CANOPEN_TASK
#  define CANOPEN_THREAD_USED        1
#  define CANOPEN_THREAD_PRIO        CAN_CANOPEN_TASK_PRIO
#  define CANOPEN_THREAD_MBOXSZ      CAN_CANOPEN_TASK_MBOXSZ
#  define CANOPEN_THREAD_STKSZ       CAN_CANOPEN_TASK_STKZE
#else
#  define CANOPEN_THREAD_USED        0
#  define CANOPEN_THREAD_PRIO        THREAD_PRIO_NONE
#  define CANOPEN_THREAD_MBOXSZ      0
#  define CANOPEN_THREAD_STKSZ       0
#endif

#ifdef USB_CDCACM_TASK
#  define CDCACM_THREAD_USED         1
#  define CDCACM_THREAD_PRIO         USB_CDCACM_TASK_PRIO
#  define CDCACM_THREAD_MBOXSZ       USB_CDCACM_TASK_MBOXSZ
#  define CDCACM_THREAD_STKSZ        USB_CDCACM_TASK_STKZE
#else
#  define CDCACM_THREAD_USED         0
#  define CDCACM_THREAD_PRIO         THREAD_PRIO_NONE
#  define CDCACM_THREAD_MBOXSZ       0
#  define CDCACM_THREAD_STKSZ        0
#endif

#ifdef LED_BLIKING_TASK
#  define LEDRUN_THREAD_USED         1
#  define LEDRUN_THREAD_PRIO         LED_BLIKING_TASK_PRIO
#  define LEDRUN_THREAD_MBOXSZ       LED_BLIKING_TASK_MBOXSZ
#  define LEDRUN_THREAD_STKSZ        LED_BLIKING_TASK_STKZE
#else
#  define LEDRUN_THREAD_USED         0
#  define LEDRUN_THREAD_PRIO         THREAD_PRIO_NONE
#  define LEDRUN_THREAD_MBOXSZ       0
#  define LEDRUN_THREAD_STKSZ        0
#endif

#define TOTAL_THREAD_USED    (TCPIP_THREAD_USED     + SLIPIF_THREAD_USED    + \
                              SNMP_THREAD_USED      + MBTCP_THREAD_USED     + \
                              IPSTACK_THREAD_USED   + CANOPEN_THREAD_USED   + \
                              CDCACM_THREAD_USED    + LEDRUN_THREAD_USED    + \
                              MPY_THREAD_USED)

#define TOTAL_THREAD_STKSZ   (TCPIP_THREAD_STKSZ    + SLIPIF_THREAD_STKSZ   + \
                              SNMP_THREAD_STKSZ     + MBTCP_THREAD_STKSZ    + \
                              IPSTACK_THREAD_STKSZ  + CANOPEN_THREAD_STKSZ  + \
                              CDCACM_THREAD_STKSZ   + LED_BLIKING_TASK_STKZE+ \
                              MPY_THREAD_STKSZ)

#define TOTAL_THREAD_MSGSZ   (TCPIP_THREAD_MBOXSZ   + SLIPIF_THREAD_MBOXSZ   + \
                              SNMP_THREAD_MBOXSZ    + MBTCP_THREAD_MBOXSZ    + \
                              IPSTACK_THREAD_MBOXSZ + CANOPEN_THREAD_MBOXSZ  + \
                              CDCACM_THREAD_MBOXSZ  + LED_BLIKING_TASK_MBOXSZ+ \
                              MPY_THREAD_MBOXSZ)

#define RTOS_RET_OK           0
#define RTOS_RET_ERR          (-1)

#define RTOS_TIMER_AUTORELOAD 1
#define RTOS_TIMER_ONESHOOT   0

#define RTOS_BLOCKING_TIMEOUT (0xFFFFFFFFUL)

/** Function prototype for RTOS thread functions */

typedef void (*rtos_thread_fn)(void *arg);
typedef void (*rtos_timer_fn)(void *arg);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CONFIG_RTOS_CONFIG_H */
