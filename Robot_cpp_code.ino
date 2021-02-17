#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <math.h>
#include "Servo_parameters.h"
#include "Angle_to_pulse.h"
#include "Inverse_kinematics.h"
#include "Inverse_kinematics_movement.h"

void setup() {
  
  Serial.begin(9600);
  Serial.println("\n16 channel Servo test!");
  
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
}

void loop() {
  //startingPosition();
  Move_gripper_to_XYZ(157.0, 0.0, 135, 157.0, -40.0, 40.0, 2);
  delay(2000);
  Move_gripper_to_XYZ(157.0, -40.0, 40.0, 157.0, 0.0, 135, 2);
  delay(2000);
 
}

float startingPosition(){
  pwm.setPWM(BASE_SERVO, 0, angleToPulse_Base(90));
  pwm.setPWM(LEFT_SERVO, 0, angleToPulse_Left(90));
  pwm.setPWM(RIGHT_SERVO, 0, angleToPulse_Right(90));
  pwm.setPWM(GRIPPER_SERVO, 0, GRIPPER_CLOSED);
  //float current_angle_Base = 90;
  //float current_angle_Left = 90;
  //float current_angle_Right = 90;
  float current_X = 157.0;
  float current_Y = 0.0;
  float current_Z = 135.0;
}
