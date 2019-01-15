/*
 * Author      : Victor Truong
 * CS 2        : MTWR, 7:30a – 12:30p
 * Assignment 4: Game of Pig
 * Due date    : 1/13/19
 */
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

/*
 * Mathematics Specification
 * 
 * This program...
 * 
 * INPUT:
 *   operation: The operation user wants to perform
 *   num1     : Input 1 for calculation
 *   num2     : Input 2 for calculation
 *   num3     : Input 3 for calculation
 *
 * OUTPUT:
 *   Outputs the equation of the operation and the result from the calculation.
 */
int main() {
    // cout <<
    //     "*****************************************\n"
    //     "  Author    : Victor Truong\n"
    //     "  ID        : 10180511\n"
    //     "  CS 2      : MTWR, 7:30a – 12:30p\n"
    //     "  Assignment: Game of Pig\n"
    //     "*****************************************\n";

    // srand(time(0));
    srand(333);

    int holdValue;
    float maxSims;
    int poss1;
    int poss2;
    int poss3;
    int poss4;
    int poss5;
    int poss6;
    int poss7;
    int gotPoss1 = 0;
    int gotPoss2 = 0;
    int gotPoss3 = 0;
    int gotPoss4 = 0;
    int gotPoss5 = 0;
    int gotPoss6 = 0;
    int gotPoss7 = 0;

    cout << "What value should we hold at? ";
    cin >> holdValue;
    cout << "\nHold-at-N turn simulations? ";
    cin >> maxSims;

    poss1 = 0;
    poss2 = holdValue;
    poss3 = holdValue + 1;
    poss4 = holdValue + 2;
    poss5 = holdValue + 3;
    poss6 = holdValue + 4;
    poss7 = holdValue + 5;
    for (int i = 0; i < maxSims; i++) {
        int score = 0;
        while (score < holdValue) {
            int random = rand() % 6 + 1; // Random number from 1-6
            if (random == 1) {
                score = 0;
                break;
            }
            else {
                score += random;
            }
        }
        if (score == poss1) {
            gotPoss1++;
        }
        else if (score == poss2) {
            gotPoss2++;
        }
        else if (score == poss3) {
            gotPoss3++;
        }
        else if (score == poss4) {
            gotPoss4++;
        }
        else if (score == poss5) {
            gotPoss5++;
        }
        else if (score == poss6) {
            gotPoss6++;
        }
        else if (score == poss7) {
            gotPoss7++;
        }
    }

    cout << left << setw(8) << "\nScore\tEstimated Probability" << endl;
    cout << setprecision(6) << fixed;
    cout << left << poss1 << "\t" << (gotPoss1 / maxSims) << endl;
    cout << left << poss2 << "\t" << (gotPoss2 / maxSims) << endl;
    cout << left << poss3 << "\t" << (gotPoss3 / maxSims) << endl;
    cout << left << poss4 << "\t" << (gotPoss4 / maxSims) << endl;
    cout << left << poss5 << "\t" << (gotPoss5 / maxSims) << endl;
    cout << left << poss6 << "\t" << (gotPoss6 / maxSims) << endl;
    cout << left << poss7 << "\t" << (gotPoss7 / maxSims) << endl;

    return 0;
}