#include <Arduino.h>
#include "espnow.h"

unsigned long lastPrintTime = 0;

const unsigned long PRINT_INTERVAL = 2000;


void setup()
{
    Serial.begin(115200);

    delay(1000);

    Serial.println();
    Serial.println("==============================");
    Serial.println("        CENTRAL NODE");
    Serial.println("==============================");

    initESPNow();
}


void loop()
{
    if (
        millis() - lastPrintTime
        < PRINT_INTERVAL
    )
    {
        return;
    }

    lastPrintTime = millis();


    Serial.println();
    Serial.println("==============================");
    Serial.println("       TRANG THAI HE THONG");
    Serial.println("==============================");


    // NODE 1
    Serial.print("Node 1: ");

    if (isNode1Online())
    {
        Serial.print("ONLINE | ");

        Serial.print(
            getNode1Distance(),
            1
        );

        Serial.println(" cm");
    }
    else
    {
        Serial.println("OFFLINE");
    }


    // NODE 2
    Serial.print("Node 2: ");

    if (isNode2Online())
    {
        Serial.print("ONLINE | ");

        Serial.print(
            getNode2Distance(),
            1
        );

        Serial.println(" cm");
    }
    else
    {
        Serial.println("OFFLINE");
    }
}