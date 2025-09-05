// Problem: Linked List Cycle II
// Given head of a linked list, return the node where the cycle begins.
// If there is no cycle, return NULL.
//
// Approach (Floyd’s Cycle Detection + Cycle Entry Point):
// 1. Use slow & fast pointers to detect if a cycle exists.
//    - slow moves 1 step, fast moves 2 steps.
//    - if they meet → cycle exists.
//    - if fast reaches NULL → no cycle.
// 2. To find cycle start:
//    - Once slow & fast meet inside the cycle, reset slow to head.
//    - Move both slow & fast by 1 step at a time.
//    - The node where they meet again = start of the cycle.
//
// Why this works?
// - When slow & fast meet, distance traveled can be expressed as:
//   (distance from head to cycle start) == (distance from meeting point to cycle start)
//   Hence, moving both at same speed will meet exactly at cycle entry.
//
// Time Complexity: O(n)   (each pointer moves at most n steps)
// Space Complexity: O(1)  (constant extra memory)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        // Step 1: Detect cycle using Floyd’s algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) return NULL; // no cycle

        // Step 2: Find cycle start
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow; // start of cycle
    }
};
