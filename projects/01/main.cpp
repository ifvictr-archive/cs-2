#include "functions.cpp"

int main()
{
    srand(1337); // Seed random numbers

    PlayerBoard board1;
    PlayerBoard board2;
    char opponentChoice;
    bool hasWon = false;
    bool hasAIOpponent = false;
    int currentPlayer = 0;

    // IN: Ask if player wants to play with another player or the computer
    cout << "Do you want to play against a player(p) or an AI(a)? ";
    cin >> opponentChoice;
    cout << endl;

    // PROC: Configure game based on opponent choice
    if (tolower(opponentChoice) == 'a')
    {
        hasAIOpponent = true;
    }

    initFleet(board1);
    initFleet(board2);
    // PROC: Initialize board depending on option
    if (hasAIOpponent)
    {
        initBoardWithAI(board1, board2);
    }
    else
    {
        initBoard(board1, board2);
    }

    // PROC: Let user have their turn
    while (!hasWon)
    {
        PlayerBoard currentBoard = currentPlayer == 0 ? board1 : board2;
        PlayerBoard &enemyBoard = currentPlayer == 0 ? board2 : board1;

        // OUT: Display starting header
        displayBoards(currentBoard.board, enemyBoard.board);
        cout << "Player " << (currentPlayer + 1) << ":" << endl;

        // PROC: If it's player 2's turn and there's an AI as opponent
        if (currentPlayer == 1 && hasAIOpponent)
        {
            getAIShot(enemyBoard);
        }
        // IN: Get user's shot
        else
        {
            getValidShot(enemyBoard);
        }

        // PROC: Immediately end game if a player has won
        hasWon = hasSunkenFleet(enemyBoard);
        if (hasWon)
        {
            cout << "You sunk the fleet!!! You win!!!" << endl;
            break;
        }

        // PROC: Switch turns
        currentPlayer = !currentPlayer;
    }

    // OUT: Show which player won
    cout << "Player " << (currentPlayer + 1) << " won!!!" << endl;

    return 0;
}