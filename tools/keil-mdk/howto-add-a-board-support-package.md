# HowTo: Add Board Support Options 

## Instructions

1. Click on `Manage Runtime Environment`.

2. Select the target board. 

3. Add any `board support` options (e.g. `LED`) and resolve any device dependencies.

4. Source files with the provided `API` interface are added under `Board Support`. For example:

5. Initialise functions can be added to `main`

    1. Add `LED_Initialize`.

    2. Explicitly define the functions used, or, import them.

        ```C
        #include "Board_LED.h"
        // extern int32_t LED_Initialize (void);
        ```