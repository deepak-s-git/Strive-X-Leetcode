// Problem: Sort Colors (Leetcode 75)
// Array contains only 0, 1, 2 → sort in-place.
// Use Dutch National Flag Algorithm with 3 pointers:
//   - low = next place for 0
//   - mid = current element
//   - high = next place for 2
// Rule: 
//   if 0 → swap with low, ++low, ++mid
//   if 1 → just ++mid
//   if 2 → swap with high, --high (don’t move mid)
//
// Time: O(n), Space: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++; mid++;
            } 
            else if (nums[mid] == 1) {
                mid++;
            } 
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
