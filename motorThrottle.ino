void runEsc(int motorNumber) {
  if (motorNumber == 1){
    esc1.writeMicroseconds(motor1Value);
  } else {
    esc2.writeMicroseconds(motor2Value);
  }
}

void motorThrottle(int target, int motorNumber) {
  int diff;

  if (motorNumber == 1) {
    diff = target - motor1Value;

    if (diff > 0) {
      motor1Value = motor1Value +4;
      runEsc(motorNumber);
    } if (diff < 0) {
      motor1Value = motor1Value -4;
      runEsc(motorNumber);
    }


  } else {

    diff = target - motor2Value;

    if (diff > 0) {
      motor2Value = motor2Value +4;
      runEsc(motorNumber);
    } if (diff < 0) {
      motor2Value = motor2Value -4;
      runEsc(motorNumber);
    }

  }
}
