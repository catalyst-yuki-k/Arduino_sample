#include <mcp_can.h>
#include <SPI.h>
 
//SPIのCSのピン番号の定義
#define PIN_CS  (10)
 
MCP_CAN CAN0(PIN_CS);

unsigned char TX_DATA[8] = {0, 1, 2, 3, 4, 5, 6, 7}; 

void setup()
{
    Serial.begin(115200);

    //CANの通信速度の定義
    if(CAN0.begin(CAN_500KBPS) == CAN_OK)
        Serial.println("CAN initialize Complete");
    else
        Serial.println("CAN initialize failure");
}
 

void loop()
{
    //ID, 標準フレーム, データ長, 送信データ
    CAN0.sendMsgBuf(0x00, 0, 8, TX_DATA);  
    delay(1000);
}
 