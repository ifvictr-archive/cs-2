/**********************************************************
* AUTHOR    :Hongyuan Zhang, Victor Truong
* LAB       :Strings
* CLASS     :CS2
* SECTION   :
* DUE DATE  :1/31/19
***********************************************************/
#include <iostream>
#include <string>

using namespace std;

/******************************************************************************
 * replaceSubstring
 *  This function returns an updated version of s1
 *****************************************************************************/
string replaceSubstring(string s1,  // IN: string to find-and-replace in
                        string s2,  // IN: string to find
                        string s3); // IN: string to replace with

/************************************************************
* Lab 13: Strings
*___________________________________________________________
* This program executes exercise 1 and 2 for lab 13.
*___________________________________________________________
* IN:
*   s1: string to find-and-replace in
*   s2: string to find
*   s3: string to replace with
*
￼￼￼￼*************************************************************/
int main()
{
    int ex;      // IN: User's exercise choice
    string line; // IN & OUT: User input of the sentence
    string s1;   // IN: string to find-and-replace in
    string s2;   // IN: string to find
    string s3;   // IN: string to replace with

    // IN: Get exercise choice
    cout << "Which exercise?";
    cin >> ex;
    cin.ignore(1000, '\n');
    cout << endl << endl;

    switch (ex)
    {
        case 1:
            cout << "Enter a sentence (no spaces, 1st letter of each word isuppercase): ";
            getline(cin, line); // IN: User inputs the sentence
            cout << endl << endl;

            for (int i = 1; i < line.length() - 1; i++)
            {
                // PROC: check for uppercase not at the beginning
                if (isupper(line[i]))
                {
                    line[i] = tolower(line[i]); // PROC: convert to lowercase
                    line.insert(i, " "); // PROC: separate words by space
                }
            }
            cout << line << endl;                       // OUT: Output line
            break;
        case 2:
            cout << "Enter the main string: ";
            getline(cin, s1, '\n'); // IN: get s1 from user
            cout << endl;
            cout << "Enter the string to replace: ";
            getline(cin, s2, '\n'); // IN: get s2 from user
            cout << endl;
            cout << "Enter the replacement string: ";
            getline(cin, s3, '\n'); // IN: get s3 from user
            cout << endl;
            cout << replaceSubstring(s1, s2, s3) << endl;
                                                // OUT: ouput the updated string
            break;
    }
    cout << endl;

    return 0;

}

/******************************************************************************
*
* Function replaceSubstring
*------------------------------------------------------------------------------
* This function takes a string (s1), searches for all occurences of s2, and then
* replaces them with s3.
*------------------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need previously defined values:
*       s1: string to find-and-replace in
*       s2: string to find
*       s3: string to replace with
*
* POST-CONDITIONS
*       This function returns an updated version of s1.
******************************************************************************/
string replaceSubstring(string s1, string s2, string s3)
{
    // PROC: Keep finding and replacing instances of s2
    while (s1.find(s2) != string::npos)
    {
        s1.replace(s1.find(s2), s2.length(), s3);
    }

    return s1;
}