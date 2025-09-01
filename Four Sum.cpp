// Problem: 4Sum
// Given an array nums and an integer target, find all unique quadruplets [a,b,c,d] 
// such that a+b+c+d = target.
//
// Approach:
// 1. Sort the array to handle duplicates easily.
// 2. Fix two numbers (i, j) using nested loops.
// 3. Use two pointers (p, q) to find the remaining pair that sums to target.
// 4. Skip duplicates for i, j, and p to avoid repeating quadruplets.
//
// Time Complexity: O(n^3)
// Space Complexity: O(1) excluding result storage.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i+1; j < n; ) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                int p = j+1, q = n-1;
                while (p < q) {
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];
                    if (sum < target) p++;
                    else if (sum > target) q--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; q--;
                        while (p < q && nums[p] == nums[p-1]) p++;
                    }
                }
                j++;
                while(j < n && nums[j] == nums[j-1]) j++;
            }
        }
        return ans;
    }
};
