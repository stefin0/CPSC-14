/*
Stefin Racho
2/6/2023
Answering various C++ questions
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main () {
/* 1. Which of the following are good variable names in C++? (If they are not a good variable name, then write why) */
    // a - should be more descriptive.
    // num5 - good.
    // long_5 - bad, because contains reserved keyword "long".
    // _num123 - good.
    // ABCDEFG - should be more descriptive.
    // sum.5 - bad, because contains period which is a reserved special character.
    // integer 5 - bad, because contains reserved keyword "integer" and a whitespace.
    // RATE5 - good.
    // total-5 - bad, because contains hyphen.
    // %car5 - bad, because contains "%".
    // short - bad, because contains reserved keyword "short".

/* 2. Are you allowed to create the 3 following variables in C++ as they are written below? Why or why not? */
    // int total, Total, TOTAL
    // yes, because isn't invalid, but convention is to use camelCase for most variables, or CAPS for constants.

/* 3. What is a byte of data? */
    // a byte of data is 8 bits of data, and a bit is either 0 or 1.

/* 4. Translate the binary number 1000 1101 into decimal format. */
    // 8 13

/* 5. Give the declaration for 3 variables called height, width, and length. All of the variables are of type double and should be initialized to 0. */
    double height = 0;
    double width = 0;
    double length = 0;

/* 6. Convert each of the following mathematical formulas to a C++ expression: */ 
    // 5x => 5 * x
    // 7x + z => (7 * x) + z
    // x - y / z => x - y / z
    // 7x + 9 / x * 9 => 7 * x + 9 / x * 9

/* 7. What are 7 mathematical operators used in C++? What are they used for? */
    // + used for addition
    // - used for subtraction
    // * used for multiplication
    // / used for division
    // % used for calculating remainder
    // ++ used for incrementing by 1
    // -- used for decrementing by 1

/* 8. What are 2 ways that you can make a new blank line in your output in C++? */
    // endl
    // \n

/* 9. What does the following line of programming code do? #include <iostream> */
    // includes the standard library from c++ that allows you to provide input and output functionality.

/* 10. Give an output statement that will produce the following message on the screen if the user enters a 1: 
    Once a person has understood the way variables are used in programming, he has understood the quintessence of programming. 
and will write the following message if the user enters a 2:
    Don’t worry if it doesn’t work right. If everything did, you’d be out of a job. 
and will output this message if the user enters anything else:
    C is quirky, flawed, and an enormous success.
*/
    int input;

    cout << "Enter 1 or 2: ";
    cin >> input;

    if (input == 1) {
        cout << "\nOnce a person has understood the way variables are used in programming, he has understood the quintessence of programming\n";
    } else if (input == 2) {
        cout << "\nDon't worry if it doesn't work right. If everything did, you'd be out of a job.\n";
    } else {
        cout << "\nC is quirky, flawed, and an enormous success.\n";
    }

/* 11. Determine the value true or false of each of the following Boolean expressions.
Assume the variable number = 0 and balance = 5: */
    // a. (number == 0) && (balance > 3) TRUE
    // b. number == 0 && balance > 3 FALSE, invalid code
    // c. balance > 10 || number < 2 FALSE, invalid code
    // d. ! (balance == 4) TRUE
    // e. (number == 0) && ( x < y ) FALSE, we don't know values of x and y
    // f. (number == 0) || ( x < y ) TRUE
    // g. ! ( ( (number < 10 ) || ( x < y) ) && ( balance <= 5 ) ) TRUE
    // h. ( ( number / balance) || (balance > 2) ) FALSE
    // i. ( (balance > 2) || ( number / balance)) TRUE
    // j. ( 4 && 8) + (! 7) FALSE, invalid code

/* 12. Rounding errors can cause problems with our programs that involve math. Such as take for example the following code: 
What is the output? Why do you get this output? */
    float floatNumber = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
    double doubleNumber = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
    long double longDouble = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
    
    cout << setprecision(17);
    cout << floatNumber << endl; // outputs 1 because float can only output up to 7 digits, rounds up.
    cout << doubleNumber << endl; // outputs 0.99999999999999989 because outputs up to 15 digits, doesn't go to 1.
    cout << longDouble << endl; // outputs 0.99999999999999989 because outputs up to 15 digits, doesn't go to 1.

    return 0;   
}