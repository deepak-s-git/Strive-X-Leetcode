// Problem: Check Knight Tour Configuration (LeetCode 2596)
// You are given an n x n grid where each cell has a unique number [0..n*n - 1].
// A knight starts at cell 0 (top-left corner).
// The knight moves in L-shape moves (chess rule).
// You must check if the numbers follow a valid knight's tour (sequence 0 → 1 → 2 ... → n*n-1).
//
// Approach:
// - Recursive DFS validation.
// - From expected number expval at (r,c), look for expval+1 in any valid knight move.
// - If reached n*n-1, tour is complete.
// - If no knight move leads to correct sequence → invalid.
//
// Time Complexity: O(8 * n^2) in worst case (each cell explored with 8 moves).
// Space Complexity: O(n^2) recursion depth in worst case.

class Solution {
public:
    // Helper function: checks if current cell has expected value
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expval) {
        // Out of bounds OR wrong value → invalid path
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expval)
            return false;

        // If we have reached last value (n*n - 1), it's valid tour
        if (expval == n * n - 1)
            return true;

        // Try all 8 possible knight moves
        int ans1 = isValid(grid, r - 2, c + 1, n, expval + 1);
        int ans2 = isValid(grid, r - 1, c + 2, n, expval + 1);
        int ans3 = isValid(grid, r + 1, c + 2, n, expval + 1);
        int ans4 = isValid(grid, r + 2, c + 1, n, expval + 1);
        int ans5 = isValid(grid, r + 2, c - 1, n, expval + 1);
        int ans6 = isValid(grid, r + 1, c - 2, n, expval + 1);
        int ans7 = isValid(grid, r - 1, c - 2, n, expval + 1);
        int ans8 = isValid(grid, r - 2, c - 1, n, expval + 1);

        // If any knight move continues valid sequence → return true
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        // Tour must start at (0,0) with value 0
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};
