#include "header.h"

using namespace std;

void displayBoards(const char board1[BOARD_SIZE][BOARD_SIZE], const char board2[BOARD_SIZE][BOARD_SIZE])
{
    const string ROW_DIV = "-----------------------------------------";
    const string BOARD_DIV = "          ";
    const string ROW_HEADER = "  1   2   3   4   5   6   7   8   9  10  ";

    cout << "                  Your Board                                          Enemy Board" << endl;
    cout << "  " << ROW_HEADER << BOARD_DIV << "  " << ROW_HEADER << endl;
    cout << "  " << ROW_DIV << BOARD_DIV << "  " << ROW_DIV << endl;
    for (int y = 0; y < BOARD_SIZE; y++)
    {
        char row = 'A' + y;
        // Your board
        cout << row << " |";
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            cout << " " << board1[y][x] << " |";
        }
        cout << BOARD_DIV;
        // Enemy board
        cout << row << " |";
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            // char filteredCell = board2[y][x] == 's' ? ' ' : board2[y][x];
            // cout << " " << filteredCell << " |";
            // For testing
            cout << " " << board2[y][x] << " |";
        }
        cout << endl;
        cout << "  " << ROW_DIV << BOARD_DIV << "  " << ROW_DIV << endl;
    }
}

void getValidShipInfo(int &x, int &y, char &orientation, const PlayerBoard &board, int shipIndex)
{
    bool isValid = false;
    string shipName = board.ships[shipIndex].name;
    char row;
    int col;

    do
    {
        // IN: Get start coordinates
        cout << "Enter the starting coordinates of your " << shipName << ": ";
        cin >> row >> col;
        cout << endl;

        // IN: Get orientation
        cout << "Enter the orientation of your " << shipName << " (horizontal(h) or vertical(v)): ";
        cin >> orientation;
        cout << endl;

        // PROC: Convert pretty coordinates to indices
        x = col - 1;
        y = tolower(row) - 'a';
        // PROC: Standardize casing
        orientation = tolower(orientation);

        // PROC: Validate input
        if (!isInBoard(x, y, orientation, board.ships[shipIndex].size))
        {
            cout << "Error: Ship placement is outside the board." << endl;
        }
        else if (spaceOccupied(board, x, y, orientation, board.ships[shipIndex].size))
        {
            cout << "Error: Space already occupied." << endl;
        }
        else
        {
            isValid = true;
        }

    } while (!isValid);
}

void getValidShot(PlayerBoard &board)
{
    bool isValid = false;
    char row;
    int col;
    int x;
    int y;

    do
    {
        cout << "Fire a shot: ";
        cin >> row >> col;
        cout << endl;
        // PROC: Convert pretty coordinates to indices
        x = col - 1;
        y = tolower(row) - 'a';

        if (!(x >= 0 && x < BOARD_SIZE) || !(y >= 0 && y < BOARD_SIZE))
        {
            cout << "Invalid" << endl;
        }
        else
        {
            isValid = true;
            if (board.board[y][x] == 's')
            {
                board.board[y][x] = 'H';
                cout << "Hit!!!" << endl;
                // PROC: Get ship that occupies point
                for (int i = 0; i < FLEET_SIZE; i++)
                {
                    // PROC: Increment hit count and check status of ship on match
                    Ship &currentShip = board.ships[i];
                    if (hasOccupiedPoint(board.ships[i], x, y))
                    {
                        currentShip.hitCount++;
                        if (currentShip.hitCount == currentShip.size)
                        {
                            cout << "You sunk the " << currentShip.name << "!!!" << endl;
                        }
                        break;
                    }
                }
            }
            else if (board.board[y][x] != 'H')
            {
                board.board[y][x] = 'M';
                cout << "You Missed." << endl;
            }
        }
    } while (!isValid);
}

bool hasOccupiedPoint(const Ship &ship, int x, int y)
{
    vector<Point> occupiedPoints = ship.occupiedPoints;
    for (int i = 0; i < occupiedPoints.size(); i++)
    {
        Point currentPoint = occupiedPoints.at(i);
        if (currentPoint.x == x && currentPoint.y == y)
        {
            return true;
        }
    }

    return false;
}

bool hasSunkenFleet(const PlayerBoard &board)
{
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        Ship currentShip = board.ships[i];
        if (currentShip.hitCount < currentShip.size)
        {
            return false;
        }
    }

    return true;
}

bool isInBoard(int startX, int startY, char orientation, int shipSize)
{
    int endX = startX;
    int endY = startY;

    if (orientation == 'h')
    {
        endX = startX + shipSize - 1;
    }
    else if (orientation == 'v')
    {
        endY = startY + shipSize - 1;
    }

    return (startX >= 0 && endX < BOARD_SIZE) && (startY >= 0 && endY < BOARD_SIZE);
}

void initBoard(PlayerBoard &board1, PlayerBoard &board2)
{
    // PROC: Set default cell value
    for (int y = 0; y < BOARD_SIZE; y++)
    {
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            board1.board[y][x] = ' ';
            board2.board[y][x] = ' ';
        }
    }

    // PROC: Initialize all fleet ships
    cout << "Player 1 set your board." << endl;
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        displayBoards(board1.board, board2.board);
        setShip(board1, i);
    }
    cout << "Player 2 set your board." << endl;
    for (int i = 0; i < FLEET_SIZE; i++)
    {
        displayBoards(board2.board, board1.board);
        setShip(board2, i);
    }
}

void initFleet(PlayerBoard &board)
{
    board.ships[0] = {"carrier", CARRIER_SIZE, 0};
    board.ships[1] = {"battleship", BATTLESHIP_SIZE, 0};
    board.ships[2] = {"cruiser", CRUISER_SIZE, 0};
    board.ships[3] = {"submarine", SUBMARINE_SIZE, 0};
    board.ships[4] = {"destroyer", DESTROYER_SIZE, 0};
}

void setShip(PlayerBoard &board, int shipIndex)
{
    int x;
    int y;
    char orientation;

    getValidShipInfo(x, y, orientation, board, shipIndex);

    // PROC: Update board with ship added
    for (int i = 0; i < board.ships[shipIndex].size; i++)
    {
        int occupiedX = x;
        int occupiedY = y;

        if (orientation == 'h')
        {
            occupiedX = x + i;
        }
        else if (orientation == 'v')
        {
            occupiedY = y + i;
        }

        board.board[occupiedY][occupiedX] = 's';
        Point occupiedPoint = {occupiedX, occupiedY};
        board.ships[shipIndex].occupiedPoints.push_back(occupiedPoint);
    }
}

bool spaceOccupied(const PlayerBoard &board, int startX, int startY, char orientation, int shipSize)
{
    for (int i = 0; i < shipSize; i++)
    {
        if (orientation == 'h' && board.board[startY][startX + i] != ' ')
        {
            return true;
        }
        else if (orientation == 'v' && board.board[startY + i][startX] != ' ')
        {
            return true;
        }
    }

    return false;
}