/**
 * @file        posix/utctime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli UTC time conversion port implementation for POSIX platforms.
 *              Must be included via api.h.
 */
#if HAVE_GMTIME_R
#   include <stddef.h>
#   include <time.h>

/**
 *  UTC time stamp conversion.
 *
 * @param[in]   seconds Time to convert, in seconds since the Epoch.
 * @param[out]  ptm     Returned tm structure containing the converted time.
 *
 * @retval  0   Success.
 * @retval  !=0 Conversion error.
 */
#   define AC_CONVERT_UTC_TIME(seconds, ptm) (gmtime_r(&(seconds), (ptm)) == NULL ? -1 : 0)
#endif /* end HAVE_GMTIME_R */
