#ifndef CONFIG_H
#define CONFIG_H


typedef struct Led {
  const int GREEN_PIN;
  const int RED_PIN;
  const int BLINK_INTERVALL;
} Led;

typedef struct Infrared_1 {
  const int PIN;
  const int ACTIVATION_DISTANCE;
  const int ACTIVATION_HOLD;
  const int ACTIVATION_DURATION;  
} Infrared_1;

typedef struct Infrared_2 {
  const int PIN;
  const int ACTIVATION_DISTANCE;            
} Infrared_2;

// Button
typedef struct Button {
  const int PIN;
} Button;

// Drucksensor
typedef struct Pressure {
  const int PIN;
  const int KEY_WEIGHT;          // Mindestgewicht ab wann die Ablage den Schluessel erkennt
} Pressure;

typedef struct Config {
  const int DEPOT_SPEAKER_PIN;
  const int DEPOT_ALARM_DURATION;              // Die Dauer des Pieptons
  //const Serial SERIAL_PORT;
//  const int DEPOT_ALARM_PAUSE;
  const Led LED;
  const Infrared_1 INFRARED_1;
  const Infrared_2 INFRARED_2;
  const Button BUTTON;
  const Pressure PRESSURE;
  unsigned long time[5];                  // Timer 
  const int PLACE_KEY_ON_DEPOT_TIME;
} Config; 

#endif
