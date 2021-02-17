#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Calculating simultanious movement for all 3 servos
float Move_gripper_to_XYZ(float current_X, float current_Y, float current_Z, float next_X, float next_Y, float next_Z, float time_s){
  float instances = time_s * 100; // Number of 10ms instances
  
  float* current_angles = inverse_kinematics_calculations(current_X, current_Y, current_Z);
  
  float* next_angles = inverse_kinematics_calculations(next_X, next_Y, next_Z);
  
  float base_angle_change = (next_angles[0] - current_angles[0]) / instances;
  float right_angle_change = (next_angles[1] - current_angles[1]) / instances;
  float left_angle_change = (next_angles[2] - current_angles[2]) / instances;

  Serial.println("-------for start---------");
  Serial.print("base: ");
  Serial.println(current_angles[0]);
  Serial.print("right: ");
  Serial.println(current_angles[1]);
  Serial.print("left: ");
  Serial.println(current_angles[2]);
  
   
  for (int i = 0; i <= instances; i++) {
    current_angles[0] = current_angles[0] + base_angle_change;
    current_angles[1] = current_angles[1] + right_angle_change;
    current_angles[2] = current_angles[2] + left_angle_change;

    pwm.setPWM(BASE_SERVO,0,angleToPulse_Base(current_angles[0]));
    pwm.setPWM(RIGHT_SERVO,0,angleToPulse_Right(current_angles[1]));
    pwm.setPWM(LEFT_SERVO,0,angleToPulse_Left(current_angles[2]));

    delay(10);
  }

  Serial.println("--------for end--------");
  Serial.print("base: ");
  Serial.println(current_angles[0]);
  Serial.print("right: ");
  Serial.println(current_angles[1]);
  Serial.print("left: ");
  Serial.println(current_angles[2]);
 
}
