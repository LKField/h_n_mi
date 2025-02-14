let prevTime;
let actualTime;
let x, y;
let diameter=10;

function setup() {
  createCanvas(640, 400);
  background(220);
  prevTime = millis();
  x = 20;
  y = 40;
  
}

function draw() {
  actualTime = millis();
  fill(y, (255 - y), y);
  
  if ((actualTime-prevTime) >= 1000) {
    print("1 second!", actualTime);
    prevTime = actualTime;
    x += 10;

    if (x >= 600) {
      x = 20;
      y += 20;
    }
  }
  
  number = str(x/10);
  circle(x, y, diameter);
  
  fill(0);
  textSize(8);
  text(number, (x-4), (y-10));
  
  
}

function keyPressed() {
  if (key=='s') {
    save("myData" + frameCount + ".jpg");
    print("myData" + frameCount + ".jpg saved");
    
  }
}