//photocell sensor
const int analogInPin = A0;
int sensorValue = 0;
//potentiometer
const int potPin = A1;
int potValue = 0;
//ultrasonic sensor
const int trigPin = 12;
const int echoPin = 13;

void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {

  sensorValue = analogRead(analogInPin);
  potValue = analogRead(potPin);
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.print(potValue);
  Serial.print(" ");
  Serial.println(distance);
  delay(500);

}
