# Web Log
This is a log of everything that is being worked on in relation this unit.
Entries are not deleted and new entries are added at the top of this file.
Try to keep this up to date; it will make writing individual and group reports
easier.

## 2019/02/28 - 20:00 Matt Crossley Script Fix

The script has been fixed by causing the script to sleep if there is nothing sitting on the pipe, meaning the CPU time is greatly reduced. This is acceptable as the installation of new firmware is not time critical. After some testing of the script, the web server can successfully move files around and therefore is functional.

## 2019/02/27 - 12:00 - Matt Crossley Script Solution

A solution was devised by Francis by utilising a pipeline. A script is run at boot to open a temporary pipe file that can be written to by the web server. The information within the pipe is then interpreted by a script that will run the required install instructions as sudo, this is a work around to allow the web server to perform install commands, as well as to restart any services if required. A currently problem with this script is that when running, an entire core of the CPU is parked at full usage, effectively blocking off one quarter of the CPU, this will be fixed soon.

## 2019/02/25 - 17:00 - Matt Crossley PM Session

In the afternoon, I worked on building up and testing the install scripts from the various firmware and software that is run on/off of the pi. Initial problems are brought about with pi permissions as the install scripts are required to move files about, install script working as sudo but yet to properly function when fun from web server.

## 2019/02/25 - 13:00 - Matt Crossley Lab AM Session

The focus of the morning lab was to implement an FFT display on the Web Server by utilising available libraries. I initially investigated using a library called plot.ly, however the utilisation of this library proved difficult when plotting dynamic, overwriting data.

I then proceeded to find an alternative library called Canvas.js which provides a much more intuitive suite of tools, allowing for a logarithmic FFT display to be easily generated. Canvas.js allows the FFT display data to be constantly updated with new data from the back-end, as well as adding an element of interactivity as by hovering over the graph, the frequency and aplitude at any point can be accruately read.

## 2019/02/21 - 00:01 - Matt Crossley - PHP File Upload

Server is accessible remotely on local network through IP, still have some DNS/port problems to work out in order to access through a URL, which will make connecting to the site much easier. Implemented PHP code to support a file uploads, this allows us to upload firmware directly the the server, uploaded file is dropped into:

`/var/www/html/uploads`

As a file named "firmware.jpg". .jpg is a placeholder extension and will be replaced, just used for testing. Upload is locked to single file extension and no files >1MB. Backend/I can work on script to automate firmware updates on change of uploaded file.

Current web will be uploaded to web branch matt (tbd).

## 2019/02/19 - 10:44 - Matt Crossley
Francis has written a basic UI for point tracking using a radar-esque display, have set up apache server on RPi and loaded this page on, working on modifying server to be accessible remotely (on same network then potentially internet).
