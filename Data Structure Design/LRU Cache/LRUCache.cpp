class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;

        moveToHead(it->second);
        return it->second->value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second->value = value;
            moveToHead(it->second);
        } else {
            if (cache.size() == cap) {
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
        }
    }

private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    void addToHead(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    int cap;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> cache;
};
