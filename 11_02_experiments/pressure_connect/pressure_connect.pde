import processing.serial.*;

Serial mySerial;   // Create object from Serial class 

String myString; 
int nl =10;
float myVal;

void setup()
{
  size(800, 600);
  printArray(Serial.list());
  //delay(5000);
  String myPort = Serial.list()[2];
  mySerial = new Serial(this, myPort, 9600);
  
}

void draw()
{
 while (mySerial.available() > 0) {
   myString=mySerial.readStringUntil(nl);
   background(0, 255, 0);
   if (myString != null) {
     
     myVal=float(myString);
     println(myVal);
     circle(width/2, height/2, myVal);
     smooth();
   }
 }
}
