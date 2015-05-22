int switchState = 0;
int timer = 500;
boolean keyDepressed = true;

void setup() {
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  digitalWrite(5, HIGH);
  while(keyDepressed) {
    switchState = digitalRead(2);
    if (switchState == HIGH) {
      keyDepressed = false;
    }
  }
  keyDepressed = true;
  
  digitalWrite(4, HIGH);
  delay(2000);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  
  while(keyDepressed) {
    switchState = digitalRead(2);
    if (switchState == HIGH) {
      keyDepressed = false;
    }
  } 
  keyDepressed = true;
  
  for  (int  i = 0;  i <  3; i++){
        delay(timer);
        digitalWrite(3, LOW);
        delay(timer);
        digitalWrite(3, HIGH);
      }
    digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(2000);
  digitalWrite(4, LOW);
}  
