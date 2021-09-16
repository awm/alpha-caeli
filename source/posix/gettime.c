/**
 * @file        posix/gettime.c
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli port implementation to obtain time on POSIX platforms.
 */
#include "alpha-caeli/api.h"

#if HAVE_GETTIMEOFDAY

AC_DEFINE_INLINE void _ac_get_time(time_t *secondsp, unsigned long *microsecondsp);

#endif /* end HAVE_GETTIMEOFDAY */
