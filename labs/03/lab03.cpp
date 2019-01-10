/*
 * Author  : Victor Truong
 * CS 2    : MTWR, 7:30a – 12:30p
 * Lab 3   : Time and Menu
 * Due date: 1/10/19
 */
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

/*
 * Branching
 *
 * This program has 2 functions that changes the amount of seconds into
 * minutes, hours, and days. The second function provide a response to each
 * selection.
 *
 * INPUT:
 *   seconds  : the amount of seconds that the user wanted to convert
 *   choice   : answer chice selected by the user
 *
 * OUTPUT:
 *   Outputs the amount of seconds converted to minutes, hours, and days
 *
 *   Outputs a response based on choice selected by the user
 */
int main() {
    // cout <<
    //     "*****************************************\n"
    //     "  Author: Victor Truong\n"
    //     "  ID    : 10180511\n"
    //     "  CS 2  : MTWR, 7:30a – 12:30p\n"
    //     "  Lab 3 : Time and Menu\n"
    //     "*****************************************\n";

    int ex; // INPUT: Exercise number to execute

    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;

    if (ex == 1) {
        int seconds;
        cout << "Enter a number of seconds: ";
        cin >> seconds;

        if (seconds >= 86400) {
            int days = seconds / 86400;
            if (days > 1)
                cout << "\nThere are " << days << " days in " << seconds
                    << " seconds.\n";
            else 
                cout << "\nThere is " << days << " day in " << seconds
                    << " seconds.\n";
        }
        else if (seconds >= 3600) {
            int hours = seconds / 3600;
            if (hours > 1)
                cout << "\nThere are " << hours << " hours in " << seconds
                    << " seconds.\n";
            else 
                cout << "\nThere is " << hours << " hour in " << seconds
                    << " seconds.\n";
        }
        else {
            int minutes = seconds / 60;
            if (minutes > 1)
                cout << "\nThere are " << minutes << " minutes in " << seconds
                    << " seconds.\n";
            else 
                cout << "\nThere is " << minutes << " minute in " << seconds
                    << " seconds.\n";
        }
    }
    else if (ex == 2) {
        char choice;
        cout << "What do you want to do tonight?\n";
        cout << "a. Go to the movies\n";
        cout << "b. Eat out\n";
        cout << "c. Hang out at the Mall\n";
        cout << "d. Go watch the Dodgers\n";
        cin >> choice;
        if (choice == 'a' || choice == 'A'){
            cout << "I know just the movie to see!\n";
        }
        else if (choice == 'b' || choice == 'B') {
            cout << "Great! I've been wanting to try that new Tuvaluan "
                "restaurant!\n";
        }
        else if (choice == 'c' || choice == 'C') {
            cout << "You bring the cash!\n";
        }
        else if (choice == 'd' || choice == 'D') {
            cout << "Take me out to the ball game ...\n";
        }
        else {
            cout << "Nothing suits you, then? I guess we’ll just stay and "
                "program!\n";
        }
    }

    return 0;
}