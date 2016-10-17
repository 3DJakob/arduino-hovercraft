void servoSteering() {
  senseLValue = analogRead(senseLPin);
  senseFValue = map(analogRead(senseFPin), minSensorValue, maxSensorValue, maxSensorValue, minSensorValue);
  senseRValue = analogRead(senseRPin);

  float top = senseFValue*1+senseRValue*2;
  float bottom = senseLValue+senseFValue+senseRValue;

  float turnValue = (top / bottom)*1000; // 0 < turnValue > 2000
  //float smoothingValue = lastTurnValue + ((turnValue - lastTurnValue)/2);
  int turnAngle = map(turnValue, 0, 2000, 180, 0);

  for (int turnAngleIterator = turnAngle; turnAngleIterator > 0; turnAngleIterator = turnAngleIterator - 1) {
    Serial.print("#");
  }
  Serial.print(turnAngle);
  Serial.println();

  steeringServo.write(turnAngle);
  //float lastTurnValue = turnValue;
}
