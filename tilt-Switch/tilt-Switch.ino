/**************************************/
/* 第14課 傾斜スイッチ サンプルコード */
/**************************************/

const int ledPin = 13;    /* ピン設定 */

/* 初期処理 */
void setup()
{
    pinMode(ledPin,OUTPUT);    /* 出力設定 */
    pinMode(2,INPUT);          /* 入力設定 */
    digitalWrite(2, HIGH);     /* 電圧設定 */
}

/* 定期処理 */
void loop()
{
    int digitalVal;

    digitalVal = digitalRead(2);     /* 電圧値の読み込み */

    if(digitalVal == HIGH) {
        digitalWrite(ledPin,LOW);    /* 消灯 */
    } else {
        digitalWrite(ledPin,HIGH);   /* 点灯 */
    }
}
