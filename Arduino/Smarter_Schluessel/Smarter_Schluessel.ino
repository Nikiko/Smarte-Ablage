unsigned char alarm_start = -1;
unsigned char alarm_stop = -1;


void setup() {
  Bean.setLed(0,0,0);
  Serial.begin(9600);
  Serial.setTimeout(5);
  //Bean.enableAdvertising( true, 0xFFFFFFFF );
}

void loop() { 
  alarm_start = Serial.read();
  //Serial.println((int)processing_val);
  if(alarm_start == (unsigned char)'A') {
    alarm_stop = -1;
    // Spiele Ton ab solange kein Stopsignal ber ein zweiten Tastendruck oder gesendet wurde oder der Schluessel auf die Ablage gelegt wurde
    while ((alarm_stop != (unsigned char)'A') and (alarm_stop != (unsigned char)'B')) {
      tone(5, 2000, 300);
      delay(600);
      alarm_stop = Serial.read();
    }
  }
 
 // Leuchte Rot bei Verbindungsabbruch
 bool connected = Bean.getConnectionState();
 if ( connected ) {
   Bean.setLed(0,0,0);
 } else {
   Bean.setLed(130,0,0);
 }
}
