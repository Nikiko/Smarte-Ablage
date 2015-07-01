#include "config.h"

// Einstellungen
Config config = {
  .DEPOT_SPEAKER_PIN = 8,
  .DEPOT_ALARM_DURATION = 100,
  .PLACE_KEY_ON_DEPOT_TIME = 15000,     // Zeit um Schlssel auf die Ablage zu legen (Wird in Statistik als ordentlich Abgelegt gezaehlt)
  //.SERIAL_PORT = 
  
  .LED = {
    .GREEN_PIN = 9,
    .RED_PIN = 13,
    .BLINK_INTERVALL = 1220
  },
  
  .INFRARED_1 = {
    .PIN = 0,
    .ACTIVATION_DISTANCE = 250,        // Distanz ab wann die Lichtsensoren aktiviert werden, je groesser der Wert desto kleiner die Distanz
    .ACTIVATION_HOLD = 300,            // Wie lange muss ein Signal erfasst werden damit es den Timer aktiviert?
    .ACTIVATION_DURATION = 1000        // In welchem Zeitfenster in Millisekunden muss Infrared 2 aktiviert werden, um Alarm auszugeben? 
  },

  .INFRARED_2 = {
    .PIN = 1,
    .ACTIVATION_DISTANCE = 250         // Distanz ab wann die Lichtsensoren aktiviert werden, je groesser der Wert desto kleiner die Distanz
  },
  
  .BUTTON = {
    .PIN = 2,
  },
  
  .PRESSURE = {
  .PIN = 2,
  .KEY_WEIGHT = 700                   // Mindestgewicht ab wann die Ablage den Schluessel erkennt
  }
};


