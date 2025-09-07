// Problem: Implement Queue using Stacks
// LeetCode: https://leetcode.com/problems/implement-queue-using-stacks/
//
// Approach (Two-Stack Method):
// - Use two stacks: s1 (main stack) and s2 (helper).
// - push(x):
//      1. Move everything from s1 -> s2.
//      2. Push x into s1.
//      3. Move everything back from s2 -> s1.
//      => Ensures front of queue is always at top of s1.
// - pop():
//      - Return and remove s1.top() (which is front of queue).
// - peek():
//      - Return s1.top().
// - empty():
//      - Return true if s1 is empty.
//
// Time Complexity:
//   push: O(n) (due to shifting elements twice)
//   pop, peek, empty: O(1)
// Space Complexity: O(n)

class MyQueue {
private:
    stack<int> s1; // main stack to hold queue elements
    stack<int> s2; // helper stack for push operation

public:
    MyQueue() {
        // nothing to initialize
    }

    // Push element x to the back of queue
    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element into s1
        s1.push(x);

        // Move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Removes element from front of queue and returns it
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }

    // Get the front element
    int peek() {
        return s1.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return s1.empty();
    }
};