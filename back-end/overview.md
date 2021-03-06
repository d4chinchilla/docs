Back-end Overview
=================

Back-end Lead: [Francis Wharf](http://github.com/xeom)

Log File: [back-end/log.md](log.md)

Components
----------

- Reading data from the microcontroller into memory.
  - [ ] started
  - [ ] working

- Doing cross correlation between the four signals.
  - [ ] started
  - [ ] working

- Finding the peaks in the cross correlations.
  - [ ] started
  - [ ] working

- Calculating and checking the angle of the source of the sound from the peaks.
  - [ ] started
  - [ ] working

- Optionally finding the frequency of the peaks so we can colour the LEDs according to frequency.
  - [ ] started
  - [ ] working
  
- x_corr code (tom)
  - [ ] finish on 20/2, but further test is needed
  - [ ] DFT method, test passed (22/2)
  - [ ] convolution method, test failed (22/2)
  
- DFT code (tom)
  - [ ] finish on 20/2, test passed
  
- find delay elements (tom)
  - [ ] finish on 21/2 (DFT only)
  - [ ] may work on normal case later, decided not use convolution method on 22/2
  - [ ] fix small issue for using DFT method on 22/2
