#include "states.h"
#include "config.h"
#include "Arduino.h"

extern Config config;

void setup() {
  pinMode(config.LED.GREEN_PIN, OUTPUT);
  pinMode(config.LED.RED_PIN, OUTPUT);
  pinMode(config.BUTTON.PIN, INPUT);
  pinMode(config.DEPOT_SPEAKER_PIN, OUTPUT);
  Serial.begin(1200);
}

void loop() {
  state();
  // Drucksensordaten
//  Serial.print("Schluesselmindestgewicht: ");
//  Serial.print(config.PRESSURE.KEY_WEIGHT );
//  Serial.print(", Drucksensor: ");
//  Serial.println(analogRead(config.PRESSURE.PIN));
}
