// Description
// Analyse if a char is a space character. Returns true if the argument is a space or horizontal tab ('\t').
// Syntax
// isWhitespace(thisChar)
// Parameters
// thisChar: variable. Allowed data types: char.
// Returns
// true: if thisChar is a space character.

if (isWhitespace(myChar)) { // tests if myChar is a space character
    Serial.println("The character is a space or tab");
}

else {
    Serial.println("The character is not a space or tab");
}