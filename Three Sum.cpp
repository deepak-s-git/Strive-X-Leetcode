// Problem: 3Sum
// Given an array nums, find all unique triplets [a,b,c] such that a+b+c = 0.
//
// Approach:
// 1. Sort the array to handle duplicates easily.
// 2. Iterate through the array, fixing one element (nums[i]).
// 3. Use two pointers (j, k) to find pairs that sum with nums[i] to 0.
// 4. Skip duplicate elements for both i and j to avoid repeating triplets.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1) excluding result storage.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate i

            int j = i+1, k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;

                    // skip duplicate j
                    while (j < k && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};
