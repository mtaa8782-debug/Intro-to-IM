
 // I chose to coonect the potentiometer to A1.
 //The potentiometer (sensor readings) value controls the horizontal position of the ellipse I used in p5

  // starting serial communication with p5
void setup() {
  Serial.begin(9600);
}

  // for reading the potentiometer value.
void loop() {
  int potentiometer = analogRead(A1);

  // changing the reaidng value from 1023 to 255 (0–255)
  int mappedPotValue = map(potentiometer, 0, 1023, 0, 255);

  // sending the mapped value to p5
  // println also adds a new line character at the end
  Serial.println(mappedPotValue);

  delay(100);
}