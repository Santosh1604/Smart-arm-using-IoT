#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "SmartArm"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Replace with your WiFi credentials
char ssid[] = "Batman";
char pass[] = "87654321";

// Blynk Auth Token
char auth[] = BLYNK_AUTH_TOKEN;

// Create servo objects
Servo servo1;
Servo servo2;
Servo servo3;

// Attach servos to GPIO pins
#define SERVO1_PIN D1
#define SERVO2_PIN D2
#define SERVO3_PIN D3

void setup() {
  // Attach servos
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);

  // Begin Blynk connection
  Blynk.begin(auth, ssid, pass);
}

// Slider 1 controls Servo 1 (V1)
BLYNK_WRITE(V1) {
  int angle = param.asInt();
  servo1.write(angle);
}

// Slider 2 controls Servo 2 (V2)
BLYNK_WRITE(V2) {
  int angle = param.asInt();
  servo2.write(angle);
}

// Slider 3 controls Servo 3 (V3)
BLYNK_WRITE(V3) {
  int angle = param.asInt();
  servo3.write(angle);
}

void loop() {
  Blynk.run();
}
