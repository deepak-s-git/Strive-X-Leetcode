// Problem: Linked List Cycle
// Given head of a linked list, determine if it contains a cycle.
// A cycle exists if a node’s next pointer points back to a previous node.
//
// Approach (Floyd’s Cycle Detection):
// 1. Use two pointers: slow and fast.
// 2. Move slow by 1 step, fast by 2 steps.
// 3. If fast and slow meet → there is a cycle.
// 4. If fast reaches NULL → no cycle.
//
// Why this works?
// - If there’s a cycle, the fast pointer laps around and eventually meets slow.
// - If there’s no cycle, fast reaches the end (NULL).
//
// Time Complexity: O(n)   (each pointer traverses at most n nodes)
// Space Complexity: O(1)  (constant extra pointers)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head; // moves 1 step
        ListNode* fast = head; // moves 2 steps

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // cycle found
            }
        }
        return false; // no cycle
    }
};
