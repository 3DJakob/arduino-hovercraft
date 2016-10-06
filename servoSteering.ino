void servoSteering() {
  senseLValue = analogRead(senseLPin);
  senseFValue = map(analogRead(senseFPin), minSensorValue, maxSensorValue, maxSensorValue, minSensorValue);
  senseRValue = analogRead(senseRPin);

  // senseLValue = 470;
  // senseFValue = 470;
  // senseRValue = 0;

  float top = senseFValue*1+senseRValue*2;
  float bottom = senseLValue+senseFValue+senseRValue;

  float turnValue = (top / bottom)*1000; // 0 < turnValue > 2000

  float turnAngle = map(turnValue, 0, 2000, 90, 0);

  servo.write(turnAngle);
}
