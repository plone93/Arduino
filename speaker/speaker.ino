#define speaker 12

void setup() {
  pinMode(speaker, OUTPUT);//스피커를 출력으로 설정

}

void loop() {
  unsigned char i;

  while(1){
    for(i = 0; i<8; i++){
      digitalWrite(speaker, HIGH); //디지철 출력 on
      delay(10);// 1000가 1초
      digitalWrite(speaker, LOW); //디지털 출력 off
      delay(10);
    }

    for(i = 0; i<100; i++){
      digitalWrite(speaker, HIGH);
      delay(5);
      digitalWrite(speaker, LOW);
      delay(5);
    }
  }

}
