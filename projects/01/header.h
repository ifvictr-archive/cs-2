#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int BOARD_SIZE = 10;
const int FLEET_SIZE = 5;

const int BATTLESHIP_SIZE = 4;
const int CARRIER_SIZE = 5;
const int CRUISER_SIZE = 3;
const int DESTROYER_SIZE = 2;
const int SUBMARINE_SIZE = 3;

struct Point
{
    int x;
    int y;
};

struct Ship
{
    string name;
    int size;
    int hitCount;
    vector<Point> occupiedPoints;
};

struct PlayerBoard
{
    char board[BOARD_SIZE][BOARD_SIZE];
    Ship ships[FLEET_SIZE];
};

void displayBoards(const char board1[BOARD_SIZE][BOARD_SIZE], const char board2[BOARD_SIZE][BOARD_SIZE]);
void getValidShipInfo(int &x, int &y, char &orientation, const PlayerBoard &board, int shipIndex);
void getValidShot(PlayerBoard &board);
bool hasOccupiedPoint(const Ship &ship, int x, int y);
bool hasSunkenFleet(const PlayerBoard &board);
bool isInBoard(int startX, int startY, char orientation, int shipSize);
void initBoard(PlayerBoard &board1, PlayerBoard &board2);
void initFleet(PlayerBoard &board);
void setShip(PlayerBoard &board, int shipIndex);
bool spaceOccupied(const PlayerBoard &board, int startX, int startY, char orientation, int shipSize);