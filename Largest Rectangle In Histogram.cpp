// Problem: Largest Rectangle in Histogram
// Given an array where each element represents the height of a histogram bar,
// find the area of the largest rectangle that can be formed.
//
// Approach (Next Smaller Elements):
// 1. For each bar, we need to know:
//      - The index of the **nearest smaller bar to the left**.
//      - The index of the **nearest smaller bar to the right**.
//    This defines the maximum width where the current bar can extend.
// 2. Use monotonic stacks to compute:
//      - `left[i]`: index of nearest smaller to the left, or -1 if none.
//      - `right[i]`: index of nearest smaller to the right, or n if none.
// 3. Width = right[i] - left[i] - 1
//    Area = heights[i] * width
// 4. Return the maximum area across all bars.
//
// Time Complexity: O(n)   (each index pushed/popped at most once)
// Space Complexity: O(n)  (extra arrays + stack)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0), right(n, 0);
        stack<int> s;

        // Step 1: Compute nearest smaller to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // clear stack for reuse
        while (!s.empty()) s.pop();

        // Step 2: Compute nearest smaller to the left
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Step 3: Calculate max area
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};
