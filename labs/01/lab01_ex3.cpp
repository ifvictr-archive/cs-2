#include <iostream>

using namespace std;

int main() {
    int age;
    double lowerLimit;
    double upperLimit;

    cout << "What is your age: \n";
    cin >> age;
    lowerLimit = (220 - age) * 0.6;
    upperLimit = (220 - age) * 0.75;
    cout << "Your target heart rate is between " << lowerLimit << " and " << upperLimit << " bpm.\n";

    return 0;
}