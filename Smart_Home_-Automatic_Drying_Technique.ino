#include <Servo.h>

#define RAIN_SENSOR A0  // Raindrop sensor connected to A0
#define THRESHOLD 500   // Adjust this value based on your environment

int servoPin = 9;       // Servo motor connected to pin 9
Servo dryingStand;

void setup() {
  pinMode(RAIN_SENSOR, INPUT);
  Serial.begin(9600);
  dryingStand.attach(servoPin);
  dryingStand.write(0);  // Clothes start outside
}

void loop() {
  int rainValue = analogRead(RAIN_SENSOR); // Read rain sensor
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  if (rainValue < THRESHOLD) {  // If rain detected
    dryingStand.write(90);  // Move clothes inside
    Serial.println("Raining! Clothes moved inside.");
  } else { 
    dryingStand.write(0);  // Move clothes outside
    Serial.println("No Rain. Clothes outside.");
  }

  delay(2000);  // Check every 2 seconds
}
