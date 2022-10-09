// Description
// The keyboard functions enable 32u4 or SAMD micro based boards to send keystrokes 
// to an attached computer through their micro’s native USB port.
// 
// Note: Not every possible ASCII character, particularly the non-printing ones, 
// can be sent with the Keyboard library.
// The library supports the use of modifier keys. 
// Modifier keys change the behavior of another key when pressed simultaneously. 
// See here for additional information on supported keys and their use.
// 
// Notes and Warnings
// These core libraries allow the 32u4 and SAMD based boards (Leonardo, Esplora, Zero, Due and MKR Family) 
// to appear as a native Mouse and/or Keyboard to a connected computer.
// 
// A word of caution on using the Mouse and Keyboard libraries: 
// if the Mouse or Keyboard library is constantly running, it will be difficult to program your board. 
// Functions such as Mouse.move() and Keyboard.print() will move your cursor or send keystrokes 
// to a connected computer and should only be called when you are ready to handle them. 
// It is recommended to use a control system to turn this functionality on, 
// like a physical switch or only responding to specific input you can control. 
// Refer to the Mouse and Keyboard examples for some ways to handle this.
// 
// When using the Mouse or Keyboard library, 
// it may be best to test your output first using Serial.print(). 
// This way, you can be sure you know what values are being reported.