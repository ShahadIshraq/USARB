#include <SoftwareSerial.h>
#include<Servo.h>

Servo myservo;
int degree=0;
int m;
SoftwareSerial mySerial(D2, D3); //RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  myservo.attach(9);
  delay(15);
  
  myservo.write(10);
  delay(400);
    myservo.detach();
 
}

void loop() {
  m=degree;
  if(Serial.available() > 0){//Read from serial monitor and send over HC-12
    int xinput = Serial.parseInt();
    mySerial.println(xinput);    
  
  }
  if(mySerial.available() > 1){//Read from HC-12 and send to serial monitor
    int xinput = mySerial.parseInt();
    Serial.println(xinput);
      
      if(xinput==5) { Serial.println("downward"); 
      
       myservo.attach(9);
  delay(15);
 
      
      
      
  
  
  
  
  for (; degree <= m+5; degree += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(degree);              // tell servo to go to position in variable 'pos'
    delay(15);  
  }
  
  myservo.detach();
  
  
  
  
  
  

  }

  if(xinput==6) {  Serial.println("Upward");
  myservo.attach(9);
  delay(15);
 
      
      
      
  
  
  
  
  for (; degree >= m-5; degree -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(degree);              // tell servo to go to position in variable 'pos'
    delay(15);  
  }
  
  myservo.detach();
  }

  if(degree>180) degree=180; 
  if(degree<0) degree=0;
 
 
 
}
 
}


