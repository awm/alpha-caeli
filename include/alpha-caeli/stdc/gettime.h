/**
 * @file        stdc/gettime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli implementation to obtain time using only standard C library calls.
 *              Must be included via api.h.  This port is limited to a resolution of one second.
 */
#include <time.h>

/**
 * Retrieve the current system time.
 *
 * @param[out]  secondsp        Seconds since the Epoch.
 * @param[out]  microsecondsp   Fraction of the current second, in microseconds.
 */
#define AC_GET_TIME(secondsp, microsecondsp) \
    do                                       \
    {                                        \
        *secondsp = time(NULL);              \
        *microsecondsp = 0;                  \
    } while (0)
