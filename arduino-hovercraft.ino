#include<Servo.h>

Servo esc1;
Servo esc2;
Servo servo;

int startPin = 12;
int servoPin = 3;
int motor1Pin = 5;
int motor2Pin = 6;

int senseLPin = 0;
int senseFPin = 1;
int senseRPin = 2;

int greenPin = 9;
int yellowPin = 10;
int redPin = 11;


int motor1Value = 1100;
int motor2Value = 1100;

int senseLValue;
int senseFValue;
int senseRValue;

int maxSensorValue = 500;
int minSensorValue = 50;

void setup() {
  pinMode(servoPin, OUTPUT);
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
  servo.attach(servoPin);


  Serial.begin(9600);
  Serial.println("Starting");
}

void loop() {

  if (digitalRead(startPin)) {

    motorThrottle(2000, 1);
    motorThrottle(1500, 2);

    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    servoSteering();


  } else {
    motor1Value = 1100;
    motor2Value = 1100;

    esc1.writeMicroseconds(1100);
    esc2.writeMicroseconds(1100);
    servo.write(45);

    analogWrite(yellowPin, 0);

    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);

  }

}
