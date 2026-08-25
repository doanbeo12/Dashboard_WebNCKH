#ifndef ALERT_LED_H
#define ALERT_LED_H


class AlertLED
{
public:

    void begin();

    void normal();

    void warning();

    void danger();

    void off();
};

#endif