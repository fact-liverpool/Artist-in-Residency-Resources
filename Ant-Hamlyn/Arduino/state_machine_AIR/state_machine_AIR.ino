//GLOBAL VARIABLES:

boolean turnOn = 0;

int inSolenoidValve = 11; //pin12
int outSolenoidValve = 12; //pin 12
int airState = 0; //false / off


void setup()

{

  //setting up ports as Inputs
  //the input_pullup turns on an internal pull up resitor of the arduino

  pinMode(2, INPUT_PULLUP); //input from button
  pinMode(3, INPUT_PULLUP); //input from button

  // making the two ports as outputs
  pinMode(inSolenoidValve, OUTPUT);
  pinMode(outSolenoidValve, OUTPUT);


  //this is a comunication channell with your computer
  //and used and the arduino is connected to you computer
  //just click in the magnifier icon over the top right corner
  Serial.begin(19200);


}
long lastTime;

void loop() {


  //reading the two inputs and storing in variables

  int buttonA = digitalRead(2); //these variables only exist in the loop (buttons, sensors ect. LOCAL VARIABLES)
  int buttonB = digitalRead(3);


  /* if buttonB was pressed and it equalled 0.
  Then.. turnOn equals 1 and perform the task for a number of milliseconds */
  //1 is

  if (buttonA == 0)

  { //start code
    Serial.println("button A");
    turnOn = 1; //  the number 1 to 'turn on'
    lastTime = millis(); //The amount of time is measured in milliseconds
  }

  /* if buttonB was pressed and it equalled 0.
  Then.. turnOn would equal 0, airstate would also equal 0.     */

  if (buttonB == 0) //0 means off / false

  { //start code
    Serial.println("button B");
    turnOn = 0; //
    airState = 0; //initial state of air


    //what do the digital ports do
    digitalWrite(outSolenoidValve, LOW); //digital write = 'Im going to tell it what to do'(whats connected,Its voltage)
    digitalWrite(inSolenoidValve, LOW);

  }
  //check if the button was pressed
  if (turnOn == 1) {
    //

    //check the air state, 0 is inflating 1 is deflating
    if (airState == 0) {
      Serial.println("stat 0");

      //time checking, the difference since first pressed
      if (millis() - lastTime < 4000) {
        Serial.println("in solenoid ON");
        digitalWrite(inSolenoidValve, HIGH);
      }

      else {
        Serial.println("in solenoid OFF");
        digitalWrite(inSolenoidValve, LOW);
        airState = 1;
        lastTime = millis();
      }
    }

    else if (airState == 1) {

      Serial.println("state 1");
      if (millis() - lastTime < 10000) {
        digitalWrite(outSolenoidValve, HIGH);
        Serial.println("out solenoid ON");
      } else {
        Serial.println("out solenoid OFF");
        digitalWrite(outSolenoidValve, LOW);
        airState = 0;
        lastTime = millis();
      }


    }

  }
//
//  Serial.print(buttonA);
//  Serial.print(" ");
//  Serial.print(buttonB);
//  Serial.println();



}
