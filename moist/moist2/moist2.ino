int sensorPin = A0;
int red = 13;
int green = 12;
int thresholdUp = 300; //476
int thresholdDown = 500; //

void setup(){
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop(){
  
  int sensorValue;
  String DisplayWords;
  
  sensorValue = analogRead(sensorPin);
  
  Serial.println(sensorValue);
  
  if (sensorValue >= thresholdDown){
      
      DisplayWords = "This plant is thirsty!";
      digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);              // wait for a second
      digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
        delay(1000); 
      Serial.print(DisplayWords);

  } else if (sensorValue <= thresholdUp){ 
      
      DisplayWords = "This plant is too wet!";  
      Serial.print(DisplayWords);
  
  } else {
      DisplayWords = "This plant is OK!";  
      Serial.print(DisplayWords);
       digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
       delay(1000);              // wait for a second
       digitalWrite(green, LOW);    // turn the LED off by making the voltage LOW
       delay(1000); 
  }

  delay(500); //wait for half a second, so it is easier to read
}
