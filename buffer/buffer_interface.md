# Buffer Interface (draft)

The buffer empties itself across a USB serial interface to the Pi, 
(or failing that, USART). It transmits the most significant 8 bits
of each measurement in the following sequence, and begins each
transmission with the byte `0xff`. This byte does not appear anywhere
else in this sequence - it is substituted for `0xfe` when it would
otherwise appear.

```
[0xff] [Mic 1 t=0] [Mic 1 t=1] [Mic 1 t=2] ... [Mic 2 t=0] [Mic 2 t=1] ... [Mic 3 t=0] ... [Mic 4 t=0] ...
```

The data is transmitted with no gaps, and the `...`s are filled in appropriately.
