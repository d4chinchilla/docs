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
