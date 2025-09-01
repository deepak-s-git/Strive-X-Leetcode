// Problem: Subsets (Power Set)
// Given an integer array nums, return all possible subsets (the power set).
//
// Approach:
// 1. Use recursion + backtracking.
// 2. At each index, we have two choices:
//      - Include nums[i] in the current subset.
//      - Exclude nums[i] and move to the next element.
// 3. Base case: when index == n, add the current subset to the result.
// 4. Collect all subsets in a 2D vector.
//
// Time Complexity: O(2^n)  (each element has 2 choices: include or exclude)
// Space Complexity: O(n) for recursion stack (excluding result storage).

class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back(ans); // store current subset
            return;
        }

        // Choice 1: include nums[i]
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        // Backtrack
        ans.pop_back();

        // Choice 2: exclude nums[i]
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};
