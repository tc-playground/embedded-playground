# Debugging

## Overview

* `Keilv5` offer debugging funcitonality upto 32k.

--

## Capabilities

1. `Reset` - Resets the board and halt at `Debug_Handler`.

2. `Break Points` - Create, disable, delete, clear all; Step in/over/out.

3. `Call Stack Window` - Show the callstack.

4. `Dissasembly Window` - Show the `assembler`.

5. `Register windows` - Show the `registers`.

6. `Symbols Window` - Show the `symbols`.

7. `Memory Windows` - Read/Write `memory` locations.

8. `Watch Window` - Watch defined variables.

9. `Command Window`.

---

## Debugging an unresponsive board using the `Call Stack`

1. Debugging an unresponsive board using the `Call Stack`.

    * NB: Executing an invalid operation will cause the `HardFault_Handler` to be invoked and the board to stop responding:

        ```C
        void raise_hard_fault(void) {
            // Create and invoke a function pointer using and invalid address
            void (*jump_addr) (void) = 0x00000000;
            jump_addr();
        }
        ```

    1. __Run__ code under `debug mode`. 
    
    2. __Start__ the execution until it stops responding.
    
    3. __Stop__ invocation to see it trapped in the `HardFault_Handler` in `startup_XXX`.

    4. __Open__ the `Call Stack` window to trace where the program is stuck and where it was called from.

---

## Using `Watch Windows`

1. Open `Watch Window`.

2. Type in a `watch expression`, or, _drag_ variables from source onto the `Watch Window`.

3. When a `breakpoint` is reached the _current value_ of the `watch expression` can be seen.