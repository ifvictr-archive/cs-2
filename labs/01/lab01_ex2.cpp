#include <iostream>
#include <string>

using namespace std;

int main() {
    double entry1;
    double entry2;
    double entry3;
    double entry4;
    double entry5;
    double entry6;

    cout << "Enter six fp numbers on a single line, separated by spaces: ";
    cin >> entry1;
    cin >> entry2;
    cin >> entry3;
    cin >> entry4;
    cin >> entry5;
    cin >> entry6;

    double sum = entry1 + entry2 + entry3 + entry4 + entry5 + entry6;
    double avg = sum / 6;
    cout << "\n";
    cout << "Sum of " << entry1 << " + " << entry2 << " + " << entry3 << " + " << entry4 << " + " << entry5 << " + " << entry6 << " = " << sum << "\n";
    cout << "Average = " << avg << "\n";

    return 0;
}