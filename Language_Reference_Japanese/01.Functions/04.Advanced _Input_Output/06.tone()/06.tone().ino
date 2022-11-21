int BuzzPin = 11; // 変数"BuzzPin"にブザーを接続している11番ピンを割り当てる。
int val = 0;      // 読み込んだ値を保存するための変数"val"を0で初期化する。

void setup() {
    pinMode(BuzzPin, OUTPUT); // 変数"BuzzPin"を出力として設定する。
} 
void loop() { 
    tone(BuzzPin,440);      //"BuzzPin"から440Hzを出力する
    delay(1000);            //1秒間まつ
    noTone(BuzzPin);        //音止める
    delay(1000);            //1秒間まつ
    tone(BuzzPin,440,1000); //"BuzzPin"から440Hzを1000ms間出力する
    noTone(BuzzPin);        //音止める
    delay(1000);            //1秒間まつ
}