// C++ code
//
int pinSensor =2;
int pinLed =12;
int pinMotion = 7;
int pinBuzzer =13;
int pirSensor =0;

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
    
    // Tell Uno2 there was motion and kick off audio
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
