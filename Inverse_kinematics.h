#include <math.h>

const float l1 = 15.0;  // Distance in the XY from the rotating ( base servo ) joint to the center of the distance between the left and right rotating servos 
const float l2 = 80.0;  // Length of arm from the shoulder joint ( rotating left/right servo joints ) to the elbow joint
const float l3 = 80.0;  // Length of arm from the elbow joint to the gripper joint
const float l5 = 62.0;  // Length from the gripper joint to the end of the gripper

const float h1 = 55.0;  // Distance in the Z axis from ground to the rotating joints ( left/right servo )

const float x_offset = 20.0;  // distance from the base rotating joint to the start of the grid in the measured in the X axis

const double Pi = atan(1) * 4;  // Pi constant

const float starting_X_distance = 157.0; // Starting position distance in the X axis
const float starting_Y_distance = 0.0;   // Starting position distance in the Y axis
const float starting_Z_distance = 135.0; // Starting position distance in the Z axis 

// Checks if Y position of the end effector is positive or negative
// and returns base angle (theta1)
float check_Y(float Y, float X){
  
  if(Y < 0.0){
    return atan(Y / (X + x_offset)) * 180 / Pi;
  } 
  
  if(Y == 0.0){
    return 90.0 ;
  } 

   return atan(Y / (X + x_offset)) * 180 / Pi + 90.0;
  
} 

// Calculating the distance between left/right servo joints to the joint between the gripper and forearm in the XY axis
float calculateR1(float X, float Y, float theta1){
  return sqrt( pow((X - l5 * sin(theta1*Pi/180) - l1 * sin(theta1*Pi/180)) , 2) + pow((Y - l5 * cos(theta1*Pi/180) - l1 * cos(theta1*Pi/180)) , 2));
}

// Calculating the distance between left/right servo joints to the joint between the gripper and forearm in the Z axis
float calculateR2(float Z){
  return Z - h1;
}

// Calculating the hypotenuse of r1 and r2
float calculateR3(float r1, float r2){
  return sqrt( pow(r1,2) + pow(r2,2) );
}

// Calculating the angle between r3 and l2 - Fi1
float calculateFi1(float l2, float l3, float r3){
  return acos(( pow(l3,2) - pow(l2,2) - pow(r3,2) ) / (-2 * l2 * r3)) * 180 / Pi;
}

// Calculating the angle between r1 and r3 - Fi2
float calculateFi2(float r1, float r2){
  return atan(r2 / r1) * 180 / Pi;
}

// Calculating the angle between l2 and l3 - Fi3
float calculateFi3(float l2, float l3, float r3){
  return acos(( pow(r3,2) - pow(l2,2) - pow(l3,2) ) / (-2 * l2 * l3)) * 180 / Pi;
}

// Calculating the rotational angle of the base servo - theta1
float calculateTheta1(float Y, float X){
  return check_Y(Y, X);
}

// Calculating the rotational angle of the right servo - theta2
float calculateTheta2(float fi1, float fi2){
  return 180.0 - ( fi1 + fi2 );
}

// Calculating the rotational angle of the left servo - theta3
float calculateTheta3(float fi3){
   return 180.0 - fi3;
}

// ima sad onda ovih par isto sto ne mora
// Inverse kinematics calculation
// Input - X, Y, Z
// Output - theta1, theta2, theta3
float* inverse_kinematics_calculations(float X, float Y, float Z){

  // size - duzina niza
  int size = 3;
  float* thetas = malloc(sizeof(float) * size);

  thetas[0] = calculateTheta1(Y, X);
  float r1 = calculateR1(X, Y, thetas[0]); 
  float r2 = calculateR2(Z);
  float r3 = calculateR3(r1, r2);
  float fi1 = calculateFi1(l2, l3, r3);
  float fi2 = calculateFi2(r1, r2);
  float fi3 = calculateFi3(l2, l3, r3);
  thetas[1] = calculateTheta2(fi1, fi2);
  thetas[2] = calculateTheta3(fi3);

  return thetas;
}