void setup() {
    // シリアル通信を設定する。
    Serial.begin(9600);
    // 出力ピンを設定する
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

void loop() {
    // A0の入力を読み込んで、LEDが接続されたPWM出力ピンにマップする。
    int sensorVal = analogRead(A0);
    Serial.print("Analog Read) : ");
    Serial.print(sensorVal);

    // デフォルトのPWM解像度。
    analogWriteResolution(8);
    analogWrite(11, map(sensorVal, 0, 1023, 0, 255));
    Serial.print(" , 8-bit PWM value : ");
    Serial.print(map(sensorVal, 0, 1023, 0, 255));

    // PWMの解像度を12bitに変更する。
    // 最大解像度である12bitはArduino Dueでのみサポートされる。
    analogWriteResolution(12);
    analogWrite(12, map(sensorVal, 0, 1023, 0, 4095));
    Serial.print(" , 12-bit PWM value : ");
    Serial.print(map(sensorVal, 0, 1023, 0, 4095));

    // PWMの解像度を4bitに変更する。
    analogWriteResolution(4);
    analogWrite(13, map(sensorVal, 0, 1023, 0, 15));
    Serial.print(", 4-bit PWM value : ");
    Serial.println(map(sensorVal, 0, 1023, 0, 15));

    delay(5);
}