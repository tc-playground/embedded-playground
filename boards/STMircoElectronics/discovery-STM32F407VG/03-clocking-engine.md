# MCU Clocking Engine and Clock Tree Interface

## Introduction

* All `MCU`s have a `clocking engine`.

* There are several clock sources available on the `ST32FM407` board.

* These are arranged is as `clock tree` thorugh various `multiplexers` and `multipliers` to produce a single `system clock (SCLK)` 

* Details on which pins control the clocks can be found in the User Manual.

* They can be configured using the `MDCube` configurator.

---

## Clock Sources

1. __Crystal Oscillator__

    1. Externl to MCU. `8MHz` on `ST32FM407`

2. __RC Oscillator__

    1. Intneral to MCU. `HSI (Hight Speed Internal`.

3. __Phased Lock Loop (PLL)__

    1. Internal to MCU.

