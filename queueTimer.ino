/*
  2017 ROT queue timer
*/

// constants won't change. Used here to set a pin number:
const int load1pin = 2;// the number of the LED pin
const int load2pin = 3;
const int load3pin = 4;

const int unload1pin = 5;
const int unload2pin = 6;
const int unload3pin = 7;

const int vid130pin = 8;
const int vid145pin = 9;
const int vid160pin = 10;

const int vid230pin = 11;
const int vid245pin = 12;
const int vid260pin = 13;

const int vid330pin = 14;
const int vid345pin = 15;
const int vid360pin = 16;

const int sel45pin = 17;
const int sel60pin = 18;

// Variables will change:
int sel45 = 0;
int sel60 = 0;
int blink = 0;


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store

// constants won't change:

void setup() {
  Serial.begin(9600);
  Serial.println("Setting up pins");
  // set the digital pin as output:
  int outMin = 2;
  int outMax = 16;
  for (int o = outMin; o <= outMax; o++)
  {
    pinMode(o, OUTPUT);
    digitalWrite(o, HIGH);
  }
  pinMode(sel45pin, INPUT_PULLUP);
  pinMode(sel60pin, INPUT_PULLUP);
}

// functions
  int pad() {
    sel45 = digitalRead(sel45pin);
    sel60 = digitalRead(sel60pin);
    Serial.println("Polling time selection - pin17 = 45s | pin18 = 60s");
    if (sel45 == LOW) {
      return 15000;
      Serial.println("45sec selected");
    }
    else if (sel60 == LOW) {
      return 30000;
      Serial.println("60sec selected");
    }
    else {
      return 0;
      Serial.println("30sec selected");
    }
  }
void loop() {
  // here is where you'd put code that needs to be running all the time.
  
  pad();
  // 0 SECOND POSITION
  
  Serial.println("turn ON LOAD-1 | OFF UNLOAD-1");
  digitalWrite(load1pin, LOW);
  digitalWrite(unload1pin, HIGH);
  if (sel45 == LOW){
    digitalWrite(vid145pin, LOW);
    Serial.println("Start vid145");
  }
  else if (sel60 == LOW){
    digitalWrite(vid160pin, LOW);
    Serial.println("Start vid160");
  }
  else {
    digitalWrite(vid130pin, LOW);
    Serial.println("Start vid130");
  }
  Serial.println("delay 15s");
  delay(15000);

  // 15 SECOND POSITION
  
  Serial.println("turn OFF LOAD-1 | ON UNLOAD-2 | OFF vid1");
  digitalWrite(load1pin, HIGH);
  digitalWrite(unload2pin, LOW);
  digitalWrite(vid130pin, HIGH);
  digitalWrite(vid145pin, HIGH);
  digitalWrite(vid160pin, HIGH);

  Serial.print("delay15s + ");
  Serial.print(pad());
  Serial.println("ms");
  //delay(15000);

  // 3 SECONDS OF FLASHING THE DOOR LIGHTS
  
  blink = 0;
  while(blink < 15){
    digitalWrite(unload2pin, LOW);
    delay(100);
    digitalWrite(unload2pin, HIGH);
    delay(100);
    blink++;
  }
  delay(27000);
  delay(pad());

  Serial.println("turn ON LOAD-2 | OFF UNLOAD-2");
  digitalWrite(load2pin, LOW);
  digitalWrite(unload2pin, HIGH);
  if (sel45 == LOW){
    digitalWrite(vid245pin, LOW);
    Serial.println("Start vid245");
  }
  else if (sel60 == LOW){
    digitalWrite(vid260pin, LOW);
    Serial.println("Start vid260");
  }
  else {
    digitalWrite(vid230pin, LOW);
    Serial.println("Start vid230");
  }

  Serial.println("delay 15s");
  delay(15000);

  Serial.println("turn OFF LOAD-2 | ON UNLOAD-3 | OFF vid2");
  digitalWrite(load2pin, HIGH);
  digitalWrite(unload3pin, LOW);
  digitalWrite(vid230pin, HIGH);
  digitalWrite(vid245pin, HIGH);
  digitalWrite(vid260pin, HIGH);

  Serial.print("delay15s + ");
  Serial.print(pad());
  Serial.println("ms");
  //delay(15000);
  blink = 0;
  while(blink < 75){
    digitalWrite(unload3pin, LOW);
    delay(100);
    digitalWrite(unload3pin, HIGH);
    delay(100);
    blink++;
  }
  delay(pad());

  Serial.println("turn ON LOAD-3 | OFF UNLOAD-3");
  digitalWrite(load3pin, LOW);
  digitalWrite(unload3pin, HIGH);
  if (sel45 == LOW){
    digitalWrite(vid345pin, LOW);
    Serial.println("Start vid345");
  }
  else if (sel60 == LOW){
    digitalWrite(vid360pin, LOW);
    Serial.println("Start vid360");
  }
  else {
    digitalWrite(vid330pin, LOW);
    Serial.println("Start vid330");
  }

  Serial.println("delay 15s");
  delay(15000);

  Serial.println("turn OFF LOAD-3 | ON UNLOAD-1 | OFF vid3");
  digitalWrite(load3pin, HIGH);
  digitalWrite(unload1pin, LOW);
  digitalWrite(vid330pin, HIGH);
  digitalWrite(vid345pin, HIGH);
  digitalWrite(vid360pin, HIGH);

  Serial.print("delay15s + ");
  Serial.print(pad());
  Serial.println("ms");
  //delay(15000);
  blink = 0;
  while(blink < 75){
    digitalWrite(unload1pin, LOW);
    delay(100);
    digitalWrite(unload1pin, HIGH);
    delay(100);
    blink++;
  }
  delay(pad());

}
