// Problem: Rearrange numbers into the lexicographically next greater permutation.
// If not possible (array is in descending order), rearrange into the smallest permutation.
//
// Approach (Next Permutation Algorithm):
// 1. Find the "pivot" from the right where nums[i] < nums[i+1].
// 2. If no pivot exists, reverse the whole array (last → first permutation).
// 3. Otherwise, swap pivot with the rightmost element greater than it.
// 4. Reverse the suffix (elements to the right of pivot) to make it smallest.
//
// Time Complexity: O(n), Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();

        // Step 1: Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse entire array
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Swap pivot with rightmost larger element
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse suffix
        int i = pivot + 1, j = n - 1;
            while (i < j) {
                swap(nums[i++], nums[j--]);
        }
    }
};
