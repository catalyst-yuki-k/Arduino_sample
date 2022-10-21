// Bits that are "bitwise ORed" with 0 are unchanged, so if myByte is a byte variable,
myByte | 0b00000000 = myByte;
// Bits that are "bitwise ORed" with 1 are set to 1 so:
myByte | 0b11111111 = 0b11111111;