/**
 * @file        posix/localtime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli local time conversion port implementation for POSIX platforms.
 *              Must be included via api.h.
 */
#if HAVE_LOCALTIME_R
#   include <time.h>

/**
 *  Local time stamp conversion.
 *
 * @param[in]   seconds Time to convert, in seconds since the Epoch.
 * @param[out]  ptm     Returned tm structure containing the converted time.
 *
 * @retval  0   Success.
 * @retval  !=0 Conversion error.
 */
#   define AC_CONVERT_LOCAL_TIME(seconds, ptm) (localtime_r(&(seconds), (ptm)) == NULL ? -1 : 0)
#endif /* end HAVE_LOCALTIME_R */
