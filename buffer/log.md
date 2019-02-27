# Buffer Log
This is a log of everything that is being worked on in relation this unit.
Entries are not deleted and new entries are added at the top of this file.
Try to keep this up to date; it will make writing individual and group reports
easier.

## 27/02/19 Investigating glitch and testing ADCs

It was noticed on the oscilloscope that the glitches always last for roughly 52us, suggesting it's the same thing causing the issue each time. It also has a repeating pattern for when it occurs. This patterns seems to suggest that if it should be happening during a serial send, it wouldn't have an effect so is unnoticeable, unless the serial itself is taking longer to send. This time period is not as large a delay when considering serial. It is only when the interval ends during a sample that it is very visible (at least with the setup used). This suggests it's a repeating process, suggesting an issue with mbed OS. However, this shouldn't be happening due to an RTOS which is supposed to depend on deterministic timings.

Using my own Nucleo board, communication with an ADC chip was tested. Sampling only the 8 most significant bits causes no issues. Sampling is reliable slightly above the 1MHz maximum clock, which is useful due to how difficult it's proving getting accurate timing. Code was made to give a sampling rate of 50kHz using my own board. Screenshot of the oscilloscope were taken as proof as it couldn't be signed off at the time.

## 26/02/19 Investigating glitch

By commenting out most of the code until it is reduced to a minimal output system, it was attempted to isolate the component causing the delay glitches. However, almost everything was commented out, and the glitch persisted. This included serial, digital reads, and all data processing, leaving only digital output. It seems unlikely this is causing the issue. Mark has been told that when designing the case, he should design it such that my own Nucleo can be used if needed. 

## 25/02/19 Timing issues

Timing/delaying the pulses has proved difficult. Any 'for' loops appear to be optimised by the compiler and either removed or unrolled to the point where their behaviour is hard to tune. Inline assembly was tried, as well as #pragmas to prevent unrolling of loops, but neither seem to have fixed the problem.

When testing the protocol on the new board, it exhibits odd behaviour. Most samples occur with no problems, however the outputs seem to have huge delays at random points. These are long enough to ruin the high sampling rate needed. Worst-case, my board can be used for the product as it has been proven to work. 

It was suggested that the reason the glitch was only happening on the new board was due to different sized registers in the UART modules of the two boards. Depending on if an interrupt was involved to send the data, which was halting the rest of the program, this could be sensible. The glitch needs more investigation.

## 22/02/19 New protocol

The bit-bashing protocol matches the SPI specification, in terms of clocks and chip-select. It is inaccurate in terms of timing, as the pins can toggle faster than the max 1MHz clock the ADC can use. Delays will need to be added using redundant loops, as the smallest function in C is wait_us(), with a minimum argument of 1, and the desired value is 0.5.

This was tested on an oscilloscope using my own Nucleo board. Timings were not worried about too much at this stage, as it will have to be done again manually when the new board arrives. It is expected that this protocol will be able to provide the 50kHz sampling rate.

To reduce the overall sample time and increase the sampling rate, it might be possible to only clock out the 8 most significant data bits from the ADC, as the last 4 are only discarded at a later date anyway. This would make it much easier to get high-speed transmissions. The ADCs need to be tested to ensure they behave in this way, without trying to finish the previous sample when the chip-select is brought low again.

## 21/02/19 Speed concerns

The new protocol uses a bit-bashing equivalent of SPI, which theoretically is almost as fast and as the pins can all toggle (if the wait_us calls are replaced by idle for loops). The concern is that the sampling and serial transmission are all calls in the function loop, and therefore the serial will be holding up the loop and the sampling rate.

The serial needs to send 52 characters, and at a baud of 115200 takes far longer than acceptable to maintain a high sampling rate. Allocating the serial transmission to a separate thread may change this to some extent, but possibly not as we're using a single-core processor.

This is going to have to be checked on an oscilloscope. In a worst case scenario, bit-bashing may be possible on the Raspberry Pi, by sampling all ADCs at the same time to remove timing concerns.

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
