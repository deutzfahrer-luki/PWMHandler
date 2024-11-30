#include <Arduino.h>
#include <ExampleLib.h>

ExampleLib EX(1);

void setup() {
  Serial.begin(115200);
  EX.init();
}

void loop() {

}
