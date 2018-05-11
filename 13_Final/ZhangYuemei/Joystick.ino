int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

int offset = 250;

void setup() {
  Serial.begin(9600); 
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin, INPUT_PULLUP); 
  
}

void loop() {
  
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  
  if(xPosition < (512 + offset) && xPosition > (512 - offset)){
    if(yPosition >= 0 && yPosition < (512 - offset)){
      Serial.write(3);
      }
    if(yPosition > (512 + offset) && yPosition < 1024){
      Serial.write(1);
      }
    }

  if(yPosition > (512 - offset) && yPosition < (512 + offset)){
    if(xPosition >= 0 && xPosition < (512 - offset)){
      Serial.write(4);
      }
    if(xPosition > (512 + offset) && xPosition < 1024){
      Serial.write(2);
      }
    }

//  Serial.println(buttonState);
  if(buttonState == 0){
    Serial.write(5);
    }

    delay(150);
}
