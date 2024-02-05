#include <Arduino.h>
#include <drivers/Watchdog.h>

void setup()
{
    Serial.begin(9600);

    // Setup the watchdog to 10s.
    Serial.println("Setting watchdog to 10s.");
    mbed::Watchdog::get_instance().start(10000);

    // Sleep 5s and kick, for three times.
    for (int i = 0; i < 3; i++)
    {
        Serial.println("Sleeping for 5s.");
        delay(5000);
        mbed::Watchdog::get_instance().kick();
    }

    // Sleep 11s causing Opta to reboot.
    Serial.println("Sleeping for 11s. Opta will reboot.");
    delay(11000);
}

void loop()
{
}
