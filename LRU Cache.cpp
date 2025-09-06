// Problem: LRU Cache
// Design a data structure that supports the following operations in O(1):
//   - get(key): Return the value if present, else -1
//   - put(key, value): Insert/Update the value. If capacity is exceeded, evict the least recently used (LRU) item.
//
// Approach:
// 1. Use a **Doubly Linked List (DLL)** + **HashMap**.
//    - DLL maintains order of usage: most recently used (MRU) at the front, LRU at the back.
//    - HashMap (key → DLL node) provides O(1) access to nodes.
// 2. Operations:
//    - get(key):
//        • If key exists: move the node to front (MRU) and return value.
//        • Else return -1.
//    - put(key, value):
//        • If key exists: remove old node, insert new node at front.
//        • If capacity full: remove node before dummyTail (LRU), erase from map.
//        • Insert new node at front, update map.
// 3. Helper functions:
//    - addToFront(node): Insert node right after dummyHead.
//    - removeNode(node): Remove a node from DLL.
//
// Time Complexity: O(1) for both get and put
// Space Complexity: O(capacity)

class LRUCache {
public:
    class DLLNode {
    public:
        int k, v;
        DLLNode* prevNode;
        DLLNode* nextNode;
        DLLNode(int key, int value) {
            this->k = key;
            this->v = value;
            prevNode = nextNode = nullptr;
        }
    };

    DLLNode* dummyHead = new DLLNode(-1, -1);
    DLLNode* dummyTail = new DLLNode(-1, -1);

    int capacity;
    unordered_map<int, DLLNode*> cache; // key -> node pointer

    LRUCache(int cap) {
        capacity = cap;
        dummyHead->nextNode = dummyTail;
        dummyTail->prevNode = dummyHead;
    }

    // Insert node right after dummyHead (marking it MRU)
    void addToFront(DLLNode* newNode) {
        DLLNode* temp = dummyHead->nextNode;
        newNode->nextNode = temp;
        newNode->prevNode = dummyHead;
        dummyHead->nextNode = newNode;
        temp->prevNode = newNode;
    }

    // Remove any node from DLL
    void removeNode(DLLNode* node) {
        DLLNode* prevTemp = node->prevNode;
        DLLNode* nextTemp = node->nextNode;
        prevTemp->nextNode = nextTemp;
        nextTemp->prevNode = prevTemp;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            DLLNode* targetNode = cache[key];
            int value = targetNode->v;

            // Move node to front (MRU)
            cache.erase(key);
            removeNode(targetNode);
            addToFront(targetNode);

            cache[key] = dummyHead->nextNode;
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            DLLNode* existing = cache[key];
            cache.erase(key);
            removeNode(existing);
        }

        if (cache.size() == capacity) {
            // Remove LRU node (just before dummyTail)
            cache.erase(dummyTail->prevNode->k);
            removeNode(dummyTail->prevNode);
        }

        // Insert new node at front (MRU)
        addToFront(new DLLNode(key, value));
        cache[key] = dummyHead->nextNode;
    }
};
