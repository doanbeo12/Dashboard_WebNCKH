#include "alert.h"

// ========================================
// KHỞI TẠO CẢM BIẾN MƯA + LED
// ========================================

void initAlert()
{
    // Cảm biến mưa
    pinMode(RAIN_DO_PIN, INPUT);

    // LED
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);

    // Tắt tất cả LED lúc khởi động
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);

    Serial.println("Rain sensor + Warning LED READY");
}


// ========================================
// ĐỌC CẢM BIẾN MƯA
// ========================================

bool isRaining()
{
    int rainState = digitalRead(RAIN_DO_PIN);

    // Phần lớn module mưa AO/DO:
    // LOW  = có nước / có mưa
    // HIGH = không mưa

    if (rainState == LOW)
    {
        return true;
    }

    return false;
}


// ========================================
// ĐIỀU KHIỂN LED THEO MỰC NƯỚC
// ========================================

void updateWarningLED(float waterLevel)
{
    // Tắt toàn bộ trước
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);


    // ==============================
    // DƯỚI 3 CM
    // BÌNH THƯỜNG
    // ==============================

    if (waterLevel < 3)
    {
        digitalWrite(LED_GREEN, HIGH);
    }


    // ==============================
    // 3 → dưới 7 CM
    // MỨC 1
    // ==============================

    else if (waterLevel < 7)
    {
        digitalWrite(LED_YELLOW, HIGH);
    }


    // ==============================
    // 7 → dưới 15 CM
    // MỨC 2
    // ==============================

    else if (waterLevel < 15)
    {
        digitalWrite(LED_YELLOW, HIGH);
    }


    // ==============================
    // TỪ 15 CM
    // MỨC 3
    // ==============================

    else
    {
        digitalWrite(LED_RED, HIGH);
    }
}