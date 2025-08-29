// Problem: Merge two sorted arrays (nums1 = A with size m+n, nums2 = B with size n)
// Task: Merge B into A in sorted order, in-place
//
// Approach:
// - Start filling from the last index (m+n-1).
// - Compare A[i] and B[j] (largest remaining elements).
// - Place the larger one at idx and move pointers.
// - If B has leftover elements, copy them (A’s leftovers are already in place).
//
// Time: O(m+n), Space: O(1)

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx = m + n - 1; // position to fill from the back
        int i = m - 1;       // last element index in A's valid part
        int j = n - 1;       // last element index in B

        // Step 1: Place bigger of A[i] and B[j] at idx, move backwards
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[idx--] = A[i--]; // put A[i], move i left
            } else {
                A[idx--] = B[j--]; // put B[j], move j left
            }
        }

        // Step 2: If B still has elements, copy them
        // (No need to handle leftover A, already in place)
        while (j >= 0) {
            A[idx--] = B[j--];
        }
    }
};
