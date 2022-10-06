//74HC595のST_CPに接続した8番ピンを、変数"latchPin"に割り当てる。
int latchPin = 8;
//74HC595のSH_CPに接続した12番ピンを、変数"clockPin"に割り当てる。
int clockPin = 12;
//74HC595のDSに接続した11番ピンを、変数"dataPin"に割り当てる。
int dataPin = 11;

void setup() {
    //各ピンを出力として設定する。
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void loop() {
    //カウントアップ
    for (int j = 0; j < 256; j++) {
        //送信中はlatchPinをLOWにする。
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, j);
        //latchPinをHIGHに戻し、情報をリッスンする必要がなくなったことを通知する。
        digitalWrite(latchPin, HIGH);
        delay(1000);
    }
}