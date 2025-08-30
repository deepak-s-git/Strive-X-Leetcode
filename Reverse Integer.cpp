// Problem: Reverse Integer (LeetCode 7)
// Given a 32-bit signed integer x, return its digits reversed.
// If the reversed integer overflows (outside [-2^31, 2^31 - 1]), return 0.
//
// Approach:
// 1. Use a `long` to safely hold the reversed number while building it.
// 2. Extract digits using modulo (%) and build the reversed number.
// 3. After the loop, check if the result fits into the 32-bit signed integer range.
//    - If not, return 0.
// 4. Otherwise, return the reversed integer.
//
// Time Complexity: O(log10(x))  (since we process each digit once)
// Space Complexity: O(1)

class Solution {
 public:
  int reverse(int x) {
    long ans = 0;

    while (x != 0) {
      ans = ans * 10 + x % 10;
      x /= 10;
    }

    return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans;
  }
};
