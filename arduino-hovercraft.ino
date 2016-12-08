#include<Servo.h>

Servo esc1;
Servo esc2;
Servo steeringServo;
Servo chairServo;

int startPin = 0;
int steeringServoPin = 13;
int chairServoPin = 12;
int motor1Pin = 6;
int motor2Pin = 5;

int senseFPin = A0;
int senseLPin = A2;
int senseRPin = A1;

int greenPin = 9;
int yellowPin = 10;
int redPin = 11;


int motor1Value = 1100;
int motor2Value = 1100;

int senseLValue;
int senseFValue;
int senseRValue;

float lastTurnValue = 1000;

int maxSensorValue = 500;
int minSensorValue = 80;
float filterValue = 10;

void setup() {
  pinMode(steeringServoPin, OUTPUT);
  pinMode(chairServoPin, OUTPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);

  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  pinMode(senseLPin, INPUT);
  pinMode(senseFPin, INPUT);
  pinMode(senseRPin, INPUT);

  esc1.attach(motor1Pin);
  esc2.attach(motor2Pin);
  steeringServo.attach(steeringServoPin);
  chairServo.attach(chairServoPin);


  Serial.begin(9600);
  Serial.println("Starting");

  chairServo.write(90);

  motorThrottle(1000, 1);
  motorThrottle(1000, 2);
  delay(2000);
}

void loop() {

  if (true) {
    motorThrottle(1000, 1);
    motorThrottle(1000, 2);

    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    servoSteering();
    chairServo.write(180);
    if (senseFValue < 100) {
      chairServo.write(0);
    }
  } else {
    motor1Value = 1100;
    motor2Value = 1100;

    esc1.writeMicroseconds(1000);
    esc2.writeMicroseconds(1000);
    steeringServo.write(45);

    analogWrite(yellowPin, 0);

    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);

  }

}
