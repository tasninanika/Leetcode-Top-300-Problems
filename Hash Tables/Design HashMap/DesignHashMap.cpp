class MyHashMap {
private:
    static const int NUM_BUCKETS = 769;
    std::vector<std::list<std::pair<int, int>>> buckets;

    int getHash(int key) {
        return key % NUM_BUCKETS;
    }

public:
    MyHashMap() : buckets(NUM_BUCKETS) {}

    void put(int key, int value) {
        int hashKey = getHash(key);
        auto& chain = buckets[hashKey];
        for (auto& [k, v] : chain) {
            if (k == key) {
                v = value;
                return;
            }
        }
        chain.push_back({key, value});
    }

    int get(int key) {
        int hashKey = getHash(key);
        const auto& chain = buckets[hashKey];
        for (const auto& [k, v] : chain) {
            if (k == key) {
                return v;
            }
        }
        return -1;
    }

    void remove(int key) {
        int hashKey = getHash(key);
        auto& chain = buckets[hashKey];
        chain.remove_if([key](const std::pair<int, int>& kv) { return kv.first == key; });
    }
};
