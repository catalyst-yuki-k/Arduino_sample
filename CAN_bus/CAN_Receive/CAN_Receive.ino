#include <mcp_can.h>
#include <SPI.h>
 
//SPIのCSのピン番号の定義
#define PIN_CS  (10)
//INTのピン番号の定義
#define PIN_INT (9)
 
MCP_CAN CAN0(PIN_CS);
 
long unsigned int RX_ID;
unsigned char len = 0;
unsigned char RX_DATA[8];

void setup(){
    Serial.begin(115200);

    //CANの通信速度の定義
    if(CAN0.begin(CAN_500KBPS) == CAN_OK)
        Serial.println("CAN initialize Complete");
    else
        Serial.println("CAN initialize failure");

    //割込用のピン設定
    pinMode(PIN_INT, INPUT); 
}
 
void loop(){
    //受信割込の発生を検知
    if(!digitalRead(PIN_INT)){
        //データ長, 受信データ
        CAN0.readMsgBuf(&len, RX_DATA);
        //CANのIDを取得
        RX_ID = CAN0.getCanId();
        //CANのIDを表示
        Serial.print("ID:%d,DATA:%d",RX_ID,HEX);
        //受信データを一つずつ表示
        for(int i = 0; i<len; i++){
            if(RX_DATA[i] < 0x10){
                Serial.print("0");
            }
            Serial.print(RX_DATA[i], HEX);
            Serial.print(" ");
        }
        //改行
        Serial.println();
    }
}