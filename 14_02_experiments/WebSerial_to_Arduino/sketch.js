/*
Example for H(n)MI Workshop
MDEF IAAC class 2025.
With this example, we are going to learn how receive
 data from our sensors using the Web Serial library for serial communication.
Documentation: https://github.com/gohai/p5.webserial
 For this exercise you will need to have already working your soft sensor connected to a microcontroller.

 */

//Serial communication variables
let port;
let lecture = 0;
let val = 0;
let connectBtn;

// My Variables
let diameter;
let colorR;
let colorG;
let colorB;
let colorHex;

/* --------- SETUP --------- */
function setup() {
  createCanvas(400, 400);
  port = createSerial();
  connectBtn = createButton("Connect Serial");
  connectBtn.position(290, 370);
  connectBtn.mousePressed(connectBtnClick);

  // My configuration
}

/* --------- DRAW --------- */
function draw() {
  readingSerial();
  serialConnected();
  background(50, 100, 255);
  
  // Change the color with press 
  colorR=map(val, 0, 4095, 10, 250);
  colorG=map(val, 0, 4095, 100, 200);
  colorB=map(val, 0, 4095, 10, 255);
  
  fill(colorR, 255, 255);

  diameter=map(val, 0, 4095, 0, width); // change the diameter with press 
  circle(width/2, height/2, diameter);
}

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
