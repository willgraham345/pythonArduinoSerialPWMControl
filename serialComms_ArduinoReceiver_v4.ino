/****************************************************************
  Author Name: Will Graham
  Date: 6-16-22
  Sketch Name: Arduino Python Communication
  Sketch Description:  Takes input from python and outputs a high voltage relay for drone flight
*******************************************************************/

/****************************
 ** #defines and #includes **
 ****************************/

/***********************
 ** Global Variables ***
 ***********************/
// *** Declare & Initialize Pins ***
const int M1_pin = 3, M2_pin = 9, M3_pin = 10, M4_pin = 11;


// *** Program Variables ***
float PWM_Outputs[4] = {};// PWM OUTPUTS is an integer array of valuefrom 0-255 (corresponding to the duty cycle)






/********************
 ** Setup Function **
 ********************/
void setup() {
  // PUT YOUR SETUP CODE HERE, TO RUN ONCE:


  // *** Configure Pins & Attach Servos ***
  pinMode(M1_pin, OUTPUT);
  pinMode(M2_pin, OUTPUT);
  pinMode(M3_pin, OUTPUT);
  pinMode(M4_pin, OUTPUT);

  // *** Initialize Serial Communication ***
  Serial.begin(115200);
}
  
  // *** Take Initial Readings ***

  // *** Move Hardware to Desired Initial Positions ***





/*******************
 ** Loop Function **
 *******************/
void loop(void) {
  while (Serial.available() <= 3) {
    ;//    do nothing here
  }
  for (int i = 0; i < 3; i++) {
    PWM_Outputs[i] = Serial.read(); // PWM OUTPUTS is an integer array of valuefrom 0-255 (corresponding to the duty cycle)
  }
  writeToMotors(PWM_Outputs);
  
}




/****************************
 ** User-Defined Functions **
 ****************************/
// create custom headings as necessary to clearly organize your sketch
// e.g., Button functions, DC Motor functions, Servo functions, etc.

void writeToMotors(float PWM_Outputs[4]){
  // PWM OUTPUTS is an integer array of valuefrom 0-255 (corresponding to the duty cycle)
  analogWrite(M1_pin, PWM_Outputs[1]);
  analogWrite(M2_pin, PWM_Outputs[2]);
  analogWrite(M3_pin, PWM_Outputs[3]);
  analogWrite(M4_pin, PWM_Outputs[4]);
  return;
}
