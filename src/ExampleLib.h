// EEPROMHandler.h
#ifndef EXAMPLELIB_H
#define EXAMPLELIB_H

#include <Arduino.h> // falls du Arduino-Funktionen benutzt

class ExampleLib
{
public:
    ExampleLib(int value) : exampleValue(value) {}
    void init();
private:
    int exampleValue; // Beispielvariable
};

#endif // EXAMPLELIB_H
