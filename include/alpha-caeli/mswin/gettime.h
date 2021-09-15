/**
 * @file        mswin/gettime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli implementation to obtain time on Windows platforms.
 *              Must be included via api.h.
 */
#if HAVE__FTIME_S
#   include <sys/timeb.h>
#   include <sys/types.h>

#   include <assert.h>

/**
 * Retrieve the current system time on Windows.
 */
AC_DECLARE_INLINE void _ac_get_time
(
    time_t          *secondsp,      ///< [out] Returned seconds since the Epoch.
    unsigned long   *microsecondsp  ///< [out] Returned microseconds into the current second.
)
{
    errno_t         result;
    struct _timeb   now;

    result = _ftime_s(&now);
    assert(result == 0);

    *secondsp       = (time_t) now.time;
    *microsecondsp  = (unsigned long) now.millitm * 1000UL;
}

/**
 * Retrieve the current system time.
 *
 * @param[out]  secondsp        Returned seconds since the Epoch.
 * @param[out]  microsecondsp   Returned fraction of the current second, in microseconds.
 */
#   define AC_GET_TIME(secondsp, microsecondsp) _ac_get_time((secondsp), (microsecondsp))

#endif /* end HAVE__FTIME_S */
