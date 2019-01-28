/*
 * Author      : Victor Truong
 * CS 2        : MTWR, 7:30a – 12:30p
 * Assignment 7: Text Adventure
 * Due date    : 1/27/19
 */
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

char getChoice();
void drawPicture();
void printStatus(int bananaCount, // IN: Player's banana count
                 int orangeCount, // IN: Player's orange count
                 string name);    // IN: Player's name
void printEnding(int bananaCount,  // IN: Player's banana count
                 int orangeCount); // IN: Player's orange count
void genieRoom(int &bananaCount,  // IN: Player's banana count (to update)
               int &orangeCount); // IN: Player's orange count (to update)
void monsterRoom(int &bananaCount, // IN: Player's banana count (to update)
                 int &orangeCount, // IN: Player's orange count (to update)
                 string name);     // IN: Player's name
void pictureRoom();

/*
 * Text Adventure
 * 
 * This program is a text adventure where the player has the option to go in one
 * of four directions: north, east, south, or west. Their objective is to
 * collect as many bananas and oranges as possible while also lasting as long as
 * possible.
 * 
 * IN:
 *   isRunning  : Whether the game should continue running or not
 *   alignment  : Current turn's alignment selection
 *   bananaCount: The amount of bananas the player has
 *   orangeCount: The amount of oranges the player has
 *   playerName : The name of the player
 *   monsterName: The name of the monster
 *   choice     : The player's direction choice
 *
 * OUT:
 *   Performs appropriate actions based on chosen direction and outputs the
 *   result of each direction choice.
 */
int main()
{
    // cout <<
    //     "*****************************************\n"
    //     "  Author    : Victor Truong\n"
    //     "  ID        : 10180511\n"
    //     "  CS 2      : MTWR, 7:30a – 12:30p\n"
    //     "  Assignment: Text Adventure\n"
    //     "*****************************************\n";
    srand(500);

    bool isRunning;     // IN: Whether the game should continue running or not
    int alignment;      // IN: Current turn's alignment selection
    int bananaCount;    // IN: The amount of bananas the player has
    int orangeCount;    // IN: The amount of oranges the player has
    string playerName;  // IN: The name of the player
    string monsterName; // IN: The name of the monster
    char choice;        // IN: The player's direction choice

    isRunning = true;
    bananaCount = 5;
    orangeCount = 3;

    // IN: Get player and monster names
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << endl;
    cout << "Name your scariest monster: ";
    cin >> monsterName;
    cout << endl;

    while (isRunning)
    {
        alignment = rand() % 2; // PROC: Generate alignment for turn

        // OUT: Print status at the beginning of each turn
        printStatus(bananaCount, orangeCount, playerName);
        choice = getChoice(); // IN: Get a choice from user

        // PROC: Handle user's choice based on current alignment
        if (alignment == 0)
        {
            switch (choice)
            {
                case 'N':
                    monsterRoom(bananaCount, orangeCount, monsterName);
                    break;
                case 'S':
                    genieRoom(bananaCount, orangeCount);
                    break;
                case 'E':
                    pictureRoom();
                    break;
                case 'W':
                    isRunning = false;
                    break;
            }
        }
        else
        {
            switch (choice)
            {
                case 'N':
                    isRunning = false;
                    break;
                case 'S':
                    monsterRoom(bananaCount, orangeCount, monsterName);
                    break;
                case 'E':
                    genieRoom(bananaCount, orangeCount);
                    break;
                case 'W':
                    pictureRoom();
                    break;
            }
        }
    }

    // OUT: Print ending after game has been finished
    printEnding(bananaCount, orangeCount);

    return 0;
}

/*
 * FUNCTION: getChoice
 * 
 * IN:
 *   choice: Arbitrary character inputted by player
 * OUT:
 *   choice: A valid direction choice
 */
char getChoice()
{
    char choice;         // IN: Player's input choice
    bool hasValidChoice; // PROC: Indicate whether choice is valid or not

    hasValidChoice = false;

    // PROC: Prompt player until we get a valid choice
    while (!hasValidChoice)
    {
        // IN: Prompt for a choice
        cout << "Pick a door to enter by typing the direction it is in (N/E/S/W): ";
        cin >> choice;
        cout << endl;

        // PROC: Check if choice is equal to any of our acceptable choices
        if (choice == 'N' || choice == 'E' || choice == 'S' || choice == 'W')
        {
            hasValidChoice = true;
        }
    }

    return choice;
}

/*
 * FUNCTION: drawPicture
 * 
 * IN:
 *   N/A
 * OUT:
 *   Prints a picture of R2-D2.
 */
void drawPicture()
{
    cout << "        _--~~--_" << endl;
    cout << "      /~/_|  |_\\~\\" << endl;
    cout << "     |____________|" << endl;
    cout << "     |[][][][][][]|" << endl;
    cout << "   __| __         |__" << endl;
    cout << "  |  ||. |   ==   |  |" << endl;
    cout << " (|  ||__|   ==   |  |)" << endl;
    cout << "  |  |[] []  ==   |  |" << endl;
    cout << "  |  |____________|  |" << endl;
    cout << "  /__\\            /__\\" << endl;
    cout << "   ~~              ~~ " << endl;
    cout << endl;
}

/*
 * FUNCTION: printStatus
 * 
 * IN:
 *   bananaCount: Player's banana count
 *   orangeCount: Player's orange count
 *   name       : Player's name
 * OUT:
 *   Prints message containing current game status.
 */
void printStatus(int bananaCount,
                 int orangeCount,
                 string name)
{
    cout << name << ", you are in a room with 4 doors." << endl;
    cout << endl;
    cout << "You are carrying " << bananaCount << " bananas and " << orangeCount
        << " oranges." << endl;
}

/*
 * FUNCTION: monsterRoom
 * 
 * IN:
 *   bananaCount: Player's banana count
 *   orangeCount: Player's orange count
 * OUT:
 *   Prints the game ending message.
 */
void printEnding(int bananaCount,
                 int orangeCount)
{
    cout << endl;
    cout << "You found the exit!" << endl;
    cout << "Your score is " << (bananaCount + orangeCount) << "(" <<
        bananaCount << " bananas and " << orangeCount << " oranges)." << endl;
    cout << "Bye bye!!!" << endl; 
}

/*
 * FUNCTION: genieRoom
 * 
 * IN:
 *   bananaCount: Player's banana count (to update)
 *   orangeCount: Player's orange count (to update)
 * OUT:
 *   Gives player 2 bananas and 1 orange and prints a message.
 */
void genieRoom(int &bananaCount,
               int &orangeCount)
{
    bananaCount += 2;
    orangeCount += 1;

    cout << endl;
    cout << "!!Poof!! A Genie pops out and grants you 2 bananas and 1 orange." << endl;
}

/*
 * FUNCTION: monsterRoom
 * 
 * IN:
 *   bananaCount: Player's banana count (to update)
 *   orangeCount: Player's orange count (to update)
 *   name       : Player's name
 * OUT:
 *   Removes all player's bananas and oranges and prints a message.
 */
void monsterRoom(int &bananaCount,
                 int &orangeCount,
                 string name)
{
    bananaCount = 0;
    orangeCount = 0;

    cout << endl;
    cout << "WATCH OUT!!!" << endl;
    cout << name << " attacks you and steals all of your bananas and oranges."
        << endl;
}

/*
 * FUNCTION: pictureRoom
 * 
 * IN:
 *   N/A
 * OUT:
 *   Prints a picture of R2-D2.
 */
void pictureRoom()
{
    cout << endl;
    cout << "You found a picture!" << endl;
    drawPicture();
}