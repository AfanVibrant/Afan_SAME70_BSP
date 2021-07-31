/**
 * \file
 *
 * \brief Stdio for SAM.
 *
 * Copyright (c) 2013-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef UTULS_UPRINTF_H_INCLUDED
#define UTULS_UPRINTF_H_INCLUDED

#include <stddef.h>

#define UTILS_DEBUG_LEVEL_MINIUM		0
#define UTILS_DEBUG_LEVEL_PRIVATE		1
#define UTILS_DEBUG_LEVEL_NORMAL		2
#define UTILS_DEBUG_LEVEL_PUBLIC		3
#define UTILS_DEBUG_LEVEL_DEFAULT		4
#define UTILS_DEBUG_LEVEL_MAXIMUM		6

#define UTILS_OS_DEBUG              UTILS_DEBUG_LEVEL_PRIVATE
#define UTILS_DRIVER_DEBUG          UTILS_DEBUG_LEVEL_NORMAL
#define UTILS_USER_DRIVER_DEBUG     UTILS_DEBUG_LEVEL_PUBLIC
#define UTILS_USER_CODE_DEBUG       UTILS_DEBUG_LEVEL_DEFAULT

#define OS_CORE			                UTILS_OS_DEBUG
#define OS_DRIVER		                UTILS_DRIVER_DEBUG
#define USER_DRIVER	                UTILS_USER_DRIVER_DEBUG
#define USER_CODE		                UTILS_USER_CODE_DEBUG

#define UPRINTF_DEBUG_FILTERON      1
#define UPRINTF_DEBUG_TASKNAMEON    1
#define UPRINTF_DEBUG_TIMESTAMP     1
#define UPRINTF_DEBUG_LEVEL         UTILS_DEBUG_LEVEL_MAXIMUM //FREERTOS_DEBUG_LEVEL_NORMAL
#define UPRINTF_TIMESTAMP_ENABLE    1

void uprintf(int level, const char *fmt, ...);

void utils_uprintk_init(void);

#endif /* UTULS_UPRINTF_H_INCLUDED */
