// hangar_door.ino
// Hangar Door Motion sensor file. This will detect motion and
// set motion pin high and is monitored by the LED device.

int pinBreakBeam = 2;
int pinMusicStatus = 4;
int pinLed = 12;
int pinMotionSignal = 8;
int pinBuzzer = 13;
int beamSensorState = 0;
int beamSensorLastState = 0;
int ledDelayTime = 15000; //15000 seconds
unsigned long previousTime = 0;


void setup(){
  Serial.begin(115200);

  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinMotionSignal, OUTPUT);

  pinMode(pinBreakBeam, INPUT_PULLUP);
  //Setup interrupt for break beam sensor
  attachInterrupt (digitalPinToInterrupt (2), detected, FALLING);   

  // Music status
  pinMode(pinMusicStatus, INPUT);

  
}

void detected(){
  //Interrupt detected
  Serial.println("Interrupt detected");
  digitalWrite(pinLed, HIGH);
 
  // Set the motion pin high so the audio and LED devices can activate
  // audio and the LED //Cue audiot 
  digitalWrite(pinMotionSignal, HIGH);
  
}

void loop()
{  
  //Check for the audio complete signal going high, then turn the LED off
  if (digitalRead(pinMusicStatus) == HIGH){
    //music is done, turn the LED off
    digitalWrite(pinLed, LOW);

  }
}
