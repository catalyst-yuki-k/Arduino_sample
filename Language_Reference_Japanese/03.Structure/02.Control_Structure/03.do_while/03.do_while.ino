// Description
// The do…​while loop works in the same manner as the while loop, 
// with the exception that the condition is tested at the end of the loop, 
// so the do loop will always run at least once.
// 
// Syntax
// do {
  // statement block
// } while (condition);
// Parameters
// condition: a boolean expression that evaluates to true or false.
// 
// Example Code
int x = 0;
do {
    delay(50);          // wait for sensors to stabilize
    x = readSensors();  // check the sensors
} while (x < 100);