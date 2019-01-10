/*
 * Author      : Victor Truong
 * CS 2        : MTWR, 7:30a – 12:30p
 * Assignment 2: Cash Register
 * Due date    : 1/13/19
 */
#include <iostream>
#include <string>

using namespace std;

/*
 * Cash Register
 * 
 * This program calculates the amount of dollars, quarters, dimes, nickels, and
 * pennies to give back.
 * 
 * INPUT:
 *   purchaseAmount: The purchase amount
 *   receivedAmount: The amount of money received
 *
 * OUTPUT:
 *   change  : Total change
 *   dollars : Amount of dollars to give back
 *   quarters: Amount of quarters to give back
 *   dimes   : Amount of dimes to give back
 *   nickels : Amount of nickels to give back
 *   pennies : Amount of pennies to give back
 */
int main() {
    cout <<
        "*****************************************\n"
        "  Author    : Victor Truong\n"
        "  ID        : 10180511\n"
        "  CS 2      : MTWR, 7:30a – 12:30p\n"
        "  Assignment: Cash Register\n"
        "*****************************************\n";

    float purchaseAmount; // INPUT: The purchase amount
    float receivedAmount; // INPUT: The amount of money received
    int change;           // PROC: Amount of change to return in pennies
    int dollars;          // OUTPUT: Amount of dollars to give back
    int quarters;         // OUTPUT: Amount of quarters to give back
    int dimes;            // OUTPUT: Amount of dimes to give back
    int nickels;          // OUTPUT: Amount of nickels to give back
    int pennies;          // OUTPUT: Amount of pennies to give back

    // INPUT: Prompt user for words
    cout << "Enter purchase amount: ";
    cin >> purchaseAmount;
    cout << "\nEnter amount received: ";
    cin >> receivedAmount;

    change = (receivedAmount - purchaseAmount) * 100 + 0.5;
    cout << "\nTotal Change: $" << (change / 100.0) << "\n";

    dollars = change / 100;
    change %= 100;
    quarters = change / 25;
    change %= 25;
    dimes = change / 10;
    change %= 10;
    nickels = change / 5;
    change %= 5;
    pennies = change;

    // OUTPUT: Generated story from user input
    cout << "\n";
    cout << "dollars " << dollars << "\n";
    cout << "quarters " << quarters << "\n";
    cout << "dimes " << dimes << "\n";
    cout << "nickels " << nickels << "\n";
    cout << "pennies " << pennies << "\n";

    return 0;
}