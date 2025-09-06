// Problem: Implement Stack using Queues
// LeetCode: https://leetcode.com/problems/implement-stack-using-queues/
//
// Approach:
// - We need to mimic **LIFO (stack)** behavior using a **queue (FIFO)**.
// - Idea: Always make the most recently pushed element appear at the **front** of the queue.
//   • push(x):
//       - Push element into queue.
//       - Rotate the queue (size-1 times) so that x comes to the front.
//   • pop():
//       - Simply pop from front (which is the top of stack).
//   • top():
//       - Return the front element of queue.
//   • empty():
//       - Return whether queue is empty.
//
// Time Complexity:
//   push: O(n) (because of rotation)
//   pop, top, empty: O(1)
// Space Complexity: O(n)

class MyStack {
public:
    queue<int> q; // single queue implementation

    MyStack() {
        // nothing to initialize
    }
    
    // Push element x onto stack
    void push(int x) {
        q.push(x);
        int n = q.size();
        
        // Rotate: move first (n-1) elements to back
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // Removes the element on top of the stack and returns it
    int pop() {
        int result = q.front();
        q.pop();
        return result;
    }
    
    // Get the top element
    int top() {
        return q.front();
    }
    
    // Returns whether the stack is empty
    bool empty() {
        return q.empty();
    }
};
