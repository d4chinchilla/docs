System Design
=============

The purpose of the system was to obtain audio from microphones, extract the angle of incidence of sounds,
and display it on the hardware, and also a web interface. In order to make this happen, data must be sampled
from an analogue microphone, and processed in a digital form which can be displayed to the user by some kind
of computer. This naturally splits the project into a digital and analogue component.

For the analogue component of the system, instrumentation amplifiers were initially chosen to
amplify the signal from the microphones, but microphone pre-amps were later chosen over them,
as the microphone output was not differential, and there were no dual rails.

Four microphones were used, as at minimum three are required to deduce the angle of a
sound, and four microphones simplify the mathematics for calculating angles. The extra
microphone also allows for increased accuracy. Using six or more was considered, but
these ideas were rejected due to the extra hardware required.

It was also decided to build some analogue filters to remove mains and any other unwanted noise.
The filtered audio can then be read by ADCs and sent to the digital components of the system over SPI.

For the digital component of the system, it was decided to use a Raspberry Pi Model 3, since
every member of the team already had one, which would be exceptionally useful for development and
testing. This presents some issues however. A Pi is well suited to performing
the signal processing portion of the system, as it has a quad-core CPU with multipliers.
However, unless an RTOS is installed, which would be awkward if it is also running a web
server, a Raspberry Pi cannot sample audio from four separate ADCs at once, with a consistent sampling
rate. It was therefore decided to handle the reading the ADCs on another piece of hardware.

An FPGA was considered for this role, as in theory it could very rapidly sample from a set of ADCs,
and if one with multipliers was chosen, could even rapidly perform some of the slower parts of
the signal processing.

However, this was rejected in favour of an ARM micro-controller, as a member of the team already
had one to begin development on, and it would cost considerably less to find the required performance.
Specifically an ARM Development Board was chosen, as it could easily interface with the Pi over USB
to transfer both data and flash new firmware.

It would be impractical to process data from all four microphones on the Raspberry Pi in real-time,
due to the huge amount of computing power required, so the decision was taken to buffer the ADCs
continually for a period of time using the micro-controller. The micro-controller can then transfer
the raw ADC readings to the Raspberry Pi over USB serial.

As a user interface, an LED ring was chosen, as it is easy to interpret. It is also aesthetically
pleasing and cheap when compared to a display. A ring of pre-made addressable LED modules was chosen,
as a bespoke solution would have been unnecessarily complex. The Pi can communicate with the LED ring
using the one-wire protocol.

A web interface was also chosen, as the Pi can easily host a web-server, and it could be used
to upload more firmware to the system, and provide the user more detailed information.
Finally, a button was also chosen to the Pi, and used to trigger calibration. The back-end on the Pi
could be shut down, or told to calibrate through a simple downward interface exposed as a FIFO.
