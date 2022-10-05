void setup() {
    pinMode(13, OUTPUT);    // 13番ピンを出力として設定する。
}

void loop() {
    digitalWrite(13, HIGH); // 13番ピンをHIGH(ON)に設定する。
    delay(1000);            // 1000ms待つ。
    digitalWrite(13, LOW);  // 13番ピンをLOW(OFF)に設定する。
    delay(1000);            // 1000ms待つ。
}