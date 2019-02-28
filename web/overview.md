# Web Overview
Web Lead: [Matt Crossley](http://github.com/mattcrossley99)

Log File: [web/log.md](log.md)

Authentication: [web/authentication/authentication.md](web/authentication/authentication.md)

## System Description
The web element of the system consists of a Apache web server that is hosted on the Raspberry Pi, the web server uses JavaScript and PHP to create UI elements and interaction. The end goal is for the system to provide a live and precise feed of the microphone data on the device by using UI elements to show the direction of incoming sound (via both a radar like display and a precise angle), to display live FFT's of the captured audio and to potentially show spacial location of the sound.
The web server will additionally serve as a control mechanism for the device, with the user being able to upload updated firmware among other functions.

## Task-list
- Basic UI Elements with random test data
  - [x] Started - No FFT
  - [ ] Working
- File Upload for Firmware
  - [x] Started - Mostly Working - Using Test Extension At The Moment
  - [ ] Working
- Back-end for file system (Incoming data/outgoing commands)
  - [x] Started
  - [ ] Working
- Data Input and Readback
  - [ ] Started
  - [ ] Working
- Correct Data Display (Radar + Numerical)
  - [ ] Started
  - [ ] Working
- Correct Data Display (FFT)
  - [ ] Started
  - [ ] Working
- UI Beautification - Maybe Use Qt with Python
  - [ ] Started
  - [ ] Working
- Additional Funcitionality (System Reboot etc.)
  - [ ] Started
  - [ ] Working
