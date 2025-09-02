// Problem: Sudoku Solver
// Given a partially filled 9×9 Sudoku board, fill the empty cells ('.') 
// so that every row, column, and 3×3 sub-grid contains digits 1–9 exactly once.
//
// Approach:
// 1. Use backtracking to try filling empty cells one by one.
// 2. For each empty cell, attempt placing digits '1'–'9'.
// 3. To check if placing a digit is valid (isSafe):
//      - Ensure digit not present in current row.
//      - Ensure digit not present in current column.
//      - Ensure digit not present in the corresponding 3×3 sub-grid.
// 4. If valid, place the digit and recurse for the next cell.
// 5. If recursion fails, backtrack (reset cell to '.') and try the next digit.
// 6. When all cells are filled correctly, the board is solved.
//
// Time Complexity: O(9^(n*n)) in worst case (each empty cell tries 9 digits).
//                 But pruning with isSafe makes it much faster in practice.
// Space Complexity: O(1) extra (in-place board modification + recursion stack).

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) return false;
        }

        // Check 3x3 sub-grid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig) return false;
            }
        }

        return true;
    }

    bool solver(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true; // solved

        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if (board[row][col] != '.') {
            return solver(board, nextRow, nextCol);
        }

        for (char dig = '1'; dig <= '9'; dig++) {
            if (isSafe(board, row, col, dig)) {
                board[row][col] = dig;
                if (solver(board, nextRow, nextCol)) return true;
                board[row][col] = '.'; // backtrack
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0, 0);
    }
};
