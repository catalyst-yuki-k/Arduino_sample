void setup() {
    // シリアル通信を設定する。
    Serial.begin(9600);
}

void loop() {
    // A0の入力をデフォルトの解像度(10bit)で読み、シリアル通信に出力する
    analogReadResolution(10);
    Serial.print("ADC 10-bit (default) : ");
    Serial.print(analogRead(A0));

    // 解像度を12bitに変更し、A0を読み込む
    analogReadResolution(12);
    Serial.print(", 12-bit : ");
    Serial.print(analogRead(A0));

    // 解像度を16bitに変更し、A0を読み込む
    analogReadResolution(16);
    Serial.print(", 16-bit : ");
    Serial.print(analogRead(A0));

    // 解像度を8bitに変更し、A0を読み込む
    analogReadResolution(8);
    Serial.print(", 8-bit : ");
    Serial.println(analogRead(A0));

    // シリアルモニターが飽和しないようにディレイを入れる
    delay(100);
}