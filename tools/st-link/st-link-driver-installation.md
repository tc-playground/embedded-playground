# ST Link Driver Installation

## Instructions

* __Windows__

    1. [Download ST-LINK](https://www.st.com/en/development-tools/stsw-link009.html)

    2. Unzip and run `stlink_dbg_winusb` as `administrator`.

    3. Check installation was successful:

        1. Connect the board via USB. 

        3. In `Computer Management` check `Device Manager` -> `Ports` -> `ST Microelectronics ST Link Virtual COM Port` is present.

           * Converses with the board over `UART`.

        2. In `Computer Management` check `Device Manager` -> `Universal Serial Bus devices` -> `ST Link Debug` is present.

            * Debugging interface used by the IDE.


* __Linux - Debian__

    ```
    sudo apt-get install libusb-1.0
    sudo apt-get install libc6-i386 lib32ncurses5
    ```

* __OSX__ - No driver installation required.


---

## Usage

1. Just connect the MCU device to a laptop using a `USB/MiniUSB` cable. 

---

## Resources

* [ST-LINK](https://www.st.com/en/development-tools/stsw-link009.html)