// Example.cpp

#include "PWMHandler.h"

PWMHandler::PWMHandler(uint8_t pin) : pin_(pin), frequency_(800L)
{
    pinMode(pin_, OUTPUT);
}

PWMHandler::PWMHandler(uint8_t pin, long frequency) : PWMHandler(pin)
{
    (frequency) ? frequency_ = frequency : Serial.println("ERROR frequency");
    periodDuration_ = (1.0 / frequency_) * 1e6;
}

void PWMHandler::setDutyCycle(uint8_t dutyCycle)
{
    if (dutyCycle > 0 && dutyCycle <= 100)
    {
        dutyCycle_ = dutyCycle;
        this->calcDutyCycle();
    }
    else
        Serial.println("Error dutyCyle setter");
}

void PWMHandler::calcDutyCycle()
{
    this->impulseDuration_ = periodDuration_ * dutyCycle_ / 100;
    this->breakDuration_ = periodDuration_ - impulseDuration_;
    // this->printDuration();
}

/* --------------- PRINTS METHODES --------------- */
void PWMHandler::printDuration()
{
    Serial.print("periodDuration_: ");
    Serial.println(periodDuration_);
    Serial.print("dutyCycle_: ");
    Serial.println(dutyCycle_);
    Serial.print("impulseDuration_: ");
    Serial.println(this->impulseDuration_);
    Serial.print("breakDuration_: ");
    Serial.println(this->breakDuration_);
}