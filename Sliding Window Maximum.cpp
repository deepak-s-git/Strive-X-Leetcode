// Problem: Sliding Window Maximum
// LeetCode: https://leetcode.com/problems/sliding-window-maximum/
//
// Approach (Monotonic Deque):
// - Use a deque to store indices of elements in the current window.
// - Maintain the deque such that:
//      * Indices are always within the current window range.
//      * Values in deque are in decreasing order (front holds max).
// - Steps:
//      1. Process the first k elements and prepare deque.
//      2. For each new element:
//          - Add max of previous window to result.
//          - Remove indices out of window from front.
//          - Remove smaller elements from back.
//          - Push current index.
//      3. Push the maximum of the last window.
//
// Time Complexity: O(n)  (each element pushed & popped at most once)
// Space Complexity: O(k) (deque stores at most k indices)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;       // stores indices of elements
        vector<int> res;

        // Process first k elements
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Process the rest of the elements
        for (int i = k; i < nums.size(); i++) {
            // Front of deque is max of the last window
            res.push_back(nums[dq.front()]);

            // Remove elements out of current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Max for the last window
        res.push_back(nums[dq.front()]);
        return res;
    }
};
