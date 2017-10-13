/*
 *  Oct 7, 2017
 *  Email: prlatlab@gmail.com; robotintheworld@163.com
 *  http://prllab.wixsite.com/prl-lab-en
 *  Author: Mengbin (Mike) Min
* This project is used to control a stepper motor which is implented on the project of asparagus harvester 
* Step 1: Power on, initialize system such as setting pin 0 as an input to control the stepper motor 
* Step 2: Press switch and release, stepper motor rotate clockwise only once to a fixed position, stop and wait
* Then repeat step2
*/

#include <Stepper.h>

const int stepsPerRevolution = 400;  // change this to fit the number of steps per revolution
                                     // NEMA 23 has 200 steps 1.8 deg each, 50 represent turning shaft 90 degrees AND CUTER 180 DEG

const int enableA = 6;
const int enableB = 5;

// flags used to run the stepper motor
int start = 0; 
bool flag = true;

int switch_i = 8; // switch input number 8

// initialize the stepper library using the default pins on the HBridge Shield:
Stepper myStepper(stepsPerRevolution, 4, 7, 3, 2);

void setup()
{
  // put your setup code here, to run once:
  pinMode(switch_i,INPUT); // THIS HERE IS WHERE YOU CONNECT SWITCH Normally Open NO, ONTO ARDUINO Digital in 0
  
    // set up the enable pins:
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  
  myStepper.setSpeed(100); // SPEED OF MOTOR IN RPM
  // initialize the serial port:
  Serial.begin(9600);
  
}
void loop()
{
   
//  // step one revolution in the other direction:
//  Serial.println("counterclockwise");
//  digitalWrite(enableA, HIGH);
//  digitalWrite(enableB, HIGH);
//  myStepper.step(stepsPerRevolution);
//  digitalWrite(enableA, LOW);
//  digitalWrite(enableB, LOW);
//  delay(1000); 

 // Run one time when input of the switch from LOw to HIGH
 // If it is low, stepper motor is off
  if(digitalRead(switch_i) == HIGH)
  {
   // debuncing
    delay (50);
    if (digitalRead(switch_i) == HIGH){ 
      start = 1;
    }
  }
  
  if (digitalRead(switch_i) == LOW)
  {
    // debouncing
    delay (100);
    if(digitalRead(switch_i) == LOW){
      start = 0;
      flag = true;
    }
  }
  
  if ( start == 1 && flag == true ){
    // step one revolution in one direction:
    Serial.println("counterclockwise"); 
    digitalWrite(enableA, HIGH);// power on
    digitalWrite(enableB, HIGH);
    myStepper.step(-stepsPerRevolution); // NUMBER OF STEPS TO TAKE 
    digitalWrite(enableA, LOW); // power off
    digitalWrite(enableB, LOW);
    delay(1000); // wait between steps
    flag = false;
    
  }
}
