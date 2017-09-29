/*
  2017 ROT queue timer
*/

// constants won't change. Used here to set a pin number:
const int load1pin = 2;// the number of the LED pin
const int load2pin = 3;
const int load3pin = 4;

const int vid1pin = 5;
const int vid2pin = 6;
const int vid3pin = 7;

const int sel60pin = 17;
const int sel75pin = 18;

// Variables will change:
int sel60 = 0;
int sel75 = 0;
int blink = 0;


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store

// constants won't change:

void setup() {
  Serial.begin(9600);
  Serial.println("Setting up pins");
  // set the digital pin as output:
  int outMin = 2;
  int outMax = 7;
  for (int o = outMin; o <= outMax; o++)
  {
    pinMode(o, OUTPUT);
    digitalWrite(o, HIGH);
  }
  pinMode(sel60pin, INPUT_PULLUP);
  pinMode(sel75pin, INPUT_PULLUP);
}

// functions
int pad() {
  sel60 = digitalRead(sel60pin);
  sel75 = digitalRead(sel75pin);
  Serial.println("Polling time selection - pin17 = 60s | pin18 = 75s");
  if (sel60 == LOW) {
    return 15000;
    Serial.println("60sec selected");
  }
  else if (sel75 == LOW) {
    return 30000;
    Serial.println("75sec selected");
  }
  else {
    return 0;
    Serial.println("45sec selected");
  }
}
void loop() {
  // 0 second position

  // read pad variable into memory
  int padT = pad();
  // insert padding as necessary for selected time
  Serial.print("PAD delay ");
  Serial.print(padT / 1000);
  Serial.println("s");
  delay(padT);

  Serial.println("turn ON LOAD-1 | ON Vid-1");
  digitalWrite(load1pin, LOW);
  digitalWrite(vid1pin, LOW);

  Serial.println("delay 15s");
  delay(15000);

  // 15 SECOND POSITION

  Serial.println("turn OFF LOAD-1 | OFF Vid-1");
  digitalWrite(load1pin, HIGH);
  digitalWrite(vid1pin, HIGH);

  Serial.println("delay 30s");
  delay(30000);

  // insert padding as necessary for selected time
  Serial.print("PAD delay ");
  Serial.print(padT / 1000);
  Serial.println("s");
  delay(padT);

  // 45 SECOND POSITION
  
  Serial.println("turn ON LOAD-2 | ON Vid-2");
  digitalWrite(load2pin, LOW);
  digitalWrite(vid2pin, LOW);

  Serial.println("delay 15s");
  delay(15000);

  // 60 SECOND POSITION

  Serial.println("turn OFF LOAD-2 | OFF vid2");
  digitalWrite(load2pin, HIGH);
  digitalWrite(vid2pin, HIGH);

  Serial.println("delay 30s");
  delay(30000);

  // insert padding as necessary for selected time
  Serial.print("PAD delay ");
  Serial.print(padT / 1000);
  Serial.println("s");
  delay(padT);

  // 90 SECOND POSITION

  Serial.println("turn ON LOAD-3 | ON Vid-3");
  digitalWrite(load3pin, LOW);
  digitalWrite(vid3pin, LOW);

  Serial.println("delay 15s");
  delay(15000);

  // 105 SECOND POSITION

  Serial.println("turn OFF LOAD-3 | OFF Vid-3");
  digitalWrite(load3pin, HIGH);
  digitalWrite(vid3pin, HIGH);

  Serial.println("delay 30s");
  delay(30000);

  // BACK TO 0 OR PAD

}
