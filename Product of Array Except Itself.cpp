// Problem: Given an integer array nums, return an array output such that output[i] 
//          is the product of all elements of nums except nums[i].
// Approach: Prefix & Suffix Product Method
// 1. Create an output array initialized with 1.
// 2. First pass (left to right): store product of all elements to the left of current index.
// 3. Second pass (right to left): multiply with product of all elements to the right.
// Time Complexity: O(n), Space Complexity: O(1) extra (excluding output array).

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1); // answer array, initially all 1s

        // Step 1: Prefix product (product of elements to the left of i)
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Step 2: Multiply with suffix product (product of elements to the right of i)
        int suffix = 1; // stores running product from the right
        for(int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};
