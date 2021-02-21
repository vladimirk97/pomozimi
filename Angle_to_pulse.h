float angleToPulse_Base(float ang) {
  float pulse = map(ang , BASE_SERVOMIN_ANGLE , BASE_SERVOMAX_ANGLE , BASE_SERVOMIN , BASE_SERVOMAX);
  return pulse;
}

float angleToPulse_Left(float ang) {
  float pulse = map(ang , LEFT_SERVOMIN_ANGLE , LEFT_SERVOMAX_ANGLE , LEFT_SERVOMIN , LEFT_SERVOMAX);
  return pulse;
}

float angleToPulse_Right(float ang) {
  float pulse = map(ang , RIGHT_SERVOMIN_ANGLE , RIGHT_SERVOMAX_ANGLE , RIGHT_SERVOMIN , RIGHT_SERVOMAX);
  return pulse;
}

float angleToPulse_Gripper(float ang) {
  float pulse = map(ang , 0 , 100 , GRIPPER_CLOSED , GRIPPER_OPEN);
  return pulse;
}
