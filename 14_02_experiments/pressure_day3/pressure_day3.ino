int sensorPin = 1;
int sensorValue;

int del_60fps = 1000/60;
int del_30fps = 1000/30;
int del_15fps = 1000/15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(sensorPin);
  //Serial.println(map(sensorValue, 100, 4095, 0, 200));

  Serial.println(sensorValue);

  delay(del_15fps);

}
