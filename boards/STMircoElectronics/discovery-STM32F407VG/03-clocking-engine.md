# MCU Clocking Engine and Clock Tree Interface

## Introduction

* All `MCU`s have a `clocking engine`.

* Peripheral clocks require a clock source - Cortex system timer, FCLK Cortex clock, Ethernet PTP, USB, bus clocks, etc. 

* There are several `clock sources` available on the `ST32FM407` board.

* These are arranged is as `clock tree` thorough various `multiplexers` and `prescalers` to produce a single `system clock (SCLK)`.

* To configure a `peripheral` it's associated clock must be enabled in the `RCC`, by finding the memory mapped enabled register and setting it.

* An `MCOx` clock output `signal` can be enabled and routed to `GPIO` pins in-order to check the clock frequency using a `logic analyser`.

> Details on which pins control the clocks can be found in the `Reference Manual` and `Datasheet`.

> The timers can also be configured using the `MDCube` configurator.

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

## STM32 CubeMX - Clock configuration

> `CubeMX` is a UI tool for generating the code for specific clock configurations for ST based boards.

1. A UI for generating `clocking engine configurations` for the `STMicroelectronic` series of boards.

    1. __CREATE__

        1. __STM32 CubeMX__ - Use `STM32 CubeMX` and generate a configuration for the desired board.

        2. __Keil__ - Add `Manage Run-Time Environemnt` for `STM32 CubeMX` and generate a configuration for the desired board.

    2. __LOAD__ - Find the `.ioc` project file (in `STCubeGenerated` folder) for the required project.


2. Clock Engine Configuration - The UI allows you to configure 

    1. The `selected clock input sources` via the `clock multiplexers`.
    
    2. The `output clock frequncy` by the `multipliers`.

---

## Manual - Peripheral and Clock configuration

> The clocking engine can also be configured manually using `memory mapped registers` with information from the `reference manual`.

> All peripheral used need to have their clocks configured and initialised.

1. Generic Algorithm - Configure a peripheral 

    1. Find the peripheral to configure.

    2. __Configure peripheral clock__

        1. Find the bus the peripheral is attached to.

        2. Find the `RCC` memory mapped register required to `enable` the clock.

            1. Find the `base address` of the `RCC`.

            2. Find the `offset` of the enable register.

        3. Find the `bits` that need to be set on the register to enable the clock for that peripheral.

    2. __Configure peripheral__

        1. Find the memory mapped register required to configure the peripheral as required.

            1. Find the `base address` of the peripheral.

            2. Find the `offset` of the configure register.
        
        3. Find the `bits` that need to be set on the register to configure the peripheral as required.

---

## Selecting and analyzing an output clock

1. MCus use the `MCOx` mechanism to write the clock __signal__ to `GPIO` pins.

    1. `MCO1` - Signal 1.

    2. `MC02` - Signal 2.

2. Outputting a clock signal:

    1. Select the required clock for the `Microcontroller clock output signal (MCOx)` signal.

    2. Output the `MCOx signal` to an `GPIO output pin`.

3. `Clock Configuration Register (CCR)`

    1. This can be used to enable the output of a specified clock signal to a GPIO pin.

4. `Pinouts` and `Alternate Function Mapping`

    1. A `port` in an `st32fm` MCU has 16 `pins`.

    1. Microcontroller `pins` can have `different modes`.
    
    2. Several functions can be multiplexed onto a single pin and the required mode configured.

    3. One `pin mode` defines outputting an `MCOx signal` to that pin. 

---

## Experiments

1. Write a program to output the `HSI` clock on the micro controller pin and measure it using a logic analyser.

1. Write a program to output the `HSE` clock on the micro controller pin and measure it using a logic analyser.