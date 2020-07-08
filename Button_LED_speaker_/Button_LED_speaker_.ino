#define Button 12
#define Speaker 8

void setup() {
  pinMode(Button, INPUT);//버튼 값을 받아들임
  pinMode(Speaker, OUTPUT);//스피커로 출력을함
  Serial.begin(9600);
}

void loop() {
  Serial.print(digitalRead(Button));//버튼이 현재 무슨값인지 시리얼 포트를 통해출력
  if(digitalRead(Button) == HIGH){//만약 디지털핀()번째 값이 on이라면
    digitalWrite(Speaker, HIGH); // 스피커를 재생
  }else{//아니면
    digitalWrite(Speaker, LOW); // 멈춤
  }

}
