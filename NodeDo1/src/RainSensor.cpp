#include "RainSensor.h"

#include <Arduino.h>

#include "Config.h"


void RainSensor::begin()
{
    pinMode(
        RAIN_DO,
        INPUT
    );
}


bool RainSensor::isRaining()
{
    return digitalRead(
        RAIN_DO
    ) == LOW;
}