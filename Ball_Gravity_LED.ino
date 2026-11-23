int potPin = A1;
int ledPin = 5;

unsigned long previousMillis = 0;
const long interval = 50;

void setup() {
  // starting serial communication with p5
  Serial.begin(9600);

  // setting the potentiometer as an analog input
  pinMode(potPin, INPUT);

  // LED as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // checking whether p5.js sent a message
  if (Serial.available() > 0) {
    // reading whether the LED should be on or off
    int ledState = Serial.parseInt();

    if (Serial.read() == '\n') {
      // turning the LED on or off based on the message
      digitalWrite(ledPin, ledState);
    }
  }

  // checking the current time.
  unsigned long currentMillis = millis();

  // now sending sensor data every 50 milliseconds
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // reading the potentiometer value from 0 to 1023
    int potValue = analogRead(potPin);

    // here I am changing the value to a range from 0 to 255
    int mappedPotValue = map(potValue, 0, 1023, 0, 255);

    // sending the potentiometer value to p5
    Serial.println(mappedPotValue);
  }
}