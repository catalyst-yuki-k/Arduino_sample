int ledPin = 9;      // 変数"ledPin"にLEDを接続している9番ピンを割り当てる。
int analogPin = 3;   // 変数"analogPin"にボリューム抵抗を接続している3番ピンを接続する。
int val = 0;         // 読み込んだ値を保存するための変数"val"を0で初期化する。

void setup() {
    pinMode(ledPin, OUTPUT);  // 変数"ledPin"を出力として設定する。
}

void loop() {
    val = analogRead(analogPin);  // 変数"analogPin"の値を読み込んで変数"val"に代入する。
    analogWrite(ledPin, val / 4); // 変数"ledPin"に変数"val"の値を設定する。
                                  // この際、analogReadの値は0～1023だが、analogWriteの値は0～255のため、1/4倍する。
}