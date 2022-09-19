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

int ledPin = 3;

void setup() {
    // Ethernet接続を開始し、サーバーを起動します。:
    Ethernet.begin(mac, ip);

    // サーバを起動する
    server.begin();

    pinMode(ledPin,OUTPUT);
    digitalWrite(ledPin,LOW);

    digitalWrite(ledPin, HIGH);   // LEDをオン
    delay(1000);                  // 1秒待つ
    digitalWrite(ledPin, LOW);    // LEDをオフ
    delay(1000);
    digitalWrite(ledPin, HIGH);   // LEDをオン
    delay(1000);                  // 1秒待つ
    digitalWrite(ledPin, LOW);    // LEDをオフ
    delay(1000);
    digitalWrite(ledPin, HIGH);   // LEDをオン
    delay(1000);                  // 1秒待つ
    digitalWrite(ledPin, LOW);    // LEDをオフ
    delay(1000);
}

void loop() {

    // Check if a client has connected
    EthernetClient client = server.available();
    if (!client) {
        return;
    }

    // Wait until the client sends some data
    while(!client.available()){
        delay(1);
    }

    // Read the first line of the request
    String request = client.readStringUntil('\r');
    client.flush();

    // Match the request
    int value = LOW;
    if (request.indexOf("/LED=ON"))  {
        digitalWrite(ledPin, HIGH);
        value = HIGH;
    }
    if (request.indexOf("/LED=OFF"))  {
        digitalWrite(ledPin, LOW);
        value = LOW;
    }
 
    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");  // 応答終了後、接続を終了します。
    client.println("Refresh: 5");  // 5秒ごとに自動的にページを更新する
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    if(value == HIGH) {
        client.print("On");
    } else {
        client.print("Off");
    }
    client.println("<a href=\"/LED=ON\"\"><button>LED ON</button></a>");
    client.println("<a href=\"/LED=OFF\"\"><button>LED OFF</button></a><br />");  
    client.println("</html>");

    delay(1);

    // コネクションを閉じる:
    client.stop();
}