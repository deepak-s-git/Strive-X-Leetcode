// Problem: Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.
//
// Approach:
// 1. Maintain four boundaries: 
//    - srow (start row), erow (end row)
//    - scol (start col), ecol (end col)
// 2. Traverse the matrix layer by layer:
//    - Left to Right along the top row
//    - Top to Bottom along the right column
//    - Right to Left along the bottom row (if not already visited)
//    - Bottom to Top along the left column (if not already visited)
// 3. Shrink the boundaries and continue until all elements are visited.
//
// Time Complexity: O(m * n)   // Each element is visited once
// Space Complexity: O(m * n) // Output list of all elements

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
        vector<int> ans;

        while (srow <= erow && scol <= ecol) {
            // Traverse top row
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }

            // Traverse right column
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }

            // Traverse bottom row
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) break;  // avoid double counting
                ans.push_back(mat[erow][j]);
            }

            // Traverse left column
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) break;  // avoid double counting
                ans.push_back(mat[i][scol]);
            }

            // Shrink boundaries
            srow++; erow--; scol++; ecol--;
        }
        return ans;
    }
};