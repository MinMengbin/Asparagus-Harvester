/*
 *  Oct 7, 2017
 *  Email: prlatlab@gmail.com; robotintheworld@163.com
 *  http://prllab.wixsite.com/prl-lab-en
 *  
* This project is used to control a stepper motor which is implented on the project of asparagus harvester 
* Step 1: Power on, initialize system such as setting pin 0 as an input to control the stepper motor 
* Step 2: Press switch and release, stepper motor rotate clockwise only once to a fixed position, stop and wait
* Step 3: Press switch and release, stepper motor rotate counterclockwise only once to a fixed position, stop and wait
* Step 4: Press switch and release, stepper motor rotate counterclockwise only once to a fixed position, stop and wait
* Step 5: Press switch and release, stepper motor rotate clockwise only once to a fixed position, stop and wait
* Then repeat step2 - step 5
*/

#include <Stepper.h> // header file for stepper motor
const int stepsPerRevolution = 25;  // change this to fit the number of steps per revolution
const int enableA = 6;
const int enableB = 5;
// initialize the stepper library using the default pins on the HBridge Shield:
Stepper myStepper(stepsPerRevolution, 4, 7, 3, 2);

int switch_s1 = 8; // top switch used to control the stepper motor

boolean flag = true; // a flag used to stop doing  

// Initialize function
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // for debugging
 pinMode (switch_s1, INPUT); 
 pinMode (enableA, OUTPUT);
 pinMode (enableA, OUTPUT);
 
 myStepper.setSpeed(150); // SPEED OF MOTOR IN RPM
}

void loop() {
  // put your main code here, to run repeatedly:  
  
  // step 2
  Serial.print("step 2: stepper motor rotate clockwise only once\n");
  Serial.print("Please press the switch and release\n");
  while ( digitalRead(switch_s1) == LOW )
  {
    delay(30);  // debuncing 
  } 
 
  flag = true;
    while ( digitalRead(switch_s1) == HIGH )
  {
    delay(30);  // debuncing
    if (digitalRead(switch_s1) == HIGH && flag == true){ 
      Serial.print( "clockwise \n");
      // run stepper motor 180deg cutter
      // put the stepper motor coding here
      stepper_CW();      
      flag = false;
    }
  } 
  
  // step 3
  Serial.print("step 3: stepper motor rotate counterclockwise only once\n");
  Serial.print("Please press the switch and release\n");
  while ( digitalRead(switch_s1) == LOW )
  {
    delay(30);  // debuncing 
  } 
  
  flag = true;
  
  while ( digitalRead(switch_s1) == HIGH )
  {
    delay(30);  // debuncing
    if (digitalRead(switch_s1) == HIGH && flag == true){ 
      Serial.print("counterclockwise \n");
      // run stepper motor barward
      stepper_CCW();
      // put the stepper motor coding here
      flag = false;
    }
  }

// step 4
  Serial.print("step 4: stepper motor rotate counterclockwise only once\n");
  Serial.print("Please press the switch and release\n");
  while ( digitalRead(switch_s1) == LOW )
  {
    delay(30);  // debuncing 
  } 
  
  flag = true;
  
  while ( digitalRead(switch_s1) == HIGH )
  {
    delay(30);  // debuncing
    if (digitalRead(switch_s1) == HIGH && flag == true){ 
      Serial.print("counterclockwise \n");
      // run stepper motor forword
      // put the stepper motor coding here
      stepper_CCW();
      flag = false;
    }
  }
   // step 5
  Serial.print("step 5: stepper motor rotate clockwise only once\n");
  Serial.print("Please press the switch and release\n");
  while ( digitalRead(switch_s1) == LOW )
  {
    delay(30);  // debuncing 
  } 
 
  flag = true;
  
  while ( digitalRead(switch_s1) == HIGH )
  {
    delay(30);  // debuncing
    if (digitalRead(switch_s1) == HIGH && flag == true){ 
      Serial.print( "clockwise \n");
      // run stepper motor forword
      stepper_CW();
      // put the stepper motor coding here
      flag = false;
    }
  } 
}

// Stepper motor rotates counterclockwise

void stepper_CW(){
  // step one revolution in the other direction:
  Serial.println("clockwise");
  digitalWrite(enableA, HIGH);
  digitalWrite(enableB, HIGH);
  myStepper.step(stepsPerRevolution);
  digitalWrite(enableA, LOW);
  digitalWrite(enableB, LOW);
  delay(1000); 
}
void stepper_CCW(){
  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  digitalWrite(enableA, HIGH);
  digitalWrite(enableB, HIGH);
  myStepper.step(-stepsPerRevolution);
  digitalWrite(enableA, LOW);
  digitalWrite(enableB, LOW);
  delay(1000); 
}

