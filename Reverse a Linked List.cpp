// Problem: Reverse Linked List
// Given the head of a singly linked list, reverse the list and return the new head.
//
// Approach (Iterative):
// 1. Maintain three pointers: prev, curr, next.
// 2. Iterate through the list:
//      - Store next node.
//      - Reverse curr->next to point to prev.
//      - Move prev and curr forward.
// 3. At the end, prev will be the new head.
//
// Time Complexity: O(n)  (each node visited once)
// Space Complexity: O(1) (only constant extra pointers)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;   // will point to reversed part
        ListNode* curr = head;   // current node being processed
        ListNode* next = NULL;   // store next node before breaking link

        while (curr != NULL) {
            next = curr->next;   // save next node
            curr->next = prev;   // reverse link
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }
        return prev; // new head
    }
};
