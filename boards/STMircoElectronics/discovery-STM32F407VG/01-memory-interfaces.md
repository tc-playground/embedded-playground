# MCU Memory Interfaces

## Memory Types and Addressing

1. Different type of memory are mapped into the same contiguous eaddress space,

2. __FLash__ - MCU `Flash` memory address - `0x0800 0000` - `0x080F FFFF` (0x080FFFFF - 0x08000000 = 1048575 = 65535 bytes = 64k)

    1. `Flash memory` is where the core embedded program `instructions` are stored.

    2. `Flash memory` is where the core embedded program `constant data value` are stored.

    3. `Flash memory` is where the core embedded program and `vector tables` stored.

3. __SRAM__ - MCU `SRAM` memory base address:

    1. `SRAM1` - `0x2000 0000` - `0x2001 BFFF` (16 KB)

    2. `SRAM2` - `0x2001 C000` - `0x2001 FFFF` (112 KB)

---

## Memory Map (STM32F407x)

> A `memory map` defines which processor addres bus addresses are maped to which preipherals.

> The detailed memory map for the `STM32F407x` can be found in the `RM0090 Reference Manual`.

1. `ARM cortex M4` - 32 bit `System Bus`

    * __Addresses__ - `2^32` - `4GB` -   `0x0000 0000` - `0xFFFF FFFF`.

2. __Flash Range__ - `0x0800 0000` - `0x080F FFFF`.

3. __SRAM1 Range__ - `0x2000 0000` - `0x2001 BFFF` (16 KB)

4. __SRAM2 Range__ - `0x2001 C000` - `0x2001 FFFF` (112 KB)

5. __Buses__

    * __AHB3__ - `0xA000 0000` - `0xA000 0FFF`

    * __AHB2__ - `0x5000 0000` - ` 0x5006 0BFF`

    * __AHB1__ - `0x4002 0000` - `0x4007 FFFF`

    * __APB2__ - `0x4001 0000` - `0x4001 6BFF` 

    * __APB1__ - `0x4000 0000` - `0x4000 7FFF` 

---

## Embedded C Memory Allocation

1. __Constant Static Variables__

    * These are placed in `Flash Memory`.

2. __Local Variables__

    * Created at runtime and live in the `stack memory`. 

    * `Stack memory` is placed in `RAM memory`.

    * `Stack memory` is only consumed at runtime.

> NB: The address of specific variables can be found using an IDE or debugger.




---

## References

* [RM0090 - Reference Manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/3d/6d/5a/66/b4/99/40/d4/DM00031020.pdf/files/DM00031020.pdf/jcr:content/translations/en.DM00031020.pdf)




