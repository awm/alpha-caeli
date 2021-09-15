/**
 * @file        api.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli port selection for the current target environment.
 */
#ifndef ALPHA_CAELI_API_H_
#define ALPHA_CAELI_API_H_

#include "features.h"

/**
 * @section mutex Mutex Ports
 */
#if AC_THREADING
#   if !defined(AC_LOCK) && !defined(AC_UNLOCK) && !defined(AC_STATIC_MUTEX_INIT)
#       include "freertos/mutex.h"
#   endif
#   if !defined(AC_LOCK) && !defined(AC_UNLOCK) && !defined(AC_STATIC_MUTEX_INIT)
#       include "mswin/mutex.h"
#   endif
#   if !defined(AC_LOCK) && !defined(AC_UNLOCK) && !defined(AC_STATIC_MUTEX_INIT)
#       include "posix/mutex.h"
#   endif
#   if !defined(AC_LOCK) && !defined(AC_UNLOCK) && !defined(AC_STATIC_MUTEX_INIT)
#       error "No mutex implementation provided, and no compatible existing port found!"
#   endif
#endif /* end AC_THREADING */

/**
 * @section gettime Time Retrieval Ports
 */
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

#endif /* end ALPHA_CAELI_API_H_ */
