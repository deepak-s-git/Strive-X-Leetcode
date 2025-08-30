// Problem: Given two strings s1 and s2, check if s2 contains a permutation of s1.
// Approach: Sliding Window + Frequency Count
// 1. Count frequency of characters in s1 (s1hash).
// 2. Use a sliding window of size s1.length() on s2 and maintain its frequency (s2hash).
// 3. At each step, compare both frequency arrays. If equal, permutation exists.
// 4. Move window forward by adding one char (right) and removing one char (left).
// Time Complexity: O(n), Space Complexity: O(1) since alphabet size is fixed (26).

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        int s1len = s1.size();
        int s2len = s2.size();
        if(s1len > s2len)
            return false;
        
        int left = 0, right = 0;

        // Build initial window of size s1len
        while(right < s1len) {
            s1hash[s1[right]-'a'] += 1;
            s2hash[s2[right]-'a'] += 1;
            right++;
        }
        right--; // right is now at window end

        // Slide window through s2
        while(right < s2len) {
            if(s1hash == s2hash) // permutation match
                return true;

            right++;
            if(right != s2len)
                s2hash[s2[right]-'a'] += 1; // include new char in window
            s2hash[s2[left]-'a'] -= 1;      // remove left char
            left++;
        }
        return false;
    }
};
