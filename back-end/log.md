# Back-end Log
This is a log of everything that is being worked on in relation this unit.
Entries are not deleted and new entries are added at the top of this file.
Try to keep this up to date; it will make writing individual and group reports
easier.

2019/02/18 Algorithm for cross correlation (f)
------------------------------------------

We could use either an FFT-based or simple algorithm for xcorrelation, the FFT one may
be faster, and certainly would be cooler, but for now it probably makes sense to make everything
work with a very simple algorithm, and then once it is working, we can improve it with FFT. We 
only need the centre of the xcorrelation, as we are looking for delays of around 1ms in a
larger signal, so the efficiency increase may not be as dramatic as it would be if we were
finding the complete xcorrelation.

2019/02/19 Multithreading and reading from serial (f)
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

2019/02/21 add code for finding delay (tom)
-------------------------------------------------

I add the code to find delay elements of the 2 sets of data using the DFT method for xcorrelation.
In addition, number of element+1 shows delay, if -ve means 1st set of data lag element+1 of 2nd data,
if +ve means 1st set of data lead element+1 of 2nd data

2019/02/21 modify code for DFT (tom)
-------------------------------------------------

I found that rounding the result of DFT may affect the result of x_corr_dft. Therefore, 
I use setprecision for cout rather than rounding

2019/02/21 Added trigonometric maths to find angles (f)
---------------------------------------------------

I added some code to sound.[ch] that models sounds and calculates their speed, and error.
I went through the details of how it all works w/ Hugo


2019/02/22 modify code for finding delay, problem for x_corr (using convolution) (tom)
-------------------------------------------------

I found that there is a small mistake for finding delay, in which the delay is equal to 
the number of element in the array, not element+1. Also, since the size of the vector for 
x_corr_dft is 2 times the original data set (zero added and it is necessary to compute
x_corr_dft), the bottom half of the result for x_corr_dft is same as the top half, but inverse in sign.
However, the problem is the value for the top half and bottom half may have +- 1 difference
(because of rounding off), which may gives a wrong result. For example, let data size = 300, then
v[30] = 352,v[569] = -353 ,and the delay will equal to 569, which is wrong. Therefore, I
in order to fix this, I just find the maximum absolute value for the top half of the vector.
In terms of x_corr, I found that the method that using convolution always gives to largest value
when 2 vector align together. For example, let data set 1 = 34,99,56,11,52 ; 
data set 2 = 85,66,34,99,56.
When executing x_coor: (zeros added in order to shift the vector)
set 1:
0,0,0,0,0,34,99,56,11,52,0,0,0,0,0

set 2:
85,66,34,99,56,0,0,0,0,0,0,0,0,0,0

When they align together:
set 1:
0,0,0,0,0,34,99,56,11,52,0,0,0,0,0

set 2:
0,0,0,0,0,85,66,34,99,56,0,0,0,0,0

x_corr will give the largest value.
As a consequence, I decided to use the dft method to do cross-correlation rather than 
using convolution. And the test for the dft method is passed. In which having 250 elements
with 50 delay still obtain the correct value for delay.

2019/02/24 Added code for detecting peaks (f)
-----------------------------------------

The peak detection algorithm was finished, tested and added. The algorithm works by finding the maximum
value in a certain width, meaning that all maxima are found, and multiple maxima close to one another
due to noise are excluded.

From there, the speed of sound and error for each possible combination of peaks can be calculated, and
the most plausible sounds selected.

2019/02/27 Finished code for file management (f)
--------------------------------------------

I have added code that manages the input and output files for the code, creates the appropriate fifos, and
trims the sound output file to size when it gets too big. This isn't altogether too interesting, but it's
necessary so that we don't end up with a file containing billions of sounds.

