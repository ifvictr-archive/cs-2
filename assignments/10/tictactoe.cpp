/*
 * Author       : Victor Truong
 * CS 2         : MTWR, 7:30a – 12:30p
 * Assignment 10: Tic Tac Toe
 * Due date     : 2/6/19
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * FUNCTION: clearScreen
 * 
 * Utilizes an escape character sequence to clear the screen
 */
void clearScreen();
/*
 * FUNCTION: drawBoard
 * 
 * Draws the provided tic-tac-toe board to the screen
 */
void drawBoard(const vector<char>& board);     // IN: The tic-tac-toe board that should be drawn
/*
 * FUNCTION: initVector
 * 
 * Fills vector with characters starting at lower case a.
 * The amount of the alphabet placed into the vector depends on its size.
 */
void initVector(vector<char>& v);              // IN: The vector to initialize
/*
 * FUNCTION: convertPosition
 * 
 * Converts a character representing a cell to associated vector index
 */
int convertPosition(char position);            // IN: The position to be converted to a vector index
/*
 * FUNCTION: validPlacement
 * 
 * Predicate function to determine if a spot in board is available.
 */
bool validPlacement(const vector<char>& board, // IN: The current tic-tac-toe board
                    int position);             // IN: An index into vector to check if available
/*
 * FUNCTION: getPlay
 * 
 * Acquires a play from the user as to where to put her mark
 */
int getPlay(const vector<char>& board);        // IN: The current tic-tac-toe board
/*
 * FUNCTION: gameWon
 * 
 * Predicate function to determine if the game has been won
 * player in a single row, column or diagonal.
 */
bool gameWon(const vector<char>& board);       // IN: The current tic-tac-toe board
/*
 * FUNCTION: boardFull
 * 
 * Predicate function to determine if the board is full
 */
bool boardFull(const vector<char>& board);     // IN: The current tic-tac-toe board

const bool CLEAR_SCREEN = true;
// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

/*
 * Tic Tac Toe
 *
 * This program is a command-line version of the two-player game of Tic Tac Toe.
 * Players type in the position they want to place at, and then it'll proceed
 * to the next player's turn.
 */
int main()
{
    // cout <<
    //     "*****************************************\n"
    //     "  Author    : Victor Truong\n"
    //     "  ID        : 10180511\n"
    //     "  CS 2      : MTWR, 7:30a – 12:30p\n"
    //     "  Assignment: Tic Tac Toe\n"
    //     "*****************************************\n";

    vector<char> board(9); // PROC: State of the tic-tac-toe board
    int turn = PLAYER1;    // PROC: Player 1 always goes first and is 'x'

    /// PROC: Initialize board to empty state
    initVector(board);
    /// PROC: Display empty board
    drawBoard(board);

    /// PROC: Play until game is over
    while (!gameWon(board) && !boardFull(board))
    {
        /// PROC: Get a play
        int pos = getPlay(board);

        /// PROC: Set the play on the board
        board.at(pos) = turn == PLAYER1 ? 'x' : 'o';

        /// PROC: Switch the turn to the other player if there can be a next turn
        if (!boardFull(board) && !gameWon(board)) {
            turn = !turn;
        }

        /// OUT: Output the updated board
        drawBoard(board);
    }

    /// OUT: Determine winner and output appropriate message
    if (gameWon(board))
    {
        if (turn == PLAYER1)
        {
            cout << "Player 1 wins!!" << endl;
        }
        else
        {
            cout << "Player 2 wins!!" << endl;
        }
    }
    else
    {
        cout << "No one wins." << endl;
    }

    return 0;
}

/*
 * FUNCTION: clearScreen
 * 
 * Utilizes an escape character sequence to clear the screen
 */
void clearScreen()
{
    cout << endl;
    if (CLEAR_SCREEN)
    {
        cout << "\033c";
    }
    cout << endl;
}

/*
 * FUNCTION: drawBoard
 * 
 * Draws the provided tic-tac-toe board to the screen
 *
 * IN:
 *   board: The tic-tac-toe board that should be drawn
 */
void drawBoard(const vector<char>& board)
{
    clearScreen();
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << board.at(i) << "  |  " << board.at(i + 1) << "  |  "
            << board.at(i + 2) << "  " << endl;
        if (i < 6)
        {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;
}

/*
 * FUNCTION: initVector
 * 
 * Fills vector with characters starting at lower case a.
 * The amount of the alphabet placed into the vector depends on its size.
 *
 * When the vector is size 1 then it will have only character a.
 * When the vector is size 5 then it will have characters a to e.
 * When the vector is size 26 then it will have characters a to z.
 * 
 * IN:
 *   v: The vector to initialize
 *   The vector size will never be over 26
 * OUT:
 *   The integer index in the vector, should be 0 to (vector size - 1)
 */
void initVector(vector<char>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v.at(i) = 'a' + i;
    }
}

/*
 * FUNCTION: convertPosition
 * 
 * Converts a character representing a cell to associated vector index
 * 
 * IN:
 *   position: The position to be converted to a vector index
 * OUT:
 *   The integer index in the vector, should be 0 to (vector size - 1)
 */
int convertPosition(char position)
{
    return position - 'a';
}

/*
 * FUNCTION: validPlacement
 * 
 * Predicate function to determine if a spot in board is available.
 * 
 * IN:
 *   board   : The current tic-tac-toe board
 *   position: An index into vector to check if available
 * OUT:
 *   true if position's state is available (not marked) AND is in bounds
 */
bool validPlacement(const vector<char>& board, int position)
{
    return position < board.size() && !(board.at(position) == 'x' || board.at(position) == 'o');
}

/*
 * FUNCTION: getPlay
 * 
 * Acquires a play from the user as to where to put her mark
 *
 * Utilizes convertPosition and validPlacement functions to convert the
 * user input and then determine if the converted input is a valid play.
 *
 * Winning conditions in tic-tac-toe require three marks from same 
 * 
 * IN:
 *   board: The current tic-tac-toe board
 *   choice: Player's choice of position on the board
 * OUT:
 *   An integer index in board vector of a chosen available board spot
 */
int getPlay(const vector<char>& board)
{
    char choice; // IN: Player's choice of position on the board
    int index;   // OUT: Index in board vector of a chosen available board spot

    // PROC: Keep on asking for position until a valid one is entered
    do
    {
        cout << "Please choose a position: ";
        cin >> choice;
        cout << endl;

        index = convertPosition(choice); // PROC: Save position for validation
    } while (!validPlacement(board, index));
    

    return index;
}

/*
 * FUNCTION: gameWon
 * 
 * Predicate function to determine if the game has been won
 * player in a single row, column or diagonal.
 *
 * Winning conditions in tic-tac-toe require three marks from same 
 * 
 * IN:
 *   board: The current tic-tac-toe board
 * OUT:
 *   True if either player has won
 */
bool gameWon(const vector<char>& board)
{
    // PROC: Check for horizontals and verticals
    for (int i = 0; i < 3; i++)
    {
        // Horizontal
        if (
            board.at(3 * i) == board.at(3 * i + 1) &&
            board.at(3 * i + 1) == board.at(3 * i + 2)
        )
        {
            return true;
        }
        // Vertical
        else if (
            board.at(i) == board.at(i + 3) &&
            board.at(i + 3) == board.at(i + 6)
        )
        {
            return true;
        }
    }

    // PROC: Check for diagonals
    if (board.at(0) == board.at(4) && board.at(4) == board.at(8))
    {
        return true;
    }
    else if (board.at(2) == board.at(4) && board.at(4) == board.at(6))
    {
        return true;
    }

    return false;
}

/*
 * FUNCTION: boardFull
 * 
 * Predicate function to determine if the board is full
 * 
 * IN:
 *   board: The current tic-tac-toe board
 * OUT:
 *   True if the board is full (no cell is available)
 */
bool boardFull(const vector<char>& board)
{
    // PROC: Look for character that isn't a player symbol
    for (int i = 0; i < board.size(); i++)
    {
        if (!(board.at(i) == 'x' || board.at(i) == 'o'))
        {
            return false;
        }
    }
    return true;
}