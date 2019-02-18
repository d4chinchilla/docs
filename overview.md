# Project Chinchilla Overview

## What is Project Chinchilla?

Project Chinchilla is a portable device which can accurately measuring the angle
from which sounds come from. It was conceived with the intent of helping deaf
people see sounds and where they come from. In addition to situational
awareness, this device will help deaf people can lip read follow conversations
with multiple interlocutors.

## Schematic
*add svg here*

## Units Making Up The Device.
* Web
* Buffer
* Back-end
* LED controller
* Hardware
  * case design
  * power
  * analogue front-end
  * schematics

## Code Repositories
| Units                                                          | Description                                                 |
|:--------------------------------------------------------------:|:------------------------------------------------------------|
| [signal_processing](github.com/d4chinchilla/signal_processing) | Microcontroller's buffer program and Raspberry pi back-end. |
| [web](https://github.com/d4chinchilla/web)                     | Server and client for the webUI.                            |
| [led_ctl](github.com/d4chinchilla/led_ctl)                     | Pretty self explanatory.                                    |
