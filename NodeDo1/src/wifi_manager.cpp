#include "wifi_manager.h"

#include <WiFi.h>

// ================================
// WIFI CỦA BẠN
// ================================

const char* WIFI_SSID =
    "Doan";

const char* WIFI_PASSWORD =
    "23456789";


// ================================
// KHỞI TẠO WIFI
// ================================

bool initWiFi()
{
    WiFi.mode(WIFI_STA);

    Serial.println();
    Serial.println("        WIFI CENTRAL");
    Serial.print("Dang ket noi WiFi");

    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );

    unsigned long startTime =
        millis();

    while (
        WiFi.status() != WL_CONNECTED
    )
    {
        delay(500);

        Serial.print(".");

        if (
            millis() - startTime > 20000
        )
        {
            Serial.println();
            Serial.println(
                "WIFI ket noi that bai"
            );

            return false;
        }
    }


    Serial.println();
    Serial.println("WIFI da ket noi");

    Serial.print("IP: ");
    Serial.println(
        WiFi.localIP()
    );

    Serial.print("Channel: ");
    Serial.println(
        WiFi.channel()
    );

    return true;
}


// ================================
// LẤY CHANNEL WIFI
// ================================

int getWiFiChannel()
{
    return WiFi.channel();
}