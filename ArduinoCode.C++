
const int IRsensor = 7;

unsigned long seconds = 0;
int RPM = 0;

int previousState = HIGH;
bool finished = false;

void setup() {
  pinMode(IRsensor, INPUT);
  Serial.begin(9600);

  previousState = digitalRead(IRsensor);
}

void loop() {

  // Count seconds since Arduino starts
  seconds = millis() / 1000;

  // Read IR sensor
  int IRsensorState = digitalRead(IRsensor);

  // Count rotations for the first 60 seconds
  if (seconds < 60) {

    if (IRsensorState == LOW &&
        previousState == HIGH) {

      RPM = RPM + 1;
      Serial.println(RPM);
    }
  }

  previousState = IRsensorState;

  // Display final RPM once after 60 seconds
  if (seconds >= 60 && !finished) {

    Serial.print("Final RPM: ");
    Serial.println(RPM);

    finished = true;
  }
}
