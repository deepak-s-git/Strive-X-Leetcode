// Problem: Aggressive Cows
// We have N stalls (positions given in arr[]) and C cows to place.
// Goal: Place cows in stalls such that the minimum distance between any two cows is maximized.
//
// Approach: Binary Search on Answer
// 1. Sort the stall positions first.
// 2. The minimum possible distance = 1 (two cows at consecutive stalls).
// 3. The maximum possible distance = arr[N-1] - arr[0] (farthest two stalls).
// 4. Binary search on distance range [1, maxDist].
// 5. For each mid (candidate minimum distance):
//      - Try placing cows greedily in stalls (always pick the next stall that is >= mid distance away).
//      - If we can place all cows → possible, so move right (st = mid + 1).
//      - Else move left (end = mid - 1).
//
// Time Complexity: O(N log(maxDist)), Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function: check if we can place C cows with at least minAllowedDist apart
    bool isPossible(vector<int> &arr, int N, int C, int minAllowedDist) {
        int cows = 1;               // first cow at the first stall
        int lastStallPos = arr[0];  // position of last placed cow

        for (int i = 1; i < N; i++) {
            // if current stall is at least minAllowedDist away from last cow
            if (arr[i] - lastStallPos >= minAllowedDist) {
                cows++;                  // place cow here
                lastStallPos = arr[i];   // update last placed stall
            }
            if (cows == C) return true;  // all cows placed successfully
        }
        return false; // not enough stalls to place all cows with given distance
    }

    // Main function: binary search on distance
    int getDistance(vector<int> &arr, int N, int C) {
        sort(arr.begin(), arr.end()); // sort stall positions

        int st = 1;                    // minimum possible distance
        int end = arr[N - 1] - arr[0]; // maximum possible distance
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // check if placement is possible with mid as minimum distance
            if (isPossible(arr, N, C, mid)) {
                ans = mid;        // store valid answer
                st = mid + 1;     // try for bigger distance
            } else {
                end = mid - 1;    // reduce distance
            }
        }
        return ans;
    }
};

int main() {
    int N = 5, C = 3;
    vector<int> arr = {1, 2, 8, 4, 9};

    Solution obj;
    cout << obj.getDistance(arr, N, C) << endl; // Output: 3
    return 0;
}
