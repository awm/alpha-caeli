#
# @file        CMakeLists.txt
# @copyright   2021 Andrew MacIsaac
# @remark
#      SPDX-License-Identifier: BSD-2-Clause
#
# @brief       Build instructions for ɑ Caeli library.
#
include(CheckSymbolExists)

# Test for platform features.
check_symbol_exists(InitOnceExecuteOnce         "Windows.h"                 HAVE_MSWIN_INIT_ONCE)
check_symbol_exists(InitializeCriticalSection   "Windows.h"                 HAVE_MSWIN_CRITICAL_SECTION)
check_symbol_exists(PTHREAD_MUTEX_INITIALIZER   "pthread.h"                 HAVE_PTHREAD_MUTEX)
check_symbol_exists(_ftime_s                    "sys/types.h;sys/timeb.h"   HAVE__FTIME_S)
check_symbol_exists(gettimeofday                "sys/time.h"                HAVE_GETTIMEOFDAY)
check_symbol_exists(gmtime_r                    "time.h"                    HAVE_GMTIME_R)
check_symbol_exists(gmtime_s                    "time.h"                    HAVE_GMTIME_S)
check_symbol_exists(localtime_r                 "time.h"                    HAVE_LOCALTIME_R)
check_symbol_exists(localtime_s                 "time.h"                    HAVE_LOCALTIME_S)
check_symbol_exists(xSemaphoreCreateMutex       "FreeRTOS.h;semphr.h"       HAVE_FREERTOS_SEMAPHORE)
check_symbol_exists(xSemaphoreCreateMutexStatic "FreeRTOS.h;semphr.h"       HAVE_FREERTOS_STATIC_SEMAPHORE)
check_symbol_exists(xTaskGetSchedulerState      "FreeRTOS.h;task.h"         HAVE_FREERTOS_XTASKGETSCHEDULERSTATE)

configure_file(features.h.in include/alpha-caeli/features.h NEWLINE_STYLE UNIX)

# Define static ɑ Caeli library.
set(
    SRCS
    freertos/mutex.c
    mswin/gettime.c
    mswin/mutex.c
    posix/gettime.c
)
add_library(ac STATIC ${SRCS})

# Set include paths for library.
target_include_directories(
    ac
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

# Add FreeRTOS includes, if applicable.
# if (FreeRTOS_FOUND)
#     target_include_directories(
#         ac
#         PRIVATE
#         ${FREERTOS_INCLUDE}
#     )
# endif()
