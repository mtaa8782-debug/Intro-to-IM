int ledPin = 5;
int brightness = 0;

void setup() {
  // starting serial communication with p5
  Serial.begin(9600);

  // I chose pin5, so I am setting it as an output for the LED
  pinMode(ledPin, OUTPUT);

  // turning the LED on to check the wiring
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);

  // waiting for p5 to begin sending data
  while (Serial.available() <= 0) {
    digitalWrite(LED_BUILTIN, HIGH);

    // using this function to send a starting value to p5
    Serial.println("0");

    delay(300);

    digitalWrite(LED_BUILTIN, LOW);
    delay(40);
  }
}

  void loop() {
  // checking if p5 sent data.
  if (Serial.available() > 0) {
    digitalWrite(LED_BUILTIN, HIGH);

    // reading brightness value from p5
    int brightnessFromP5 = Serial.parseInt();

    if (Serial.read() == '\n') {
      // keeping the brightness between 0 and 255.
      brightness = constrain(brightnessFromP5, 0, 255);

      // using the value to control the LED brightness
      analogWrite(ledPin, brightness);
    }

    digitalWrite(LED_BUILTIN, LOW);
  }
}