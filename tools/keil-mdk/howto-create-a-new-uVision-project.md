# HowTo: Create a new uVision Projects

## Instructions

1. __Create__ a new project and select the required target board. 

    1. Ensure the `Device Startup` routines for the board are added, along with `CMSIS Core` and any other dependencies. This will add:

        1. `startup_XXX.s` - Assembly file containing `vector table` information for the microcontroller.

        2. `startup_XXX.c` - C file defining `start up routines` that are called before the `main` function. Setting up `clocks`, `vector tables`, etc.

2. __Add__ a `main` function to be called by the `Reset_Handler`

    1. Code always restarts from the `Reset_Handler` of the `Microcontroller Unit (MCU)`. The `Reset_Handler` is called whenever the system is (re)powered on.

        1. The `Reset_Handler` is defined in assembly in `startup_XXX.s` in the `Vector table`.

        2. The `Reset Handler` calls the `SystemInit` and then the `__main` assembler procedures.

        3. `SystemInit` is defined in `startup_XXX.c`
    
    2. Click on `Source Group` and add a new `C` file with the desired name, e.g. 'main'.

    3. Define a simple `C` main function:

        ```C
        int main(void) {
	        return 0;
        }
        ```

3. __Build__ the project by hitting `F7`.


