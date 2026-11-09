int BlueLED = 9;       // The PWM pin connected to my Blue LED
int digitalLED = 13;     // The pin connected to my second LED
int buttonPin = 2;       // The pin connected to my button

int brightness = 0;      // storing the Blue LED brightness

void setup() {
  // for starting the Serial Monitor to see my sensor readings.
  Serial.begin(9600);

  // setting both LEDs as outputs.
  pinMode(BlueLED, OUTPUT);
  pinMode(digitalLED, OUTPUT);

  // setting the button as an input.
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // reading the amount of light reaching my photoresistor.
  int sensorValue = analogRead(A2);

  // limiting the sensor reading to the range I want.
  sensorValue = constrain(sensorValue, 70, 600);

  // if its dark then the candle lights.
  // If there is enough light, the candle can turn completely off.
  if (sensorValue >= 600) {
    brightness = 0;
  } else {
    brightness = map(sensorValue, 70, 600, 255, 0);
  }

  // controlling the brightness of my candle LED.
  analogWrite(BlueLED, brightness);

  // whether the button is pressed.
  int buttonState = digitalRead(buttonPin);

  // second LED turns on only while I press the button.
  if (buttonState == LOW) {
    digitalWrite(digitalLED, HIGH);
  } else {
    digitalWrite(digitalLED, LOW);
  }

  // printing the sensor value to check how the light changes.
  Serial.println(sensorValue);

  // I am waiting briefly before reading the sensor again.
  delay(30);
}