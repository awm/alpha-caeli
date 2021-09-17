/**
 * @file        gettime.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli get time port selection for the current target environment.
 */
#ifndef ALPHA_CAELI_GETTIME_H_
#define ALPHA_CAELI_GETTIME_H_

#include "features.h"
#include "compiler.h"

#ifndef AC_GET_TIME
#   include "mswin/gettime.h"
#endif
#ifndef AC_GET_TIME
#   include "posix/gettime.h"
#endif
#ifndef AC_GET_TIME
#   include "stdc/gettime.h"
#endif
#ifndef AC_GET_TIME
#   error "No implementation provided to obtain time, and no compatible existing port found!"
#endif

#endif /* end ALPHA_CAELI_GETTIME_H_ */
