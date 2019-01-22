/*
 * Author  : Victor Truong
 * CS 2    : MTWR, 7:30a – 12:30p
 * Lab 7   : Intro to Functions - Liters and MPG
 * Due date: 1/22/19
 */
#include <iostream>

using namespace std;

const double LITERS_TO_GALLONS = 0.264179;

float mpgCalculator(float, float);

/*
 * Intro to Functions - Liters and MPG
 *
 * This program reads from an input file and outputs a formatted version
 *
 * INPUT:
 *   car1Liters  : The liters for car 1 -> input by user
 *   car1Miles   : The miles for car 1 -> input by user
 *   car2Liters  : The liters for car 2 -> input by user
 *   car2Miles   : The miles for car 2  -> input by user
 *   repeatChoice: User's decision to continue looping or not
 * OUTPUT:
 *   car1Mpg: Calculated MPG of car 1
 *   car2Mpg: Calculated MPG of car 2
 */
int main()
{
    char repeatChoice; // INPUT: User's decision to continue looping or not
    float car1Liters;  // INPUT: The liters for car 1 -> input by user
    float car1Miles;   // INPUT: The miles for car 1 -> input by user
    float car2Liters;  // INPUT: The liters for car 2 -> input by user
    float car2Miles;   // INPUT: The miles for car 2  -> input by user
    float car1Mpg;     // OUTPUT: Calculated MPG of car 1
    float car2Mpg;     // OUTPUT: Calculated MPG of car 2

    car1Liters = 0;
    car1Miles = 0;
    car2Liters = 0;
    car2Miles = 0;
    car1Mpg = 0;
    car2Mpg = 0;

    do
    {
        // INPUT
        cout << "Enter the number of liters of gas consumed: ";
        cin >> car1Liters;
        cout << "\nEnter the number of miles traveled: ";
        cin >> car1Miles;
        // OUTPUT
        cout << "\nThis car gets " << mpgCalculator(car1Liters, car1Miles)
            << " miles per gallon.\n";
        cout << "Calculate again? \n";
        cin >> repeatChoice;
    } while (repeatChoice != 'n');

    // INPUT
    cout << "\n\n";
    cout << "Enter the number of liters consumed for the first car: ";
    cin >> car1Liters;
    cout << "\nEnter the number of miles traveled for the first car: ";
    cin >> car1Miles;
    cout << "\nEnter the number of liters consumed for the second car: ";
    cin >> car2Liters;
    cout << "\nEnter the number of miles traveled for the second car: ";
    cin >> car2Miles;

    // PROCESSING
    car1Mpg = mpgCalculator(car1Liters, car1Miles);
    car2Mpg = mpgCalculator(car2Liters, car2Miles);

    // OUTPUT
    cout << "\n\n\n";
    cout << "The first car gets " << car1Mpg << " miles per gallon.\n";
    cout << "The second car gets " << car2Mpg << " miles per gallon.\n";

    if (car1Mpg > car2Mpg)
    {
        cout << "The first car has better gas mileage.\n";
    }
    else
    {
        cout << "The second car has better gas mileage.\n";
    }

    return 0;
}

float mpgCalculator(float liters, float miles)
{
    float gallons;
    float mpg;

    gallons = liters * LITERS_TO_GALLONS;
    mpg = miles / gallons;

    return mpg;
}