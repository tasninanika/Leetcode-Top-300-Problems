class SnapshotArray {
private:
    vector<vector<pair<int, int>>> data;
    int snap_id;

public:
    SnapshotArray(int length) : data(length), snap_id(0) {
        for (int i = 0; i < length; ++i) {
            data[i].emplace_back(-1, 0);
        }
    }

    void set(int index, int val) {
        if (data[index].back().first == snap_id) {
            data[index].back().second = val;
        }
        else {
            data[index].emplace_back(snap_id, val);
        }
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        auto& vec = data[index];
        auto it = upper_bound(vec.begin(), vec.end(), make_pair(snap_id, INT_MAX));
        it--;
        return it->second;
    }
};
