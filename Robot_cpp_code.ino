#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <math.h>
#include "Servo_parameters.h"
#include "Angle_to_pulse.h"
#include "Inverse_kinematics.h"
#include "Inverse_kinematics_movement.h"
#include "Gripper_open.h"

void setup() {
  
  Serial.begin(9600);
  Serial.println("\n16 channel Servo test!");
  
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
}

void loop() {
  startingPosition();
  delay(1000);
  Move_gripper_to_XYZ(157.0, 0.0, 135.0, 100.0, 60.0, 40.0, 1);
  //delay(1000);
  gripper_open(0, 100);
  //delay(1000);
  Move_gripper_to_XYZ(100.0, 60.0, 40.0, 130.0, 90.0, 40.0, 0.5);
  //delay(1000);
  gripper_open(100, 35);
  Move_gripper_to_XYZ(130.0, 90.0, 40.0, 130.0, 90.0, 80.0, 0.5);
  //delay(2000);
  Move_gripper_to_XYZ(130.0, 90.0, 80.0, 130.0, -90.0, 80.0, 1);
  //delay(1000);
  Move_gripper_to_XYZ(130.0, -90.0, 80.0, 130.0, -90.0, 40.0, 0.5);
  //delay(1000);
  gripper_open(35, 100);
  //delay(1000);
  Move_gripper_to_XYZ(130.0, -90.0, 40.0, 100.0, -60.0, 40.0, 0.5);
  //delay(1000);
  gripper_open(100, 0);
  //delay(1000);
  Move_gripper_to_XYZ(100.0, -60.0, 40.0, 157.0, 0.0, 135.0, 1);

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
  // neki array pozicija
}
