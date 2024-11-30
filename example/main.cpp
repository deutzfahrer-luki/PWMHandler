#include <Arduino.h>
#include <PWMHandler.h>

#define PIN 32
#define FREQUENZY 800

PWMHandler Pin(PIN, FREQUENZY);

uint8_t pwmValue = 25;

void setup()
{
  Serial.begin(115200);
  Serial.println("Hallo Welt");
}

void loop()
{
  Pin.setDutyCycle(pwmValue);
  Pin.printDuration();

  delay(100000);
}
