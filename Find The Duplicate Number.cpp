// Problem: Find the Duplicate Number
//
// Description:
// You are given an array of n + 1 integers, where each integer is in the range [1, n] inclusive.
// - Exactly one integer appears more than once.
// - Return that duplicate number.
// - You must solve the problem without modifying the array and using only constant extra space.
//
// Approach (Floyd’s Tortoise and Hare):
// 1. Treat the array as a linked list where each index points to nums[index].
// 2. Since there is a duplicate, this "linked list" must contain a cycle.
// 3. Use Floyd’s Cycle Detection Algorithm to find the start of the cycle:
//    - Phase 1: Move slow by 1 step and fast by 2 steps until they meet inside the cycle.
//    - Phase 2: Reset slow to start (nums[0]) and move both slow and fast by 1 step.
//               The point where they meet again is the duplicate number.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Phase 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find entry point of the cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
