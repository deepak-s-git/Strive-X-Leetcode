// Problem: Reverse Integer (LeetCode 7)
// Given a 32-bit signed integer x, return its digits reversed.
// If the reversed integer overflows (goes beyond [-2^31, 2^31 - 1]), return 0.
//
// Approach:
// 1. Extract digits one by one using modulo (%) and division (/).
// 2. Before updating the reversed number, check for overflow/underflow.
//    - If revNum > INT_MAX/10 OR revNum < INT_MIN/10, return 0.
// 3. Update revNum = revNum * 10 + last_digit.
//
// Time Complexity: O(log10(x))  (number of digits in x)
// Space Complexity: O(1)

class Solution {
public:
    int reverse(int x) {
        int revNum = 0;

        while (x != 0) {
            int dig = x % 10;

            // Check for overflow before multiplying by 10
            if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10) {
                return 0;
            }

            revNum = revNum * 10 + dig;
            x = x / 10;
        }
        return revNum;
    }
};
