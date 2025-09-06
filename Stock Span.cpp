// Problem: Stock Span Problem
// Given an array of stock prices for n days, for each day i find the span:
//   - The maximum number of consecutive days (ending on day i)
//     for which the stock price <= price[i].
//
// Example:
// Input:  [100, 80, 60, 70, 60, 75, 85]
// Output: [1,   1,  1,  2,  1,  4,  6]
//
// Approach (Monotonic Stack):
// 1. Use a stack to store indices of previous higher prices.
// 2. For each price[i]:
//      - Pop from stack while price[top] <= price[i] (they are "spanned").
//      - If stack becomes empty → span = i+1 (all previous days covered).
//      - Else → span = i - stack.top() (distance from last higher price).
// 3. Push current index onto the stack.
// 4. Print the span array.
//
// Time Complexity: O(n)  (each index pushed/popped at most once)
// Space Complexity: O(n)  (stack + answer array)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans(price.size());
    stack<int> s; // stores indices

    for (int i = 0; i < price.size(); i++) {
        // Pop indices with price <= current price
        while (!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }

        // If no greater element on left, span = i+1
        ans[i] = s.empty() ? (i + 1) : (i - s.top());

        s.push(i); // push current index
    }

    // Print spans
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
