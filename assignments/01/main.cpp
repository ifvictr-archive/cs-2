/*
 * Author      : Victor Truong
 * CS 2        : MTWR, 7:30a – 12:30p
 * Assignment 1: Madlibs
 * Due date    : 1/8/19
 */
#include <iostream>
#include <string>

using namespace std;

/*
 * Madlibs
 * 
 * This program takes user input to generate a Madlib story.
 * 
 * INPUT:
 *   animal   : Type of animal
 *   food     : Type of food
 *   material1: Type of building material
 *   material2: Type of building material
 *   material3: Type of building material
 *   pastVerb1: Past verb 1
 *   pastVerb2: Past verb 2
 *   pastVerb3: Past verb 3
 *   noun1    : Noun 1
 *   noun2    : Noun 2
 *
 * OUTPUT:
 *   story: Resulting story from user inputs
 */
int main() {
    string animal;    // INPUT: Type of animal
    string food;      // INPUT: Type of food
    string material1; // INPUT: Type of building material
    string material2; // INPUT: Type of building material
    string material3; // INPUT: Type of building material
    string pastVerb1; // INPUT: Past verb 1
    string pastVerb2; // INPUT: Past verb 2
    string pastVerb3; // INPUT: Past verb 3
    string noun1;     // INPUT: Noun 1
    string noun2;     // INPUT: Noun 2

    string measuringStick(80, '-');

    // INPUT: Prompt user for words
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

    // OUTPUT: Generated story from user input
    cout << measuringStick << "\n";
    cout <<
        "Once upon a time there was an old mother " << animal << " who had "
        "three little\n" << animal << "s. She did not have enough " << food
        << " to feed them. So when they were\nold enough, she sent them out "
        "into the world to seek their fortunes.\n\n";
    cout <<
        "The first little " << animal << " was very lazy. He didn't want to "
        "work at all and he\nbuilt his house out of " << material1 << ". The "
        "second little " << animal << " worked a little\nbit harder but he was "
        "somewhat lazy too and he built his house out of\n" << material2
        << ". Then, they " << pastVerb1 << " and " << pastVerb2 << " and "
        << pastVerb3 << " together the\nrest of the day.\n\n";
    cout <<
        "The third little " << animal << " worked hard all day and built his"
        "house with \n" << material3 << ". It was a sturdy house complete with "
        " a fine " << noun1 << " and\n" << noun2 << ". It looked like it could "
        " withstand the strongest winds.\n";
    cout << measuringStick << "\n";

    return 0;
}