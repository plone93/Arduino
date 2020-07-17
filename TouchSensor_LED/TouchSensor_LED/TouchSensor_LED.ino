#define touchSensor 3
#define led1 8
#define led2 9
#define led3 10

int count = 0;

void setup() {
  pinMode(touchSensor, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  int value = digitalRead(touchSensor);

  if(value == HIGH){
    digitalWrite(led1, HIGH);
    
    count++;
    Serial.println("터치");

    if(count > 40){
      digitalWrite(led2, HIGH);
    }else if(count > 20){
      digitalWrite(led3, HIGH);
    }
  }else{
    count--;
    Serial.println("대기중");

    if(count < 0){
      count = 0;
    }
    
    if(count <= 0){
      digitalWrite(led1, LOW);
    }else if(count < 20){
      digitalWrite(led2, LOW);
    }else if(count < 40){
      digitalWrite(led3, LOW);
    }
  }
  delay(30);
}
