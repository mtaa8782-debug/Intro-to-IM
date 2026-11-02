// I am choosing pin 11 to send the signal to the distance sensor.
const int trigPin = 11;

// I am choosing pin 12 to receive the signal back from the sensor.
const int echoPin = 12;

// I am using pin 13 to control my light.
const int lightPin = 13;


// This runs one time when I start the Arduino
void setup() {
  // I am setting the trigger pin as an output because it sends signal.
  pinMode(trigPin, OUTPUT);

  // I am setting the echo pin as an input because it receives signal.
  pinMode(echoPin, INPUT);

  // I am setting the light pin as an output because it controls my light.
  pinMode(lightPin, OUTPUT);
}


// This section repeats when my Arduino is still turned on.
void loop() {
  // I am creating a variable to store how long the sensor signal takes to return.
  long duration;

  // I am creating a variable to store the distance in centimeters.
  int distance;


  // I am making sure the trigger signal starts while it is turned off.
  digitalWrite(trigPin, LOW);

  // waiting for two microseconds before sending the signal.
  delayMicroseconds(2);

  // turning the trigger signal on.
  digitalWrite(trigPin, HIGH);

  // keeping the signal on for ten microseconds.
  delayMicroseconds(10);

  // turning the trigger signal off after sending it.
  digitalWrite(trigPin, LOW);


  // measuring how long it takes for the echo to return.
  duration = pulseIn(echoPin, HIGH);

  // and then converting the echo time into distance in centimeters.
  distance = duration * 0.034 / 2;


  // now I set it so if I am or anyone trying it is closer than 15 centimeters, the LDE turn on.
  if (distance > 0 && distance < 15) {
    digitalWrite(lightPin, HIGH);
  }

  // if farther away then i want my light off.
  else {
    digitalWrite(lightPin, LOW);
  }

  // wait briefly before measuring the distance again.
  delay(100);
}
