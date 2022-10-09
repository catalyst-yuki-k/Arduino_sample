// Description
// Turns off the given interrupt.
// Syntax
// detachInterrupt(digitalPinToInterrupt(pin)) (recommended)
// detachInterrupt(interrupt) (not recommended)
// detachInterrupt(pin) (Not recommended. Additionally, this syntax only works on Arduino SAMD Boards, Uno WiFi Rev2, Due, and 101.)
// Parameters
// interrupt: the number of the interrupt to disable (see attachInterrupt() for more details).
// pin: the Arduino pin number of the interrupt to disable
// Returns
// Nothing