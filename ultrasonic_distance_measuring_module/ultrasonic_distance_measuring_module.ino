#define TrigPin 2
#define EchoPin 3

void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

}

void loop() {
  float cm;

    digitalWrite(TrigPin, LOW);  /* 電圧設定 */
    delayMicroseconds(2);        /* プログラム停止時間(us)の設定 */
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, LOW);

    /* パルスを読み取り距離をcmに変換 */
    cm = pulseIn(EchoPin, HIGH) / 58.0; //pulseIn: 핀으로 입력되는 펄스의 시간을 측정하는  함수 low에서 high , high에서 low로 바뀌는 시간
    cm = (int(cm * 100.0)) / 100.0;

    /* シリアルモニタに測定距離(cm)を表示 */
    Serial.print(cm);
    Serial.println("cm");

    delay(1000); /* プログラム停止時間(ms)の設定 */


}
