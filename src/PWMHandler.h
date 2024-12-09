// EEPROMHandler.h
#ifndef PWMHANDLER_H
#define PWMHANDLER_H

#include <Arduino.h> // falls du Arduino-Funktionen benutzt
#define OFFSET 0.12
class PWMHandler
{
public:
    PWMHandler(uint8_t Pin, unsigned long periodDuration_us);

    // setter
    void setDutyCycle(float dutyCycle);

    // print alll durations
    void printDuration();

    // update the pwm modulation
    void updateModulation();

    // get Duty Cycle
    float getDutyCycle() { return this->dutyCycle_; }

private:
    int pin_;
    float dutyCycle_;
    unsigned long periodDuration_ = 0;

    // rechnen
    unsigned long frequency_;
    unsigned long impulseDuration_ = 0;
    unsigned long breakDuration_ = 0;

    // for the timer
    unsigned long currentTime_;
    unsigned long pastTime_;
    unsigned long oldTime_;

    bool state_ = false;
    bool stateHL_ = false;
    void setState(bool state);
    void calcDutyCycle();
};

#endif // PWMHANDLER_H
