/**
 * @file        utctime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli UTC time port selection for the current target environment.
 */
#ifndef ALPHA_CAELI_UTCTIME_H_
#define ALPHA_CAELI_UTCTIME_H_

#include "alpha-caeli/features.h"
#include "compiler.h"

#ifndef AC_CONVERT_UTC_TIME
#   include "mswin/utctime.h"
#endif
#ifndef AC_CONVERT_UTC_TIME
#   include "posix/utctime.h"
#endif
#ifndef AC_CONVERT_UTC_TIME
#   include "stdc/utctime.h"
#endif
#ifndef AC_CONVERT_LOCAL_TIME
#   error "No UTC time conversion implementation provided, and no compatible existing port found!"
#endif

#endif /* end ALPHA_CAELI_UTCTIME_H_ */
