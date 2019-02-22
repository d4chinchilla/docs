Rough Estimates of Data Rates as Guide for Bottlenecks and Feasibility
----------------------------------------------------------------------

The microphones are 20cm apart, meaning sound at 343m/s takes 0.583ms to pass
between them. This corresponds to a frequency of 1.71kHz, and therefore, we need
to sample the sound at a far higher rate to effectively measure time of flight.

It is also noteworthy that sound below this frequency would be more trivial to
find the direction of, but since the speed of sound is known, it is entirely
possible to find the direction of sound above this frequency too.

60kHz would be an appropriate rate to sample the sound at. Our ADCs can
sample at 100kHz, so this rate should be suitable for them, and with a
clock speed of around 80MHz, the ucontroller should be able to pump this
far slower data out of the ADCs with no issues.

If the data is buffered into 1024 byte long packets. Each byte would represent
a time 16.666us apart, and so the entire packet would represent 17.07ms. There
would be four data streams in this packet, giving it a total size to send from
the ucontroller to the pi of 4097B, which will be easy to do 10 times a second,
giving an average rate of 41kB/s. (4097B is also very easily going to fit in the
memory of the ucontroller)

If we do a naive cross convolution on these packets, we will need to do around
574k multiplications to obtain a result, but since we are only interested in the
region from +0.6ms to -0.6ms - (the maximum time difference we can see is 0.583ms
- anything beyond that cannot represent sound as it would be travelling below
343 m/s), the result of our cross correlation need only be around 72 samples long,
meaning we only need to perform around 1024*72~=74k multiplications for one naive
cross correlation. Per packet we must do this three times, and if we again process
packets at 10Hz, we will need to process data at a rate of around 2220kFLOPS, which
should easily be possible on the raspberry pi.

Overall, there seem to be no particularly bad bottlenecks in this design. The physical
limitations of the size of the system, and of the speed of the ADCs look to be the
biggest issues. We have plenty of room to push the system to higher performance than
10 samples per second, but for now it is a reasonable target.

Splitting the data into discrete samples also solves the issue of loading it onto the
raspberry pi, which would otherwise cause quite a bad bottleneck.
