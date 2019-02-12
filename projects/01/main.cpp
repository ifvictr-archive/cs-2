#include "functions.cpp"

int main()
{
    PlayerBoard board1;
    PlayerBoard board2;
    char opponentChoice;
    bool hasWon = false;
    int currentPlayer = 0;

    // IN: Ask if player wants to play with another player or the computer
    cout << "Player(p) or AI(a)? " << endl;
    cin >> opponentChoice;
    cout << endl;

    initFleet(board1);
    initFleet(board2);
    initBoard(board1, board2);

    // PROC: Let user have their turn
    while (!hasWon)
    {
        PlayerBoard currentBoard = currentPlayer == 0 ? board1 : board2;
        PlayerBoard &enemyBoard = currentPlayer == 0 ? board2 : board1;

        // OUT: Display starting header
        displayBoards(currentBoard.board, enemyBoard.board);
        cout << "Player " << (currentPlayer + 1) << ":" << endl;

        // IN: Get user's shot
        getValidShot(enemyBoard);

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

    return 0;
}