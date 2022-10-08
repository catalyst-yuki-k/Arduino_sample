// Description
// Analyse if a char is an hexadecimal digit (A-F, 0-9). Returns true if thisChar contains an hexadecimal digit.
// Syntax
// isHexadecimalDigit(thisChar)
// Parameters
// thisChar: variable. Allowed data types: char.
// Returns
// true: if thisChar is an hexadecimal digit.

if (isHexadecimalDigit(myChar)) { // tests if myChar is an hexadecimal digit
    Serial.println("The character is an hexadecimal digit");
}

else {
    Serial.println("The character is not an hexadecimal digit");
}