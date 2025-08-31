// Problem: Find Missing and Repeated Values
//
// Description:
// You are given an n x n grid of integers where each number is between 1 and n² inclusive.
// - Exactly one number is missing.
// - Exactly one number appears twice.
// Return a vector of size 2: [repeated, missing].
//
// Approach:
// 1. Traverse the grid and compute the actual sum of all elements.
// 2. Use a hash set to detect the repeated number while iterating.
// 3. Compute the expected sum of numbers from 1 to n² using the formula: n² * (n² + 1) / 2.
// 4. Using the difference between expected and actual sum, deduce the missing number.
//    - missing = expectedSum + repeated - actualSum
// 5. Return [repeated, missing].
//
// Time Complexity: O(n²)   (single pass through the grid)
// Space Complexity: O(n²)  (hash set for elements seen)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) { 
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a, b;  // a = repeated, b = missing
        int expSum = 0, actualSum = 0;

        // Traverse the grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                actualSum += grid[i][j];

                // Detect repeated number
                if(s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        // Expected sum of numbers 1 to n²
        expSum = (n * n) * (n * n + 1) / 2;

        // Deduce missing number
        b = expSum + a - actualSum;
        ans.push_back(b);

        return ans;
    }
};
