#include <iostream>
#include <vector>

using namespace std;

// Function to print the Sudoku board
void printBoard(const vector<vector<int> >& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to find an empty cell in the Sudoku grid
bool findEmpty(const vector<vector<int> >& board, int& row, int& col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if placing 'num' in the given row and column is valid
bool isValid(const vector<vector<int> >& board, int num, int row, int col) {
    // Check row and column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int> >& board) {
    int row, col;
    if (!findEmpty(board, row, col)) {
        return true; // Solved
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, num, row, col)) {
            board[row][col] = num;

            if (solveSudoku(board)) {
                return true;
            }

            // Undo the move (backtrack)
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    // Define a raw array first
    int raw_board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Convert to a vector of vectors
    vector<vector<int> > board(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = raw_board[i][j];
        }
    }

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists for the given Sudoku." << endl;
    }

    return 0;
}