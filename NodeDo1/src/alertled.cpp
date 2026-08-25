#include "AlertLED.h"

#include <Arduino.h>

#include "Config.h"


void AlertLED::begin()
{
    pinMode(
        LED_GREEN,
        OUTPUT
    );

    pinMode(
        LED_YELLOW,
        OUTPUT
    );

    pinMode(
        LED_RED,
        OUTPUT
    );


    off();
}


void AlertLED::off()
{
    digitalWrite(
        LED_GREEN,
        LOW
    );

    digitalWrite(
        LED_YELLOW,
        LOW
    );

    digitalWrite(
        LED_RED,
        LOW
    );
}


void AlertLED::normal()
{
    off();

    digitalWrite(
        LED_GREEN,
        HIGH
    );
}


void AlertLED::warning()
{
    off();

    digitalWrite(
        LED_YELLOW,
        HIGH
    );
}


void AlertLED::danger()
{
    off();

    digitalWrite(
        LED_RED,
        HIGH
    );
}