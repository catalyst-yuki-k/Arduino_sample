#include <SPI.h>
#include <Ethernet.h>

// MACアドレスの設定
byte mac[] = {
    0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
// IPアドレスの定義
IPAddress ip(192, 168, 1, 177);

// Ethernetサーバーライブラリを、使用したいIPアドレスとポートで初期化します
// （HTTPの場合は80番がデフォルト）
EthernetServer server(80);

void setup() {
    // Ethernet.init(pin)を使ってCSピンを設定することができます。
    //Ethernet.init(10);  // Most Arduino shields
    //Ethernet.init(5);   // MKR ETH Shield
    //Ethernet.init(0);   // Teensy 2.0
    //Ethernet.init(20);  // Teensy++ 2.0
    //Ethernet.init(15);  // ESP8266 with Adafruit FeatherWing Ethernet
    //Ethernet.init(33);  // ESP32 with Adafruit FeatherWing Ethernet

    // シリアル通信を開始し、ポートが開くのを待つ:
    Serial.begin(9600);
    while (!Serial) {
        ; // シリアルポートが接続されるのを待ちます。ネイティブUSBポートのみ必要
    }
    Serial.println("Ethernet WebServer Example");

    // Ethernet接続を開始し、サーバーを起動します。:
    Ethernet.begin(mac, ip);

    // イーサネットハードウェアが存在するか確認する
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
        Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
        while (true) {
            delay(1); // 何もしない、イーサネットハードウェアなしで動作させる意味はない
        }
    }
    // ケーブルが接続されているかどうか確認する
    if (Ethernet.linkStatus() == LinkOFF) {
        Serial.println("Ethernet cable is not connected.");
    }

    // サーバを起動する
    server.begin();
    // サーバのIPアドレスを表示する。
    Serial.print("server is at ");
    Serial.println(Ethernet.localIP());
}


void loop() {
    // クライアントを待つ
    EthernetClient client = server.available();
    if (client) {
        Serial.println("new client");
        // HTTPリクエストの末尾が空行の場合
        bool currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {
                // cにクライアントを代入する
                char c = client.read();
                // シリアル通信にcの内容を表示する
                Serial.write(c);
                // 行末が改行文字　かつ　currentLineIsBlankが真の場合
                if (c == '\n' && currentLineIsBlank) {
                    // 標準的なHTTPレスポンスヘッダを送信する
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");  // 応答終了後、接続を終了します。
                    client.println("Refresh: 5");  // 5秒ごとに自動的にページを更新する
                    client.println();
                    client.println("<!DOCTYPE HTML>");
                    client.println("<html>");
                    // 各アナログ入力端子の値を出力する
                    for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
                        int sensorReading = analogRead(analogChannel);
                        client.print("analog input ");
                        client.print(analogChannel);
                        client.print(" is ");
                        client.print(sensorReading);
                        client.println("<br />");
                    }
                    client.println("</html>");
                    break;
                }
                if (c == '\n') {// cが改行文字の場合（想定した改行文字のみの場合）
                    // currentLineIsBlankを真とする
                    currentLineIsBlank = true;
                } else if (c != '\r') {// cがキャリッジリターンではない場合
                    // currentLineIsBlankを偽とする
                    currentLineIsBlank = false;
                }
            }
        }
        // ウェブブラウザがデータを受信する時間を与える
        delay(1);
        // コネクションを閉じる:
        client.stop();
        Serial.println("client disconnected");
    }
}