/*************************************************/
/* 第12課 4ビットデジタルチューブ サンプルコード */
/*************************************************/

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
const int d1 = 12; /* 1000の位 */

/* 初期処理 */
void setup()
{
    pinMode(d1, OUTPUT);
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
}

/* 定期処理 */
void loop()
{
    Display(1, 1); // 디스플레이 함수는 최하단에 있음
    delay(1000);
    Display(2, 2);
    delay(1000);
   //Display(3, 3);
    Display(4, 4);
    delay(1000);

    /*
    1234 전부 동시에 켜져있는 것처럼 보이지만
    딜레이를 넣어보면 1~4까지 차례대로 빠르게 깜빡거려서 동시에 켜져있는 것처럼 보일뿐
    */
}

/* 表示する桁を選択する関数
1~4자리 중 어느 자리인지 판별
*/
void WeiXuan(unsigned char n)
{
    switch(n){
    case 1:                   /* 1,10,100の桁表示 */
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      digitalWrite(d4, LOW);
      break;
    case 2:                  /* 1,10,1000の桁表示 */
      digitalWrite(d1, LOW);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      digitalWrite(d4, LOW);
      break;
    case 3:                  /* 1,100,1000の桁表示 */
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, LOW);
      break;
    case 4:                  /* 10,100,1000の桁表示 */
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      digitalWrite(d4, HIGH);
      break;
    default :                 /* 4桁全て表示 */
      digitalWrite(d1, LOW);
      digitalWrite(d2, LOW);
      digitalWrite(d3, LOW);
      digitalWrite(d4, LOW);
      break;
    }
}

/* Num_X():Xを表示するよう電圧設定する関数 */
void Num_0()
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(dp,HIGH);
}

void Num_1()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp,HIGH);
}

void Num_2()
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(dp,HIGH);
}

void Num_3()
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(dp,HIGH);
}

void Num_4()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp,HIGH);
}

void Num_5()
{
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp,HIGH);
}

void Num_6()
{
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp,HIGH);
}

void Num_7()
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp,HIGH);
}

void Num_8()
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp,HIGH);
}

void Num_9()
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp,HIGH);
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
void pickNumber(unsigned char n)
{
    switch(n){
    case 0:
      Num_0();
      break;
    case 1:
      Num_1();
      break;
    case 2:
      Num_2();
      break;
    case 3:
      Num_3();
      break;
    case 4:
      Num_4();
      break;
    case 5:
      Num_5();
      break;
    case 6:
      Num_6();
      break;
    case 7:
      Num_7();
      break;
    case 8:
      Num_8();
      break;
    case 9:
      Num_9();
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
    WeiXuan(x);//몇번째에
    pickNumber(Number);//Number 숫자를 표시

    delay(1); /* プログラム停止時間(ms)の設定 */
    Clear();  /* 画面をクリア */
}
