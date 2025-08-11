class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }

        const auto& values = store[key];

        auto it = upper_bound(values.begin(), values.end(), make_pair(timestamp, string("")),
                              [](const pair<int, string>& a, const pair<int, string>& b) {
                                  return a.first < b.first;
                              });

        if (it == values.begin()) {
            return "";
        }

        --it;

        return it->second;
    }
};
