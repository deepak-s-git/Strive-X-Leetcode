// Problem: Perform in-place string compression.
// Given an array of characters, compress it by replacing sequences of repeating
// characters with the character followed by the count of repetitions.
// Example: ['a','a','b','b','c','c','c'] → ['a','2','b','2','c','3']
// Approach:
// 1. Iterate through the array, count consecutive occurrences of each character.
// 2. Place the character at the current answer index.
// 3. If the count > 1, convert count to string and place each digit separately.
// 4. Continue until all characters are processed. Return the new length.
// Time Complexity: O(n), Space Complexity: O(1) (in-place).

class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;

        for (int i = 0; i < chars.size();) {
            const char ch = chars[i];
            int count = 0;

            // Count consecutive occurrences of current char
            while (i < chars.size() && chars[i] == ch) {
                ++count;
                ++i;
            }

            // Place the character
            chars[ans++] = ch;

            // Place the count if > 1
            if (count > 1) {
                for (const char c : to_string(count)) {
                    chars[ans++] = c;
                }
            }
        }
        return ans; // length of compressed string
    }
};
