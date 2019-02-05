/*
 * Author  : Victor Truong & Yong Qiang Zhang
 * CS 2    : MTWR, 7:30a – 12:30p
 * Lab 14  : Vectors
 * Due date: 2/5/19
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * split
 *
 * This function breaks the target string into multiple strings based on the
 * specified delimiter
 */
vector<string> split(string target,     // IN: String to split
                     string delimiter); // IN: String to split target by

/*
 * Vectors
 *
 * This program takes a string from the user and returns all the words separated
 * at a delimiter.
 *
 * IN:
 *   input    : String to split
 *   delimiter: String to split target by
 * OUT:
 *   splitInput: All strings separated by delimiter
 */
int main()
{
    string target;             // IN: String to split
    string delimiter;          // IN: String to split target by
    vector<string> splitInput; // OUT: All strings separated by delimiter

    // IN: Prompt user
    cout << "Enter the target string: ";
    getline(cin, target);
    cout << endl;
    cout << "Enter the delimiter: ";
    getline(cin, delimiter);
    cout << endl;

    // PROC: Handle user input
    splitInput = split(target, delimiter);

    // OUT: Show strings separated by delimiter
    for (int i = 0; i < splitInput.size(); i++)
    {
        cout << splitInput.at(i) << endl;
    }
    cout << endl;
}

/*
 * FUNCTION split
 *
 * This function breaks the target string into multiple strings based on the
 * specified delimiter
 *
 * PRE-CONDITIONS
 *   target   : String to split
 *   delimiter: String to split target by
 *
 * POST-CONDITIONS
 *   Returns all strings separated by delimiter
 */
vector<string> split(string target, string delimiter)
{
    vector<string> pieces; // OUT: All strings split by delimiter
    string currPiece;      // PROC: Substring up to delimiter

    // PROC: Keep looking for instances of delimiter
    while (target.find(delimiter) != string::npos)
    {
        currPiece = target.substr(0, target.find(delimiter));
        // PROC: Remove current piece from string
        target = target.substr(currPiece.length() + delimiter.length(), target.length());
        // PROC: Ignore empty strings
        if (currPiece.length() > 0)
        {
            pieces.push_back(currPiece);
        }
    }
    pieces.push_back(target); // PROC: Add remaining portion of string

    return pieces;
}