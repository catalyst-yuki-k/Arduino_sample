int ledPin = 13;  // 変数"ledPin"にLEDを接続している13番ピンを割り当てる。
int inPin = 7;    // 変数"inPin"にボタンを接続している7番ピンを割り当てる。
int val = 0;      // 読み込んだ値を保存するための変数"val"を0で初期化する。

void setup() {
    pinMode(ledPin, OUTPUT);  // 変数"ledPin"を出力として設定する。
    pinMode(inPin, INPUT);    // 変数"inPin"を入力として設定する。
}

void loop() {
    val = digitalRead(inPin);   // 変数"inPin"の値を読み込んで変数"val"に代入する。
    digitalWrite(ledPin, val);  // 変数"ledPin"に変数"val"の値を設定する。
}