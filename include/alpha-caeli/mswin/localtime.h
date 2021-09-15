/**
 * @file        port/mswin/localtime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli local time conversion port implementation for Windows platforms.
 *              Must be included via api.h.
 */
#if HAVE_LOCALTIME_S
#   include <time.h>

/**
 *  Local time stamp conversion.
 *
 * @param[in]   seconds Time to convert, in seconds since the Epoch.
 * @param[out]  ptm     Returned tm structure containing the converted time.
 *
 * @retval  0   Success.
 * @retval  <0  Conversion error.
 */
#   define AC_CONVERT_LOCAL_TIME(seconds, ptm) (localtime_s((ptm), &(seconds)) == 0 ? 0 : -1)
#endif /* end HAVE_LOCALTIME_S */
