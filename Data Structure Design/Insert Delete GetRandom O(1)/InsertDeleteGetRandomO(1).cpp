class RandomizedSet {
private:
    std::unordered_map<int, int> valToIndex;
    std::vector<int> elements;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        elements.push_back(val);
        valToIndex[val] = elements.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }

        int indexToRemove = valToIndex[val];
        int lastElement = elements.back();
        elements[indexToRemove] = lastElement;
        valToIndex[lastElement] = indexToRemove;

        elements.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % elements.size();
        return elements[randomIndex];
    }
};
