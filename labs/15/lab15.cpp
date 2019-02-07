/**************************************************************************
 * AUTHOR             : Kevin Ngo & Victor Truong
 * LAB 15             : Movie Data
 * CLASS              : CS 002
 * SECTION            : MW: 7:30a - 12:30p
 * DUE DATE           : 02/06/2019
 *************************************************************************/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**************************************************************************
 * Movie Data
 *
 * _______________________________________________________________________
 * Description
 *
 *      In this lab, the user must input a MovieData, which consists of a
 *      title, director, year, and runtime. This will be added to an array
 *      of other MovieData, which all hold information on films. 10 of
 *      which must be extracted from a txt file while one must be hard
 *      coded in through the code.
 *
 * _______________________________________________________________________
 * INPUT:
 *      m: A movie data that will hold the information of the movies.
 * OUTPUT:
 *      List all information of movies
 *************************************************************************/

struct MovieData
{
    string title;
    string director;
    int year;
    int runtime;
};

/**************************************************************************
 * FUNCTION
 *      recordData
 *
 * _______________________________________________________________________
 * Description
 *      Returns whether or not the file has been found. If it has, it will
 *      record the information into the array.
 * _______________________________________________________________________
 * PRE-CONDITION:
 *      m: an array that holds movie information
 * POST-CONDITION:
 *      returns a bool on whether or not the file could be opened
 *************************************************************************/
bool recordData(MovieData m[]); // IN: An array that holds movie information

/**************************************************************************
 * FUNCTION
 *      printMovieData
 *
 * _______________________________________________________________________
 * Description
 *      Will print out the movie information
 * _______________________________________________________________________
 * PRE-CONDITION:
 *      m: an array that holds movie information
 * POST-CONDITION:
 *      none
 *************************************************************************/
void printMovieData(const MovieData &m); // IN: An array that holds movie information

int main()
{
    MovieData m[12]; // PROC: Array to store all movies

    // PROC: Hardcode first movie
    m[0] = {"Apollo 13", "Ron Howard", 1995, 140};

    // IN: Get one movie from user
    cout << "Enter Title: " << endl;
    getline(cin, m[1].title);
    cout << "Enter Director: " << endl;
    getline(cin, m[1].director);
    cout << "Enter Year Released: " << endl;
    cin >> m[1].year;
    cout << "Enter Running Time (in minutes): " << endl;
    cin >> m[1].runtime;
    cin.ignore(2);

    // PROC: Attempt to save movie info from file
    bool found = recordData(m);
    if (!found)
    {
        cout << "Error in finding file" << endl;
        return 1;
    }

    // OUT: Print out all movie data
    for (int i = 0; i < 12; i++)
    {
        printMovieData(m[i]);
        cout << endl;
    }

    return 0;
}


/**************************************************************************
 * FUNCTION
 *      recordData
 *
 * _______________________________________________________________________
 * Description
 *      Returns whether or not the file has been found. If it has, it will
 *      record the information into the array.
 * _______________________________________________________________________
 * PRE-CONDITION:
 *      m: an array that holds movie information
 * POST-CONDITION:
 *      returns a bool on whether or not the file could be opened
 *************************************************************************/
bool recordData(MovieData m[])
{
    ifstream file; // PROC: File to fetch movie info from
    file.open("movies.txt");
    if (file)
    {
        // PROC: Save all movies into the array
        for (int i = 2; i < 12; i++)
        {
            getline(file, m[i].title);
            getline(file, m[i].director);
            file >> m[i].year;
            file >> m[i].runtime;
            file.ignore(2);
        }
    }
    else
    {
        return false;
    }
    file.close(); // PROC: Close file after using

    return true;
}

/**************************************************************************
 * FUNCTION
 *      printMovieData
 *
 * _______________________________________________________________________
 * Description
 *      Prints out the movie information
 * _______________________________________________________________________
 * PRE-CONDITION:
 *      m: an array that holds movie information
 * POST-CONDITION:
 *      prints out all the information about the movie that was passed in
 *************************************************************************/
void printMovieData(const MovieData &m)
{
    cout << "Title: " << m.title << "\nDirector: " << m.director
        << "\nYear released: " << m.year << "\nRunning Time: " << m.runtime
        << endl;
}