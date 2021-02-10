int angleToPulse_Base(int ang) {
  int pulse = map(ang , BASE_SERVOMIN_ANGLE , BASE_SERVOMAX_ANGLE , BASE_SERVOMIN , BASE_SERVOMAX);
  return pulse;
}

int angleToPulse_Left(int ang) {
  int pulse = map(ang , LEFT_SERVOMIN_ANGLE , LEFT_SERVOMAX_ANGLE , LEFT_SERVOMIN , LEFT_SERVOMAX);
  return pulse;
}

int angleToPulse_Right(int ang) {
  int pulse = map(ang , RIGHT_SERVOMIN_ANGLE , RIGHT_SERVOMAX_ANGLE , RIGHT_SERVOMIN , RIGHT_SERVOMAX);
  return pulse;
}

int angleToPulse_Gripper(int ang) {
  int pulse = map(ang , 0 , 100 , GRIPPER_OPEN , GRIPPER_CLOSED);
  return pulse;
}
