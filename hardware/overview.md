# Hardware Overview
Hardware Lead: [William Webb](http://github.com/bishopstoenail)  

Log File: [hardware/log.md](log.md)  

## Mic & Preamp
Output: 0 - +3.3V  
Power:  Regulated +3.3V

## ADC
Input:  0 - +3.3V
Output: 12 bit & 1 sign bit  
Power: +5V Unregulated, +3V3 Reference  

## Power
Primary source of power is a USB battery bank.  
This takes care of battery management and charging.  

Spliced into the +5V wires from the battery is a power switch for everything.  
Yes this kills the pi in a sligihtly cruel manner.  
No we don't care.  
This also provides a good place to split off for the ADC and preamp power.  
