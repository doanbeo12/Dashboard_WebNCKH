#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal_I2C.h>


class LCD
{
private:

    LiquidCrystal_I2C lcd;


public:

    LCD();

    void begin();

    void showWaterLevel(
        float node1,
        float node2
    );
};

#endif