# Hardware Log
This is a log of everything that is being worked on in relation this unit.
Entries are not deleted and new entries are added at the top of this file.
Try to keep this up to date; it will make writing individual and group reports
easier.

## 2019/02/18  
Will:  
Looking for a suitable ADC  
Sampling speed and low noise are priorities  
Most probably running off linear reg at 3.3V  
Pseudo-differential ADC moves (potentially) too slowly for the audio  
Differential would be perfect  
Single ended will be fine (probably) as long as careful with layout  
  
Carol:  
Looking for suitable Linear regulator for Mic, Amplifier, etc.  
Looking for suitable battery bank  
Rechargable USB battery bank is stable enough for the RPi  
Will use linear regs to make stable for audio section  

## 2019/02/19
Finalising parts list  
Ensuring there are suitable substitute parts if things dont go to plan  

Battery bank has an output of +5V +-5% USB  
Suspiciously also says 9V and 12V outputs from the same port?!  

Parts list converted to csv for easier management  
Thinking about filtering the output of the Maxim chip to reduce buggery further  
Should look into the spectral range of human voice a bit more  
Suggestions that human voice does fine through a 50Hz highpass  
That's a start at least  
Need to look for a suitable opamp to do this with  
TL071 I had hoped to use requires too high a voltage  
 
## 2019/02/20-21
Requsitions form handed in  
LED strip we had hoped to use was not available as was US stock  
Alternative source has been sent back to Mark Temple  
Perfboard has been sourced along with some tin-copper wire  
Use of the Ultimaker has been secured  
This includes both the option of sending files for printing and also borrowing  
the printer for some time to complete the prints  
LMV358 opamp was chosen but will require a bit of messing to make sure it's  
alright as was chosed quite quickly  

## 2019/02/22
Will - Working on completing a general wiring diagram designed to seperate the 
analogue and digital sections of the project.  
Carol - Finalising and simulating the design for the filter on the output of 
the preamp. Also looking at what filtering we can do on the preamp itself.  

## 2019/02/25  
A note on calculating gain for the preamp  
We're going to have to do it experimentally really  
Although 45dB as a mic equates to roughly 5mV/94dB SPL  
Plan for today:  
[x] Get microphone module schematic drawn up  
[ ] Prototype on breadboard microphone module and determine required gain  
[ ] Pick value of passives for required response  
[ ] Prototype with additional active filter  
[ ] Begin moving onto stripboard  

So maybe due to the late delivery of parts today hasn't been as successful as 
originally hoped  
Progress has been made as far as putting a few amplifiers onto breakout boards 
and drawing out the schematic properly  
The basic amp has been built on a breadboard but is lacking in gain and is 
suffering from MASSIVE 50Hz interference  
Suspected the noise if from equipment, should try in lab soon  

It may or may not be what I would describe as a grounding issue...  

## 2019/02/27  
Fixed sorta kinda  
Needs more filtering to remove 50Hz noise maybe  
Plugged in in labs and has very little noise compared to at home (if any)  
Shouldn't be a problem at all  
Was worrying about nothing (as usual) maybe probably  

Impedance on pullup was matched to the capsule properly, previous was massive  
and hence gave crap SNR  
Preamp filter thresholds are being changed to match the human voice a bit 
betterer  
There's a simple fft of my voice lying around of my windows install desktop  


Filter is being redesigned, previously had a first order active filter  
Would be better if we were using a second order filter if going active  

Still seeing massive noise when tested in the house  
Also seeing very significant 4kHz switching noise from the battery bank  
May or may not be an issue, will have to see if it's still there once in labs  

