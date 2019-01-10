/*
 * Author      : Victor Truong
 * CS 2        : MTWR, 7:30a – 12:30p
 * Assignment 3: Mathematics Specification
 * Due date    : 1/13/19
 */
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

/*
 * Mathematics Specification
 * 
 * This program...
 * 
 * INPUT:
 *   operation: The operation user wants to perform
 *   num1     : Input 1 for calculation
 *   num2     : Input 2 for calculation
 *   num3     : Input 3 for calculation
 *
 * OUTPUT:
 *   Outputs the equation of the operation and the result from the calculation.
 */
int main() {
    // cout <<
    //     "*****************************************\n"
    //     "  Author    : Victor Truong\n"
    //     "  ID        : 10180511\n"
    //     "  CS 2      : MTWR, 7:30a – 12:30p\n"
    //     "  Assignment: Mathematics Specification\n"
    //     "*****************************************\n";

    string operation;
    float num1;
    float num2;
    float num3;

    // INPUT: Prompt user
    cout << "Please choose an operation: ";
    cin >> operation;
    if (
        operation == "addition" ||
        operation == "division" ||
        operation == "multiplication" ||
        operation == "subtraction" ||
        operation == "fabs" ||
        operation == "pythagorean" ||
        operation == "quadratic" ||
        operation == "sqrt"
    ) {
        cout << "\nEnter your first number: ";
        cin >> num1;
        if (!(operation == "fabs" || operation == "sqrt")) {
            cout << "\nEnter your second number: ";
            cin >> num2;
            if (operation == "quadratic") {
                cout << "\nEnter your third number: ";
                cin >> num3;
            }
        }
    }
    else {
        cout << "Error: Operation not supported.\n";
    }
    // OUTPUT: Generated story from user input
    cout << "\n";
    if (operation == "addition") {
        cout << "Equation: " << num1 << " + " << num2 << "\n";
        cout << "Result: " << (num1 + num2) << "\n";
    }
    else if (operation == "division") {
        cout << "Equation: " << num1 << " / " << num2 << "\n";
        if (!num2) {
            cout << "Error: Cannot divide by zero.\n";
        }
        else {
            cout << "Result: " << (num1 / num2) << "\n";
        }
    }
    else if (operation == "multiplication") {
        cout << "Equation: " << num1 << " * " << num2 << "\n";
        cout << "Result: " << (num1 * num2) << "\n";
    }
    else if (operation == "subtraction") {
        cout << "Equation: " << num1 << " - " << num2 << "\n";
        cout << "Result: " << (num1 - num2) << "\n";
    }
    else if (operation == "fabs") {
        cout << "Equation: fabs(" << num1 << ")\n";
        cout << "Result: " << fabs(num1) << "\n";
    }
    else if (operation == "pythagorean") {
        cout << "Equation: sqrt(" << num1 << "^2 + " << num2 << "^2)\n";
        cout << "Result: " << sqrt(pow(num1, 2) + pow(num2, 2)) << "\n";
    }
    else if (operation == "quadratic") {
        cout << "Equation: " << num1 << "x^2 + " << num2 << "x + " << num3
            << " = 0\n";
        float discriminant = pow(num2, 2) - (4 * num1 * num3);
        if (discriminant < 0) {
            cout << "Error: Cannot take square root of a negative number.\n";
        }
        else {
            float answer1 = (-1 * num2 + sqrt(discriminant)) / (2 * num1);
            float answer2 = (-1 * num2 - sqrt(discriminant)) / (2 * num1);
            cout << "Result: " << answer1 << ", " << answer2 << "\n";
        }

    }
    else if (operation == "sqrt") {
        cout << "Equation: sqrt(" << num1 << ")\n";
        if (num1 < 0) {
            cout << "Error: Cannot take square root of a negative number.\n";
        }
        else {
            cout << "Result: " << sqrt(num1) << "\n";
        }
    }

    return 0;
}