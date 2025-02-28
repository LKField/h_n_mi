/*
Example for H(n)MI Workshop
MDEF IAAC class 2025.
With this example, we are going to explore how to register data related to time. 
We will ise the Web Serial library for serial communication.
Documentation: https://github.com/gohai/p5.webserial
For this exercise you will need to have already working your soft sensor connected to a microcontroller.

 */
// Serial communication and reading values
let port;
let lecture = 0;
let val = 0;
let connectBtn;

let diameter; // diameter of the circle
let connected = 0; // boolean variable

// Drawing with time variables
let actualTime, previousTime;
let x, y;
let period = 1000;
let margin = 20;
let sz = 0;
let colorG;

function setup() {
  // The size of the canvas
  createCanvas(600, 600);

  //Configuration for serial communication
  port = createSerial();
  connectBtn = createButton("Connect Serial");
  connectBtn.position(width / 2, height / 2);
  connectBtn.mousePressed(connectBtnClick);

  // My configuration
  background(0);
  previousTime = millis();
//  x = margin;
  x = width/2;
  y = height/2;
}

function draw() {
  // Calling functions for serial communication (don't erase them)
  readingSerial();
  serialConnected();

  // Project functions or instructions

  if (connected == 1) {
    // If we have already connected the serial port, then.. do...

    // Calculating Time
//    actualTime = millis();
//    if (actualTime - previousTime >= period) {
//      print("1 sec!");
//      previousTime = millis();
//      x = x + width / 60; // x+(width divided by 60 seconds)
//    }

    if (x>= width-margin) {
      save("myData"+frameCount+".jpg");
      noLoop();
    }
    
    
    if (sz>= width-margin) {
      save("myData"+frameCount+".jpg");
      noLoop();
    }


//    sz = map(val, 0, 4000, 5, 400);
    sz = sz + 1;
    colorR = map(val, 500, 4095, 10, 255);
    colorB = map(val, 500, 4095, 255, 10);

    stroke(colorR, 0, colorB);
    noFill();
    circle(x, y, sz);
  }
} // -- draw loop ends

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

/* These functions are related to the webSerial library
and are responsible for stabishing connection with your USB ports and the browser. We recommend not to modify them.*/

function serialConnected() {
  if (!port.opened()) {
    connectBtn.html("Connect Serial");
  } else {
    connectBtn.hide();
    connected = 1;
  }
}

function connectBtnClick() {
  if (!port.opened()) {
    port.open(9600);
  } else {
    port.close();
  }
}

function readingSerial() {
  if (port.available() > 0) {
    lecture = port.readUntil("\n");
    if (lecture) {
      lecture = int(lecture);
      console.log(val);
      val = lecture;
    }
  }
}
