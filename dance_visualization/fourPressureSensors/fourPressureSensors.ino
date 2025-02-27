// Code to measure the pressure sensors in shoes 

// Define the pins and values for the left foot sensors 
int LsensorPin_ball = 1;
int LsensorPin_heel = 2;
int LsensorValue_ball;
int LsensorValue_heel;
int LBallMapped;
int LHeelMapped;

// Define the pins and values for the right foot sensors
int RsensorPin_ball = 4;
int RsensorPin_heel = 5;
int RsensorValue_ball;
int RsensorValue_heel;
int RBallMapped;
int RHeelMapped;

// Define delays for integration with P5.js
int del_60fps = 1000/60;
int del_30fps = 1000/30;
int del_15fps = 1000/15;


// Data initialize 
int data[4];

void setup() {
  // Set up the pins for the sensors 
  Serial.begin(9600);
  pinMode(LsensorPin_ball, INPUT);
  pinMode(LsensorPin_heel, INPUT);
  pinMode(RsensorPin_ball, INPUT);
  pinMode(RsensorPin_heel, INPUT);

}

void loop() {
  LsensorValue_ball=analogRead(LsensorPin_ball);
  LsensorValue_heel=analogRead(LsensorPin_heel);
  RsensorValue_ball=analogRead(RsensorPin_ball);
  RsensorValue_heel=analogRead(RsensorPin_heel);

  data[0] = LsensorValue_ball;
  data[1] = LsensorValue_heel;
  data[2] = RsensorValue_ball;
  data[3] = RsensorValue_heel;

  Serial.println(data[0]);
  
  delay(del_15fps);
// for (int i = 0; i < 4; i = i + 1) {
//       Serial.print(data[i]);
//     }
//     Serial.println();
}

// void loop() {
//   // Measure and print the left foot sensors 
//   LsensorValue_ball=analogRead(LsensorPin_ball);
//   LsensorValue_heel=analogRead(LsensorPin_heel);

//   // Remap the values to account for shoe tightness added pressure 
//   LBallMapped = map(LsensorValue_ball, 1300, 4065, 100, 4095);
//   LHeelMapped = map(LsensorValue_heel, 650, 4065, 100, 4095);

//   // Print the findings in the Serial 
//   Serial.print("LEFT: Ball of Foot Pressure: ");
//   Serial.print(LsensorValue_ball);
// //  Serial.print(LBallMapped);
//   Serial.print(" Heel Pressure: ");
// //  Serial.println(LHeelMapped);
//   Serial.println(LsensorValue_heel);

//   // Measure and print the right foot sensors 
//   RsensorValue_ball=analogRead(RsensorPin_ball);
//   RsensorValue_heel=analogRead(RsensorPin_heel);

//   // Remap the values to account for shoe tightness added pressure 
//   RBallMapped = map(RsensorValue_ball, 1300, 4065, 100, 4095);
//   RHeelMapped = map(RsensorValue_heel, 650, 4065, 100, 4095);

//   // Print the findings in the Serial 
//   Serial.print("RIGHT: Ball of Foot Pressure: ");
//   Serial.print(RsensorValue_ball);
// //  Serial.print(RBallMapped);
//   Serial.print(" Heel Pressure: ");
// //  Serial.println(RHeelMapped);
//   Serial.println(RsensorValue_heel);

//   delay(del_15fps);

// }
