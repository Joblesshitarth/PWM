#include <Arduino.h>

const int ledPin = 4; // Safe non-JTAG pin
const int freq = 5000;
const int resolution = 8;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Modern ESP32-S3 LEDC API initialization
  ledcAttach(ledPin, freq, resolution);
  Serial.println("PWM Fade Initialized on GPIO 4");
}

void loop() {
  // Fade up
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(ledPin, dutyCycle);
    delay(15);
  }
  
  // Fade down
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledPin, dutyCycle);
    delay(15);
  }
} 