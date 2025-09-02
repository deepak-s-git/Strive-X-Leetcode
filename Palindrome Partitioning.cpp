// Problem: Palindrome Partitioning (LeetCode 131)
// Given a string s, partition s such that every substring is a palindrome.
// Return all possible palindrome partitioning.
//
// Approach:
// 1. Use backtracking to explore all possible prefix cuts.
// 2. At each step, take substring s[0..i]. If it's palindrome → include in path.
// 3. Recurse on remaining substring s[i+1..end].
// 4. When string becomes empty, store current partition.
// 5. Backtrack to try other partitions.
//
// Time Complexity: O(2^n * n) approx (for generating + palindrome check).
// Space Complexity: O(n) recursion + storage for partitions.

class Solution {
public:
    // Check if a string is palindrome
    bool isPalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    // Recursive helper to generate all palindrome partitions
    void getAllParts(string s, vector<string>& partitions,
                     vector<vector<string>>& ans) {
        // Base case: if string is empty, we found a valid partition
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        // Try all possible prefixes
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            // If prefix is palindrome, include in current path
            if (isPalin(part)) {
                partitions.push_back(part);

                // Recurse on remaining substring
                getAllParts(s.substr(i + 1), partitions, ans);

                // Backtrack: remove last added substring
                partitions.pop_back();
            }
        }
    }

    // Main function
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);
        return ans;
    }
};
