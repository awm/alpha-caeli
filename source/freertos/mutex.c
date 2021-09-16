/**
 * @file        freertos/mutex.c
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli port implementation for FreeRTOS platforms.
 */
#include "alpha-caeli/api.h"

#if (HAVE_FREERTOS_STATIC_SEMAPHORE) || defined(HAVE_FREERTOS_SEMAPHORE) && \
    HAVE_FREERTOS_XTASKGETSCHEDULERSTATE

AC_DEFINE_INLINE void _ac_lock_mutex(ac_mutex *mutex);
AC_DEFINE_INLINE void _ac_unlock_mutex(ac_mutex *mutex);

#endif /* end (HAVE_FREERTOS_STATIC_SEMAPHORE || HAVE_FREERTOS_SEMAPHORE) &&
              HAVE_FREERTOS_XTASKGETSCHEDULERSTATE */
