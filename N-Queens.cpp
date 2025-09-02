// Problem: N-Queens
// Place n queens on an n×n chessboard so that no two queens attack each other.
// Return all distinct solutions.
//
// Approach:
// 1. Use backtracking: try to place one queen in each row.
// 2. For each column in the current row, check if placing a queen is safe.
// 3. "Safe" means:
//      - No queen in the same column above.
//      - No queen on the upper-left diagonal.
//      - No queen on the upper-right diagonal.
//    (No need to check the current row or below, since we place row by row.)
// 4. If safe, place 'Q' and recurse for next row. Backtrack after recursion.
// 5. When row == n, store the board configuration as a solution.
//
// Time Complexity: O(n!) approx (backtracking).
// Space Complexity: O(n^2) for board + recursion stack.

class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nQueens(vector<string>& board, int row, int n,
                 vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nQueens(board, 0, n, ans);
        return ans;
    }
};
