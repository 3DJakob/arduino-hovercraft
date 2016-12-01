void servoSteering() {
  senseLValue = analogRead(senseLPin);
  senseFValue = map(analogRead(senseFPin), minSensorValue, maxSensorValue, maxSensorValue, minSensorValue);
  senseRValue = analogRead(senseRPin);

  float top = senseFValue*1+senseRValue*2;
  float bottom = senseLValue+senseFValue+senseRValue;

  float turnValue = lastTurnValue + ((((top / bottom)*1000) - lastTurnValue)/filterValue);
  lastTurnValue = turnValue;

  int turnAngle = map(turnValue, 600, 1400, 180, 0);


  for (int turnAngleIterator = turnAngle; turnAngleIterator > 0; turnAngleIterator = turnAngleIterator - 5) {
    Serial.print("#");
  }
  Serial.print(turnAngle);
  Serial.println();

  if (turnAngle > 180) {
    steeringServo.write(180);
  } else if (turnAngle < 0) {
    steeringServo.write(0);
  } else {
    steeringServo.write(turnAngle);
  }
}
