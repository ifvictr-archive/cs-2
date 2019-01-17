/*
 * Author  : Victor Truong
 * CS 2    : MTWR, 7:30a – 12:30p
 * Lab 5   : Manipulators and File IO
 * Due date: 1/17/19
 */
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

/*
 * Manipulators and File IO
 *
 * This program reads from an input file and outputs a formatted version
 *
 * INPUT:
 *   rectLength    : Length of the rectangle
 *   rectWidth     : Width of the rectangle
 *   circleRadius  : Radius of the circle
 *   firstName     : First name of the person
 *   lastName      : Last name of the person
 *   age           : Age of the person
 *   savingsBalance: Savings balance of the person
 *   annualInterest: Annual interest of the balance
 *   letter        : Letter in between A and Y (inclusive)
 *
 * OUTPUT:
 *   rectArea     : Area calculated from length and width
 *   rectPerimeter: Perimeter calculated from length and width
 *   circleArea   : Area calculated from radius
 *   circleCircum : Circumference calculated from radius
 *   endBalance   : Savings balance with interest applied
 *   nextLetter   : Letter following the input letter
 */
int main() {
    const float PI = 3.14159;

    ifstream inFile;
    ofstream outFile;
    float rectLength;
    float rectWidth;
    float circleRadius;
    string firstName;
    string lastName;
    int age;
    float savingsBalance;
    float annualInterest;
    char letter;
    float rectArea;
    float rectPerimeter;
    float circleArea;
    float circleCircum;
    float endBalance;
    char nextLetter;

    inFile.open("inData.txt");
    outFile.open("outData.txt");

    inFile >> rectLength >> rectWidth;
    inFile >> circleRadius;
    inFile >> firstName >> lastName >> age;
    inFile >> savingsBalance >> annualInterest;
    inFile >> letter;

    rectArea = rectLength * rectWidth;
    rectPerimeter = (rectWidth + rectLength) * 2;
    circleArea = PI * circleRadius * circleRadius;
    circleCircum = 2 * PI * circleRadius;
    endBalance = savingsBalance * (1 + (annualInterest / 12) / 100);
    nextLetter = letter + 1;

    cout << fixed << setprecision(2);
    cout << "Rectangle:\n";
    cout << "Length = " << rectLength << ", width = " << rectWidth << ", area = " << rectArea << ", perimeter = " << rectPerimeter << "\n\n";
    cout << "Circle:\n";
    cout << "Radius = " << circleRadius << ", area = " << circleArea << ", circumference = " << circleCircum << "\n\n";
    cout << "Name: " << firstName << " " << lastName << ", age: " << age << "\n";
    cout << "Beginning balance = $" << savingsBalance << ", interest rate = " << annualInterest << "\n";
    cout << "Balance at the end of the month = $" << endBalance << "\n\n";
    cout << "The character that comes after " << letter << " in the ASCII set is " << nextLetter << "\n";

    inFile.close();
    outFile.close();

    return 0;
}