#include "PWMHandler.h"

/* --------------- CONSTRUCTOR --------------- */
PWMHandler::PWMHandler(uint8_t pin, unsigned long periodDuration_us) : pin_(pin)
{
    pinMode(pin_, OUTPUT);
    (periodDuration_us) ? periodDuration_ = periodDuration_us : Serial.println("ERROR frequency");
    frequency_ = 1e6 / periodDuration_;
}

/* --------------- SETTER METHODES --------------- */
void PWMHandler::setDutyCycle(float dutyCycle)
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
    this->breakDuration_ = periodDuration_ * (dutyCycle_+OFFSET) / 100;
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
    Serial.println(this->periodDuration_);
    Serial.print("frequency_ : ");
    Serial.println(this->frequency_);
    Serial.print("dutyCycle_: ");
    Serial.println(this->dutyCycle_);
    Serial.print("impulseDuration_: ");
    Serial.println(this->impulseDuration_);
    Serial.print("breakDuration_: ");
    Serial.println(this->breakDuration_);
}