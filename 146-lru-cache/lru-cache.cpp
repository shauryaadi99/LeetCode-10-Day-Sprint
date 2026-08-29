class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            this->key = k;
            this->val = v;
            prev = next = NULL;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addNode(Node* newNode) {
        Node* oldnext = head->next;
        head->next = newNode;
        newNode->next = oldnext;
        newNode->prev = head;
        oldnext->prev = newNode;
    }
    void deleteNode(Node* currNode) {
        Node* prevNode = currNode->prev;
        Node* nextNode = currNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    unordered_map<int, Node*> mp;
    int limit;
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.count(key)) {
            Node* resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if (mp.size() == limit) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */