#include <Stepper.h> // header file for stepper motor
const int stepsPerRevolution = 360;  // change this to fit the number of steps per revolution
const int enableA = 6;
const int enableB = 5;

// initialize the stepper library using the default pins on the HBridge Shield:
Stepper myStepper(stepsPerRevolution, 4, 7, 3, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode (enableA, OUTPUT);
  pinMode (enableB, OUTPUT);
  myStepper.setSpeed(120); // SPEED OF MOTOR IN RPM
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper_CCW();
}
void stepper_CCW(){
  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  digitalWrite(enableA, HIGH);  
  digitalWrite(enableB, HIGH);
 /* delay(50);
  myStepper.step(stepsPerRevolution);
  digitalWrite(enableA, LOW);
  digitalWrite(enableB, LOW);*/
  myStepper.step(stepsPerRevolution);
  delay(1000); 
}
