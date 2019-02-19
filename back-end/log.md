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
