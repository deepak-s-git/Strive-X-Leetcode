// Problem: Remove all occurrences of substring `part` from string `s`.
// Approach:
// 1. While `part` exists in `s`, find its position using `find()`.
// 2. Erase it using `erase(start, length)`.
// 3. Continue until no more occurrences are found.
// Time Complexity: O(n * m) in worst case (n = length of s, m = length of part),
// Space Complexity: O(1) extra.

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};
