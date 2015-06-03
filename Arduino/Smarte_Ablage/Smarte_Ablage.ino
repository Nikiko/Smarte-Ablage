#include "states.h"
#include "config.h"
#include "Arduino.h"

extern Config config;

void setup() {
  pinMode(config.LED.GREEN_PIN, OUTPUT);
  pinMode(config.LED.RED_PIN, OUTPUT);
  pinMode(config.BUTTON.PIN, INPUT);
  pinMode(config.DEPOT_SPEAKER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  state();
}
