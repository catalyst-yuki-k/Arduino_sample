// Bits that are "bitwise ANDed" with 0 are cleared to 0 so, if myByte is a byte variable,
myByte & 0b00000000 = 0;
// Bits that are "bitwise ANDed" with 1 are unchanged so,
myByte & 0b11111111 = myByte;