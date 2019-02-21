# Web Log
This is a log of everything that is being worked on in relation this unit.
Entries are not deleted and new entries are added at the top of this file.
Try to keep this up to date; it will make writing individual and group reports
easier.

## 2019/02/21 - 00:01 - Matt Crossley - PHP File Upload

Server is accessible remotely on local network through IP, still have some DNS/port problems to work out in order to access through a URL, which will make connecting to the site much easier. Implemented PHP code to support a file uploads, this allows us to upload firmware directly the the server, uploaded file is dropped into:

`/var/www/html/uploads`

As a file named "firmware.jpg". .jpg is a placeholder extension and will be replaced, just used for testing. Upload is locked to single file extension and no files >1MB. Backend/I can work on script to automate firmware updates on change of uploaded file.

Current web uploaded to web branch matt.

## 2019/02/19 - 10:44 - Matt Crossley
Francis has written a basic UI for point tracking using a radar-esque display, have set up apache server on RPi and loaded this page on, working on modifying server to be accessible remotely (on same network then potentially internet).
