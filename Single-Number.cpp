// Problem: Given a non-empty array of integers, every element appears twice except for one. Find that single one.
// Approach: Use bitwise XOR to cancel out duplicate numbers. XOR of two same numbers is 0, and 0 ^ x = x.

// So, XOR-ing all numbers gives us the unique (non-duplicate) number.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        // Loop through all numbers and XOR them
        for(int val : nums){
            ans ^= val;  // cancels out duplicates, leaves the unique one
        }

        return ans;
    }
};
