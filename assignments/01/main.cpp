#include <iostream>
#include <string>

using namespace std;

int main() {
    string animal;
    string food;
    string material1;
    string material2;
    string material3;
    string pastVerb1;
    string pastVerb2;
    string pastVerb3;
    string noun1;
    string noun2;

    string measuringStick(80, '-');

    // Prompt for input
    cout << "Please enter a type of animal: ";
    cin >> animal;
    cout << "\nPlease enter a type of food: ";
    cin >> food;
    cout << "\nPlease enter a building material (1/3): ";
    cin >> material1;
    cout << "\nPlease enter a building material (2/3): ";
    cin >> material2;
    cout << "\nPlease enter a building material (3/3): ";
    cin >> material3;
    cout << "\nPlease enter a past-tense verb (1/3): ";
    cin >> pastVerb1;
    cout << "\nPlease enter a past-tense verb (2/3): ";
    cin >> pastVerb2;
    cout << "\nPlease enter a past-tense verb (3/3): ";
    cin >> pastVerb3;
    cout << "\nPlease enter a noun (1/2): ";
    cin >> noun1;
    cout << "\nPlease enter a noun (2/2): ";
    cin >> noun2;
    cout << "\n";

    // Output madlib result
    cout << measuringStick << "\n";
    cout <<
        "Once upon a time there was an old mother " << animal << " who had three little\n"
        << animal << "s. She did not have enough " << food << " to feed them. So when they were\n"
        "old enough, she sent them out into the world to seek their fortunes.\n\n";
    cout <<
        "The first little " << animal << " was very lazy. He didn't want to work at all and he\n"
        "built his house out of " << material1 << ". The second little " << animal << " worked a little\n"
        "bit harder but he was somewhat lazy too and he built his house out of\n"
        << material2 << ". Then, they " << pastVerb1 << " and " << pastVerb2 << " and " << pastVerb3 << " together the\n"
        "rest of the day.\n\n";
    cout <<
        "The third little " << animal << " worked hard all day and built his house with \n"
        << material3 << ". It was a sturdy house complete with a fine " << noun1 << " and\n"
        << noun2 << ". It looked like it could withstand the strongest winds.\n";
    cout << measuringStick << "\n";

    return 0;
}