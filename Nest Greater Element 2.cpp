// Problem: Next Greater Element II (Circular Array)
// Given a circular array nums, return the "next greater element" for each element.
// The next greater element of nums[i] is the first greater number to its right,
// considering the array circular (wrap-around). If none exists, return -1.
//
// Approach (Monotonic Stack + Circular Simulation):
// 1. Use a decreasing monotonic stack to keep candidate indices.
// 2. Traverse array **twice** (simulate circular array using i % n).
// 3. For each element nums[i % n]:
//      - While stack top is smaller/equal, pop (not a valid NGE).
//      - If stack not empty, ans[i % n] = nums[stack.top()].
//      - Push current index (i % n) to stack.
// 4. By iterating 2n times, every element has a chance to "see" its NGE.
//
// Time Complexity: O(n)   (each index pushed/popped at most once)
// Space Complexity: O(n)  (stack + answer array)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);   // default = -1 (no NGE)
        stack<int> s;             // stores indices (monotonic decreasing)

        // Traverse twice to handle circularity
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i % n] = nums[s.top()];
            }
            s.push(i % n);
        }
        return ans;
    }
};
