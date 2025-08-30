// Problem: Matrix Diagonal Sum
// Given a square matrix 'mat', return the sum of the matrix diagonals.
// Both the primary diagonal (top-left to bottom-right) and the secondary
// diagonal (top-right to bottom-left) are included. If a cell is counted
// twice (the center in odd-sized matrices), count it only once.
//
// Approach:
// 1. Iterate through each row 'i'.
// 2. Add the element at the primary diagonal -> mat[i][i].
// 3. Add the element at the secondary diagonal -> mat[i][n-i-1].
// 4. Avoid double counting when 'i == n-i-1' (center element in odd n).
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mat[i][i];               // primary diagonal
            if (i != n - i - 1)             // avoid double count
                sum += mat[i][n - i - 1];   // secondary diagonal
        }
        return sum;
    }
};
