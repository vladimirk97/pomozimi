#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <math.h>
#include "Servo_parameters.h"
#include "Angle_to_pulse.h"
#include "Inverse_kinematics.h"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
}

void loop() {
  startingPosition();
  float Z = 105.0;
  float X = 130.0;
  float Y = 0.0;
  //pwm.setPWM(BASE_SERVO,0,angleToPulse_Base(theta1));
  //pwm.setPWM(LEFT_SERVO,0,angleToPulse_Left(theta3));
  //pwm.setPWM(RIGHT_SERVO,0,angleToPulse_Right(theta2));
  //float X =
  delay(6000);
  Serial.print("left: ");
  Serial.println(theta3);
  Serial.print("right: ");
  Serial.println(theta2);
}

int startingPosition(){
  pwm.setPWM(BASE_SERVO,0,angleToPulse_Base(90));
  pwm.setPWM(LEFT_SERVO,0,angleToPulse_Left(90));
  pwm.setPWM(RIGHT_SERVO,0,angleToPulse_Right(90));
  pwm.setPWM(GRIPPER_SERVO,0,GRIPPER_CLOSED);
  float current_angle_Base = 90;
  float current_angle_Left = 90;
  float current_angle_Right = 90;
}
