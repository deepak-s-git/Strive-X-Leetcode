// Problem: Search for a target value in a rotated sorted array (no duplicates) 
//          and return its index. If not found, return -1.
// Approach: Modified Binary Search
// 1. Use binary search, but at each step decide which half of the array is sorted.
// 2. If the left half is sorted, check if the target lies within it.
//    - If yes, search left half; otherwise, search right half.
// 3. If the right half is sorted, check if the target lies within it.
//    - If yes, search right half; otherwise, search left half.
// Time Complexity: O(log n), Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int st = 0, end = nums.size() - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] == tar) {
                return mid; // target found
            }

            // Left half is sorted
            if(nums[st] <= nums[mid]) {
                if(nums[st] <= tar && tar <= nums[mid]) {
                    end = mid - 1; // search left half
                } else {
                    st = mid + 1;  // search right half
                }
            }
            // Right half is sorted
            else {
                if(nums[mid] <= tar && tar <= nums[end]) {
                    st = mid + 1;  // search right half
                } else {
                    end = mid - 1; // search left half
                }
            }
        }
        return -1; // target not found
    }
};
