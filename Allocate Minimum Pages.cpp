// Problem: Book Allocation Problem
// Given an array where arr[i] = number of pages in the i-th book and k students,
// allocate books in order such that the maximum number of pages assigned to a student is minimized.
// Return that minimum possible value. If k > n (students more than books), return -1.
//
// Approach: Binary Search on Answer
// 1. The minimum possible value is 0, and the maximum possible is the sum of all pages.
// 2. Use binary search to guess a maximum allowed page count (mid).
// 3. Check feasibility with helper function isValid():
//    - Traverse the array, assigning books sequentially until exceeding mid, then allocate to the next student.
//    - If the number of students needed is more than k, it's not feasible.
// 4. If feasible, try smaller values (end = mid - 1). Otherwise, try larger values (st = mid + 1).
// Time Complexity: O(n * log(sum)), Space Complexity: O(1)

class Solution {
  public:
    bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages) {
        int students = 1, pages = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > maxAllowedPages) {
                return false; // single book exceeds limit
            }
            
            if(pages + arr[i] <= maxAllowedPages) {
                pages += arr[i]; // keep adding to current student
            } else {
                students++;       // allocate new student
                pages = arr[i];   // start fresh with this book
            }
        }
        return students <= m;
    }
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1; // more students than books → not possible
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i]; // total pages
        }
        
        int ans = -1;
        int st = 0, end = sum;
        
        while(st <= end) {
            int mid = st + (end - st) / 2;
            
            if(isValid(arr, n, k, mid)) {
                ans = mid;        // feasible → store answer
                end = mid - 1;    // try for smaller max
            } else {
                st = mid + 1;     // not feasible → increase limit
            }
        }
        return ans;
    }
};
