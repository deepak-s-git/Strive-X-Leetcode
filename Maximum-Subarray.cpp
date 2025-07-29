// Problem: Find the contiguous subarray (with at least one number) that has the largest sum.
// Best Approach: Kadane's Algorithm — keep track of current subarray sum, and update the max seen so far.

// If current sum becomes negative, reset it to 0 (because a negative sum can't help future subarrays).

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;

        for(int val : nums){
            currSum += val; // add current value to the running sum
            maxSum = max(currSum, maxSum); // update max if needed

            // if current sum is negative, drop it and start fresh
            if(currSum < 0){
                currSum = 0;
            }
        }

        return maxSum;
    }
};
