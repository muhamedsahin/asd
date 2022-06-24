#include <SoftwareSerial.h>


SoftwareSerial esp(10, 11);

String delimiter = "/9j/4AAQSkZJRgABAQEAAAAAAAD/2wBDAAoHCAkIBgoJCAkLCwoMDxkQDw4ODx8WFxIZJCAmJ";
String asd = "";

void setup() {
  Serial.begin(19200);
  while (!Serial) {
    ;
  }

  
  esp.begin(19200);
}

void loop() {
  /*
  commy.listen();
  while (commy.available() > 0) {
    char inByte = commy.read();
    Serial.write(inByte);
  }
  // Serial.println();
  
  esp.listen();
  */
  if (asd.lastIndexOf(delimiter) > 1) {
    Serial.println(asd.substring(asd.indexOf(delimiter), asd.lastIndexOf(delimiter)));
    Serial.println("oldu");
    Serial.println(asd);
    asd = asd.substring(asd.lastIndexOf(delimiter), asd.length());
  } else {
    Serial.print("Last index of it===");
    Serial.println(asd.lastIndexOf(delimiter));
    Serial.println(asd);
    
  }
  
  
  //Serial.println(asd);
  
  while (esp.available() > 0) {
/*
    */
    char inByte = esp.read();
    Serial.write(inByte);
    //commy.write(inByte);
    asd += inByte;
    
  }
  

  
  
 
  //Serial.println(asd);
  
  //Serial.println();
  /*
  while (commy.available() > 0) {
    char inByte = commy.read();
    Serial.write(inByte);
  }
  */
  
  // Serial.println();

  
}
