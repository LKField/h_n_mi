int sensorPin = A0;
int sensorValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue=analogRead(sensorPin);
Serial.println(sensorValue);
}
