/**
 * @file        compiler.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli compiler feature detection.
 */
#ifndef ALPHA_CAELI_COMPILER_H_
#define ALPHA_CAELI_COMPILER_H_

/// Mark a parameter as unused.
#define AC_UNUSED(x) ((void) (x))

/**
 * @def AC_DECLARE_INLINE
 *
 * Declare an inline function in a header.
 */
#ifndef AC_DECLARE_INLINE
#   if __GNUC_GNU_INLINE__
#       define AC_DECLARE_INLINE extern inline
#   elif __GNUC__ || __clang__
#       define AC_DECLARE_INLINE inline
#   else
#       define AC_DECLARE_INLINE static inline
#   endif
#endif /* end !defined(AC_DECLARE_INLINE) */

/**
 * @def AC_DEFINE_INLINE
 *
 * Emit a function definition for a declared inline function, if the compiler decides not to inline
 * it.
 */
#ifndef AC_DEFINE_INLINE
#   if __GNUC_GNU_INLINE__
#       define AC_DEFINE_INLINE inline
#   elif __GNUC__ || __clang__
#       define AC_DEFINE_INLINE extern inline
#   else
#       define AC_DEFINE_INLINE static inline
#   endif
#endif /* end !defined(AC_DEFINE_INLINE) */

#endif /* end ALPHA_CAELI_COMPILER_H_ */
