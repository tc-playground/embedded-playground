# Install Keil MDK

## Introduction

* `Keil` is a `microcontroller development kit` target at the `ARM` based microcontrollers.

* `Keil` is `windows only`.

---

## Keil MDK Components

### MDK Tools

1. __MDK Core__

    1. `uVision` IDE and debugger

    2. `ARM` C/C++ compiler.

### Software Packs

1. __Device__

2. __CMSIS__ - A vendor-independent hardware abstraction layer for microcontrollers that are based on Arm® Cortex® processors.

3. __MDK Middleware__

    1. Network IPv4/IPv6 

    2. USB Host Device

    3. File System

---

## Installing Packs

1. To install a new pack select the `Pack Installer`, navigate to the desired board, and, install the desired packs.

2. The source code for the packs can be found in: `${keil}/ARM/PACK/${board}/${version}/Drivers.${board}HAL_Driver/Src`

---

## References

* [Keil MDK](https://www2.keil.com/mdk5)

* [CMSIS](https://developer.arm.com/tools-and-software/embedded/cmsis)

