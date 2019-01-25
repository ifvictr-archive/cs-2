/*
 * Author  : Victor Truong & Nicholas Spector
 * CS 2    : MTWR, 7:30a – 12:30p
 * Lab 9   : Functions with Pass by Reference Parameters
 * Due date: 1/24/19
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool readNumsFromFile(string filename,
                      int &min,
                      int &max,
                      float &avg);

/*
 * Functions with Pass by Reference Parameters
 *
 * This program
 *
 * INPUT:
 *   exercise: The exercise to do
 *   filename: File to read numbers from
 *
 * OUTPUT:
 *   min: Smallest number in file
 *   max: Largest number in file
 *   avg: Average of all numbers from file
 */
int main()
{
    // cout <<
    //     "*****************************************\n"
    //     "  Author: Victor Truong & Nicholas Spector\n"
    //     "  ID    : 10180511\n"
    //     "  CS 2  : MTWR, 7:30a – 12:30p\n"
    //     "  Lab 9 : Functions with Pass by Reference Parameters\n"
    //     "*****************************************\n";


    int ex;          // INPUT: Exercise number to execute
    string filename; // INPUT: File to read numbers from
    int min;         // OUTPUT: Smallest number in file
    int max;         // OUTPUT: Largest number in file
    float avg;       // OUTPUT: Average of all numbers from file
    min = 0;
    max = 0;
    avg = 0;

    cout << "Which exercise? "; // Prompts the user to a certain exercise
    cin >> ex;
    cout << endl;

    switch (ex)
    {
        case 1:
            readNumsFromFile("numbers.dat", min, max, avg);
            cout << "The min is: " << min << endl;
            cout << "The max is: " << max << endl;
            cout << "The average is: " << avg << endl;
            break;
        case 2:
            cout << "Enter the name of the file: ";
            cin >> filename;

            cout << endl;
            if (readNumsFromFile(filename, min, max, avg))
            {
                cout << "The max number is: " << max << endl;
                cout << "The min number is: " << min << endl;
                cout << "The average is: " << avg << endl;
            }
            else
            {
                cout << "Cannot open the file!" << endl;
            }
            break;
    }
    return 0;
}

bool readNumsFromFile(string filename, int &min, int &max, float &avg)
{
    ifstream inFile; // INPUT: File object to readf rom
    int num;         // PROCESSING: Number to be processed
    int sum;         // PROCESSING: Sum of all numbers in file
    int numsCounted; // PROCESSING: Total numbers counted from file
    num = 0;
    sum = 0;
    numsCounted = 0;

    inFile.open(filename.c_str());
    if (!inFile)
    {
        return false;
    }

    inFile >> num;

    sum += num;
    numsCounted++;
    min = num;
    max = num;
    
    // PROCESSING: Find min, max, and average numbers
    while (inFile >> num)
    {
        sum += num;
        numsCounted++;
        
        if (num < min)
        {
            min = num;
        }
        if (num > max)
        {
            max = num;
        }
    }
    avg = sum / static_cast<float>(numsCounted);

    inFile.close();

    return true;
}