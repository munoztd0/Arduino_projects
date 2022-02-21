// CAT TOY

#include <Servo.h> //Loading the servo library


//ULTRASONIC SENSOR
int pingPin=8;  //set untrasonic sensor to pin 8
float pingTime;   //sets pingTime as a float
float pingDistance; //sets pingDistance as a float
float speedOfSound = 0.0135039; //inches per second,
int playDistance = 32;  // distance in inches that triggers the toy
float catFound;     // distance in which the cat was found that triggered the toy. For testing purposes.

//LEDS
int greenLed=5;  //sets green LED to pin 5
int redLed=3;   //sets red LED it pin 3

//SERVO
int pos=82;  // declare and initialize the pos variable for the servo position. 82 is the middle~ of this specific servo's range. Servo's range is 2 - 165.
int servoPin=9; // tell arduino that servo is hooked up to pin 9
float waitTime;// how log the servo waits for before shaking again
int waitMin = 1000; // sets minimum wait time
int waitMax = 3000; // sets maximum wait time
Servo myServo;  // creates the servo object within arduino
int counter;    // counter for servo loop
int repeat = 10; //how many times the servo moves before scanning for the cat again


void setup() {

myServo.attach(servoPin); //connects servo to arduino

Serial.begin (9600);  //connects arduino to computer over usb
Serial.print ("Welcome to the cat toy serial monitor");  //this is for if the arduino is plugged into a computer for testing
Serial.println(" ");

myServo.write(pos);            // centers the servo

Serial.print("servo set to ");  // displaying servo information for diagnostic purposes
Serial.print(pos);
Serial.println(" ");

analogWrite (greenLed, 255);    //turn on leds for visual que
analogWrite (redLed, 255);    // I used analog controls for this because digital wasn't turning them on brightly enough. 

delay (2000);   // wait for leds

analogWrite (greenLed, 0);    //turn off leds
analogWrite (redLed, 0);

delay(50);     // wait for leds

}


void loop() {

//LOOPING ULTRASONIC PING WHILE WAITING FOR CAT///////////////////

do{

analogWrite(greenLed, 255); //turn on green led
analogWrite(redLed, 0); //turn off red led

counter = 1;                    // resets counter to 1

Serial.print ("Ultrasonic sensor is currently scaning"); //telling the serial monitor what step of the program is happening
Serial.println(" ");

pinMode (pingPin, OUTPUT);    // sets pingPin to output
digitalWrite (pingPin, LOW);    //produces no signal for 10 microseconds for a clean signal
delayMicroseconds(10);
digitalWrite (pingPin, HIGH);   //produces a ping signal for 5 microseconds
delayMicroseconds(5);
digitalWrite(pingPin, LOW);   //stops the ping signal
pinMode(pingPin, INPUT);      // Sets the pingPin to input to receive the ping signal
pingTime = pulseIn(pingPin, HIGH); // collects pingTime data

pingDistance = (speedOfSound*pingTime)/2;  //calculates distance

catFound = pingDistance;

Serial.print ("time = ");       // printing things for diagnostic purposes
Serial.print (pingTime);
Serial.println(" ");
Serial.print ("distance = ");
Serial.print (pingDistance);
Serial.println(" ");

// delay (1000);  // turn on an off with comments to help read terminal better

}
while ((pingDistance>=playDistance)); //end of do while loop

// LOOPING WHILE ULTRASONIC SENSOR IS TRIPPED  //////////////////////////////

do{

analogWrite(greenLed, 0);   //turn off green led
analogWrite(redLed, 255);   //turn on red led

Serial.print("Cat found at ");      // printing to help diagnostics
Serial.print(catFound);
Serial.println(" ");
Serial.print("currently on cycle ");
Serial.print(counter);
Serial.println(" ");

//randomSeed(analogRead (A1));  // Reads voltage of A1 to create random number. currently disabled cause was somehow getting stuck on 1 number.
pos = (random (2, 100));    // creates random location to move servo to 166
myServo.write(pos);         // moves servo to that location

Serial.print("Servo set to ");  // printing to console to help diagnostics
Serial.print(pos);
Serial.println(" ");

waitTime=(random (waitMin, waitMax));  // setting a random wait time

Serial.print("waiting for ");  // displaying the selected random wait time to the console
Serial.print(waitTime);
Serial.println(" ");

delay(waitTime);  // waiting for the randomly selected wait time.

counter = counter+1;  // adding 1 to the counter that determines the loop exit

}
while (counter <= repeat);   // checking the counter to determine if the loop exits

} // End of program
