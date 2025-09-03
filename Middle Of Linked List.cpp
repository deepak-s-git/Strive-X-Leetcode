// Problem: Middle of the Linked List
// Given the head of a singly linked list, return the middle node.
// If there are two middle nodes, return the second middle.
//
// Approach (Two-Pointer):
// 1. Use two pointers: slow and fast.
// 2. Move slow by 1 step, fast by 2 steps.
// 3. When fast reaches the end, slow will be at the middle.
//    - If list has odd length → exact middle.
//    - If list has even length → second middle (as required).
//
// Time Complexity: O(n)  (traverse list once)
// Space Complexity: O(1) (only two pointers)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;  // moves 1 step
        ListNode* fast = head;  // moves 2 steps

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;         // 1 step
            fast = fast->next->next;   // 2 steps
        }
        return slow; // slow now points to middle
    }
};
