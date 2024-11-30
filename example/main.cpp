#include <Arduino.h>
#include <PWMHandler.h>

#define PIN 32
#define FREQUENZY 800

PWMHandler Pin(PIN, FREQUENZY);

uint8_t pwmValue = 20;

void updatePWMFromSerial()
{
  if (Serial.available() > 0)
  {
    int newPwmValue = Serial.parseInt();
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
