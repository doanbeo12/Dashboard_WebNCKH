#ifndef CONFIG_H
#define CONFIG_H

// ==============================
// CẢM BIẾN MƯA
// ==============================

#define RAIN_DO 35


// ==============================
// LCD I2C
// ==============================

#define LCD_SDA 21
#define LCD_SCL 22

#define LCD_ADDRESS 0x27


// ==============================
// LED CẢNH BÁO
// ==============================

#define LED_GREEN 25
#define LED_YELLOW 26
#define LED_RED 32


// ==============================
// THÔNG SỐ ĐO MỰC NƯỚC
// ==============================

#define SENSOR_HEIGHT 30.0


// ==============================
// NGƯỠNG CẢNH BÁO
// ==============================

#define LEVEL_NORMAL 3.0

#define LEVEL_WARNING 7.0

#define LEVEL_DANGER 15.0

#endif