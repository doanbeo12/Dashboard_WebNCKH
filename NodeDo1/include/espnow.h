#ifndef ESPNOW_H
#define ESPNOW_H

#include <Arduino.h>

// Phải giống Node 1
struct SensorData
{
    int nodeID;
    float distance;
};

bool initESPNow();

float getNode1Distance();
float getNode2Distance();

bool isNode1Online();
bool isNode2Online();

#endif