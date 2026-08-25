#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic
{
private:

    uint8_t trigPin;
    uint8_t echoPin;

public:

    Ultrasonic(uint8_t trig, uint8_t echo)
    {
        trigPin = trig;
        echoPin = echo;
    }

    void begin()
    {
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);

        digitalWrite(trigPin, LOW);
    }

    float readDistance()
    {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);

        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);

        digitalWrite(trigPin, LOW);

        long duration = pulseIn(
            echoPin,
            HIGH,
            30000
        );

        if (duration == 0)
        {
            return -1;
        }

        float distance =
            duration * 0.0343 / 2.0;

        return distance;
    }
};

#endif