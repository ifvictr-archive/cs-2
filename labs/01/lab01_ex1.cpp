#include <iostream>
#include <string>

using namespace std;

int main() {
    int entry1;
    int entry2;

    cout << "Enter the first integer: ";
    cin >> entry1;
    cout << "\nEnter the second integer: ";
    cin >> entry2;

    cout << "\n";
    cout << entry1 << " + " << entry2 << " = " << (entry1 + entry2) << "\n";
    cout << entry1 << " * " << entry2 << " = " << (entry1 * entry2) << "\n";
    cout << entry1 << " / " << entry2 << " = " << (entry1 / entry2) << "\n";
    cout << entry1 << " % " << entry2 << " = " << (entry1 % entry2) << "\n";

    return 0;
}