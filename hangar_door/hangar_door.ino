// hangar_door.ino
// Hangar Door Motion sensor file. This will detect motion and
// set motion pin high and is monitored by the LED device.

int pinSensor = 2;
int pinLed = 12;
int pinMotion = 8;
int pinBuzzer = 13;
int pirSensor = 0;

void setup()
{
  Serial.begin(115200);
  
  pinMode(pinSensor, INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinMotion, OUTPUT);
  
}

void loop()
{
  Serial.println(digitalRead(pinMotion));
  
  pirSensor = digitalRead(pinSensor);
  if (pirSensor == HIGH)
  {
    
    digitalWrite(pinLed, HIGH);

    // Set the motion pin high so the audio and LED devices can activate
    // audio and the LED  
    digitalWrite(pinMotion, HIGH);
    Serial.println(digitalRead(pinMotion));
    
    tone(pinBuzzer, 1000, 500);
  
  }
  
  else {
    
    digitalWrite(pinLed, LOW);
    digitalWrite(pinMotion, LOW);
  }
  
  delay(100);
}
