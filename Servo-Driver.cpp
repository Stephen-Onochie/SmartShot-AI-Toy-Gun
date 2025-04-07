#include <ESP32Servo.h>

Servo turnServo;
const int ServoPin = D7;

void setup() {
  Serial.begin(115200);          // Start Serial Communication
  turnServo.attach(ServoPin);    // Attach servo to pin D7
  turnServo.write(90);           // Start centered
  Serial.println("Ready to receive servo angles (0-180)...");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');  // Read until newline
    input.trim();                                 // Remove whitespace
    int angle = input.toInt();                    // Convert string to int

    if (angle >= 0 && angle <= 180) {
      turnServo.write(angle);
      Serial.print("Moved to: ");
      Serial.println(angle);
    } else {
      Serial.println("Invalid angle. Enter value from 0 to 180.");
    }
  }
}
