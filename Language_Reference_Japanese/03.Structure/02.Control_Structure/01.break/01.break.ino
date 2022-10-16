// Description
// break is used to exit from a for, while or do…​while loop, 
// bypassing the normal loop condition. 
// It is also used to exit from a switch case statement.
// 
// Example Code
// In the following code, the control exits the for loop when the sensor value exceeds the threshold.
int threshold = 40;

for (int x = 0; x < 255; x++) {
    analogWrite(PWMpin, x);
    sens = analogRead(sensorPin);
    if (sens > threshold) {     // bail out on sensor detect
        x = 0;
        break;
    }
    delay(50);
}