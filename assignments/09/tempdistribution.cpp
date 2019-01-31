/*
 * Author      : Victor Truong
 * CS 2        : MTWR, 7:30a – 12:30p
 * Assignment 9: Temperature Distribution Grid
 * Due date    : 2/1/19
 */
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int ROWS = 6;
const int COLS = 8;

void initGrid(
    double grid[ROWS][COLS], // IN: Grid to populate
    double topEdgeTemp,      // IN: Temperature of top edge
    double rightEdgeTemp,    // IN: Temperature of right edge
    double bottomEdgeTemp,   // IN: Temperature of bottom edge
    double leftEdgeTemp      // IN: Temperature of left edge
);
double generateNextGrid(double grid[ROWS][COLS]); // IN: Grid to update
void saveTemps(
    const double grid[ROWS][COLS], // IN: Grid to save
    ostream& dest                  // IN: Destination to output to
);

/*
 * Temperature Distribution Grid
 *
 * This program takes an input file with four temperatures and tolerance to
 * generate a grid and simulate temperatures until the entire grid has reached
 * equilibrium in temperature.
 */
int main()
{
    // cout <<
    //     "*****************************************\n"
    //     "  Author    : Victor Truong\n"
    //     "  ID        : 10180511\n"
    //     "  CS 2      : MTWR, 7:30a – 12:30p\n"
    //     "  Assignment: Temp Distribution Grid\n"
    //     "*****************************************\n";

    string inFilename;             // IN: Input filename from user
    string outFilename;            // IN: Output filename from user
    fstream inFile;                // PROC: Input filestream
    fstream outFile;               // PROC: Output filestream
    double topEdgeTemp;            // IN: Temperature of top edge
    double rightEdgeTemp;          // IN: Temperature of right edge
    double bottomEdgeTemp;         // IN: Temperature of bottom edge
    double leftEdgeTemp;           // IN: Temperature of left edge
    double tolerance;              // IN: Max tolerance in temperature difference
    double grid[ROWS][COLS] = {0}; // PROC: Grid of all cell temperatures
    double greatestDiff;           // PROC: Greatest difference of temperatures

    // IN: Get input and output filenames
    cout << "Enter input file name: ";
    cin >> inFilename;
    cout << endl << endl;
    cout << "Enter output file name: ";
    cin >> outFilename;
    cout << endl << endl;

    // PROC: Open files and end program if failed
    inFile.open(inFilename.c_str());
    outFile.open(outFilename.c_str());
    if (!inFile)
    {
        cout << "Could not locate: " << inFilename << endl;
        return 1;
    }

    // IN: Retrieve user's config from file
    inFile >> topEdgeTemp >> rightEdgeTemp >> bottomEdgeTemp >> leftEdgeTemp;
    inFile >> tolerance;

    // PROC: Initialize grid using user's input file
    initGrid(grid, topEdgeTemp, rightEdgeTemp, bottomEdgeTemp, leftEdgeTemp);

    // PROC: Continue updating inner cells until equilibrium is reached
    do
    {
        greatestDiff = generateNextGrid(grid);
    } while (greatestDiff >= tolerance);

    // OUT: Save inner cells to output file
    // saveTemps(grid, outFile);
    saveTemps(grid, cout); // Hypergrade-specific output

    // PROC: Close files
    inFile.close();
    outFile.close();

    return 0;
}

/*
 * FUNCTION: initGrid
 * 
 * Populates the grid with edge temperatures.
 * 
 * IN:
 *   grid          : Grid to populate
 *   topEdgeTemp   : Temperature of top edge
 *   rightEdgeTemp : Temperature of right edge
 *   bottomEdgeTemp: Temperature of bottom edge
 *   leftEdgeTemp  : Temperature of left edge
 */
void initGrid(
    double grid[ROWS][COLS],
    double topEdgeTemp,
    double rightEdgeTemp,
    double bottomEdgeTemp,
    double leftEdgeTemp
)
{
    // PROC: Iterate over each row and set appropriate temperatures
    for (int row = 0; row < ROWS; row++)
    {
        // PROC: Set top edge
        if (row == 0)
        {
            for (int col = 0; col < COLS; col++)
            {
                grid[row][col] = topEdgeTemp;
            }
        }
        // PROC: Set bottom edge
        else if (row == ROWS - 1)
        {
            for (int col = 0; col < COLS; col++)
            {
                grid[row][col] = bottomEdgeTemp;
            }
        }
        // PROC: Set left and right edges
        else
        {
            grid[row][0] = leftEdgeTemp;
            grid[row][COLS - 1] = rightEdgeTemp;
        }
    }
}

/*
 * FUNCTION: generateNextGrid
 * 
 * Updates the specified grid's cell temperatures by setting each cell to the
 * average temperature of the four cells adjacent to them.
 * 
 * IN:
 *   grid: Grid to update
 * OUT:
 *   greatestDiff: Greatest temperature difference in grid
 */
double generateNextGrid(double grid[ROWS][COLS])
{
    double greatestDiff = 0; // PROC: Greatest temperature difference in grid

    // PROC: Update inner cells' temperatures
    for (int row = 1; row < ROWS - 1; row++)
    {
        for (int col = 1; col < COLS - 1; col++)
        {
            // PROC: Derive cell's new temperature from adjacent cells
            double topCellTemp = grid[row - 1][col];    // PROC: Temperature of cell above
            double rightCellTemp = grid[row][col + 1];  // PROC: Temperature of cell to the right
            double bottomCellTemp = grid[row + 1][col]; // PROC: Temperature of cell below
            double leftCellTemp = grid[row][col - 1];   // PROC: Temperature of cell to left
            double prevCellTemp = grid[row][col];       // PROC: Temperature of current cell
            double nextCellTemp = (
                topCellTemp +
                rightCellTemp +
                bottomCellTemp +
                leftCellTemp
            ) / 4.0;                                    // PROC: New temperature of current cell
            // PROC: Update temperature
            grid[row][col] = nextCellTemp;

            // PROC: Update max diff
            double diff = abs(prevCellTemp - nextCellTemp); // PROC: Difference between old and new temperatures
            if (diff > greatestDiff)
            {
                greatestDiff = diff;
            }
        }
    }

    return greatestDiff;
}

/*
 * FUNCTION: saveTemps
 * 
 * Takes given grid and saves all inner cells' temperature to specified
 * destination.
 * 
 * IN:
 *   grid: Grid to save
 *   dest: Destination to output to
 */
void saveTemps(const double grid[ROWS][COLS], ostream& dest)
{
    for (int row = 1; row < ROWS - 1; row++)
    {
        for (int col = 1; col < COLS - 1; col++)
        {
            dest << grid[row][col] << " ";
        }
        dest << endl;
    }
}