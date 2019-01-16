/*
 * Author  : Victor Truong
 * CS 2    : MTWR, 7:30a – 12:30p
 * Lab 5   : More Loops
 * Due date: 1/16/19
 */
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

/*
 * More Loops
 *
 * This program has 3 functions that:
 *   1) Print numbers counting by 1, by 2, and by *-2
 *   2) Input grades
 *   3) Toss a coin and get heads or tails
 *
 * INPUT:
 *   exercise: the exercise to do
 *   n1      : first number to input (lower than second number)
 *   n2      : second number to input
 *   grades  : list of grades to input
 *   choice  : yes or no choice to cointinue
 *
 * OUTPUT:
 *   Outputs numbers counting by 1, by 2, and by *-2
 *   Outputs total amount of grades received by students for each letter grade
 *   Outputs heads or tails based on choice selected by the user
 */
int main() {
    // cout <<
    //     "*****************************************\n"
    //     "  Author: Victor Truong\n"
    //     "  ID    : 10180511\n"
    //     "  CS 2  : MTWR, 7:30a – 12:30p\n"
    //     "  Lab 5 : More Loops\n"
    //     "*****************************************\n";

    // srand(time(0));

    int ex; // INPUT: Exercise number to execute

    cout << "Which exercise? "; // Prompts the user to a certain exercise
    cin >> ex;
    cout << endl;

    if (ex == 1) {
        int n1; // INPUT: Number to start loop from
        int n2; // INPUT: Number to end loop at
        cout << "Enter beginning and ending numbers, separated by space: ";
        cin >> n1;
        cin >> n2;
        cout << "\n";
        // OUTPUT: Counts from n1 to n2 by 1s
        for (int i = n1; i <= n2; i++) {
            if (i != n1) {
                cout << ", ";
            }
            cout << i;
        }
        cout << "\nEnter beginning and ending numbers, separated by space: ";
        cin >> n1;
        cin >> n2;
        cout << "\n";
        // OUTPUT: Counts from n1 to n2 by 2s
        for (int i = n1; i <= n2; i += 2) {
            if (i != n1) {
                cout << ", ";
            }
            cout << i;
        }
        cout << "\nEnter the beginning and largest positive numbers, separated "
            << "by space: ";
        cin >> n1;
        cin >> n2;
        cout << "\n";
        // OUTPUT: Counts from n1 to n2 by *-2
        for (int i = n1; fabs(i) <= n2; i *= -2) {
            if (i != n1) {
                cout << ", ";
            }
            cout << i;
        }
        cout << "\n";
    }
    else if (ex == 2) {
        int aCount = 0;
        int bCount = 0;
        int cCount = 0;
        int dCount = 0;
        int fCount = 0;
        bool isFinished = false;
        int grade;
        while (!isFinished) {
            cout << "Enter one or more grades, or -1 to stop: \n";
            cin >> grade;
            if (grade == -1) {
                isFinished = true;
                break;
            }
            if (grade >= 90 && grade <= 100) {
                aCount++;
            }
            else if (grade >= 80 && grade <= 89) {
                bCount++;
            }
            else if (grade >= 70 && grade <= 79) {
                cCount++;
            }
            else if (grade >= 60 && grade <= 69) {
                dCount++;
            }
            else if (grade >= 0 && grade <= 59) {
                fCount++;
            }
        }
        cout << "The grades breakdown is: \n";
        cout << "As: " << aCount << "\n";
        cout << "Bs: " << bCount << "\n";
        cout << "Cs: " << cCount << "\n";
        cout << "Ds: " << dCount << "\n";
        cout << "Fs: " << fCount << "\n";
    }
    else if (ex == 3) {
        string choice = "yes"; // INPUT: Determine whether to continue or not
        while (choice == "yes") {
            cout << "Toss the coin? ";
            cin >> choice;
            cout << "\n";
            if (choice == "yes") {
                int side = rand() % 2;
                if (side == 0) {
                    cout << "heads\n";
                }
                else {
                    cout << "tails\n";
                }
            }
        }
    }
    return 0;
}