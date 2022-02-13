/**
 * @file        freertos/mutex.h
 * @copyright   2021 Andrew MacIsaac
 * @remark
 *      SPDX-License-Identifier: BSD-2-Clause
 *
 * @brief       Alpha Caeli FreeRTOS mutex wrapper.
 *              Must be included via api.h.
 */
#if (HAVE_FREERTOS_STATIC_SEMAPHORE || HAVE_FREERTOS_SEMAPHORE) && \
    HAVE_FREERTOS_XTASKGETSCHEDULERSTATE
#   include <FreeRTOS.h>
#   include <semphr.h>
#   include <task.h>

#   include <assert.h>

/// FreeRTOS mutex structure.
typedef struct _ac_freertos_mutex
{
    volatile int        init_state; ///< Initialization state.
#   if HAVE_FREERTOS_STATIC_SEMAPHORE
    StaticSemaphore_t   mutex;      ///< Mutex variable.
#   else
    Semaphore_t         mutex;      ///< Mutex variable.
#   endif
} ac_mutex_t;

/// Static initializer for a mutex variable.
#   define AC_STATIC_MUTEX_INIT { false }

/**
 * Lock a FreeRTOS mutex.  FreeRTOS does not have a static initializer for mutex objects, so we
 * perform one-time initialization the first time the mutex is locked.
 */
AC_DECLARE_INLINE void _ac_lock_mutex
(
    ac_mutex_t *mutex ///< Mutex instance.
)
{
#   if HAVE_FREERTOS_STATIC_SEMAPHORE
    SemaphoreHandle_t sem = &mutex->mutex;
#   elif HAVE_FREERTOS_SEMAPHORE
    SemaphoreHandle_t sem = mutex->mutex;
#   endif

    if (xTaskGetSchedulerState() == taskSCHEDULER_RUNNING)
    {
        vTaskSuspendAll();
        if (!mutex->initialized)
        {
#   if HAVE_FREERTOS_STATIC_SEMAPHORE
            sem = xSemaphoreCreateMutexStatic(&mutex->mutex);
#   elif HAVE_FREERTOS_SEMAPHORE
            sem = xSemaphoreCreateMutex();
#   endif
            mutex->initialized = true;
        }
        xTaskResumeAll();

        assert(sem != NULL);
        xSemaphoreTake(sem, portMAX_DELAY);
    }
}

/**
 * Unlock a FreeRTOS mutex.
 */
AC_DECLARE_INLINE void _ac_unlock_mutex
(
    ac_mutex_t *mutex ///< Mutex instance.
)
{
#   if HAVE_FREERTOS_STATIC_SEMAPHORE
    SemaphoreHandle_t sem = &mutex->mutex;
#   elif HAVE_FREERTOS_SEMAPHORE
    SemaphoreHandle_t sem = mutex->mutex;
#   endif

    if (xTaskGetSchedulerState() == taskSCHEDULER_RUNNING)
    {
        xSemaphoreGive(sem);
    }
}

/**
 * Lock a mutex.
 *
 * @param   m   Mutex instance pointer.
 */
#   define AC_LOCK(m)   _ac_lock_mutex(m)

/**
 * Unlock a mutex.
 *
 * @param   m   Mutex instance pointer.
 */
#   define AC_UNLOCK(m) _ac_unlock_mutex(m)

#endif /* end (HAVE_FREERTOS_STATIC_SEMAPHORE || HAVE_FREERTOS_SEMAPHORE) &&
              HAVE_FREERTOS_XTASKGETSCHEDULERSTATE */
