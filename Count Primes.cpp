// Problem: Count the number of prime numbers strictly less than n.
// Approach: Sieve of Eratosthenes
// 1. Create a boolean array `isPrime` initialized to true.
// 2. Iterate from 2 to n-1, and whenever we find a prime,
//    increment count and mark all multiples of it as non-prime.
// 3. Optimization: Instead of starting from i*2, we can start
//    from i*i since smaller multiples are already marked by smaller primes.
// Time Complexity: O(n log log n), Space Complexity: O(n)

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;

                // Start from i*i instead of i*2
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        }
        return count;
    }
};
