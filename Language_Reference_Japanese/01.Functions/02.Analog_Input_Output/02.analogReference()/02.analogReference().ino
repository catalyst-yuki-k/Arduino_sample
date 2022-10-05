int analogPin = A3; // ボリューム抵抗の中央の端子をアナログピンの3番に接続する。
                    // ボリューム抵抗の両側の端子はGNDと5Vに接続する。
int val = 0;  // 読み込んだ値を保存するための変数"val"を0で初期化する。

void setup() {
    analogReference(DEFAULT);     // 5V駆動のArduinoでは5V、3.3V駆動のArduinoでは3.3Vが設定される。
    Serial.begin(9600);           // シリアル通信を設定する。
}

void loop() {
    val = analogRead(analogPin);  // 入力ピンの値を読み込む。
    Serial.println(val);          // 変数"val"の値をシリアル通信で表示する。
}