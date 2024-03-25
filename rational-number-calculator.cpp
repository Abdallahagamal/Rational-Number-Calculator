#include <iostream>
#include <regex>
#include <string>
#include <cctype>
using namespace std;
// Purpose: rational number calculator that is capable of taking two rational numbers positive or negative and an operation you want, then Calculate it for you, 
// NOTE: you Should Write the expression by this way (Fraction 1) (the operation) (fraction 2) like 1/2 / 5/8, 7/2 * 2, 8 - 1/2, 5 + 5.

// Author: Abdallahagamal, Eyad-Nader, Abdlmonem Osama
// Emails: abdallahgamal987@gmail.com, eyadnader322@gmail.com, Abdlmonem.gadoo@gmail.com.



// Function to find the greatest common divisor using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to simplify a fraction
void simplifyFraction(int& numerator, int& denominator) {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}
void addFractions(int numerator_1, int Denominator_1, int numerator_2, int Denominator_2, int& resultNumerator, int& resultDenominator) {
    // Find a common denominator
    int commonDenominator = Denominator_1 * Denominator_2;

    // Add the numerators
    int newNumerator1 = numerator_1 * Denominator_2;
    int newNumerator2 = numerator_2 * Denominator_1;
    resultNumerator = newNumerator1 + newNumerator2;
    resultDenominator = commonDenominator;

    // Simplify the resulting fraction
    int divisor = gcd(resultNumerator, resultDenominator);
    resultNumerator /= divisor;
    resultDenominator /= divisor;
}
void subtractfractions(int numerator_1, int Denominator_1, int numerator_2, int Denominator_2, int& resultNumerator, int& resultDenominator) {
    // Find a common denominator
    int commonDenominator = Denominator_1 * Denominator_2;

    // Add the numerators
    int newNumerator1 = numerator_1 * Denominator_2;
    int newNumerator2 = numerator_2 * Denominator_1;
    resultNumerator = newNumerator1 - newNumerator2;
    resultDenominator = commonDenominator;

    // Simplify the resulting fraction
    int divisor = gcd(resultNumerator, resultDenominator);
    resultNumerator /= divisor;
    resultDenominator /= divisor;
}
void multiplyFractions(int numerator_1, int Denominator_1, int numerator_2, int Denominator_2, int& resultNumerator, int& resultDenominator) {
    // Multiply the numerators and denominators
    resultNumerator = numerator_1 * numerator_2;
    resultDenominator = Denominator_1 * Denominator_2;

    // Simplify the resulting fraction
    int divisor = gcd(resultNumerator, resultDenominator);
    resultNumerator /= divisor;
    resultDenominator /= divisor;
}
void divideFractions(int numerator_1, int Denominator_1, int numerator_2, int Denominator_2, int& resultNumerator, int& resultDenominator) {
    // Check for division by zero
    if (numerator_2 == 0) {
        cout << "Error: Division by zero" << endl;
        return;
    }

    int m1 = Denominator_2;
    int m2 = numerator_2;
    resultNumerator = numerator_1 * m1;
    resultDenominator = Denominator_1 * m2;
    int divisor = gcd(resultNumerator, resultDenominator);
    resultNumerator /= divisor;
    resultDenominator /= divisor;
}
int main() {
    cout << "=========================Rational Number Calculator=========================" << endl;
    smatch match;
    string choice, num1;
    //Menu
    cout << "1) Calculate\n2) Exit\nPlease enter your choice: ";
    while (true) {
        cin >> choice;
        cin.ignore();
        if (choice == "1") {
            cout << "Please enter a rational number operation OR write exit (to exit) \n";
            while (true) {
                //get the expression from user
                getline(cin, num1);
                if (num1 == "exit" || num1 == "EXIT")
                {
                    cout << "Thank you!";
                    return 0;
                }

                // this pattern to check the operators the user will enter
                regex pattern_0(".?..?.?.?.?.[+\\-*/]..?..?.?.?.?.?");

                //This patterns is the expressions that the user may be will enter

                //the expression of pattern 1 like: 1/2 + 8/9
                regex pattern_1("[+]?(-?[0-9]+)[/][+]?(-?[0-9]+) ([\\+\\-\\*/]) [+]?(-?[0-9]+)[/][+]?(-?[0-9]+)");
                //the expression of pattern 2 like: 1/2 + 8
                regex pattern_2("[+]?(-?[0-9]+)[/][+]?(-?[0-9]+) ([\\+\\-\\*/]) [+]?(-?[0-9]+)"); //No denominator in fraction 2
                //the expression of pattern 1 like: 1 + 8/9
                regex pattern_3("[+]?(-?[0-9]+) ([\\+\\-\\*/]) [+]?(-?[0-9]+)[/][+]?(-?[0-9]+)"); //No denominator in fraction 1
                //the expression of pattern 1 like: 1 + 8
                regex pattern_4("[+]?(-?[0-9]+) ([\\+\\-\\*/]) [+]?(-?[0-9]+)"); //No denominator in fraction 1 and 2
                //this pattern to check the expression 
                regex pattern_5("(.)+(.)?((.)?)+ . (.)+(.)?((.)?)+");

                if (regex_match(num1, pattern_5)) {
                    if (regex_match(num1, pattern_0)) {

                        if (regex_match(num1, match, pattern_1)) {
                            int numerator_1 = stoi(match[1].str()), Denominator_1 = stoi(match[2].str()), numerator_2 = stoi(match[4].str()), Denominator_2 = stoi(match[5].str());
                            string opretor = match[3].str();
                            //Add fraction
                            if (Denominator_1 == 0 || Denominator_2 == 0) {
                                cout << "It cannot be divided by zero, Try again! \n";

                            }
                            else if (opretor == "+")
                            {
                                int resultNumerator, resultDenominator;
                                addFractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }

                            }
                            //Multiply fractions
                            else if (opretor == "*")
                            {
                                int resultNumerator, resultDenominator;
                                multiplyFractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                            }
                            //Subtract fractions
                            else if (opretor == "-")
                            {
                                int resultNumerator, resultDenominator;
                                subtractfractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                            }
                            //Divide fractions
                            else if (opretor == "/")
                            {
                                int resultNumerator, resultDenominator;
                                if (numerator_2 == 0)
                                {
                                    cout << "It cannot be divided by zero, Try again! \n";
                                    continue;
                                }

                                divideFractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                            }




                        }
                        else if (regex_match(num1, match, pattern_2)) {
                            int numerator_1 = stoi(match[1].str()), Denominator_1 = stoi(match[2].str()), numerator_2 = stoi(match[4].str());
                            string opretor = match[3].str();
                            int Denominator_2 = 1;
                            int resultNumerator, resultDenominator;
                            if (Denominator_1 == 0) {
                                cout << "It cannot be divided by zero, Try again! \n";

                            }
                            //Add fraction
                            else if (opretor == "+") {
                                addFractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }

                            }
                            //Subtract fractions
                            else if (opretor == "-") {
                                subtractfractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                            }
                            //Multiply fractions
                            else if (opretor == "*") {
                                multiplyFractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }

                            }
                            //Divide fractions
                            else if (opretor == "/") {
                                if (numerator_2 == 0) {
                                    cout << "It cannot be divided by zero, Try again! \n";
                                    continue;
                                }
                                divideFractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }

                            }

                        }
                        else if (regex_match(num1, match, pattern_3)) {
                            int numerator_1 = stoi(match[1].str()), numerator_2 = stoi(match[3].str()), Denominator_2 = stoi(match[4].str());
                            string opretor = match[2].str();
                            int Denominator_1 = 1;
                            int resultNumerator, resultDenominator;
                            //Add fraction
                            if (Denominator_2 == 0) {
                                cout << "It cannot be divided by zero, Try again! \n";
                            }
                            else if (opretor == "+") {
                                addFractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                            }
                            //Subtract fractions
                            else if (opretor == "-") {
                                subtractfractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                            }
                            //Multiply fractions
                            else if (opretor == "*") {
                                multiplyFractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";

                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";

                                }

                            }
                            //Divide fractions
                            else if (opretor == "/") {
                                if (numerator_2 == 0) {
                                    cout << "It cannot be divided by zero, Try again! \n";
                                    continue;
                                }
                                divideFractions(numerator_1, Denominator_1, numerator_2, Denominator_2, resultNumerator, resultDenominator);
                                //this to simplify the fraction
                                if (resultDenominator == 1) {
                                    cout << "= " << resultNumerator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }
                                else {
                                    cout << "= " << resultNumerator << "/" << resultDenominator << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }

                            }
                        }
                        else if (regex_match(num1, match, pattern_4)) {
                            int numerator_1 = stoi(match[1].str()), numerator_2 = stoi(match[3].str());
                            string opretor = match[2].str();
                            //Add fraction
                            if (opretor == "+") {
                                cout << "= " << numerator_1 + numerator_2 << endl;
                                cout << "Please enter a rational number operation OR exit \n";

                            }
                            //Subtract fractions
                            else if (opretor == "-") {
                                cout << "= " << numerator_1 - numerator_2 << endl;
                                cout << "Please enter a rational number operation OR exit \n";
                            }
                            //Multiply fractions
                            else if (opretor == "*") {
                                cout << "= " << numerator_1 * numerator_2 << endl;
                                cout << "Please enter a rational number operation OR exit \n";
                            }
                            //Divide fractions
                            else if (opretor == "/") {
                                //this to simplify the fraction
                                if (numerator_2 == 0) {
                                    cout << "It cannot be divided by zero, Try again! \n";
                                    continue;
                                }
                                simplifyFraction(numerator_1, numerator_2);
                                if (numerator_2 == 1) {
                                    cout << "= " << numerator_1 << endl;
                                    cout << "Please enter a rational number operation OR exit \n";

                                }
                                else {
                                    cout << numerator_1 << "/" << numerator_2 << endl;
                                    cout << "Please enter a rational number operation OR exit \n";
                                }

                            }
                        }
                        else {
                            cout << "Invalid operand. Try again! : " << endl;
                        }

                    }
                    else {
                        cout << "Invalid operator. Try again! : " << endl;
                    }
                }
                else {
                    cout << "Invalid expression, Try again!" << endl;
                }
            }

        }
        else if (choice == "2") {
            cout << "Thank you!";
            return 0;
        }
        else {
            cout << "enter right choice: ";
        }

    }
}