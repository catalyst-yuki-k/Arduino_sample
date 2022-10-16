// Description
// Like if statements, switch case controls the flow of programs by allowing programmers to specify different code that should be executed in various conditions. 
// In particular, a switch statement compares the value of a variable to the values specified in case statements. 
// When a case statement is found whose value matches that of the variable, the code in that case statement is run.
// 
// The break keyword exits the switch statement, and is typically used at the end of each case. 
// Without a break statement, the switch statement will continue executing the following expressions ("falling-through") until a break, 
// or the end of the switch statement is reached.
/*
Syntax
switch (var) {
  case label1:
    // statements
    break;
  case label2:
    // statements
    break;
  default:
    // statements
    break;
}
*/
// Parameters
// var: a variable whose value to compare with various cases. Allowed data types: int, char.
// label1, label2: constants. Allowed data types: int, char.
// 
// Returns
// Nothing
// 
// Example Code
/*
switch (var) {
    case 1:
        //do something when var equals 1
        break;
    case 2:
        //do something when var equals 2
        break;
    default:
        // if nothing else matches, do the default
        // default is optional
        break;
}
*/