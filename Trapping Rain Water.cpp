// Problem: Trapping Rain Water
// Given n non-negative integers representing elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.
//
// Approach (Two Pointer):
// 1. Maintain two pointers `l` (left) and `r` (right).
// 2. Track maximum heights from left (`lmax`) and right (`rmax`).
// 3. At each step:
//      - If lmax < rmax:
//          - water trapped at l depends only on lmax (since right side is taller).
//          - ans += lmax - height[l], move l++.
//      - Else:
//          - water trapped at r depends only on rmax.
//          - ans += rmax - height[r], move r--.
// 4. Continue until l < r.
//
//
// Time Complexity: O(n)   (single pass)
// Space Complexity: O(1)  (constant extra memory)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;

        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};
