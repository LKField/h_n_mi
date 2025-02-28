import processing.serial.*;
Serial myPort; 

int rows = 2;
int cols = 2;
int maxNumberOfSensors = rows * cols;
float[] sensorValue = new float[maxNumberOfSensors];
float[] previousValue = new float[maxNumberOfSensors];
int rectSize = 0;
int rectY;
float sz1 = 0;
float sz2 = 0;
float sz3 = 0;
float sz4 = 0;
int[] colorR;
int[] colorG;
int[] colorB;

void setup() {
  size(600, 600);
  rectSize = width / rows;

  println(Serial.list());
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
  myPort.bufferUntil('\n');
  background(255);
  smooth();
  rectMode(CORNER);
}

void draw() {
  fill(0);
  textSize(16);

  if (sz1 < 300) {
    for (int i = 0; i < maxNumberOfSensors; i++) {
      sz1 += 0.1;
      text("Left - Ball of Foot", 15, 295);
      stroke(sensorValue[0], 255, 0);
      noFill();
      rect(0, 0, sz1, sz1);
      rect(rectSize * (i % rows), rectY, rectSize, rectSize);
      if ((i + 1) % rows == 0) rectY += rectSize;
    }
  }
  rectY = 0;

  if (sz2 < 300) {
    for (int i = 0; i < maxNumberOfSensors; i++) {
      sz2 += 0.1;
      text("Left - Heel", 315, 295);
      stroke(sensorValue[1], 0, 255);
      noFill();
      rect(width/2, 0, sz2, sz2);
      rect(width/2 + rectSize * (i % rows), rectY, rectSize, rectSize);
      if ((i + 1) % rows == 0) rectY += rectSize;
    }
  }
  rectY = 0;

  if (sz3 < 300) {
    for (int i = 0; i < maxNumberOfSensors; i++) {
      sz3 += 0.1;
      text("Right - Ball of Foot", 15, 595);
      stroke(255, sensorValue[2], 0);
      noFill();
      rect(0, height/2, sz3, sz3);
      rect(rectSize * (i % rows), height/2 + rectY, rectSize, rectSize);
      if ((i + 1) % rows == 0) rectY += rectSize;
    }
  }
  rectY = 0;

  if (sz4 < 300) {
    for (int i = 0; i < maxNumberOfSensors; i++) {
      sz4 += 0.1;
      text("Right - Heel", 315, 595);
      stroke(50, 150, sensorValue[3]);
      noFill();
      rect(width/2, height/2, sz4, sz4);
      rect(width/2 + rectSize * (i % rows), height/2 + rectY, rectSize, rectSize);
      if ((i + 1) % rows == 0) rectY += rectSize;
    }
  }
  rectY = 0;
}

void serialEvent(Serial myPort) {
  String inString = myPort.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
    int incomingValues[] = int(split(inString, "\t"));

    if (incomingValues.length <= maxNumberOfSensors && incomingValues.length > 0) {
      for (int i = 0; i < incomingValues.length; i++) {
        sensorValue[i] = map(incomingValues[i], 500, 4095, 0, 255);
      }
    }
  }
}
