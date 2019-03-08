## Amplfiier?                                                                   
An instrumentation amplifier was not chosen to act as the preamp as it is primar
ily a differential type amplfiier. Since the signal from the microphone capsule
was with reference to ground to begin with, no gains were made with the added co
mplexity of an instrumentation amplifier. Filters were wanted to be implemented
also before or in the preamp to eliminate them while they are still small signal
s, and the architecture for the instruemntation amplifier would make this a hard
er task to design such filters.
                                                                                
## Filters?                                                                     
It makes sense to adapt the preamp to only amplify the signal frequencies in the first place, as opposed to amplifying everything and then filtering afterwards. The preamp design filter, however, consists of only a second order high-pass and first order low-pass. The rolloff for the low-pass is arguably too slow and an additional filter would have increased this to a second or third order rolloff,
 leading to less higher frequencies being sampled, which had been proved to be p
roblematic.

