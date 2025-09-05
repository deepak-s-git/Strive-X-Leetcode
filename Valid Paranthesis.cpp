// Problem: Valid Parentheses
// Given a string s containing just '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.
// A string is valid if:
//   - Open brackets are closed by the same type of brackets.
//   - Open brackets are closed in the correct order.
//
// Approach:
// 1. Use a stack to store opening brackets.
// 2. For every closing bracket, check the top of stack:
//      - If it matches, pop it.
//      - Otherwise, it's invalid.
// 3. At the end, the stack must be empty for the string to be valid.
//
// Time Complexity: O(n)  (each char processed once)
// Space Complexity: O(n)  (stack in worst case)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            // Push opening brackets
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } 
            // Handle closing brackets
            else {
                if (st.empty()) return false; // no match

                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '[' && s[i] == ']') ||
                    (st.top() == '{' && s[i] == '}')) {
                    st.pop(); // valid match → remove from stack
                } else {
                    return false; // mismatch
                }
            }
        }
        // Valid only if no unmatched opening brackets remain
        return st.empty();
    }
};
