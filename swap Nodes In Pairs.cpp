// Problem: Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes.
// Return the modified list.
//
// Approach (Iterative):
// 1. If list is empty or has only 1 node → return as is.
// 2. Use three pointers: 
//      - first (1st node in pair)
//      - sec   (2nd node in pair)
//      - prev  (end of previously swapped pair)
// 3. Swap first and sec → update links carefully.
// 4. Connect previous pair’s end to current swapped pair.
// 5. Move forward by two nodes and repeat.
//
// Time Complexity: O(n)  (each node visited once)
// Space Complexity: O(1)  (constant extra space)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; // 0 or 1 node → no swap
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while (first != NULL && sec != NULL) {
            ListNode* third = sec->next; // node after pair

            // Swap the pair
            sec->next = first;
            first->next = third;

            // Connect previous pair with current swapped pair
            if (prev != NULL) {
                prev->next = sec;
            } else {
                head = sec; // update head after first swap
            }

            // Move prev and first forward
            prev = first;
            first = third;

            // Update sec (second node of next pair)
            if (third != NULL) {
                sec = third->next;
            } else {
                sec = NULL;
            }
        }
        return head;
    }
};
