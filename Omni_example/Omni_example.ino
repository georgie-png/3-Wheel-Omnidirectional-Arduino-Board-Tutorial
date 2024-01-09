
#include <Servo.h> 

Servo myservo1, myservo2, myservo3; 

typedef struct
  {
    int mov;
    int dur;
  } Move;

// const int setting totall um steps
const int totalSteps = 6;

Move moves[totalSteps] = {{
    .mov=0,
    .dur=100,
  },
  {
    .mov=4,
    .dur=2000,
  },
  {
    .mov=2,
    .dur=1500,
  },
  {
    .mov=5,
    .dur=400,
  },
  {
    .mov=1,
    .dur=600,
  },
  {
    .mov=6,
    .dur=1400,
  },};


// a long to hold the inex for the loop
long indx = 0;

void setup() {
  
  // The servo 1 control wire is connected to Arduino D2 pin.
  myservo1.attach(2);

  // The servo 2 control wire is connected to Arduino D4 pin.
  myservo2.attach(4);

  // The servo 2 control wire is connected to Arduino D6 pin.
  myservo3.attach(6);
  
  // Servo1, Servo2 and Servo 3 are stationary.
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);

}

void loop() {

  int thisIndx = indx%totalSteps;

  //  get this move from 
  Move thisMove = moves[thisIndx];

 // stops all servos for 1 second.
  moveLogic(thisMove.mov, thisMove.dur);

  indx++;

}

void moveLogic(int movement, int duration){

  if(movement==0){
    movement1(duration);
  }
  else if(movement==1){
    movement2(duration);
  }
  
}

void movement1(int length){
  myservo1.write(0);
  myservo2.write(90);
  myservo3.write(180);
  delay(length);
}

void movement2(int length){
  myservo1.write(180);
  myservo2.write(0);
  myservo3.write(90);
  delay(length);
}

void movement3(int length){
  myservo1.write(0);
  myservo2.write(0);
  myservo3.write(0);
  delay(length);
}

void movement4(int length){
  myservo1.write(90);
  myservo2.write(180);
  myservo3.write(0);
  delay(length);
}

void movement5(int length){
  myservo1.write(180);
  myservo2.write(180);
  myservo3.write(180);
  delay(length);
}

void movement6(int length){
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  delay(length);
}
