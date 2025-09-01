// Problem: Subsets II (Handling Duplicates)
// Given an integer array nums that may contain duplicates, return all possible 
// unique subsets (the power set).
//
// Approach:
// 1. Sort the array to group duplicates together.
// 2. Use recursion + backtracking to explore subsets.
// 3. At each index, we have two choices:
//      - Include nums[i] in the current subset.
//      - Exclude nums[i], but skip over duplicate elements to avoid repeated subsets.
// 4. Base case: when index == n, add the current subset to the result.
// 5. Sorting + duplicate skipping ensures uniqueness.
//
// Time Complexity: O(2^n) in the worst case (all unique elements).
// Space Complexity: O(n) for recursion stack (excluding result storage).

class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // Choice 1: include nums[i]
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        // Backtrack
        ans.pop_back();

        // Choice 2: exclude nums[i] and skip duplicates
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1])
            idx++;

        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to handle duplicates

        vector<vector<int>> allSubsets;
        vector<int> ans;
        
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};
