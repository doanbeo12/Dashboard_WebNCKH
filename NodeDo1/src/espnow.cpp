#include "espnow.h"

#include <WiFi.h>
#include <esp_now.h>
#include <string.h>


// ========================================
// NODE 1
// ========================================

static float node1Distance = 0.0f;
static unsigned long node1LastReceived = 0;
static bool node1Received = false;


// ========================================
// NODE 2
// ========================================

static float node2Distance = 0.0f;
static unsigned long node2LastReceived = 0;
static bool node2Received = false;


// Quá 6 giây không nhận dữ liệu → OFFLINE
static const unsigned long NODE_TIMEOUT = 6000;


// ========================================
// CALLBACK NHẬN ESP-NOW
// ========================================

void onDataReceive(
    const uint8_t *mac,
    const uint8_t *incomingData,
    int len
)
{
    if (len != sizeof(SensorData))
    {
        Serial.print("Sai kich thuoc goi tin: ");
        Serial.println(len);

        return;
    }


    SensorData receivedData;

    memcpy(
        &receivedData,
        incomingData,
        sizeof(receivedData)
    );


    // ====================================
    // NODE 1
    // ====================================

    if (receivedData.nodeID == 1)
    {
        node1Distance =
            receivedData.distance;

        node1LastReceived =
            millis();

        node1Received =
            true;


        Serial.println();
        Serial.println("------------------------------");

        Serial.println("NHAN DU LIEU NODE 1");

        Serial.print("Khoang cach: ");
        Serial.print(node1Distance, 1);
        Serial.println(" cm");
    }


    // ====================================
    // NODE 2
    // ====================================

    else if (receivedData.nodeID == 2)
    {
        node2Distance =
            receivedData.distance;

        node2LastReceived =
            millis();

        node2Received =
            true;


        Serial.println();
        Serial.println("------------------------------");

        Serial.println("NHAN DU LIEU NODE 2");

        Serial.print("Khoang cach: ");
        Serial.print(node2Distance, 1);
        Serial.println(" cm");
    }
}


// ========================================
// KHỞI TẠO ESP-NOW
// ========================================

bool initESPNow()
{
    WiFi.mode(WIFI_STA);

    delay(100);

    Serial.println();
    Serial.println("==============================");
    Serial.println("       CENTRAL ESP-NOW");
    Serial.println("==============================");

    Serial.print("Central MAC: ");
    Serial.println(WiFi.macAddress());


    if (esp_now_init() != ESP_OK)
    {
        Serial.println("ESP-NOW INIT FAILED");

        return false;
    }


    esp_now_register_recv_cb(
        onDataReceive
    );


    Serial.println(
        "ESP-NOW READY - WAITING DATA..."
    );


    return true;
}


// ========================================
// LẤY KHOẢNG CÁCH NODE 1
// ========================================

float getNode1Distance()
{
    return node1Distance;
}


// ========================================
// LẤY KHOẢNG CÁCH NODE 2
// ========================================

float getNode2Distance()
{
    return node2Distance;
}


// ========================================
// NODE 1 ONLINE
// ========================================

bool isNode1Online()
{
    if (!node1Received)
    {
        return false;
    }

    return (
        millis() - node1LastReceived
        <= NODE_TIMEOUT
    );
}


// ========================================
// NODE 2 ONLINE
// ========================================

bool isNode2Online()
{
    if (!node2Received)
    {
        return false;
    }

    return (
        millis() - node2LastReceived
        <= NODE_TIMEOUT
    );
}