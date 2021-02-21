// Open the gripper claw from 0% to 100% 
float gripper_open(float current_open_amount, float next_open_amount){
  
  float open_amount_difference_per_step = ( next_open_amount - current_open_amount) / 100 ;
  
  for(int i = 0; i <= 100; i++){
    current_open_amount += open_amount_difference_per_step;
    pwm.setPWM(GRIPPER_SERVO, 0, angleToPulse_Gripper(current_open_amount));
    delay(5);
  }
}
