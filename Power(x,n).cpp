// Problem: Implement pow(x, n) — calculate x raised to the power n.
// Approach: Binary Exponentiation (Fast Power)
// 1. If n is negative, invert x and make n positive.
// 2. Use binary representation of n to compute the power in O(log n) time.
//    - If the current bit is 1 (odd exponent), multiply result by x.
//    - Square x at each step and move to the next bit by dividing exponent by 2.

class Solution {
public:
    double myPow(double x, int n) {
        long binForm = n; // store in long to handle -2^31 edge case

        if(n < 0) {
            x = 1 / x;       // reciprocal for negative exponent
            binForm = -binForm;
        }

        double ans = 1;

        while(binForm > 0) {
            if(binForm % 2 == 1) { // if current bit is set
                ans *= x;          // multiply result by current x
            }
            x *= x;                // square x for next bit
            binForm /= 2;          // move to next bit
        }

        return ans;
    }
};
