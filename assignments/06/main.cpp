/*
 * Author      : Victor Truong
 * CS 2        : MTWR, 7:30a – 12:30p
 * Assignment 6: Hangman
 * Due date    : 1/24/19
 */
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

char getGuess(string prevGuesses);     // IN: List of previous guesses
string setupUnsolved(string phrase);   // IN: Phrase to convert to puzzle
string updateUnsolved(string phrase,   // IN: Base string to compare to
                      string unsolved, // IN: Current state of puzzle
                      char guess);     // IN: Character to check against phrase

/*
 * Hangman
 * 
 * This program is a simplified version of the Hangman game.
 * 
 * IN:
 *   phrase: Phrase to initialize a game of hangman with
 *
 * OUT:
 *   puzzle          : Current state of hangman puzzle
 *   guesses         : List of guesses made by user
 *   wrongGuessesLeft: Remaining guesses before game ends
 */
int main()
{
    // cout <<
    //     "*****************************************\n"
    //     "  Author    : Victor Truong\n"
    //     "  ID        : 10180511\n"
    //     "  CS 2      : MTWR, 7:30a – 12:30p\n"
    //     "  Assignment: Hangman\n"
    //     "*****************************************\n";
    bool hasWon;          // IN: Flag to indicate whether user has won
    string phrase;        // IN: Phrase to initialize a game of hangman with
    string puzzle;        // IN: Current game state
    string nextPuzzle;    // IN: Next game state (for comparison)
    string guesses;       // IN: List of guesses made by user
    int wrongGuessesLeft; // IN: Remaining guesses before game ends

    hasWon = false;
    guesses = "";
    wrongGuessesLeft = 7;

    // IN
    cout << "Enter phrase: ";
    getline(cin, phrase);
    puzzle = setupUnsolved(phrase);

    // OUT
    cout << "\n";
    cout << "Phrase: " << puzzle << "\n";

    // PROC
    while (wrongGuessesLeft > 0)
    {
        // system("cls");

        // OUT: Print status if user has made guesses already
        if (guesses != "")
        {
            cout << "Guessed so far: " << guesses << "\n";
            cout << "Wrong guesses left: " << wrongGuessesLeft << "\n";
            cout << puzzle << "\n\n";
        }

        // PROC: Stop executing after entire phrase has been guessed
        if (puzzle == phrase)
        {
            hasWon = true;
            break;
        }

        // PROC: Add user's new guess to existing guesses
        char guess = getGuess(guesses);
        guesses += guess;
        
        // PROC: Decrease remaining guesses if no progress was made
        nextPuzzle = updateUnsolved(phrase, puzzle, guess);
        if (puzzle != nextPuzzle)
        {
            puzzle = nextPuzzle;
        }
        else
        {
            wrongGuessesLeft--;
        }
    }

    // OUT: Print game outcome
    if (hasWon)
    {
        cout << "Congratulations!! You won!\n";
    }
    else
    {
        cout << "You lost!\n";
    }

    return 0;
}

char getGuess(string prevGuesses) // IN: List of previous guesses
{
    char guess;
    cout << "Enter a guess: ";
    while (true)
    {
        // IN
        cin >> guess;
        cout << "\n";

        bool isLowercase = guess == tolower(guess);
        bool isNewGuess = prevGuesses.find(guess) == string::npos;
        if (isalpha(guess) && isLowercase && isNewGuess)
        {
            break;
        }
        else
        {
            cout << "Invalid guess! Please re-enter a guess: ";
        }
    }

    return guess;
}

string setupUnsolved(string phrase) // IN: Phrase to convert to puzzle
{
    for (int i = 0; i < phrase.size(); i++)
    {
        char currChar = phrase.at(i); // PROC: Current character
        if (isalpha(currChar))
        {
            phrase.at(i) = '-';
        }
    }

    return phrase;
}

string updateUnsolved(string phrase,   // IN: Base string to compare to
                      string unsolved, // IN: Current state of puzzle
                      char guess)      // IN: Character to check against phrase
{
    for (int i = 0; i < phrase.size(); i++)
    {
        bool isCorrect = tolower(phrase.at(i)) == guess;
        bool isUnsolved = tolower(unsolved.at(i)) != tolower(phrase.at(i));
        if (isCorrect && isUnsolved)
        {
            unsolved.at(i) = phrase.at(i);
        }
    }

    return unsolved;
}