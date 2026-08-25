#include "LCD.h"

#include <Arduino.h>
#include <Wire.h>

#include "Config.h"


LCD::LCD()
    : lcd(
        LCD_ADDRESS,
        16,
        2
    )
{
}


void LCD::begin()
{
    Wire.begin(
        LCD_SDA,
        LCD_SCL
    );


    lcd.init();

    lcd.backlight();

    lcd.clear();
}


void LCD::showWaterLevel(
    float node1,
    float node2
)
{
    lcd.clear();


    lcd.setCursor(
        0,
        0
    );

    lcd.print("N1:");

    lcd.print(
        node1,
        1
    );

    lcd.print("cm");


    lcd.setCursor(
        0,
        1
    );

    lcd.print("N2:");

    lcd.print(
        node2,
        1
    );

    lcd.print("cm");
}