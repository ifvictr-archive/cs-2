/*
 * Author  : Victor Truong
 * CS 2    : MTWR, 7:30a – 12:30p
 * Lab 4   : Loops
 * Due date: 1/14/19
 */
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

/*
 * Loops
 *
 * This program has 3 functions that:
 *   1) let's you know if your string contains "e" or "x"
 *   2) converts a string into leet
 *   3) find position of "." and "stop"
 *
 * INPUT:
 *   ex      : the exercise to do
 *   word    : the word to process
 *   sentence: the sentence to search through
 *
 * OUTPUT:
 *   Outputs if "e" or "x" is present, leet version of string, and position of
 *   "." and "stop"
 *
 *   Outputs a response based on choice selected by the user
 */
int main() {
    // cout <<
    //     "*****************************************\n"
    //     "  Author: Victor Truong\n"
    //     "  ID    : 10180511\n"
    //     "  CS 2  : MTWR, 7:30a – 12:30p\n"
    //     "  Lab 4 : Loops\n"
    //     "*****************************************\n";

    int ex; // INPUT: Exercise number to execute

    cout << "Which exercise: "; // Prompts the user to a certain exercise
    cin >> ex;
    cout << endl;

    if (ex == 1) {
        string word;
        bool hasE = false; // Boolean for if the word has the letter e
        bool hasX = false; // Boolean for if the word has the letter x
        cout << "Enter a word: ";
        cin >> word;
        cout << "\n";
        // PROCESSING: Loop through to check for 'e' and 'x'
        for (int pos = 0; pos < word.size(); pos++) {
            char letter = word.at(pos);
            if (letter == 'e') {
                hasE = true;
            }
            else if (letter == 'x') {
                hasX = true;
            }
        }
        // OUTPUT: If word contains 'e' or 'x'
        if (hasE) {
            cout << "Your word " << word << " contains the character 'e'\n";
        }
        if (hasX) {
            cout << "Your word " << word << " contains the character 'x'\n";
        }
    }
    else if (ex == 2) {
        string word;
        cout << "Enter a word: ";
        cin >> word;
        // PROCESSING: Converts 'e', '1', and 'x' to leet
        for (int pos = 0; pos < word.size(); pos++) {
            char letter = word.at(pos);
            if (letter == 'e') {
                word.at(pos) = '3';
            }
            else if (letter == 'i') {
                word.at(pos) = '1';
            }
            else if (letter == 'x') {
                word.at(pos) = '*';
            }
        }
        cout << "\nYour word transformed is " << word << endl;
    }
    else if (ex == 3) {
        string sentence; // INPUT: Sentence to process
        cout << "Enter a sentence: ";
        cin >> sentence;
        cout << "\n";
        int periodPos = sentence.find('.');
        int stopPos = sentence.find("stop");
        // OUTPUT: Let user know if sentence contains "." or "stop"
        if (periodPos == string::npos) {
            cout << "Your sentence does not contain the character '.'\n";
        }
        else {
            cout << "The character '.' is located at index " << periodPos
                << "\n";
        }
        if (stopPos == string::npos) {
            cout << "Your sentence does not contain the word \"stop\"\n";
        }
        else {
            cout << "The word \"stop\" is located at index " << stopPos << "\n";
        }
    }
    return 0;
}