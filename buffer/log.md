# Buffer Log
This is a log of everything that is being worked on in relation this unit.
Entries are not deleted and new entries are added at the top of this file.
Try to keep this up to date; it will make writing individual and group reports
easier.

## 19/02/19 Issues with QSPI
QSPI (QuadSPI) is a variant of SPI that essentially operates four SPI lines simultaneiously, using the same data, clock and chip select lines. According to the documentation of mbed OS, there is QSPI support built in. The original program was designed to use this.

However, using both the CLI tools and the online compiler, it was impossible to get QSPI programs to compile, claiming QSPI was not defined as a type.

The advantage of using QSPI was that it would lead to all four ADCs being read simultaneously, without having to worry about delays in timing between the samples. Using four seperate instances of SPI may remove this advantage.

The best workaround for this (I currently think) is to use a single SPI bus, with the clock and chip select lines connected to all ADCs. The data lines could be read simultaneously using the BusIn command, which does as described below (from the docs):
>With the BusIn API, you can combine number of DigitalIn pins to read them at once. This abstraction is useful for checking multiple inputs together as single interface instead of individual pins.

Assuming the delays throughout the wiring and ADC chips are all about the same, and the different data lines actually are read at the same time by BusIn, this would functionally be the same as QSPI. Future attempts at reading the ADCs will be done using this method, not QSPI.

## 18/02/19 mbed CLI
mbed CLI tools have been installed and got working. To build and upload code,
add the code in a file named main.cpp inside the directory "mbed-os-program".
From inside the 'current' directory (this is just how I've set it up on my system - more of a reminder to me) use the command:

`mbed compile -t GCC_ARM -m NUCLEO_L432KC -f`

Assuming the board is plugged in, the code will compile and upload automatically.

If these instructions are not exactly followed, possible annoying things that may
happen include:

* It might not compile at all
* It might decide to compile all libraries again (and then probably not work)
* It might name the binary something different, so after compile won't flash

However, if this can be set up on Linux then the Pi would be capable of flashing the code onto the ARM chip on its own (ie. doing a firmware update).

## 2019/02/19

Added a draft of what the pi backend currently expects the serial to look like. This might 
be changed later - it is very simple to do this in the backend.
