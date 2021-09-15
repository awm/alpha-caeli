/**
 * @file        stdc/utctime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli UTC time conversion port implementation using only standard C library
 *              calls.  Must be included via api.h.  This port is limited to single-threaded
 *              environments as it uses library calls which are not thread-safe.
 */
#if !AC_THREADING
#   include <time.h>

/**
 *  UTC time stamp conversion.
 *
 * @param[in]   seconds Time to convert, in seconds since the Epoch.
 * @param[out]  ptm     Returned tm structure containing the converted time.
 *
 * @retval  0   Success.
 * @retval  <0  Conversion error.
 */
#   define AC_CONVERT_UTC_TIME(seconds, ptm) ((*(ptm) = *gmtime(&(seconds))), 0)
#endif /* end !AC_THREADING */
