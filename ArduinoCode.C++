const int IRsensor = 7;
int seconds = 0;
int RPM = 0;

void setup(){
    pinMode(IRsensor, INPUT);
    Serial.begin(9600);
}

void loop(){
    int IRsensorState = digitalRead(IRsensor);
    if(IRsensorState == LOW){
        RPM = RPM + 1;
        println(RPM);
    } else if(IRsensorState == HIGH){
        println("Detected nothing");
    }
}

// TODO for Tasmina:
// Implement the seconds variable functionality for it must:
//1. Represent the real world seconds once the arduino starts/
//count the seconds from when the arduino starts
//2. Once the seconds reach 60 seconds, the RPM variable stops counting upwards,
//since it is the RPM measurement in the minute