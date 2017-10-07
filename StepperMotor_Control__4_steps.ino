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

int switch_s1 = 8; // the switch used to control the stepper motor
boolean flag = true; // a flag used to stop doing  

// Initialize function
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // for debugging
 pinMode (switch_s1, INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:  
  
  // step 2
  Serial.print("step 2: stepper motor rotate clockwise only once\n");
  Serial.print("Please press the switch and release\n");
  while ( digitalRead(switch_s1) == LOW )
  {
    delay(50);  // debuncing 
  } 
 
  flag = true;
  
  while ( digitalRead(switch_s1) == HIGH )
  {
    delay(50);  // debuncing
    if (digitalRead(switch_s1) == HIGH && flag == true){ 
      Serial.print( "clockwise \n");
      // run stepper motor forword
      // put the stepper motor coding here
      flag = false;
    }
  } 
  
  // step 3
  Serial.print("step 3: stepper motor rotate counterclockwise only once\n");
  Serial.print("Please press the switch and release\n");
  while ( digitalRead(switch_s1) == LOW )
  {
    delay(50);  // debuncing 
  } 
  
  flag = true;
  
  while ( digitalRead(switch_s1) == HIGH )
  {
    delay(50);  // debuncing
    if (digitalRead(switch_s1) == HIGH && flag == true){ 
      Serial.print("counterclockwise \n");
      // run stepper motor barward
      // put the stepper motor coding here
      flag = false;
    }
  }

// step 4
  Serial.print("step 4: stepper motor rotate counterclockwise only once\n");
  Serial.print("Please press the switch and release\n");
  while ( digitalRead(switch_s1) == LOW )
  {
    delay(50);  // debuncing 
  } 
  
  flag = true;
  
  while ( digitalRead(switch_s1) == HIGH )
  {
    delay(50);  // debuncing
    if (digitalRead(switch_s1) == HIGH && flag == true){ 
      Serial.print("counterclockwise \n");
      // run stepper motor forword
      // put the stepper motor coding here
      flag = false;
    }
  }
   // step 5
  Serial.print("step 5: stepper motor rotate clockwise only once\n");
  Serial.print("Please press the switch and release\n");
  while ( digitalRead(switch_s1) == LOW )
  {
    delay(50);  // debuncing 
  } 
 
  flag = true;
  
  while ( digitalRead(switch_s1) == HIGH )
  {
    delay(50);  // debuncing
    if (digitalRead(switch_s1) == HIGH && flag == true){ 
      Serial.print( "clockwise \n");
      // run stepper motor forword
      // put the stepper motor coding here
      flag = false;
    }
  } 
}
