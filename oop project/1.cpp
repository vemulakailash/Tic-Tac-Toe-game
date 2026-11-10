#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:

    // Constructor
    TicTacToe() {
        currentPlayer = 'X';

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    // Display the board
    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2)
                    cout << " | ";
            }
            cout << endl;

            if (i < 2)
                cout << "---|---|---\n";
        }
        cout << endl;
    }

    // Take player input
    void makeMove() {
        int row, col;

        while (true) {
            cout << "Player " << currentPlayer;
            cout << ", enter row and column (1-3): ";
            cin >> row >> col;

            row--;
            col--;

            if (row >= 0 && row < 3 &&
                col >= 0 && col < 3 &&
                board[row][col] == ' ') {

                board[row][col] = currentPlayer;
                break;
            }

            cout << "Invalid move! Try again.\n";
        }
    }

    // Check winner
    bool checkWinner() {

        for (int i = 0; i < 3; i++) {

            if (board[i][0] == currentPlayer &&
                board[i][1] == currentPlayer &&
                board[i][2] == currentPlayer)
                return true;

            if (board[0][i] == currentPlayer &&
                board[1][i] == currentPlayer &&
                board[2][i] == currentPlayer)
                return true;
        }

        if (board[0][0] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][2] == currentPlayer)
            return true;

        if (board[0][2] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][0] == currentPlayer)
            return true;

        return false;
    }

    // Check draw
    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    // Switch player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Start the game
    void playGame() {

        cout << "===== TIC TAC TOE GAME =====\n";

        while (true) {

            displayBoard();
            makeMove();

            if (checkWinner()) {
                displayBoard();
                cout << "Player " << currentPlayer
                     << " Wins!\n";
                break;
            }

            if (checkDraw()) {
                displayBoard();
                cout << "Game Draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

// Main function
int main() {

    TicTacToe game;

    game.playGame();

    return 0;
}
