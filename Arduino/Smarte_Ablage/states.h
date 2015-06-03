#ifndef STATES_H
#define STATES_H

#include "HardwareSerial.h"
//#include "Arduino.h"

typedef void (*functionType)();

void initial();
void key_on_depot();
void key_apart();
void key_at_home();

extern functionType state; 

#endif
