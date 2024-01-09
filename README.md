# 3-Wheel-Omnidirectional-Arduino-Board

In this tutorial we will be working together with the omnidirectional wheels on three rotary encoders to  create little dancing robots!

---
## So What Are We Doing?

In the slides that go with this we have seen the logics and movements of the setup.

Now its time to put our knowledges into practice!

---

## Firstly let's Cable up a servo motor!

![[Wiring-the-360-degree-servo-motor-with-Arduino-Uno-1024x496.jpg]]

The servo needs to be connected up to the:
- [ ] power
- [ ] ground
- [ ] data pin (2)

---

## Next To Code It.

- [ ] Create a new project called `Omni-dance`

### In the code:

- [ ] Include the `Servo.h` lib
- [ ] Creat a Servo object called `myServo1` 
- [ ] In the setup attach `myServo1` to the pin the servo is on (pin 2).
- [ ] Write 90 to `myServo1` to set it to being stopped.

```c++
# Include the servo lib
#include <Servo.h> 

# Create a new Servo object called myServo1;
Servo myServo1; 


void setup() {
  
  // Attach servo 1 to be controled by D2 pin.
  myServo1.attach(2);


  // set Servo1 to stationary.
  myservo1.write(90);
}

```

---
## Reminder of how Servos work?

A continuous servo like we have here is controlled with a setting of 0 -180. 

With it representing a gradient of rotation from:
- 0 = counter-clockwise 
- 90 = stopped
- 180 = clockwise

---
### So to test this we can:

- [ ] Add some `write` functions and delays int the setup, so that it looks similar to this (but do explore and find out how it works by setting the write values to different numbers between 0-180)

```c++
void setup() {
  
  // Attach servo 1 to be controled by D2 pin.
  myServo1.attach(2);


  // Set Servo1 to stationary.
  myservo1.write(90);
  // delay for 5 seconds
  delay(5000);

  // Set Servo1 to slowly turning clockwise.
  myservo1.write(100);
  // delay for 5 seconds
  delay(5000);
  
  // Set Servo1 to medium turning counter-clockwise.
  myservo1.write(45);
  // delay for 5 seconds
  delay(5000);

  // Set Servo1 to fast turning clockwise.
  myservo1.write(180);
  // delay for 5 seconds
  delay(5000);

  // Set Servo1 to stationary.
  myservo1.write(90);

}
```

---
## Run and Test it.

It should move the wheel in the different cycle you set up!

Go on and try a different set of values to get a feel for it.

---
## Now that we know how it works!

we can start to setup the more complex configuration with three motors.

---
## Connect up the servos the same as before

But attaching to pins:
- [ ] servo2 = pin 4
- [ ] servo3 = pin 6

![[Pasted image 20240108205940.png]]

---
## Now in the code we need to:

- [ ] Clear all the tests.
- [ ] Initiate servo 2 and 3.
- [ ] Attach servo 2 to pin 4.
- [ ] Attach servo 3 to pin 6.
- [ ] Write 90 to all servos to stop them all.

This will setup the wheels/servos ready for us to control and get them to dance/move.

```c++

Servo myservo1, myservo2, myservo3; 


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
```

---
## Writing movement functions!

These will be the functions to replicate the movements in this diagram.

![[Pasted image 20240108210559.png]]

---
## Working out the movement functions.

So this is a bit where you have to work out the movement functions and turn the images/diagrams into computational logics!!!

I will give an example of the movement 1.

![[Pasted image 20240108211704.png]]

As you see in the diagram it needs:
- [ ] servo1 turning counter-clockwise
- [ ] servo2 not turning
- [ ] servo3 three turning clockwise.

In Arduino code this function looks like:
```c++
void movement1(){
  myservo1.write(0);
  myservo2.write(90);
  myservo3.write(180);
}
```

---
## Now to make it run for a specific length of time.

We do this by:
- [ ] Letting the function take an int variable called `length` which tells it how long to run for in Millis.
- [ ] Use that value to delay it after setting the servos going.

```c++
void movement1(int length){
  myservo1.write(0);
  myservo2.write(90);
  myservo3.write(180);
  delay(length);
}
```

---
## Testing it!

Now if we just test this first movement from the setup it would look like:
```c++
void setup() {
  
  // The servo 1 control wire is connected to Arduino D2 pin.
  myservo1.attach(2);

  // The servo 2 control wire is connected to Arduino D4 pin.
  myservo2.attach(4);

  // The servo 2 control wire is connected to Arduino D6 pin.
  myservo3.attach(6);

  movement1(5000); /// <<<<<<<<< running movement one for 5 secs

  // Servo1, Servo2 and Servo 3 are stationary.
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);

}
```

---
### Once tested remove any movements from setup that were added.


---
## Now time for you to work out the rest!

![[Pasted image 20240108210559.png]]

Use the diagram to work out the other 4 movements shown!

You also need to add another 6th movement not shown, that is where it is staying still. 

Tick of the movements:
- [ ] `movement1()`
- [ ] `movement2()`
- [ ] `movement3()`
- [ ] `movement4()`
- [ ] `movement5()`
- [ ] `movement6()`

---
## When you are done you should have:

```c++
void movement1(...){
...
}
void movement2(...){
...
}
void movement3(...){
...
}
void movement4(...){
...
}
void movement5(...){
...
}
void movement6(...){
...
}
```

But obviously filled with the right commands/variables.

You can also debug these by testing them in the setup like we did with `movement1` before.


---
## Now to Make it Dance!

Once you know that it is all setup and the movements are correct, we can now start to make sequences or dances/movements.

Lets run through all of the movements for 1 second each within the loop function:
```c++
void loop() {
  // Delay the start for 10 seconds
  delay(10000);

  //Servos spins forward at full speed for 1 seconds and it will move in the direction of the two wheels rotating clockwise and anticlockwise.
  movement1(1000);
  
  //Servos spins forward at full speed for 1 seconds and it will move in the direction of the two wheels rotating clockwise and anticlockwise.
  movement2(1000);

  //Servos spins forward at full speed for 1 Seconds all wheels are moving clockwise, so the board will rotate from right to left. 
  movement3(1000);
  
  //Servos spins forward at full speed for 1 seconds and it will move in the direction of the two wheels rotating clockwise and anticlockwise.
  movement4(1000);

  //Servos spins forward at full speed for 1 Seconds all wheels are moving anticlockwise, so the board will rotate from left to right.
  movement5(1000);

 // stops all servos for 1 second.
  movement6(1000);

}
```


---
### Test it out!

See how it works.

Maybe mix up the order and durations of it to get it to do different moves.

🤖

Once you feel like you know how the moves combine and work move onto the next step.


---
## Running it through arrays/commands.

This next stage is to operationalise these functions so that they are more functional within a bigger more complex system. This might be receiving commands from p5, responding to more complex sensed data, or in our case today, playing out a list/array of data/movements. 

You might ask why go to all the trouble to create this system, but when it comes to utilising it in more complex ways, you will be glad you set up so sound easy to use functions.


---
## If logic 

To run a functions from numerical variables, we need to use if logic. In this case we will use integer numbers (whole numbers) to repressent the functions. This looks like: 

- [ ] `movement1()` == `0`
- [ ] `movement2()` == `1`
- [ ] `movement3()`== `2`
- [ ] `movement4()`== `3`
- [ ] `movement5()` == `4`
- [ ] `movement6()` == `5`

**NOTE:** You may ask why we go from 1 to 0, but this is to make it more accessible to for loops, which normally cycle from 0-N.

Here I will show you how to do it for the first two movements and   you repeat the logic in this new `moveLogic` function. 

```c++
void moveLogic(int movement, int duration){

  if(movement==0){
    movement1(duration);
  }
  else if(movement==1){
    movement2(duration);
  }
  
}
```


---
### Lets test it!

Now in the loop we should be able to run:
```c++
void loop() {

  delay(10000);

  //Servos spins forward at full speed for 1 seconds and it will move in the direction of the two wheels rotating clockwise and anticlockwise.
  moveLogic(0, 1000);

  
  //Servos spins forward at full speed for 1 seconds and it will move in the direction of the two wheels rotating clockwise and anticlockwise.
  moveLogic(1, 1000);


  //Servos spins forward at full speed for 1 Seconds all wheels are moving clockwise, so the board will rotate from right to left. 
  moveLogic(2, 1000);

  
  //Servos spins forward at full speed for 1 seconds and it will move in the direction of the two wheels rotating clockwise and anticlockwise.
  moveLogic(3, 1000);


  //Servos spins forward at full speed for 1 Seconds all wheels are moving anticlockwise, so the board will rotate from left to right.
  moveLogic(4, 1000);


 // stops all servos for 1 second.
  moveLogic(5, 1000);

}
```

This should give us the same result we had from the "**Now to make it dance**" step above, and seems to actually take more logic to do the same thing, so why do we do it? We can now use this more easily within automatic systems as you will see.


---
## Random dance!

Now we have the `moveLogic`  function up and going we can utilise it to make our omni bot do a random dance. 


```c++

void loop() {
  // get a random int from 0-6 to chose a move
  int randMove = random(6);
  
  //get a random duration fro 0.5-1.5 secs
  int randDuration = random(500,1500);

  // run the logic and thus the random movement for the random duration.
  moveLogic(randMove, randDuration);

}

```


---
## Array Choreography

[Arrays](https://www.arduino.cc/reference/en/language/variables/data-types/array/) are a way of storing data as a list or collection. In this example we are going to use arrays to store the movements and their duration.

Lets setup our new variable at the top of the page with:
- [ ] Declare a const int that holds the total num of steps in `totalSteps`
- [ ] Declare `movementArray` to hold the movements, fill with values from 0-5 representing the different moves.
- [ ] Declare `durationsArray` to hold the durations for these steps, set them to values in Millis.
- [ ] Declare a integer called `index`  to track what index in the array we are. 

It should look like this at the top of the page:
``` c++
#include <Servo.h> 

Servo myservo1, myservo2, myservo3; 
///// \/ New code to add \/

// const int setting totall num steps
const int totalSteps = 6;

// int arrays of length totalSteps, with each step having a:
// - movment int
int movementArray[totalSteps] = {  2,   0,   1,    3,  5,   4};
// - duration int
int durationsArray[totalSteps] ={200, 400, 800, 3000, 60, 400};

// a long to hold the inex position for the looping over
long indx = 0;
```


---
## How to loop over those moves with modulo!

To do this we will be using modulo (my/Georges favourite math function). It is a fun and v useful function that in this case lets you use a constantly raising and infinitely rising index to find its position within a finite array. 

### How does it do this?

Modulo, or `%` (percentage sign) in code, gives us the remainder after division. A good example of modulo is translating the 24hr clock to the 12hr clock. see below:

#### 12 Hour Time

12-hour time uses modulo 12

**Example:** **14** mod **12** equals **2** (`14%12=2`)
Because $14/12=1$, **Leaving** a remainder of **2**.

![[modulus.svg]]

So **14** o'clock becomes **2** o'clock.


---
## How to Modulo an Array?

Modulo then makes it super easy to translate an index (potentially infinite) to a position in a finite array, all we need to do is `index%arrayLength`.

Here is a gif of modulo in action in js, see how index never goes over the array Length (10):
![[D23XMdf-2519117421.gif]]

For us in Arduino code this looks like:
```c++
void loop() {
  // get this index by using modulo, getting the remainder of indx/totalStep
  int thisIndx = indx%totalSteps;

  //  get thisMove by reading the move from thisIndx position.
  int thisMove = movementArray[thisIndx];
  //  get thisDuration by reading the duration from thisIndx position.
  int thisDuration = durationsArray[thisIndx];

 // Uses the move logic to move to these commands
  moveLogic(thisMove, thisDuration);

  // add one to the indx
  indx++;
}
```


---
## Test it out!!

It should now do move around following those pre-set commands.

Try to edit the commands in the array to get it to do a new dance, by editing the number of steps and an what they are:
```c++
// const int setting totall num steps
const int totalSteps = 6;

// int arrays of length totalSteps, with each step having a:
// - movment int
int movementArray[totalSteps] = {  2,   0,   1,    3,  5,   4};
// - duration int
int durationsArray[totalSteps] ={200, 400, 800, 3000, 60, 400};
```

**NOTE:** Make sure that both the arrays are the same length and remember that each move is a combination of the move and duration at each step of bot arrays.


---
## Structs to the rescue!

You may have found that the array input is a little confusing and might throw errors when we make mistakes on matching steps together. To clear this up we can use a struct to hold each steps movement commands together in one place instead of across multiple arrays. 

We can declare a struct called `Move` to hold our move and duration values:
```c++
// declaring a struct
typedef struct
  {
  // giving it an int for move number and duration of move
    int mov;
    int dur;
  } Move; // Naming it `Move`
```

This now means we have a structure that holds all our variables together!

---
## Translating our commands into a struct array.

This is where you see why these are so handy, instead of the two, hard to manage arrays, we can now write one that is easier to understand.

so instead of:
```c++
// int arrays of length totalSteps, with each step having a:
// - movment int
int movementArray[totalSteps] = {  2,   0,   1,    3,  5,   4};
// - duration int
int durationsArray[totalSteps] ={200, 400, 800, 3000, 60, 400};
```

we can have:
```c++
Move moves[totalSteps] = {{
    .mov=2,
    .dur=200,
  },
  {
    .mov=0,
    .dur=400,
  },
  {
    .mov=1,
    .dur=800,
  },
  {
    .mov=3,
    .dur=3000,
  },
  {
    .mov=5,
    .dur=60,
  },
  {
    .mov=4,
    .dur=400,
  },};
```

This bundles each step together, so it is clear what is with what and what does what! Keeping it clear and easy.


---
## Now to use it in the loop

And again it makes it more compact and easy to understand, as we can get both the duration and movement from the one move struct.

So the loop now looks like
```c++
void loop() {

  int thisIndx = indx%totalSteps;

  //  get this move from 
  Move thisMove = moves[thisIndx];

 // stops all servos for 1 second.
  moveLogic(thisMove.mov, thisMove.dur);

  indx++;

}
```


---
## Test it!

Try to make new moves and different dances, this will help you understand how arrays and structs work!

Maybe see if you can get it to go in a loop, or along a set course.


---
# Well done!

Now you have completed this you can start to think about how you could use this in more complex ways. 

Think about:
- How could you control this from P5?
- What other systems can you choregraph?
- How can you package up and use different data in structs to do more complex things?
