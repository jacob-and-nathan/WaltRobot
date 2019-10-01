#include "musical_notes.h"
#include <Servo.h>

Servo servo1;
Servo servo2;// create servo object to control a servo
Servo servo3;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int buzzer = 8;

// defines pins numbers
const int trigPin = 12;
const int echoPin = 11;
// defines variables
long duration;
int distance;

void distanceCheck () {
    // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return (distance);
}

void scared () {
  servo3.write(120);
    delay (20);
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    if (distance < 20) {
      squeak();
      for (pos = 0; pos < 100; pos ++) {
        servo1.write(pos);
        servo2.write(pos);
        servo3.write(180);
      }
      } else {
        uhoh();
        servo1.write(100);
        delay (500);
        servo1.write(0);
        servo3.write(180);
        delay (500);
      }
      }


      void wave () {
        waka();
        delay (500);
        servo1.write(150);
        delay(750);
        servo1.write(100);
        delay(20);
      }
    


void setup() {
  servo1.attach(9);  // attaches the servo on pin 9 to the servo1 object
  servo2.attach(10);
  servo3.attach(7);
//tone(buzzer, 100, 450);
//laugh2();
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  servo3.write(180);
  delay (1000);
  servo2.write (150);
  servo1.write(100);
}

void loop() {
  delay(20);
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 10 ) {
    scared ();
  } else if (distance < 30) {
    delay (500);
    distanceCheck();
    if (distance < 30) {
      
    } else {
    wave ();
    }
  }
  }



