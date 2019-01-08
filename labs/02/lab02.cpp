#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int ex;
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;
    if (ex == 1) {
        // All Exercise 1 code
        int isbn;
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

        int checksum = (digit1 + (digit2 * 2) + (digit3 * 3) + (digit4 * 4) + (digit5 * 5) + (digit6 * 6) + (digit7 * 7) + (digit8 * 8) + (digit9 * 9)) % 11;

        cout << "\nChecksum: " << checksum << "\n";
    }
    else if (ex == 2) {
        // All Exercise 2 code
        char letter;
        int position;
        cout << "Enter a character: ";
        cin >> letter;
        position = letter - 96;
        cout << "\n" << letter << " is letter " << position << "\n";
    }

    return 0;
}