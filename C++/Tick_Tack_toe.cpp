#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Horizontal win
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Vertical win
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Diagonal win
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Diagonal win
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    int row, col;
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    for (int move = 1; move <= 9; ++move) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the chosen cell is valid and empty
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            --move; // Decrement move to allow the same player to try again
            continue;
        }

        board[row][col] = currentPlayer;
        displayBoard(board);

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // If all moves have been played and there's no winner, it's a tie.
    if (checkWin(board, 'X') == false && checkWin(board, 'O') == false) {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
