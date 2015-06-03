#include "states.h"
#include "config.h"
#include "Arduino.h"

//#include <stdarg.h>
//#include "WProgram.h"

extern Config config;

functionType state = initial;
bool ir_alarm = false;

void initial() {
  // LED gruen leuchten lassen
  analogWrite(config.LED.RED_PIN, 0);
  analogWrite(config.LED.GREEN_PIN, 255);
  state = key_on_depot;
}

void key_on_depot(){
  // Liegt Schluessel nicht mehr auf der Ablage?
  if (analogRead(config.PRESSURE.PIN) < config.PRESSURE.KEY_WEIGHT) {
    // LED rot leuchten lassen
    analogWrite(config.LED.RED_PIN, 130);
    analogWrite(config.LED.GREEN_PIN, 0);
    state = key_apart;
  }
}

char last_button_status = 0;

void key_apart() {
  // Liegt Schluessel wieder auf der Ablage?
  if (analogRead(config.PRESSURE.PIN) >= config.PRESSURE.KEY_WEIGHT){
    // LED gruen leuchten lassen
    analogWrite(config.LED.RED_PIN, 0);
    analogWrite(config.LED.GREEN_PIN, 255);
    // Depot Piepton deaktivieren
    noTone(config.DEPOT_SPEAKER_PIN);
    config.time[0] = 0; 
    state = key_on_depot;
  }
  // Wurde der erste IR Sensor aktiviert?
  if (analogRead(config.INFRARED_1.PIN) > config.INFRARED_1.ACTIVATION_DISTANCE) { 
    // Setze aktuelle Zeit
    config.time[0] = millis();
    // Alarm wurde noch nicht gegeben
    ir_alarm = false; 
  }
  // Sind beide IR Sensoren gleichzeitig aktiviert worden?
  if ((analogRead(config.INFRARED_1.PIN) > config.INFRARED_1.ACTIVATION_DISTANCE) &&
  (analogRead(config.INFRARED_2.PIN) > config.INFRARED_2.ACTIVATION_DISTANCE)) { 
    ir_alarm = true;  //Verhindere, dass Alarmsignal ertoent
  }
  // Wurde der zweite IR Sensor aktiviert waehrend der erste noch auf aktiv gesetzt (ACTIVATION_DURATION noch nicht abgelaufen) war?
  else if ((analogRead(config.INFRARED_2.PIN) > config.INFRARED_2.ACTIVATION_DISTANCE) && 
   ((millis() - config.time[0]) < config.INFRARED_1.ACTIVATION_DURATION) &&
   (ir_alarm == false)) {  
    // Piepton an
    config.time[1] = millis(); 
    tone(config.DEPOT_SPEAKER_PIN, 2000);
    ir_alarm = true;  //Alarm wurde gestartet
    //Serial.print("2");
  } 
  // Ist die Alarmdauer vorbei?
  else if ((millis() - config.time[1]) > config.DEPOT_ALARM_DURATION) {
    // Piepton aus
    noTone(config.DEPOT_SPEAKER_PIN);
  }
  // Wurde der Suchknopf an Ablage betaetigt?
  if (digitalRead(config.BUTTON.PIN) == HIGH) {
    if(last_button_status != HIGH){
      Serial.write((unsigned char)'A');
      last_button_status = HIGH;
    }
  } else {
    //if(button_first) Serial.write((unsigned char)0);
    if(last_button_status != LOW){
      last_button_status = LOW;
    }
  }
  // Befindet sich der Schluessel in der Naehe?
//  if () { 
//    //Bluetooth empfang da?   
//  }
}


