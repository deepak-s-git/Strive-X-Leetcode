// Problem: Min Stack
// Design a stack that supports push, pop, top, and getMin in O(1) time.
//
// Approach (Single Stack + Encoding):
// - Maintain a variable minVal to track the current minimum.
// - Instead of pushing values directly when a new minimum comes,
//   encode it using: encodedVal = 2*val - minVal.
//   This way, when popping, we can decode the previous min.
// 
// push(val):
//   - If stack empty: push val, set minVal = val.
//   - If val >= minVal: push val normally.
//   - If val < minVal: push encoded value (2*val - minVal),
//     update minVal = val.
// 
// pop():
//   - If top < minVal: it means top is an encoded value.
//     Restore previous min using: minVal = 2*minVal - top.
//   - Pop the element.
// 
// top():
//   - If top < minVal: return minVal (since top is encoded).
//   - Else, return top normally.
// 
// getMin():
//   - Return current minVal.
//
// Time Complexity: O(1) for all operations
// Space Complexity: O(n) for stack

class MinStack {
public:
    stack<long long> s;
    long long minVal;

    MinStack() {}
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } else if (val < minVal) {
            // Encode value
            s.push(2LL * val - minVal);
            minVal = val;
        } else {
            s.push(val);
        }
    }
    
    void pop() {
        if (s.top() < minVal) {
            // Restore previous min
            minVal = 2 * minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if (s.top() < minVal) {
            return minVal;
        }
        return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};
