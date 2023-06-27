// hangar_door.ino
// Hangar Door Motion sensor file. This will detect motion and
// set motion pin high and is monitored by the LED device.

int pinBreakBeam = 2;
int pinLed = 12;
int pinMotionSignal = 8;
int pinBuzzer = 13;
int beamSensorState = 0;
int beamSensorLastState = 0;
int ledDelayTime = 15000; //15000 seconds
unsigned long previousTime = 0;


void setup()
{
  Serial.begin(115200);

  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinMotionSignal, OUTPUT);

  pinMode(pinBreakBeam, INPUT_PULLUP);
  //Setup interrupt for break beam sensor
  attachInterrupt (digitalPinToInterrupt (2), detected, FALLING);   
  
}

void detected ()
{
  //Interrupt detected
  Serial.println("Interrupt detected");
  digitalWrite(pinLed, HIGH);
  
  //start time to turn off LED after 15s
  //delayMicroseconds(100000000);
  //digitalWrite(pinLed, LOW);

  bool temp = false;
  while(!temp){
    temp = ledTimer();
  }

  // Set the motion pin high so the audio and LED devices can activate
  // audio and the LED //Cue audiot 
  digitalWrite(pinMotionSignal, HIGH);
}

  
}
void loop()
{  

}
