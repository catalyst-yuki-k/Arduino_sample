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
    // Ethernet接続を開始し、サーバーを起動します。:
    Ethernet.begin(mac, ip);

    // サーバを起動する
    server.begin();
}


void loop() {
    // クライアントを待つ
    EthernetClient client = server.available();

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
    // ウェブブラウザがデータを受信する時間を与える
    delay(1);
    // コネクションを閉じる:
    client.stop();
}