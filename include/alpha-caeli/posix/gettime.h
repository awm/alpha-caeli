/**
 * @file        posix/gettime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli implementation to obtain time on POSIX platforms.
 *              Must be included via api.h.
 */
#if HAVE_GETTIMEOFDAY
#   include <stddef.h>
#   include <sys/time.h>

/**
 * Retrieve the current system time using POSIX gettimeofday().
 */
AC_DECLARE_INLINE void _ac_get_time
(
    time_t          *secondsp,      ///< [out]  Seconds since the Epoch.
    unsigned long   *microsecondsp  ///< [out]  Fraction of the current second, in microseconds.
)
{
    struct timeval now;

    gettimeofday(&now, NULL);
    *secondsp       = (time_t) now.tv_sec;
    *microsecondsp  = (unsigned long) now.tv_usec;
}

/**
 * Retrieve the current system time.
 *
 * @param[out]  secondsp        Seconds since the Epoch.
 * @param[out]  microsecondsp   Fraction of the current second, in microseconds.
 */
#   define AC_GET_TIME(secondsp, microsecondsp) _ac_get_time((secondsp), (microsecondsp))

#endif /* end HAVE_GETTIMEOFDAY */
