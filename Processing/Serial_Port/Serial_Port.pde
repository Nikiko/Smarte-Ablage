import processing.serial.*;

Serial port_uno;
Serial port_bean;
char uno_val;

// Vorher unbedingt mit Bean Connecten, ansonsten läuft es nicht!
// Bean sollte in der Blutoothliste als Connected stehen!

void setup() {
  int port_uno_id = 0;
  int port_bean_id = 0;
  for (String s: Serial.list()) {
    if (s.substring(s.length()-12).equals("usbmodem1411")) 
      break;
    ++port_uno_id;  
  }
  for (String s: Serial.list()) {
    if (s.substring(s.length()-14).equals("LightBlue-Bean")) 
      break;
    ++port_bean_id;  
  }
  
  port_uno = new Serial (this, Serial.list() [port_uno_id], 1200);
  port_bean = new Serial (this, Serial.list() [port_bean_id], 1200); 
   
  port_uno.clear();
  port_bean.clear();
  println(Serial.list());
}
char a = 1;

void draw() {
  println((int)a);  
   port_bean.write(a);
   port_bean.write(a);
   ++a;
   if(a == 255) a = 1;
}

void serialEvent (Serial port) {
  if (port_uno.available() > 0) {
    char uno_val2 = port.readChar();
    if((int)uno_val != 255)
      println(str(uno_val) + " " + str((int)uno_val) );
    if(uno_val2 != uno_val && uno_val2 != 10 && uno_val2 != 13){
      uno_val = uno_val2;
      port_bean.write(uno_val);
      if((int)uno_val != 0) {
        println((int)uno_val);  
      }
    }
    
  }
}
