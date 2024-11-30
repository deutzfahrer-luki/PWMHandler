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

/* --------------- SETTER METHODES --------------- */
void PWMHandler::setDutyCycle(uint8_t dutyCycle)
{
    if (dutyCycle > 0 && dutyCycle < 100)
    {
        dutyCycle_ = dutyCycle;
        this->calcDutyCycle();
    }
    else
        Serial.println("Error dutyCyle setter");
}

/* --------------- CALC METHODES --------------- */
void PWMHandler::calcDutyCycle()
{
    this->breakDuration_ = periodDuration_ * dutyCycle_ / 100;
    this->impulseDuration_ = periodDuration_ - breakDuration_;
    // this->printDuration();
}

/* --------------- HARDWARE METHODES --------------- */
void PWMHandler::setState(bool state)
{
    digitalWrite(this->pin_, state);
}

void PWMHandler::updateModulation()
{
    currentTime_ = micros();
    pastTime_ = currentTime_ - oldTime_;

    if (!stateHL_ && pastTime_ >= impulseDuration_)
    {
        stateHL_ = HIGH;
        setState(stateHL_);
        oldTime_ = currentTime_;
    }
    else if (stateHL_ && pastTime_ >= breakDuration_)
    {
        stateHL_ = LOW;
        setState(stateHL_);
        oldTime_ = currentTime_;
    }
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