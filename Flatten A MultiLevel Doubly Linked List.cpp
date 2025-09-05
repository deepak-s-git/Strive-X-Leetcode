// Problem: Flatten a Multilevel Doubly Linked List
// Each node has `next`, `prev`, and an optional `child` pointer.
// Flatten the list so that all nodes appear in a single-level doubly linked list.
//
// Approach (DFS recursion):
// 1. Traverse the list node by node.
// 2. If a node has a child:
//      - Save `next` pointer.
//      - Recursively flatten the child list.
//      - Attach flattened child between current node and `next`.
//      - Fix `prev` links.
//      - Continue to the end of the child before reconnecting `next`.
// 3. Return the head.
//
// Time Complexity: O(n) (every node visited once)
// Space Complexity: O(1) extra (ignoring recursion stack)

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* next = curr->next;

                // Recursively flatten the child
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // Move curr to the end of the flattened child list
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // Reconnect the saved `next`
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
