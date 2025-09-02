// Problem: Combination Sum
// Given an array of distinct integers (candidates) and a target integer, 
// return all unique combinations where the chosen numbers sum to target. 
// Each number can be used unlimited times. 
//
// Approach:
// - Use backtracking to explore all possible combinations.
// - At each index, you have two choices:
//   1. Pick the current element and reduce the target (stay on same index since elements can be reused).
//   2. Skip the current element and move to the next index.
// - If target == 0, we found a valid combination -> add to answer.
// - If target < 0 or index exceeds array size, stop exploring.
// - No need for a set, as the approach itself avoids duplicates.
//
// Time Complexity: O(2^(t/m)) approx, where t = target and m = smallest candidate (branching factor).
// Space Complexity: O(target) recursion stack (worst case when repeatedly subtracting smallest number).

class Solution {
public:
    void solve(vector<int> &candidates, int idx, int target, 
               vector<int> &current, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        if (idx >= candidates.size() || target < 0) return;

        // pick the element
        current.push_back(candidates[idx]);
        solve(candidates, idx, target - candidates[idx], current, ans); 
        current.pop_back();

        // skip the element
        solve(candidates, idx + 1, target, current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(candidates, 0, target, current, ans);
        return ans;
    }
};
