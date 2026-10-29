const int IRsensor = 6;

unsigned long seconds = 0;
float RPM_count = 0;

int previousState = HIGH;
bool finished = false;

void setup() {
  pinMode(IRsensor, INPUT);
  Serial.begin(230400);

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

      RPM_count = RPM_count + 1;
      Serial.println(RPM_count);
    }
  }

  previousState = IRsensorState;

  // Display final RPM once after 60 seconds
  if (seconds >= 60 && !finished) {

    Serial.print("Final RPM: ");
<<<<<<< HEAD
    Serial.println(RPM/3);
=======
    Serial.println(RPM_count/3);
>>>>>>> 1344a974fbe565aae9ffa52efe3c668fcc391df5

    finished = true;
  }
}
