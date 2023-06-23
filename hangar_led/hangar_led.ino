// hangar_led.ino
// This monitors the motion output from the motion device
// When it detects a high signal, it will turn on the LED

int redPin= 7;
int greenPin = 6;
int bluePin = 5;
int pinMotion = 8;

void setup() {

  Serial.begin(115200);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(pinMotion, INPUT);
}

void loop() {
  int motion_signal;
  
  Serial.println(digitalRead(pinMotion));
  
  //Set default color GREEN
  setColor(0, 255, 0); // Green Color
  delay(1000);

  motion_signal = digitalRead(pinMotion);

  if (motion_signal == HIGH) {
    //setColor(255, 255, 0); // Yellow Color
    //delay(1000);

    setColor(255, 0, 0); // Red Color
    delay(2000);
  }
  
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
