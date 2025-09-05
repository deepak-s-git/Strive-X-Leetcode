// Problem: Merge Two Sorted Lists
// Merge two sorted linked lists into one sorted list and return its head.
//
// Approach (Recursive):
// 1. If one list is empty, return the other.
// 2. Compare head values:
//    - Smaller node becomes part of result,
//    - Recurse on the remaining list.
// 3. Return the chosen node.
//
// Time Complexity: O(n + m)
// Space Complexity: O(n + m) due to recursion stack.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};
