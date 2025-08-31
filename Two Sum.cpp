// Problem: Two Sum
//
// Description:
// Given an array of integers `nums` and an integer `target`,
// return indices of the two numbers such that they add up to `target`.
// It is guaranteed that exactly one solution exists.
//
// Approach:
// - Use a hashmap (unordered_map) to store elements and their indices.
// - For each element `nums[i]`, compute the complement = target - nums[i].
// - If the complement exists in the hashmap, return its index and `i`.
// - Otherwise, store the current element with its index in the hashmap.
// - Since only one solution is guaranteed, return immediately once found.
//
// Time Complexity: O(n)   (each element is processed once)
// Space Complexity: O(n)  (hashmap stores up to n elements)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;   // value -> index
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - first;

            // Check if complement exists
            if(m.find(second) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[second]);
                return ans;   // return immediately when found
            }

            // Otherwise store current element
            m[first] = i;
        }

        return ans; // One solution is always guaranteed
    }
};
