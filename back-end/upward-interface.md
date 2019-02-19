The upward interface of the raspberry pi backend (draft)
========================================================

The interface will be a file in the temp directory - `/tmp/chinchilla-backend`

The file will be a series of entries, each corresponding to sounds that the algorithm
has detected. 

This will be a normal file and not a FIFO, since multiple processes will need to read it.
The file should therefore be opened, read and closed as fast as possible by processes that
use it, and it should be opened in a read-only mode. Keeping the file open for long periods
may cause issues, and new events won't appear in it.

Each new event is appended to the end of the file, and periodically, when the file becomes
large, events from the top may be deleted, leaving at least the most recent event.

Each line represents an event, and is individually formatted as JSON, in the following way
(note that the single line has been expanded here to allow for comments).
```JS
{
    "id": 1,            // An incrementing id for the events in the file, each event has
                        //  an id of one higher than the previous one.
    "angle": 1.234,     // The angle of the detected sound in radians.
    "amplitude": 1.234, // The amplitude of the detected sound,
                        //  0 corresponds to a nonexistent sound, and 1 corresponds to the
                        //  loudest expected sound.
    "freq": {???}       // To be determined later.
    "time": 1234        // The time of the event (in miliseconds since unix epoch)
}
```
