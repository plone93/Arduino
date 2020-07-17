#define Led 13
#define touch 3
int val;

void setup() {
  pinMode(Led, OUTPUT);  // 터치센서 값을 출력
  pinMode(touch, INPUT); // 터치 센서 값을 받아 들임
  Serial.begin(9600); // 9600시리얼 포트 실행

}

void loop() {
  val = digitalRead(touch);//터치센서 값을 val 변수에 대입
  Serial.println(val);

  if(val = HIGH){ // 터치센서에서 읽어들인 값이 있다면
    digitalWrite(Led, HIGH);
  }else{
    digitalWrite(Led, LOW);
  }
}
