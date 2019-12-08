# MCU Clocking Engine and Clock Tree Interface

## Introduction

* All `MCU`s have a `clocking engine`.

* Peripheral clocks require a clock source - Cortex system timer, FCLK Cortex clock, Ethernet PTP, USB, bus clocks, etc. 

* There are several `clock sources` available on the `ST32FM407` board.

* These are arranged is as `clock tree` thorough various `multiplexers` and `prescalers` to produce a single `system clock (SCLK)` .

> Details on which pins control the clocks can be found in the User Manual.

> They can be configured using the `MDCube` configurator.

---

## Reset and Clock Control (RCC) Engine

* The MCU clocks are configured by the `Reset and Clock Control (RCC)` sub system.

* Configuration is performed by setting `RCC registers`.

---

## Source Clocks `(ST32FM407)`

1. __Crystal Oscillator - HSE__

    1. Externl to MCU. `HSE (Hight Speed External)`. 

        * `8MHz` on `ST32FM407`.

        * Disabled by default. Need to be enabled in `System Core RCC`.
        
        * Might also be provided by the `STLink debugger`.

2. __RC Oscillator - HSI__

    1. Intneral to MCU. `HSI (Hight Speed Internal)`.

        * `16MHz` `RC oscillator` on `ST32FM407`.

        * Can be used as a `PLL` source.

        * Enabled by default.

3. __Phased Lock Loop (PLL)__

    1. Internal to MCU.

    2. `Clock Muliplier Engine` - Can boost the clock to higher freqeuncies.

        * This is configured by `register` on board. Please consult the `Reset and Clock control (RCC)` documentation.

> For a particular board consult the manual on how to obtain a `clock source (OSC)`.

---

## System Clock `(ST32FM407)`

1. `System Clocks` are derived from the `Source Clocks` via `multiplexers` and `prescalers`.

    1. `System Clock (SYSCLK)` - The main `system clock`.

    2. `Bus Clock (HCLK)` - The `bus` clock, via the `AHB prescalar`. 

        * NB: The same as the processor clock.

    3. `Bus Clock (PCLK1)` - The `bus` clock, via the `APB1` prescalar`.

    4. `Bus Clock (PCLK2)` - The `bus` clock, via the `APB2` prescalar`. 

---

## Peripheral Clocks

1. In modern MCU's before using a peripheral it's clock must be enabled via `RCC register`.


---

## System Clock Mux

1. A board mmight have `clock multiplexers` to select the input of a `specific clock source`.

----

## STM32 CubeMX

1. A UI for generating `clocking engine configurations` for the `STMicroelectronic` series of boards.

    1. __CREATE__

        1. __STM32 CubeMX__ - Use `STM32 CubeMX` and generate a configuration for the desired board.

        2. __Keil__ - Add `Manage Run-Time Environemnt` for `STM32 CubeMX` and generate a configuration for the desired board.

    2. __LOAD__ - Find the `.ioc` project file (in `STCubeGenerated` folder) for the required project.


2. Clock Engine Configuration - The UI allows you to configure 

    1. The `selected clock input sources` via the `clock multiplexers`.
    
    2. The `output clock frequncy` by the `multipliers`.

