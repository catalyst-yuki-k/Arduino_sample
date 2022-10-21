// Bits that are "bitwise XORed" with 0 are left unchanged. So if myByte is a byte variable,
myByte ^ 0b00000000 = myByte;
// Bits that are "bitwise XORed" with 1 are toggled so:
myByte ^ 0b11111111 = ~myByte;