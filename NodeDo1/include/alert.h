#ifndef ALERT_H
#define ALERT_H

#include <Arduino.h>

// ==============================
// CẢM BIẾN MƯA
// ==============================

#define RAIN_DO_PIN 35

// ==============================
// LED CẢNH BÁO
// ==============================

#define LED_GREEN 25
#define LED_YELLOW 26
#define LED_RED 32

// ==============================
// KHỞI TẠO
// ==============================

void initAlert();

// ==============================
// ĐỌC CẢM BIẾN MƯA
// ==============================

bool isRaining();

// ==============================
// ĐIỀU KHIỂN LED
// ==============================

void updateWarningLED(float waterLevel);

#endif