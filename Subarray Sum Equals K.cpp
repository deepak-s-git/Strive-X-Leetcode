// Problem: Subarray Sum Equals K
// Given an array nums and an integer k, return the total number of subarrays whose sum equals k.
//
// Approach:
// 1. Build prefix sums to calculate subarray sums quickly.
// 2. Use a hashmap to store frequencies of prefix sums seen so far.
// 3. For each prefix sum, check if (prefixSum - k) exists in the map → if yes, 
//    it means there’s a subarray ending here with sum k.
// 4. Also handle the case when prefixSum itself equals k.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefixSum(n, 0);

        // Step 1: Build prefix sum
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        // Step 2: Map to store frequencies of prefix sums
        unordered_map<int, int> m;
        for (int j = 0; j < n; j++) {
            if (prefixSum[j] == k) count++;

            int val = prefixSum[j] - k;
            if (m.find(val) != m.end()) {
                count += m[val];
            }

            m[prefixSum[j]]++;
        }
        return count;
    }
};
