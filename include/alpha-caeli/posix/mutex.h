/**
 * @file        posix/mutex.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli mutex port implementation for POSIX platforms.
 *              Must be included via api.h.
 */
#if HAVE_PTHREAD_MUTEX
#   include <pthread.h>

/// POSIX mutex type.
typedef pthread_mutex_t ac_mutex_t;

/**
 * Static initializer for a mutex variable.
 */
#   define AC_STATIC_MUTEX_INIT     PTHREAD_MUTEX_INITIALIZER

/**
 * Lock a mutex.
 *
 * @param   m   Mutex instance pointer.
 */
#   define AC_LOCK(m)               pthread_mutex_lock(m)

/**
 * Unlock a mutex.
 *
 * @param   m   Mutex instance pointer.
 */
#   define AC_UNLOCK(m)             pthread_mutex_unlock(m)

#endif /* end HAVE_PTHREAD_MUTEX */
