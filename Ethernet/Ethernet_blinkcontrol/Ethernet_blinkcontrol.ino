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

//LEDの出力ピンの定義
int ledPin = 3;
//LED状態の変数
int led_value;

void setup() {
    // Ethernet接続を開始し、サーバーを起動します
    Ethernet.begin(mac, ip);

    // サーバを起動する
    server.begin();

    //LEDの初期化
    pinMode(ledPin,OUTPUT);
    digitalWrite(ledPin,LOW);

    led_value = 0;
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

    //バッファ内のすべての送信文字が送信されるまで待機
    client.flush();

    // ページアドレス後方の「=」が何文字目であるか取得
    int led_value_index = (int)request.indexOf("=");
    // 「=」の後に続く文字(ONは1、OFFは0)を取得
    String led_value_str = request.substring(led_value_index+1,led_value_index+2);

    if (led_value_str.equals("1"))  {//「=」の後に続く文字が1の場合はONに切り替える
        digitalWrite(ledPin, HIGH);
        led_value = 1;//フラグを切り替える
    }else if(led_value_str.equals("0")){//「=」の後に続く文字が0の場合はOFFに切り替える
        digitalWrite(ledPin, LOW);
        led_value = 0;//フラグを切り替える
    }else{//どちらでもない場合は何もしない
        ;
    }

    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");  // 応答終了後、接続を終了します。
    client.println("Refresh: 5");  // 5秒ごとに自動的にページを更新する
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    if(led_value==1) {//1の場合はページの表示を「LED is ON」に切り替える
        client.print("LED is ON<br/>");
    } else {//0の場合はページの表示を「LED is OFF」に切り替える
        client.print("LED is OFF<br/>");
    }
     client.println("<form ACTION='/' method=get>");
    client.println("<button type='submit' name='LED' value='1'>ON</button>");
    client.println("<button type='submit' name='LED' value='0'>OFF</button>");
    client.println("</form>");
    client.println("</html>");

    delay(1);

    // コネクションを閉じる:
    client.stop();
}