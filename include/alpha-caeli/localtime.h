/**
 * @file        localtime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli local time conversion port selection for the current target environment.
 */
#ifndef ALPHA_CAELI_LOCALTIME_H_
#define ALPHA_CAELI_LOCALTIME_H_

#include "alpha-caeli/features.h"
#include "compiler.h"

#ifndef AC_CONVERT_LOCAL_TIME
#   include "mswin/localtime.h"
#endif
#ifndef AC_CONVERT_LOCAL_TIME
#   include "posix/localtime.h"
#endif
#ifndef AC_CONVERT_LOCAL_TIME
#   include "stdc/localtime.h"
#endif
#ifndef AC_CONVERT_LOCAL_TIME
#   error "No local time conversion implementation provided, and no compatible existing port found!"
#endif

#endif /* end ALPHA_CAELI_LOCALTIME_H_ */
