// Problem: Check if a given string is a valid palindrome, considering only alphanumeric characters 
// and ignoring cases.
//
// Approach:
// 1. Use two pointers (st and end) from left and right.
// 2. Skip non-alphanumeric characters using isalnum().
// 3. Compare lowercase versions of characters at st and end.
// 4. If mismatch → return false, else keep moving pointers inward.
// 5. If loop ends without mismatches → return true.
//
// Time Complexity: O(n), Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;

        while (st < end) {
            if (!isalnum(s[st])) { st++; continue; }
            if (!isalnum(s[end])) { end--; continue; }
            if (tolower(s[st]) != tolower(s[end])) return false;
            st++; end--;
        }
        return true;
    }
};
