#define a 7
#define b 6
#define c 5
#define d 10
#define e 11
#define f 8
#define g 9
#define dp 4

void setup() {
  for(int i=4; i<11; i++){
    pinMode(i, OUTPUT);//위에서 선언된 핀번호를 반복문을 통해 설정
  }

}

void loop() {
  while(1){
        digital_0();
        delay(1000);
        digital_1();
        delay(1000);
        digital_2();
        delay(1000);
        digital_3();
        delay(1000);
        digital_4();
        delay(1000);
        digital_5();
        delay(1000);
        digital_6();
        delay(1000);
        digital_7();
        delay(1000);
        digital_8();
        delay(1000);
        digital_9();
        delay(1000);
    }


}

void digital_0(void){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}

void digital_1(void){
  digitalWrite(c, HIGH);
  digitalWrite(b, HIGH);

  for(int j=7; j<=11;j++){
    digitalWrite(j, LOW);
  }
  digitalWrite(dp, LOW);
}

void digital_2(void){
  digitalWrite(b, HIGH);
  digitalWrite(a, HIGH);

  for(int j=9; j<=11; j++){
    digitalWrite(j, HIGH);
  }
  digitalWrite(dp, LOW);
  digitalWrite(c, LOW);
  digitalWrite(f, LOW);
}

void digital_3(void){
  digitalWrite(g, HIGH);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(dp, LOW);
  digitalWrite(f, LOW);
  digitalWrite(e, LOW);
}

void digital_4(void)
{
    digitalWrite(c,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
    digitalWrite(a,LOW);
    digitalWrite(e,LOW);
    digitalWrite(d,LOW);
}

void digital_5(void)
{
    digitalWrite(a,HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}

void digital_6(void)
{
    int j;

    for(j=7; j<=11; j++){
        digitalWrite(j,HIGH);
    }
    digitalWrite(c,HIGH);
    digitalWrite(dp,LOW);
    digitalWrite(b,LOW);
}

void digital_7(void)
{
    int j;

    for(j=5; j<=7; j++){
        digitalWrite(j,HIGH);
    }
    digitalWrite(dp,LOW);
    for(j=8; j<=11; j++){
        digitalWrite(j,LOW);
    }
}

void digital_8(void)
{
    int j;

    for(j=5; j<=11; j++){
        digitalWrite(j,HIGH);
    }
    digitalWrite(dp,LOW);
}

void digital_9(void)
{
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
