#include "config.h"

// Einstellungen
Config config = {
  .DEPOT_SPEAKER_PIN = 8,
  .DEPOT_ALARM_DURATION = 100,
  //.SERIAL_PORT = 
  
  .LED = {
    .GREEN_PIN = 9,
    .RED_PIN = 13,
    .BLINK_INTERVALL = 1220
  },
  
  .INFRARED_1 = {
    .PIN = 0,
    .ACTIVATION_DISTANCE = 200,        // Distanz ab wann die Lichtsensoren aktiviert werden, je groesser der Wert desto kleiner die Distanz
    .ACTIVATION_DURATION = 1000        // In welchem Zeitfenster in Millisekunden muss Infrared 2 aktiviert werden, um Alarm auszugeben? 
  },

  .INFRARED_2 = {
    .PIN = 1,
    .ACTIVATION_DISTANCE = 200         // Distanz ab wann die Lichtsensoren aktiviert werden, je groesser der Wert desto kleiner die Distanz
  },
  
  .BUTTON = {
    .PIN = 2,
  },
  
  .PRESSURE = {
  .PIN = 2,
  .KEY_WEIGHT = 500                   // Mindestgewicht ab wann die Ablage den Schluessel erkennt
  }
};


