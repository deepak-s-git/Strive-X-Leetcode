// Problem: Palindrome Number (LeetCode 9)
// Given an integer x, return true if x is a palindrome, and false otherwise.
//
// Approach:
// 1. Negative numbers are not palindromes (e.g., -121 != 121-).
// 2. Reverse the integer using modulo (%) to extract digits.
// 3. Store the reversed number in a `long long` to avoid overflow.
// 4. Compare the reversed number with the original number.
//    - If equal, it's a palindrome.
//    - Otherwise, it's not.
//
// Time Complexity: O(log10(x))  (we process each digit once)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;  // negative numbers can't be palindromes

        long long reversed = 0;
        long long temp = x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};
