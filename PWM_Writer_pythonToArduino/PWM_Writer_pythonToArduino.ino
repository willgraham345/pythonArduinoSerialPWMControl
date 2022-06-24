/****************************************************************
  Author Name: Will Graham
  Date: 6-124-22
  Sketch Name: Python Serial Receiver, and PWM Output
  Sketch Description:  Takes input from python and outputs a corresponding duty cyle to designated Arduino pin (0-5V)
*******************************************************************/

///

/****************************
 ** Instructions for Using with Python
 ****************************/
// Install/include pyserial, and specify the port Arduino connects with on the Python driver. Simple, one value serial communication. 
/***********************
 ** Global Variables ***
 ***********************/
// *** Declare & Initialize Pins ***
const int highVoltageRelayPin = 10; // High voltage relay controller pin. 



// *** Program Variables ***
int dutyCycle; //Duty cycle initialization
  // Note: Duty cycle will range from 0-5V



/********************
 ** Setup Function **
 ********************/
void setup() {
  // PUT YOUR SETUP CODE HERE, TO RUN ONCE:


  // *** Configure Pins & Attach Servos ***
  pinMode(highVoltageRelayPin, OUTPUT);

  // *** Initialize Serial Communication ***
  Serial.begin(115200); //Serial communication happens at 1152-
}
  
  // *** Take Initial Readings ***

  // *** Move Hardware to Desired Initial Positions ***





/*******************
 ** Loop Function **
 *******************/
void loop(void) {
  while (Serial.available()==0) {
    ;//    do nothing here
  }
  dutyCycle = Serial.read();
  int dutyCycle_255 = int(dutyCycle*2.55); // Convert the 0-100 of duty cyle, to 0-255 of analogWrite
  analogWrite(highVoltageRelayPin, dutyCycle_255); //Write value to pin
  
}




/****************************
 ** User-Defined Functions **
 ****************************/
// create custom headings as necessary to clearly organize your sketch
// e.g., Button functions, DC Motor functions, Servo functions, etc
