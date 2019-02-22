# Back-end Log
This is a log of everything that is being worked on in relation this unit.
Entries are not deleted and new entries are added at the top of this file.
Try to keep this up to date; it will make writing individual and group reports
easier.

2019/02/18 Algorithm for cross correlation
------------------------------------------

We could use either an FFT-based or simple algorithm for xcorrelation, the FFT one may
be faster, and certainly would be cooler, but for now it probably makes sense to make everything
work with a very simple algorithm, and then once it is working, we can improve it with FFT. We 
only need the centre of the xcorrelation, as we are looking for delays of around 1ms in a
larger signal, so the efficiency increase may not be as dramatic as it would be if we were
finding the complete xcorrelation.

2019/02/19 Multithreading and reading from serial
-------------------------------------------------

I initialized the repository and added a the management for launching cross correlation jobs,
and also for reading from the serial input. A seperate thread will be launched for each
cross correlation, which should make everything nice and fast on the 4-core 'pi.

2019/02/20 finish code for DFT (tested) and x_corr (tom)
-------------------------------------------------

I finished coding for DFT and xcorrelation, for the xcorrelation part, I have implement to method to
do it, which are the normal case (convolution) and using DFT (discrete fouriere transform).
Also, I found that if the number of samples if not enough, the result of the xcorrelation
would be wrong. And I assume the minimum number of sample to do xcorrelation without error is 30.

2019/02/21 add code for getting delay (tom)
-------------------------------------------------

I add the code to find delay elements of the 2 sets of data using the DFT method for xcorrelation.
In addition, number of element+1 shows delay, if -ve means 1st set of data lag element+1 of 2nd data,
if +ve means 1st set of data lead element+1 of 2nd data

2019/02/21 modify code for DFT (tom)
-------------------------------------------------

I found that rounding the result of DFT may affect the result of x_corr. Therefore, 
I use setprecision for cout rather than rounding
