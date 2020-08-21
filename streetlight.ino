const int buttonPin=2;
int buttonState=LOW;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(buttonPin);
  int light=analogRead(A0);
  int man=analogRead(A2);
  
  if((buttonState==HIGH)||((man!=0)&&(light<=500)))
  {
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
 // delay(1000);                       // wait for a second
  }
  else{
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
 // delay(1000);                       // wait for a second
  }
  Serial.println(light);
  delay(500);  
  //Serial.println(light);
 // delay(500);     

}
