/* ピン設定(7セグ) */
const int a  = 1;  /* a */
const int b  = 2;  /* b */
const int c  = 3;  /* c */
const int d  = 4;  /* d */
const int e  = 5;  /* e */
const int f  = 6;  /* f */
const int g  = 7;  /* g */
const int dp = 8;  /* ピリオド */

/* ピン設定(桁) */
const int d4 = 9;  /* 1の位 */
const int d3 = 10; /* 10の位 */
const int d2 = 11; /* 100の位 */
/*const int d1 = 12;*/ /* 1000の位 */


const int  DISPLAY_TIME = 5000; /* 表示時間(ms) */

#define cds A0

/* 初期処理 */
void setup()
{ 
    pinMode(d2, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(d4, OUTPUT);
    pinMode(a,  OUTPUT);
    pinMode(b,  OUTPUT);
    pinMode(c,  OUTPUT);
    pinMode(d,  OUTPUT);
    pinMode(e,  OUTPUT);
    pinMode(f,  OUTPUT);
    pinMode(g,  OUTPUT);
    pinMode(dp, OUTPUT);
    Serial.begin(9600);

}

/* 定期処理 */
void loop()
{ 
    //멤버 필드
    int display_1,display_10,display_01;
    unsigned long start_time;

    Serial.println(analogRead(cds));//조도센서에서 읽어 들인 값을 시리얼포트로 출력
    int cds = analogRead(cds); // int 변수 대입
     /*
     조도센서는 빛이 많이 들어오면 값이 낮아지고
     빛이 적어지면 값이 높아짐
     */ 

    /* 各桁の表示する数値を算出 */
    display_01   = cds / 10   % 10; /* 1/10 の位(cm) */
    display_1    = cds / 100  % 10; /* 1    の位(cm) */
    display_10   = cds / 1000 % 10; /* 10   の位(cm) */

    /* 測定値表示 */
    /* Display(x,y):x桁にyを表示 */
    start_time = millis(); /* 프로그램 작동 시작부터 mm단위로 시간을 표시 1~999999*/
    while(millis() < start_time + DISPLAY_TIME){ /// DISPLAY_TIME 위에서 5000으로 초기화 함
        Display(1, display_01);
        Display(2, display_1);
        Display(3, display_10);
    }

}

/* 表示する桁を選択する関数 */
void WeiXuan(unsigned char n)
{
    switch(n){
    case 1:                   /* 1の桁表示 */
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      digitalWrite(d4, HIGH);
      break;
    case 2:                  /* 10の桁表示 */
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, LOW);
      break;
    case 3:                  /* 100の桁表示 */
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      digitalWrite(d4, LOW);
      break;
    default :                 /* 4桁全て表示 */
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      digitalWrite(d4, LOW);
      break;
    }
}

/* Num_X():Xを表示するよう電圧設定する関数 */
void Num_0(int keta)
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    /* 一の桁表示時はピリオドも一緒に点灯する */
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

void Num_1(int keta)
{
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

void Num_2(int keta)
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

void Num_3(int keta)
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

void Num_4(int keta)
{
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

void Num_5(int keta)
{
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

void Num_6(int keta)
{
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

void Num_7(int keta)
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

void Num_8(int keta)
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

void Num_9(int keta)
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    if (keta == 2) {
        digitalWrite(dp,LOW);
    } else {
        digitalWrite(dp,HIGH);
    }
}

/* 表示をクリア */
void Clear()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp,HIGH);
}

/* 数字を表示する関数を呼び分ける関数 */
void pickNumber(int keta,unsigned char num)
{
    switch(num){
    case 0:
      Num_0(keta);
      break;
    case 1:
      Num_1(keta);
      break;
    case 2:
      Num_2(keta);
      break;
    case 3:
      Num_3(keta);
      break;
    case 4:
      Num_4(keta);
      break;
    case 5:
      Num_5(keta);
      break;
    case 6:
      Num_6(keta);
      break;
    case 7:
      Num_7(keta);
      break;
    case 8:
      Num_8(keta);
      break;
    case 9:
      Num_9(keta);
      break;
    default:
      Clear();
      break; 
    }
}

/* x桁目にNumberを表示する関数 */
void Display(unsigned char x, unsigned char Number)
{
    /* 数字を表示 */
    WeiXuan(x);
    pickNumber(x,Number);

    delay(1); /* プログラム停止時間(ms)の設定 */
    Clear();  /* 画面をクリア */
}
