# OPTA-PROG-RESET-BOARD
This programming aims to establish a watchdog time setting in the OPTA Finder, causing the device to restart in cases of malfunction.

# GOAL
° Establish OPTA Watchdog Timer Configuration

# Software Requirements
° Arduino IDE
° Arduino Web Editor

# Finder OPTA and watchdogs
Finder OPTA has Watchdog Timer to reset the hardware in case of malfunctions/crashes.

As explained at the beginning of this tutorial, the Finder Opta can leverage the Watchdog class provided by MbedOS to set a hardware timer that resets the device in case of malfunctions.

```
#include <Arduino.h>
#include <drivers/Watchdog.h>

void setup()
{
    Serial.begin(9600);

    // Setup the watchdog to 10s.
    Serial.println("Setting watchdog to 10s.");
    mbed::Watchdog::get_instance().start(10000);
```

In the code above, the sketch gets the reference to the Watchdog instance of MbedOS and starts it, with a maximum timeout of 10 seconds.

# Refreshing thee Watchdog

Next, the sketch will make the Finder Opta sleep for 5 seconds for three consecutive times, refreshing the watchdog timer at the end of each:

```
    // Sleep 5s and kick, for three times.
    for (int i = 0; i < 3; i++)
    {
        Serial.println("Sleeping for 5s.");
        delay(5000);
        mbed::Watchdog::get_instance().kick();
    }
```
Then the sketch will try to sleep for 11 seconds, triggering the watchdog and causing the Finder Opta to reboot:
```
// Sleep 11s causing Opta to reboot.
    Serial.println("Sleeping for 11s. Opta will reboot.");
    delay(11000);
}
```

At this point we will see the LEDs on the Finder Opta blink as they usually do after a manual reboot, and the sketch will start from the beginning. Note that, during the execution of the program the Finder Opta will print on the serial monitor the operation that it is executing, producing an output that should look like the one below:

```
Setting watchdog to 10s.
Sleeping for 5s.
Sleeping for 5s.
Sleeping for 5s.
Sleeping for 11s. Opta will reboot.
```

# Conclusion

This tutorial shows how to configure a watchdog timer on the Finder Opta to reboot the device in case of malfunctions, and then it verifies its functionality using a sequence of delays.


