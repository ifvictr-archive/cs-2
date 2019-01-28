/*********************************************************
 *  AUTHOR          : Nicholas Spector & Victor Truong
 *  Lab #8          : Functions
 *  CLASS           : CS2
 *  SECTION         : MTWR: 07:30a – 12:30p
 *  Due Date        : 01/23/19
 *********************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*******************************************************************************
* Functions
*
* Exercise 1:
* This program calculates the sum of the digits of a number and outputs a table
* of prime numbers in a range (based on user input).
*
* Exercise 2:
* This program prompts the user for two numbers. It then finds all of the prime
* numbers between the two numbers and prints them in a table to the user.
*
* INPUT:
*
*   ex              : The exercise that the user will choose -> input by user
*   EXERCISE 1
*   num             : Number whose digits will be summed up -> input by user
*   EXERCISE 2
*   number_one      : Starting number of range to check for prime numbers in
*                     -> input by user
*   number_two      : ending number of range to check for prime numbers in
*                     -> input by user
*
* OUTPUT:
*
*   EXERCISE 1:
*   SumDigits()     : Sum of all the digits in number
*
*   EXERCISE 2:
*   prime_number    : Outputs each prime number between number one and two
*
*
*******************************************************************************/

/****************************************************************
* IsPrime
*   Finds out whether the number is prime or not prime
*   - returns the true if number is prime and false if not prime
****************************************************************/
bool IsPrime(
                int number);    // IN - Number to check if it's prime

/****************************************************************
* SumDigits
*   This function receives an integer and returns the sum of all
*   the digits
*   - returns the sum of all of the digits
****************************************************************/
int SumDigits(
                int number);    // IN - Numbers whose digits will be summed
                                // together

int main()
{

    int ex;           // INPUT - The exercise that the user is choosing

    // INPUT - User is asked to type in the exercise number
    cout << "Which exercise? ";
    ex = 0;
    cin >> ex;
    cout << "\n";

    // PROCESSING - Chooses exercise 1 if "1" is chosen
    if(ex == 1)
    {

        int num;      // INPUT - The integer whose digits will be summed

        // INITIALIZE VARIABLES
        num = 0;

        // PROCESSING - Loops, allowing user to continue doing calculations
        // until they put in '0' to quit
        do
        {

            // INPUT - Prompts user to enter an integer or a 0 to quit
            cout << "Please enter an integer (0 to quit): ";
            cin >> num;
            cout << "\n";

            // PROCESSING - If user doesn't put in 0
            if (num != 0)
            {

                // OUTPUT - Prints out the sum of the digits of the number
                // to the user
                cout << "The sum of the digits of " << num << " is "
                     << SumDigits(num) << "\n";

            }

            // PROCESSING & OUT - If user puts in 0, then "Goodbye" is printed
            // to the user
            else
            {
                cout << "Goodbye \n";
            }

        } while (num != 0);
    }

    // PROCESSING: Chooses exercise 2 if '2' is chosen
    if(ex == 2)
    {

        int number_one;       // INPUT - The first number
        int number_two;       // INPUT - The second number
        int numberOnLine;     // CALC - Keeps track of how many words are
                              // currently on the line

        // INITIALIZES VARIABLES
        number_one = 0;
        number_two = 0;
        numberOnLine = 1;

        // INPUT - Prompts the user to input two positive numbers
        cout << "Please input two positive numbers: ";
        cin >> number_one >> number_two;

        // OUTPUT - Reiterates the positive numbers to the sceen
        cout << "\nThe prime numbers between " << number_one << " and "
             << number_two << " are: \n";

        // PROCESSING - Goes through each number between the inputted numbers
        for( ; number_one < number_two; number_one++)
        {

            // PROCESSING - Checks if the number is prime, if so it prints it
            // to a table
            if(IsPrime(number_one))
            {

                // OUTPUT - Prints out the number and a tab
                cout << number_one << "\t";

                // PROCESSING - If 8 numbers have been printed, then create
                // a new line
                if(numberOnLine == 8)
                {
                    cout << "\n";
                    numberOnLine = 1;

                }

                // PROCESSING - If there still isn't 8 numbers on a line, then
                // add one to the count
                else
                {
                    numberOnLine++;
                }

            }
        }

        cout << "\n";

    }

    return 0;

}


/*******************************************************************************
 *
 * FUNCTION IsPrime
 *_________________________________________________________
 *
 * This function returns a true bool if the number passed to it is prime. If it
 * is not prime, it returns false.
 *
 * _________________________________________________________
 * PRE-CONDITIONS
 *  number:    The number that is being checked to see if it is prime
 *
 * POST-CONDITIONS
 *  Will return true if number is prime and false if it is not.
 ******************************************************************************/
bool IsPrime(int number)
{

    int x;                  // CALC - Used to loop through the numbers of
                            // of the number being prime checked

    // INITIALIZES VARIABLE
    x = 0;

    // PROCESSING - Loops through half of the numbers of the numbering being
    // prime checked
    for(x = 2; x <= number / 2; x++)
    {

        // PROCESSING - If the modulus of the number and one of the numbers
        // lesser than it equals 0, then the number is not prime
        if(number % x == 0)
            return false;

    }

    return true;
}

/*******************************************************************************
 *
 * FUNCTION SumDigits
 *_________________________________________________________
 *
 * Finds the sum of all of the individual digits in a number.
 *
 * _________________________________________________________
 * PRE-CONDITIONS
 *  number:    The number whose digits are all being summed together
 *
 * POST-CONDITIONS
 *  sum:       Will return the sum of all of the digits individually added
 *             together
 ******************************************************************************/
int SumDigits(int number)      
{
    int sum;                     // CALC & OUT - Used to hold the sum of the
                                 // digits and is returned
    int currDigit;               // CALC - Holds the digit that is being worked
                                 // on

    // INITIALIZES VARIABLES
    sum = 0;
    currDigit = 0;

    // PROCESSING - Finds absolute value of number
    number = abs(number);

    // PROCESSING - Loops until each digit is summed
    while (number > 0)
    {

        // PROCESSING - Fins the digit on the far right, adds it to the sum
        // then it divides the number by 10 so that the next digit could be
        // moved to the far right
        currDigit = number % 10;
        sum += currDigit;
        number /= 10;
    }

    return sum;

}



