# LED Control Log
This is a log of everything that is being worked on in relation this unit.
Entries are not deleted and new entries are added at the top of this file.
Try to keep this up to date; it will make writing individual and group reports
easier.

## 22/02/2019 LED control code completed
Completed LED control code to take the angle and amplitude from the json file and, after checking it is the most recent entry, lighting up six LEDs which fade out. Currently, the amplitude scales the brightness as well as controls the colour: where blue is low amplitude, through green and then red is high amplitude. Once these levels have been set, every two milliseconds the brightness for all LEDs go down by one, thus achieving a fading effect. The calibration button code still needs to be done

Discovered that original method was blocking and that keeping the fading within the function would block another sound from being displayed.

## 25/02/2019 LED control code tested and button code completed
Tested LED code and debugged to ensure that it worked. Added code to ensure multiple signals mixed properly, and that they would loop round properly. Added hardware button code to write calibrate or reset command to a file when the hardware button is pressed momentarily or held for more than two seconds.
