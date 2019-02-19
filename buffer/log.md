# Buffer Log
This is a log of everything that is being worked on in relation this unit.
Entries are not deleted and new entries are added at the top of this file.
Try to keep this up to date; it will make writing individual and group reports
easier.

## 2019/02/18 mbed CLI
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
