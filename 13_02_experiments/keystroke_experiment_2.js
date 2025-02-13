var move = 0;

function setup() {
  createCanvas(400, 400);
  background('yellow');

  describe('A magenta line on a yellow background that moves in x2 and y1 by 1 until the user presses the "m" key when it will move by 20. When the user presses "ENTER" the drawing clears and restarts.');
  
}

function draw() {
  stroke('magenta');
  strokeWeight(5);
  fill(255,0,0);
  //line(100, move, move, 300);
  ellipse(move, move, move, move)
    
  stroke('black');
  strokeWeight(1);
  fill(255,255,0);

  move = move + 1;
  
}

function keyPressed() {
   if (key === 'm') {
    move = move + 20;
  }
  if (keyCode === ENTER) {
    clear();
    background('yellow');
    move = 0;
  }
}