// Problem: In a sorted array where every element appears exactly twice except one element 
//          which appears only once, find that single element.
// Approach: Binary Search on indices (Pair Indexing Logic)
// 1. If array size = 1, return that element.
// 2. Check edge cases: if the single element is at index 0 or last index.
// 3. For middle elements, check if nums[mid] is the unique one 
//    (not equal to neighbors).
// 4. Otherwise, use index parity to decide which half to search:
//    - If mid is even, its pair should be at mid+1. If not, answer lies on left.
//    - If mid is odd, its pair should be at mid-1. If not, answer lies on left.
// Time Complexity: O(log n), Space Complexity: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        int st = 0, end = n - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            // Edge cases: check first or last index
            if(mid == 0 && nums[0] != nums[1]) return nums[mid];
            if(mid == n - 1 && nums[n - 1] != nums[n - 2]) return nums[mid];

            // Found the unique element
            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) return nums[mid];

            // Binary search based on index parity
            if(mid % 2 == 0) {
                if(nums[mid - 1] == nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if(nums[mid - 1] == nums[mid]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1; // should never hit for valid input
    }
};
