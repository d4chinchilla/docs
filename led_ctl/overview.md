# LED Control Overview
LED Control Lead: [Mark Warnants](http://github.com/markwarnants)

Log File: [led_ctl/log.md](log.md)

## Neopixels
Programming in Python (must be run as root)    
Using adafruit libraries    

### Hardware
Pi 5V to Neopixel 5V    
Pi GND to Neopixel GND    
With 1000µF protection capacitor between 5V and GND    
Pi GPIO18 to Neopixel Din with 470Ω resistor in between    

### Setup
- Update / Upgrade Pi
- Install python3-pip
- Enable SPI & I2C in raspi-config interfacing options & reboot
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
