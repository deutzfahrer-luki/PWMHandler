// EEPROMHandler.h
#ifndef PWMHANDLER_H
#define PWMHANDLER_H

#include <Arduino.h> // falls du Arduino-Funktionen benutzt

#define SDBS_CALC true

class PWMHandler
{
public:
    PWMHandler(uint8_t Pin);
    PWMHandler(uint8_t Pin, long frequency);

    // setter
    void setDutyCycle(uint8_t dutyCycle);

    void setState(bool state);
    void updateModulation();

private:
    int pin_;
    unsigned long frequency_;
    uint8_t dutyCycle_;

    // rechnen
    unsigned long periodDuration_ = 0;
    unsigned long impulseDuration_ = 0;
    unsigned long breakDuration_ = 0;

    // for the timer
    unsigned long currentTime_;
    unsigned long pastTime_;
    unsigned long oldTime_;

    bool state_ = false;
    bool stateHL_ = false;

    void calcDutyCycle();

public:
    void printDuration();
};

#endif // PWMHANDLER_H
