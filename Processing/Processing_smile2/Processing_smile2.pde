import processing.serial.*;
int i = 1;

// Für Statistikausgabe
int search_count = 0;
int search_average = 0;
int smile_width = 0;
float mouth_edges = 0;       
float mouth_middle = 0;    
double noob_scala = 0;      
float noob_percent = 0;

int key_deposit_remember = 0;
int key_deposit_forgot = 0;



Serial port_uno;
Serial port_bean;
char uno_val;

// Bean sollte in der Blutoothliste als Connected stehen!

void setup() {
  size(displayWidth, displayHeight);
  smile_width = displayWidth/8;
  mouth_middle = displayHeight/4;
  
  int port_uno_id = 0;
  int port_bean_id = 0;
  for (String s: Serial.list()) {
    if ((s.substring(s.length()-12).equals("usbmodem1421")) || (s.substring(s.length()-12).equals("usbmodem1411"))) {
      break;
    }
    ++port_uno_id;  
  } 
  for (String s: Serial.list()) {
    if (s.substring(s.length()-14).equals("LightBlue-Bean")) {
      break;
    }
    ++port_bean_id;  
  }
  port_uno = new Serial (this, Serial.list() [port_uno_id], 9600);
  port_bean = new Serial (this, Serial.list() [port_bean_id], 9600); 
   
  port_uno.clear();
  port_bean.clear();
  println(Serial.list());
  smooth();
}


void draw() {
  background (0);
  textSize(46);
  fill(255);
  
  text("Smarte Ablage", displayWidth/1.6, (displayHeight/2)-100); 
  
  textSize(21);
  text("Vergessen Schlüssel abzulegen: " + key_deposit_forgot, displayWidth/1.6, displayHeight/2); 
  text("Schlüssel ordentlich abgelegt: " + key_deposit_remember, displayWidth/1.6, displayHeight/2+50); 
  text("Erinnerungsrate: " + (int)noob_scala + "%", displayWidth/1.6, displayHeight/2+100); 
  ellipse(displayWidth/3, displayHeight/2, displayWidth/3, displayWidth/3);
  
  // Mundwinkel zeichnen die Mundwinkel passen sich dynamisch an
  strokeWeight(15);
  bezier(   
    (displayWidth/3)-(smile_width),                  (displayHeight/2)+mouth_edges, 
    (displayWidth/3)-(smile_width*0.75),             (displayHeight/2)+mouth_middle, 
    (displayWidth/3)+(smile_width*0.75),             (displayHeight/2)+mouth_middle, 
    (displayWidth/3)+(smile_width),                  (displayHeight/2)+mouth_edges
  );
  
  fill(0);
  ellipse(displayWidth/3-displayWidth/18, displayHeight/2-displayHeight/8, displayWidth/26, displayHeight/12);
  ellipse(displayWidth/3+displayWidth/18, displayHeight/2-displayHeight/8, displayWidth/26, displayHeight/12);
}


void serialEvent (Serial port) {
  if (port_uno.available() > 0) {
    char serial_val = port.readChar();
    if((int)serial_val != 0) {
      print("Sent "); 
      println(serial_val); 
      ++i;
    }
    if ((serial_val == 65) || (serial_val == 66)) {
      port_bean.write(serial_val);
    }
    if (serial_val == 84) {
      ++key_deposit_forgot;
      if (key_deposit_forgot != 0){
        noob_scala = (((double)key_deposit_remember * 100)/ ((double)key_deposit_remember + (double)key_deposit_forgot));
        mouth_edges = map((float)noob_scala, 0, 100, displayHeight/8, 0);
        mouth_middle = map((float)noob_scala, 0, 100, -displayHeight/10, displayHeight/4);
      }
    }
    if (serial_val == 71) {
      ++key_deposit_remember;
      noob_scala = (((double)key_deposit_remember * 100)/ ((double)key_deposit_remember + (double)key_deposit_forgot));
      mouth_edges = map((float)noob_scala, 0, 100, displayHeight/8, 0);
      mouth_middle = map((float)noob_scala, 0, 100, -displayHeight/10, displayHeight/4);
    }
  }
}


