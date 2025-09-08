struct Node {
    int key, val;
    Node *next, *prev;

    Node() {
        key = val = -1;
        next = prev = nullptr;
    }
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = prev = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    Node *head, *tail;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void deletion(int key) {
        Node* node = mpp[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtBegin(int key, Node* node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
        mpp[key] = node;
    }

    int get(int key) {
        if (!mpp.count(key)) return -1;
        Node* node = mpp[key];
        deletion(key);
        insertAtBegin(key, node);
        return node->val;
    }

    void put(int key, int value) {
        if (mpp.count(key)) {
            Node* node = mpp[key];
            node->val = value;
            deletion(key);
            insertAtBegin(key, node);
            return;
        }
        if (mpp.size() == capacity) {
            Node* node = tail->prev;
            deletion(node->key);
            mpp.erase(node->key);
            delete node;
        }
        Node* node = new Node(key, value);
        insertAtBegin(key, node);
    }
};
