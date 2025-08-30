// Problem: Reverse the words in a given string (remove extra spaces).
// Approach:
// 1. Reverse the entire string first → words will appear in reverse order.
// 2. Traverse through the string, extract each word (ignoring spaces).
// 3. Reverse each extracted word and append it to the answer.
// 4. Trim the leading space by returning ans.substr(1).
// Example: "  hello   world  " → "world hello"
// Time Complexity: O(n), Space Complexity: O(n) for the result string.

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        // Step 1: Reverse the whole string
        reverse(s.begin(), s.end());

        // Step 2: Traverse and build words
        for(int i = 0; i < n; i++) {
            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Step 3: Reverse the individual word
            reverse(word.begin(), word.end());

            // Step 4: Add word to result if it's not empty
            if(word.length() > 0) {
                ans += " " + word;
            }
        }

        // Step 5: Remove extra space at the beginning
        return ans.substr(1);
    }
};
