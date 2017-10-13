/*
 *  Oct 9, 2017
 *  Email: prlatlab@gmail.com; robotintheworld@163.com
 *  http://prllab.wixsite.com/prl-lab-en
 *  Author: Mengbin (Mike) Min
* This project is used to control a stepper motor which is implented on the project of asparagus harvester 
* Step 1: Power on, initialize system such as setting pin 0 and pin 1 as inputs to control the stepper motor 
* Step 2: Press the valve manual switch to move pneumatic actuator down, the bottom magnetic switch on (Pin 0),
* the top magnetic switch off (Pin 1),then the stepper motor rotate clockwise only once to a fixed position, stop and wait
* Step 3: Press the valve manual switch to move pneumatic actuator up, the top magnetic switch on (Pin 1),
* the bottom magnetic switch off (Pin 0),then the stepper motor rotate clockwise only once to a fixed position, stop and wait
* Then repeat step2 ->  step3
*/

#include <Stepper.h> // header file for stepper motor
//user manual 
//https://cdn.fbsbx.com/v/t59.2708-21/17479905_1906213009658358_3061590844801810432_n.pdf/ST330_Stepper_Motor_Driver_Board_User_Manual.pdf?oh=8f9f634d6247e10944b3d605274e038d&oe=59DCF767&dl=1

// Variables for the stepper motor driver
const int stepsPerRevolution = 30;  // change this to fit the number of steps per revolution
                                     // NEMA 23 has 200 steps 1.8 deg each, 50 represent turning shaft 90 degrees AND CUTER 180 DEG
const int enableA = 6;
const int enableB = 5;

// initialize the stepper library using the default pins on the HBridge Shield:
Stepper myStepper(stepsPerRevolution, 4, 7, 3, 2);

int mswitch_bottom = 0; // bottom magnetic switch
int mswitch_top = 1; // top magnetic switch

boolean flag = true; // a flag used to stop doing for the first time

// Initialize function
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // for debugging
 pinMode (mswitch_bottom, INPUT); 
 pinMode (mswitch_top, INPUT);

 // set up the enable pins:
 pinMode(enableA, OUTPUT);
 pinMode(enableB, OUTPUT); 

 myStepper.setSpeed(60); // SPEED OF MOTOR IN RPM
}

void loop() {
  // put your main code here, to run repeatedly:  
  
  // step 2  
  if ( digitalRead(mswitch_top) == HIGH && digitalRead(mswitch_bottom) == LOW && flag == false )
  {
    delay(50);  // Waiting for switch stablizing
    if ( digitalRead(mswitch_top) == HIGH && digitalRead(mswitch_bottom) == LOW && flag == false )
    {
       Serial.print("step 2: stepper motor rotate clockwise only once\n");
       Serial.print("Please press valve manual switch \n");
       // stepper motor rotate clockwise only once coding
       stepper_CW();
       flag = false;
    }
  } 

 // step 3
   if ( digitalRead(mswitch_top) == LOW && digitalRead(mswitch_bottom) == HIGH && flag == false )
  {
    delay(50);  // Waiting for switch stablizing
    if ( digitalRead(mswitch_top) == LOW && digitalRead(mswitch_bottom) == HIGH && flag == false )
    {  
       Serial.print("step 3: stepper motor rotate clockwise only once\n");
       Serial.print("Please press valve manual switch \n");
       // stepper motor rotate counterclockwise only once coding
       stepper_CW();
       flag = false;
    }
  } 

}

// Stepper motor rotates clockwise

void stepper_CW(){
  // step one revolution in the other direction:
  Serial.println("clockwise");
  digitalWrite(enableA, HIGH);
  digitalWrite(enableB, HIGH);
  myStepper.step(stepsPerRevolution);
//  digitalWrite(enableA, LOW);
//  digitalWrite(enableB, LOW);
  delay(1000); 
}

// Stepper motor rotates counterclockwise

void stepper_CCW(){
  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  digitalWrite(enableA, HIGH);
  digitalWrite(enableB, HIGH);
  myStepper.step(stepsPerRevolution);
//  digitalWrite(enableA, LOW);
//  digitalWrite(enableB, LOW);
  delay(1000); 
}
