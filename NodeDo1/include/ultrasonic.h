#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {

private:
    uint8_t trig;
    uint8_t echo;

public:

    Ultrasonic(uint8_t trigPin, uint8_t echoPin)
        : trig(trigPin), echo(echoPin) {}

    void begin() {

        pinMode(trig, OUTPUT);
        pinMode(echo, INPUT);

        digitalWrite(trig, LOW);
    }

    float read() {

        digitalWrite(trig, LOW);
        delayMicroseconds(2);

        digitalWrite(trig, HIGH);
        delayMicroseconds(10);

        digitalWrite(trig, LOW);

        long duration =
            pulseIn(echo, HIGH, 30000);

        if (duration == 0)
            return -1;

        return duration * 0.0343 / 2.0;
    }
};

#endif