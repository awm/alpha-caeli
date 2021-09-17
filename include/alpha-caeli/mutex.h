/**
 * @file        mutex.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli mutex port selection for the current target environment.
 */
#ifndef ALPHA_CAELI_MUTEX_H_
#define ALPHA_CAELI_MUTEX_H_

#include "features.h"
#include "compiler.h"

#if !defined(AC_LOCK) && !defined(AC_UNLOCK) && !defined(AC_STATIC_MUTEX_INIT)
#    include "freertos/mutex.h"
#endif
#if !defined(AC_LOCK) && !defined(AC_UNLOCK) && !defined(AC_STATIC_MUTEX_INIT)
#    include "mswin/mutex.h"
#endif
#if !defined(AC_LOCK) && !defined(AC_UNLOCK) && !defined(AC_STATIC_MUTEX_INIT)
#    include "posix/mutex.h"
#endif
#if !defined(AC_LOCK) && !defined(AC_UNLOCK) && !defined(AC_STATIC_MUTEX_INIT)
#    error "No mutex implementation provided, and no compatible existing port found!"
#endif

#endif /* end ALPHA_CAELI_MUTEX_H_ */
