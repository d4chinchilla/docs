# Interface for communication of calibration button status

The interface will be a file in the temp directory - `/tmp/chinchilla-led-ctl`

This will be a FIFO interface passing one of two commands between the led-ctl code and the backend: `calibrate` and `reset`. The `calibrate` command, will be sent when the hardware button is pressed, and will trigger the backend to take a sample of sound to improve sound recognition. The `reset` command will be sent when the hardware button is pressed for more than two seconds, and will trigger a full restart of the raspberry pi with normal services resuming on boot up.
