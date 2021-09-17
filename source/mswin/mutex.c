/**
 * @file        mswin/mutex.c
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli mutex port implementation for Windows platforms.
 */
#include "alpha-caeli/mutex.h"

#if HAVE_MSWIN_INIT_ONCE && HAVE_MSWIN_CRITICAL_SECTION

AC_DEFINE_INLINE void _ac_lock_mutex(ac_mutex *mutex);

BOOL _ac_init_mutex(PINIT_ONCE init_once, PVOID param, PVOID *ctx)
{
    ac_mutex *mutex = (ac_mutex *) param;
    assert(mutex != NULL);

    AC_UNUSED(init_once);
    AC_UNUSED(ctx);

    InitializeCriticalSection(&mutex->critical_section);
    return TRUE;
}

#endif /* end HAVE_MSWIN_INIT_ONCE && HAVE_MSWIN_CRITICAL_SECTION */
