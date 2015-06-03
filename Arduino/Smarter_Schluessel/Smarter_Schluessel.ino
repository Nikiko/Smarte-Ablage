unsigned char processing_val = -1;

void setup() {
  // put your setup code here, to run once:
  Bean.setLed(0,0,0);
  Serial.begin(1200);
  //Bean.enableAdvertising( true, 0xFFFFFFFF );
  Serial.setTimeout(1000);
  //Serial.println("Hello World!");
}

void loop() { 
  processing_val = Serial.read();
  //if(processing_val != 255){
    //Serial.print("Falsches Signal:");
    Serial.println((int)processing_val);
    //delay(200);
  //}
  if(processing_val == (unsigned char)'A') {
    Serial.println("PIIIIIIIEEEEEEP");
    tone(5, 2000, 500);
    delay(500);
  }
  //Bean.sleep(1000); 
 
  //Serial.println(processing_val);
 
 
 
 // Leuchte zur Kontrolle
 bool connected = Bean.getConnectionState();
 if ( connected ) {
   Bean.setLed(0,255,0);
 } else {
   Bean.setLed(130,0,0);
 }
 
 //delay(200);
}
