// Problem: Given an array of heights, find the maximum water container formed between two lines.
// Approach: Two-pointer method.
// 1. Start pointers at both ends (left and right).
// 2. Calculate the water area as width * min(height[left], height[right]).
// 3. Update maxWater if the current area is larger.
// 4. Move the pointer at the shorter line inward (since moving the taller one won't help increase height).
// Time Complexity: O(n), Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0, rp = height.size() - 1; // start at ends

        while(lp < rp) {
            int w = rp - lp; // width between lines
            int h = min(height[lp], height[rp]); // height of container
            int currWtr = w * h; // current water area

            maxWater = max(currWtr, maxWater);

            // Move the pointer at the shorter line inward
            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxWater;
    }
};
