# LED Control Overview
LED Control Lead: [Mark Warnants](http://github.com/markwarnants)

Log File: [led_ctl/log.md](log.md)

## LED ring and calibration button
LEDs are individually addressable with 8-bit RGB channels. Communication is based on a single-wire protocol, which has strict timing requirements. They will recieve power directly from the battery and be connected to the raspberry pi GPIO. Each LED has a WS2812 chip inside which enables it to detect the address and decode the colour. The programming for this will recieve an angle, amplitude and frequency from the back-end; these are used to light up the LEDs to represent the signal and its direction. This will be written in python (must be run as root). Libraries written by Adafruit (below), will be used to ensure the timing requirements are met and simplify the programming process.    

A calibration button will also be connected to the raspberry pi via the GPIO. This will add a line to a file when pressed, and also when pressed and held to send a restart signal.

### Hardware
LEDs:
- Pi 5V to Neopixel 5V
- Pi GND to Neopixel GND
- With 1000µF protection capacitor between 5V and GND
- Pi GPIO18 to Neopixel Din with 470Ω resistor in between

Calibration button:
- Pi GND to one button leg
- Pi GPIO4 to adjacent button leg

### Setup
- Update / Upgrade Pi
- Install python3-pip
- Install GPIO library: <code>sudo pip3 install RPI.GPIO</code>
- Install adafruit_blinka: <code>sudo pip3 install adafruit-blinka</code>
- Install CircuitPython: <code>sudo pip3 install rpi_ws281x adafruit-circuitpython-neopixel</code>

### Sources
Neopixel install:    
<https://learn.adafruit.com/neopixels-on-raspberry-pi?view=all>    
<https://github.com/adafruit/Adafruit_CircuitPython_NeoPixel>    
Licence: MIT    

Circuit python install:    
<https://learn.adafruit.com/circuitpython-on-raspberrypi-linux?view=all>    
<https://github.com/adafruit/circuitpython>    
Licence: MIT    
