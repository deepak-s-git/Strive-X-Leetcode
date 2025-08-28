// Problem: Painter's Partition Problem
// We have 'n' boards of lengths arr[0..n-1] and 'm' painters. 
// Each painter paints continuous boards only.
// Goal: Minimize the maximum time taken by any painter.
//
// Approach: Binary Search on Answer
// 1. The minimum possible time = max board length (since at least one board must be painted).
// 2. The maximum possible time = sum of all boards (if one painter paints all).
// 3. Use binary search on this range [maxVal, sum] to guess a maximum allowed time (mid).
// 4. Check feasibility with helper function isPossible():
//      - Traverse the boards, assign them to painters until exceeding mid, then allocate to the next painter.
//      - If number of painters needed > m → not feasible.
// 5. If feasible, try smaller values (end = mid - 1). Else try larger (st = mid + 1).
//
// Time Complexity: O(n * log(sum)), Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function: check if it's possible with given max allowed time
    bool isPossible(vector<int> &arr, int n, int m, int allowedTime) {
        int painters = 1, time = 0;

        for (int i = 0; i < n; i++) {
            // If a single board is larger than allowedTime, impossible
            if (arr[i] > allowedTime) return false;

            // If current painter can take this board
            if (time + arr[i] <= allowedTime) {
                time += arr[i]; // add to current painter's load
            } else {
                // Otherwise, allocate to a new painter
                painters++;
                if (painters > m) return false; // too many painters needed
                time = arr[i]; // start new painter with current board
            }
        }
        return true; // allocation is feasible
    }

    // Main function: binary search on answer
    int minTimeToPaint(vector<int> &arr, int n, int m) {
        int sum = 0, maxVal = INT_MIN;

        // Calculate total sum and largest board
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxVal = max(maxVal, arr[i]);
        }

        int st = maxVal, end = sum, ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Check feasibility with current mid
            if (isPossible(arr, n, m, mid)) {
                ans = mid;         // store current best answer
                end = mid - 1;     // try smaller maximum time
            } else {
                st = mid + 1;      // increase limit since not feasible
            }
        }
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.minTimeToPaint(arr, n, m) << endl;
    return 0;
}
