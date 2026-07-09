#include <iostream>
using namespace std;

const int N = 9;

// Function to print Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0)
            cout << "------+-------+------" << endl;

        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0)
                cout << "| ";

            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Check whether placing a number is safe
bool isSafe(int grid[N][N], int row, int col, int num) {

    // Check row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num)
            return false;
    }

    // Check column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num)
            return false;
    }

    // Check 3×3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Backtracking function
bool solveSudoku(int grid[N][N], int row, int col) {

    // If all rows are completed
    if (row == N - 1 && col == N)
        return true;

    // Move to next row
    if (col == N) {
        row++;
        col = 0;
    }

    // Skip filled cells
    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {

        if (isSafe(grid, row, col, num)) {

            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1))
                return true;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int grid[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout << "Original Sudoku:\n\n";
    printGrid(grid);

    cout << "\nSolving Sudoku...\n\n";

    if (solveSudoku(grid, 0, 0)) {
        cout << "Solved Sudoku:\n\n";
        printGrid(grid);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}