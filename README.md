# PWMHandler Library for ESP32

## Overview
The `PWMHandler` class for ESP32 allows you to generate a PWM signal on a specified pin with adjustable frequency and duty cycle. This class provides methods to set the PWM signal's duty cycle, print the modulation details, and continuously update the PWM signal.

## Public Methods

### 1. **Constructor**: `PWMHandler(uint8_t Pin, unsigned long periodDuration_us)`
   - **Description**: Initializes a new `PWMHandler` object that will control the PWM signal on the specified pin.
   - **Parameters**:
     - `Pin`: The GPIO pin number where the PWM signal will be output.
     - `periodDuration_us`: The period duration of the PWM signal in microseconds, which determines the frequency (e.g., 20000 for 50Hz).

### 2. **`void setDutyCycle(uint8_t dutyCycle)`**
   - **Description**: Sets the duty cycle of the PWM signal. The duty cycle defines the percentage of time the signal stays "high" during each period.
   - **Parameters**:
     - `dutyCycle`: A value between 0 and 255. A value of 255 corresponds to a 100% duty cycle, and 0 corresponds to a 0% duty cycle. For example, a value of 51 corresponds to approximately 20%.
  
### 3. **`void printDuration()`**
   - **Description**: Prints the calculated period duration, impulse duration (high time), and break duration (low time) of the PWM signal to the Serial Monitor.
   - **Usage**: Use this method to check the calculated values based on the period and duty cycle.

### 4. **`void updateModulation()`**
   - **Description**: Continuously updates the PWM signal. This method switches the PWM signal between "high" and "low" states based on the calculated duty cycle and period.
   - **Usage**: This method should be called in the `loop()` function to keep the PWM signal running.

## Example Usage

```cpp
#include <Arduino.h>
#include <PWMHandler.h>

#define PIN 33  // The pin where the PWM signal will be generated
#define PERIOD_DURATION 20000  // 20 ms period for 50 Hz PWM frequency

PWMHandler pwm(PIN, PERIOD_DURATION);

void setup() {
  Serial.begin(115200);
  Serial.println("PWM Signal Example");

  pwm.setDutyCycle(51);  // Set duty cycle to approximately 20%
  pwm.printDuration();    // Print period and duty cycle details to Serial Monitor
}

void loop() {
  pwm.updateModulation();  // Continuously update the PWM signal
}
```
### Code Explanation:
1. **Initialization**:
   - `PWMHandler pwm(PIN, PERIOD_DURATION);` initializes the PWM handler for pin 33 with a 20 ms period (50 Hz frequency).
   
2. **Set Duty Cycle**:
   - `pwm.setDutyCycle(51);` sets the PWM duty cycle to approximately 20% (since the range is 0-255, where 255 is 100%).

3. **Print Duration**:
   - `pwm.printDuration();` prints the calculated PWM signal duration to the Serial Monitor. It shows the full period duration, impulse duration (high time), and break duration (low time).

4. **Continuous Update**:
   - `pwm.updateModulation();` is called inside the `loop()` function to continuously switch the PWM signal between its high and low states based on the current time and duty cycle.

## Customization
- **Pin Selection**:  
   You can change the pin number (`PIN`) to any available GPIO pin on the ESP32. Just ensure the pin you choose supports PWM output.

- **Frequency**:  
   You can adjust the `PERIOD_DURATION` to modify the frequency of the PWM signal. For example:
   - A `PERIOD_DURATION` of `10000` will result in a 100 Hz PWM frequency (10 ms period).
   - A `PERIOD_DURATION` of `5000` will produce a 200 Hz PWM frequency (5 ms period).

- **Duty Cycle**:  
   You can change the `setDutyCycle()` parameter to adjust the PWM duty cycle. The value is scaled from 0 to 255, where:
   - `0` means the PWM signal is always LOW (0% duty cycle).
   - `255` means the PWM signal is always HIGH (100% duty cycle).
   - For intermediate values, the signal will stay HIGH for a percentage of each cycle, based on the duty cycle value.

   For example, setting the duty cycle to `51` (around 20%) will result in the signal being HIGH for 20% of the period and LOW for the remaining 80%.

## Troubleshooting
- **PWM Signal Not Outputting**:  
   If the PWM signal isn't being output correctly, ensure that the selected pin supports PWM functionality. Also, check your `PERIOD_DURATION` to ensure the frequency is within the range your application needs.
  
- **Incorrect PWM Behavior**:  
   If the signal seems to be stuck at a high or low state, verify that the duty cycle is set correctly and ensure that `updateModulation()` is being called in the `loop()` function.

## License

This code is licensed under the MIT License. See the LICENSE file for more details.

## Including in your project:
```bash
lib_deps = https://github.com/deutzfahrer-luki/PWMHandler.git
```
