// Problem: Copy List with Random Pointer
// Given a linked list where each node has an extra random pointer, 
// create a deep copy of the list.
//
// Approach:
// 1. Use a hashmap to store mapping: original node -> copied node.
// 2. First pass: copy all nodes (with `next` links) and fill the map.
// 3. Second pass: assign `random` pointers using the map.
// 4. Return the new head.
//
// Time Complexity: O(n)
// Space Complexity: O(n) for hashmap

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> m;

        // Create first node
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;

        // First pass: copy nodes and next pointers
        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Second pass: assign random pointers
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
