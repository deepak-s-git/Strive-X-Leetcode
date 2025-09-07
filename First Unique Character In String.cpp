// Problem: First Unique Character in a String
// Approach:
// - Use a frequency array of size 26 (since input contains only lowercase letters).
// - First pass: count the frequency of each character.
// - Second pass: find the first index where frequency == 1.
// - If none found, return -1.
//
// Time Complexity: O(n)  (two passes over the string)
// Space Complexity: O(1) (fixed array of size 26)

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Find first index with frequency 1
        for (int idx = 0; idx < s.size(); idx++) {
            if (freq[s[idx] - 'a'] == 1) {
                return idx;
            }
        }

        return -1;
    }
};
