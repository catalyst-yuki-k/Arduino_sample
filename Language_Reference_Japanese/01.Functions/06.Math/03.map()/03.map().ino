/* Map an analog value to 8 bits (0 to 255) */
void setup() {}

void loop() {
    int val = analogRead(0);
    val = map(val, 0, 1023, 0, 255);
    analogWrite(9, val);
}