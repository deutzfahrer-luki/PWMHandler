#include <Arduino.h>
#include <PWMHandler.h>

#define PIN 33
#define PERIOD_DURATION 20000

PWMHandler Pin(PIN, PERIOD_DURATION);

float pwmValue = 20;

void updatePWMFromSerial()
{
  if (Serial.available() > 0)
  {
    float newPwmValue = Serial.parseFloat();
    if (newPwmValue >= 0 && newPwmValue <= 100)
    {
      pwmValue = newPwmValue;
      Pin.setDutyCycle(pwmValue);
      Pin.printDuration();
    }
    else
      Serial.println("Ungueltiger Wert! Bitte eine Zahl zwischen 0 und 100 eingeben.");
    while (Serial.available() > 0)
      Serial.read();
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Hallo Welt");
  Pin.setDutyCycle(pwmValue);
  Pin.printDuration();
}

void loop()
{
  updatePWMFromSerial();
  Pin.updateModulation();
}
