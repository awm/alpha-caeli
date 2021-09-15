# ɑ Caeli

**A library of portable system APIs.**

ɑ Caeli provides a thin portability layer of a selection of system functions for use in other
projects.

## Feature Matrix

| Feature               | Standard C Library   | Windows            | POSIX              | FreeRTOS           |
| --------------------: | :------------------: | :----------------: | :----------------: | :----------------: |
| Mutex                 |                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
| System Time Access    | :heavy_check_mark:\* | :heavy_check_mark: | :heavy_check_mark: |                    |
| Local Time Conversion | :heavy_check_mark:\* | :heavy_check_mark: | :heavy_check_mark: |                    |
| UTC Time Conversion   | :heavy_check_mark:\* | :heavy_check_mark: | :heavy_check_mark: |                    |

*\* Single-threaded only.*
