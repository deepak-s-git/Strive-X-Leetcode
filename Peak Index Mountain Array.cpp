// Problem: Given a mountain array (strictly increasing then strictly decreasing),
//          return the index of the peak element (the maximum).
// Approach: Binary Search on the property of a mountain array.
// 1. Start search between indices [1, n-2] since peak can’t be at the edges.
// 2. At each mid, check if arr[mid] is greater than both neighbors — if yes, that’s the peak.
// 3. If the left neighbor is smaller (ascending slope), move right.
// 4. Otherwise, move left (descending slope).
// Time Complexity: O(log n), Space Complexity: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2; // edges can't be the peak

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid; // found the peak
            } 
            else if(arr[mid - 1] < arr[mid]) {
                st = mid + 1; // move right, still ascending
            } 
            else { 
                end = mid - 1; // move left, descending slope
            }
        }
        return -1; // should not reach here in valid mountain array
    }
};
