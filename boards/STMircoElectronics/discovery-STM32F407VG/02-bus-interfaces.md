# MCU Bus Interfaces

## Introduction

* All MCUs will have several `busses` for reading and writing data to and from peripherals.

* A `bus matrix` can be used to multiplex `primary` devices with `secondary` devices.

* Operations can be transmitted from one bus to another via a `bridge`.

* Buses can operate at different clock-speeds to trade-off `energy consumption` vs `speed`.

---

## ARM Cortex M32-4 180 MHz

1. __ARM Cortex M32__ - has 3 `32 bit` address buses.

    1. __I-BUS__ - `Instruction Bus`. Reads/writes program `instructions` from `Flash memory`.

        * Instruction fetches from Code memory space, `0x00000000` to `0x1FFFFFFF`, are performed over this 32-bit `AHB-Lite bus`.

        * Connects to: `AHB Bus Matrix` -> `Flash I/F Controller`.

    2. __D-BUS__ - `Data Bus`. Reads/writes program `read-only constant data` from `Flash memory`.

        * Data and debug accesses to Code memory space, `0x00000000` to `0x1FFFFFFF`, are performed over this 32-bit `AHB-Lite` bus.

        * Connects to: `AHB Bus Matrix` -> `Flash I/F Controller`.

    3. __S-BUS__ - `System Bus` - 180 Mhz.

        * Instruction fetches, and data and debug accesses, to address ranges `0x20000000` to `0xDFFFFFFF` and `0xE0100000` to `0xFFFFFFFF` are performed over this 32-bit `AHB-Lite bus`.

        * Connects to: `AHB Bus Matrix` --> `AHB1 Bus` --> `GPIO`, `AHB/APB1 Bridge` and `AHB/APB2 Bridge`.

            * `AHB/APB1 Bridge` --> `APB1 Bus` 45 MHz --> `Timers`, `UART`, `DAC`, `HDMI`, `RTC`, `Power Management`, etc.

            * `AHB/APB2 Bridge` --> `APB2 Bus` 90 MHz --> `Timers`, `UART`, `Temp sensor`, etc.

        * Connects to: `AHB Bus Matrix` --> `AHB2 Bus` 180 MHz --> `Camera`, `USB`.

    > Faster `Advanced High Performance Bus (AHB)` vs Slower `Advanced Peripheral Bus (APB)`


2. __Bus Matrix__

    1. The `DMA Bus Matrix` routes `primary (master)` devices through to slaves.

        1. __Primary Devices__ - `Cortex M4`, `Ethernet`, `USB`, `DMA1`, `DMA2`, etc.

        2. __Secondary Devices__ - `AHB1`, `AHB2`, `SRAM1`, `SRAM2`, `FSMC`, `Flash`, etc.
    
    2. Not all `primary` devices will be connected to `secondary` devices.


3. __Peripheral Buses__

    > All peripherals are accessed over the `S-BUS` via buses extended over the .

    1. __AHB1__ - 180 MHz - `GPIO`, `AHB/APB1 Bridge` and `AHB/APB2 Bridge`.

    2. __AHB2__ - 180 MHz - `Camera`, `USB`.

    2. __APB1__ - 45 MHz - `Timers`, `UART`, `DAC`, `HDMI`, `RTC`, `Power Management`, etc.

    3. __APB2__ - 90 MHz - `Timers`, `UART`, `Temp sensor`, etc.

---

## References

* [Reference Manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/3d/6d/5a/66/b4/99/40/d4/DM00031020.pdf/files/DM00031020.pdf/jcr:content/translations/en.DM00031020.pdf)

* [DMA Application Note](https://www.st.com/content/ccc/resource/technical/document/application_note/27/46/7c/ea/2d/91/40/a9/DM00046011.pdf/files/DM00046011.pdf/jcr:content/translations/en.DM00046011.pdf)