// Problem: Search a 2D Matrix II
// You are given an m x n matrix where each row and column are sorted in ascending order.
// Given an integer target, return true if target is in the matrix, otherwise false.
//
// Approach (Staircase Search):
// 1. Start at the top-right corner of the matrix.
// 2. If the target equals the current element, return true.
// 3. If the target is smaller, move left (decrease column).
// 4. If the target is larger, move down (increase row).
// 5. Stop when indices go out of bounds. If not found, return false.
//
// Time Complexity: O(m + n)   // Worst case: traversing one row and one column
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (mat[r][c] == target) {
                return true;
            } else if (mat[r][c] > target) {
                c--;  // move left
            } else {
                r++;  // move down
            }
        }
        return false;
    }
};