#include <math.h>
float l1 = 15.0;
float l2 = 40.0;
float l3 = 80.0;
float l5 = 62.0;
float h1 = 55.0; 

float theta1;
float Z = 105.0;
float X = 130.0;
int checkY(float y_pos){
  if(y_pos < 0){
    float theta1 = atan(y_pos / (X+20));
    return theta1;
  } 
  else if(y_pos = 0){
    float theta1 = 90;
    return theta1;
  } 
  else if(y_pos > 0){
    float theta1 = atan(y_pos / (X+20)) + 90;
    return theta1;
  }  
  return theta1;
} 

float Y = checkY(0);


float r1 = sqrt((X - l5 * sin(theta1))*(X - l5 * sin(theta1)) + (Y - l5 * cos(theta1))*(Y - l5 * cos(theta1))) - l1;
float r2 = Z - h1;
float r3 = sqrt(r1*r1 + r2*r2);
float fi2 = atan(r2 / r1);
float fi1 = acos((l3*l3 - l2*l2 - r3*r3) / (-2 * l2 * r3));
float theta2 = 180 - fi1 - fi2;
float fi3 = acos((r3*r3 - l2*l2 - l3*l3) / (-2 * l2 * l3));
float theta3 = 180 - fi3;
