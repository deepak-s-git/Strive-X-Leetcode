// Problem: Reverse Nodes in k-Group
// Given a linked list, reverse nodes in groups of size k.
// If the remaining nodes are fewer than k, leave them as is.
//
// Approach (Recursion):
// 1. Count k nodes ahead starting from head.
//    - If fewer than k nodes remain, return head (no reversal).
// 2. Otherwise, recursively call reverseKGroup for the rest of the list.
// 3. Reverse the current group of k nodes and attach it to the result of recursion.
// 4. Return new head of the reversed group.
//
// Time Complexity: O(n)  (each node visited once)
// Space Complexity: O(n/k) recursion depth

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // Step 1: check if there are at least k nodes
        while (cnt < k) {
            if (temp == NULL) {
                return head; // not enough nodes, return as is
            }
            temp = temp->next;
            cnt++;
        }

        // Step 2: recursively reverse from kth node onward
        ListNode* prevNode = reverseKGroup(temp, k);

        // Step 3: reverse current group of k nodes
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }

        return prevNode; // new head of this reversed group
    }
};
