int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if (switchState == LOW) { // button pressed
    
    digitalWrite(3, HIGH); // green LED
    digitalWrite(4, LOW); // red LED
    digitalWrite(5, LOW); // red LED
  }
 else { // button not pressed
    
    digitalWrite(3, LOW); // green LED
    digitalWrite(4, LOW); // red LED
    digitalWrite(5, HIGH); // red LED

    delay(250); // wait
    
    digitalWrite(4, HIGH); // red LED
    digitalWrite(5, LOW); // red LED

    delay(250); // wait

    
 }

}
