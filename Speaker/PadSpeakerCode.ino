/*

  AUdio player based on the tutorial provided by Arduino using Infared sensors
http://arduino.cc/en/Tutorial/SimpleAudioPlayerZero

 Demonstrates the use of the Audio library for the Arduino Zero

 Hardware required :

 * Arduino shield with a SD card on CS4

 * A sound file named "launch.wav" and "PAD.wav" in the root directory of the SD card

 * An audio amplifier to connect to the DAC0 and ground

 * A speaker to connect to the audio amplifier
*/

#include <SD.h>
#include <SPI.h>
#include <AudioZero.h>

int launchSensor = 2;
int padSensor = 3;

void setup()
{
 //Read in inputs from sensors
	pinMode(launchSensor, INPUT);
	pinMode(padSensor, INPUT);

  // debug output at 115200 baud

  Serial.begin(115200);

  // setup SD-card

  Serial.print("Initializing SD card...");
	//if the SD card can't be read, print an error and stop.  
  if (!SD.begin(4)) {

    Serial.println(" failed!");

    while(true);

  }

  Serial.println(" done.");

  // 44100kHz stereo => 88200 sample rate

  AudioZero.begin(2*44100);
}

void loop()
{
	// read in inputs for each sensor
	int padSensorState = digitalRead(padSensor);
	int launchSensorState = digitalRead(launchSensor);

  // open wave files from sdcard

  File padFile = SD.open("Pad.wav");
	File launchFile = SD.open("launch.wav");

  if (!padFile || !launchFile) {

    // if the file didn't open, print an error and stop

    Serial.println("error opening One or more wav files");

    while (true);

  }

  Serial.print("Playing");
	//if the sesnor for the pad is HIGH, play the pad audio file
	if(padSensorState == HIGH){
			Serial.print("Playing PAD audio file");
			AudioZero.play(padFile);
	}
	//if the sesnor for the pad is HIGH, play the pad audio file
	if(launchSensorState == HIGH){
		 Serial.print("Playing LAUNCH audio file");
		 AudioZero.play(launchFile);
	}
}