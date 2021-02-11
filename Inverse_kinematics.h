#include <math.h>

// constants 
// Add more descriptive names if possible - I guess length and height ? 
const float l1 = 15.0;
const float l2 = 40.0;
const float l3 = 80.0;
const float l5 = 62.0; // where is l4 ?

const float h1 = 55.0; 

const float x_offset = 20.0;
const float right_angle_degrees = 90;
const float straight_angle_degrees = 180;

// Methods

// Method description
float calculateR1(float x, float y, float theta1) {
   return sqrt((x - l5 * sin(theta1))*(x - l5 * sin(theta1)) + (y - l5 * cos(theta1))*(y - l5 * cos(theta1))) - l1;
}

// Method description
float calculateR2(float z, float h1) {
  return z-h1;
}

// Method description
float calculateR3(float r1, float r2) {
  return sqrt( pow(r1, 2) + pow(r2, 2) );
}

// Method description
float calculateFi1(float r3) {
  // what is -2 -> extract to a more descriptive variable
  return acos( ( pow(l3, 2) - pow(l2, 2) - pow(r3, 2) ) / (-2 * l2 * r3));
}

// Method description
float calculateFi2(float r1, float r2) {
  return atan(r2 / r1);
}

// Method description
float calculateFi3(float r3) {
  return acos(( pow(r3, 2) - pow(l2, 2) - pow(l3, 2) ) / (-2 * l2 * l3));
}


// Method description
float calculateTheta1(float x, float y){
  
  if(y < 0) {
    return atan(y_pos / ());
  } 
  
  if(y == 0){
    return right_angle_degrees;
  } 

  return atan(y / (x + x_offset)) + right_angle_degrees;
} 

// Method description
float calculateTheta2(float fi1, float fi2){
  return straight_angle_degrees - fi1 - fi2;
}

// Method description
float calculateTheta3(float fi3){
  return straight_angle_degrees - fi3;
}

// variables 
float X = 130.0;
float Y = 0.0;
float Z = 105.0;

float theta1 = calculateTheta1(X, Y);

float r1 = calculateR1(X, Y, theta1);
float r2 = calculateR2(Z, h1);
float r3 = calculateR3(r1, r2);

float fi1 = calculateFi1(r3);
float fi2 = calculateFi2(r1, r2);
float fi3 = calculateFi3(r3);

float theta2 = calculateTheta2(fi1, fi2);
float theta3 = calculateTheta3(fi3);
