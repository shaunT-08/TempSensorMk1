#include <Arduino.h>
#include <SHT1x-ESP.h>

// Function to Run: Scans temperature, if temperature is above 50 degrees, the LED flashes red, and if below 50 degrees
// the LED flashes green

// SHT1x Sensor -> D5 and D6 on Arduino -> D3 and D4 -> LED

// Defining the Data and Clock pins
// The data pin carries the actual data, while the clock pin provides a 
// continous signal to maintain coherence between the sensor and the Arduino

#define dataPin data
#define clockPin SCK // SCK pin used for SPI communication

// Declaring the SHT1x sensor as an object
// that outputs to the D5 and D6 pins on the Aruduino
SHT1x sht1x(D5, D6);

// put function declarations here:
boolean tempToLED(float tempF); // Function is defined

void setup() {
  // put your setup code here, to run once:
  
  // Initializes Baud Rate, the rate of data transfer
  Serial.begin(9600);

  // Initializing output pins
  pinMode(D3, OUTPUT); 
  pinMode(D4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float tempinF = sht1x.readTemperatureF();

  if (tempToLED(tempinF)) {

    digitalWrite(D4, HIGH);
    digitalWrite(D3, LOW);
    delay(1000); // delay for 1 second (1000 milliseconds)

  } else {

    digitalWrite(D4, LOW);
    digitalWrite(D3, HIGH);
    delay(1000); // delay for 1 second (1000 milliseconds)

  }
}

// put function definitions here:

// Arduino has to output to the D3 and D4 pins to the LEDs
boolean tempToLED(float tempF) {
  
  if (tempF > 50) {
    return true;

  } else if (tempF < 50) {
    return false;

  }

}