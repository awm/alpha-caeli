# ɑ Caeli

**A library of portable system APIs.**

ɑ Caeli provides a thin portability layer of a selection of system functions for use in other
projects.

## Feature Matrix

| Feature               | Standard C Library   | Windows            | POSIX              | FreeRTOS           |
| --------------------- | -------------------- | ------------------ | ------------------ | ------------------ |
| Mutexes               |                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| Obtain System Time    | :heavy_check_mark:\* | :heavy_check_mark: | :heavy_check_mark: |                    |
| Local Time Conversion | :heavy_check_mark:\* | :heavy_check_mark: | :heavy_check_mark: |                    |
| UTC Time Conversion   | :heavy_check_mark:\* | :heavy_check_mark: | :heavy_check_mark: |                    |

*\* Single-threaded only.*
