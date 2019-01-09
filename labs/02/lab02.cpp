/*
 * Author  : Victor Truong
 * CS 2    : MTWR, 7:30a – 12:30p
 * Lab 2   : Arithmetic Operations and Data Types
 * Due date: 1/8/19
 */
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

/*
 * ISBN Checksum / Letter Position Calculator
 *
 * This program calculates the checksum of a given ISBN and also the position
 * of a given letter in the alphabet chart.
 * 
 * INPUT:
 *   ex  : Exercise number to execute
 *   isbn: ISBN to calculate checksum
 *
 * OUTPUT:
 *   checksum: Checksum of ISBN
 *   position: Position of the letter in the alphabet
 */
int main() {
    cout <<
        "*****************************************\n"
        "  Author: Victor Truong\n"
        "  ID    : 10180511\n"
        "  CS 2  : MTWR, 7:30a – 12:30p\n"
        "  Lab 2 : Arithmetic Operations and Data Types\n"
        "*****************************************\n";

    int ex; // INPUT: Exercise number to execute

    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;

    if (ex == 1) {
        // All Exercise 1 code
        int isbn; // INPUT: ISBN to calculate checksum
        cout << "Please enter the first 9 digits of the ISBN: ";
        cin >> isbn;

        int digit9 = isbn % 10;
        isbn /= 10;
        int digit8 = isbn % 10;
        isbn /= 10;
        int digit7 = isbn % 10;
        isbn /= 10;
        int digit6 = isbn % 10;
        isbn /= 10;
        int digit5 = isbn % 10;
        isbn /= 10;
        int digit4 = isbn % 10;
        isbn /= 10;
        int digit3 = isbn % 10;
        isbn /= 10;
        int digit2 = isbn % 10;
        isbn /= 10;
        int digit1 = isbn % 10;

        int checksum = (digit1 +
            (digit2 * 2) +
            (digit3 * 3) +
            (digit4 * 4) +
            (digit5 * 5) +
            (digit6 * 6) +
            (digit7 * 7) +
            (digit8 * 8) +
            (digit9 * 9)
        ) % 11; // OUTPUT: Checksum of ISBN

        cout << "\nChecksum: " << checksum << "\n";
    }
    else if (ex == 2) {
        // All Exercise 2 code
        char letter;  // INPUT: Letter to calculate position of
        int position; // OUTPUT: Position of the letter in the alphabet

        cout << "Enter a character: ";
        cin >> letter;

        position = 26 - ('z' - letter);
        cout << "\n" << letter << " is letter " << position << "\n";
    }

    return 0;
}