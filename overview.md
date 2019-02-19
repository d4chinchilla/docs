# Project Chinchilla Overview

Project Lead: [Hugo McNally](http://github.com/hu90m)

Main Log File: [log.md](log.md)

## What is Project Chinchilla?

Project Chinchilla is a portable device which can accurately measure the angle
from which sounds come from. It was conceived with the intent of helping deaf
people see sounds and where they come from. In addition to situational
awareness, this device will help deaf people can lip read follow conversations
with multiple interlocutors.

## Block Diagram
![](block_diagram.svg)


## Units
* [Web](web/overview.md)
* [Buffer](buffer/overview.md)
* [Back-end](back-end/overview.md)
* [LED controller](led_ctl/overview.md)
* [Hardware](hardware/overview.md)

## Unit Leads
* Back-end Lead: [Francis Wharf](http://github.com/xeom)
* Buffer Lead: [Matthew Johns](http://github.com/mjohns4)
* Hardware Lead: [William Webb](http://github.com/bishopstoenail)
* LED Control Lead: [Mark Warnants](http://github.com/markwarnants)
* Web Lead: [Matt Crossley](http://github.com/mattcrossley99)

## Interfaces

### ADCs -> Buffer
This is the interface between the ADCs and microcontroller.
This interface will be finalised by the Hardware Lead
([William Webb](http://github.com/bishopstoenail)).
Information about this finalised can be found in
[hardware/adc_to_buffer.md](hardware/adc_interface.md).

### Buffer -> Back-end
This is the interface between the microcontroller and Raspberry Pi's back-end.
This interface will be finalised by the Buffer Lead
([Matthew Johns](http://github.com/mjohns4)).
Information about this interface can be found in
[buffer/buffer_interface.md](buffer/buffer_interface.md).

### Back-end -> webUI and LED Control
This is the interface between the Raspberry Pi's back-end and all user serving
components.
This interface will be finalised by the Back-end Lead
(Back-end Lead: [Francis Wharf](http://github.com/xeom)).
Information about this interface can be found in
[back-end/upward-interface.md](back-end/upward-interface.md).

## Code Repositories
| Units                                                                  | Description                                                 |
|:----------------------------------------------------------------------:|:------------------------------------------------------------|
| [signal_processing](https://github.com/d4chinchilla/signal_processing) | Microcontroller's buffer program and Raspberry pi back-end. |
| [web](https://github.com/d4chinchilla/web)                             | Server and client for the webUI.                            |
| [led_ctl](https://github.com/d4chinchilla/led_ctl)                     | Pretty self explanatory.                                    |

## Are you a Git Noob?
Francis has written a great guide in ['git.md'](git.md).
