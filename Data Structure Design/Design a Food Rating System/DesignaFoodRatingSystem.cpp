class FoodRatings {
public:
    struct cmp {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) const {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        }
    };

    unordered_map<string, pair<string, int>> foodInfo;
    unordered_map<string, set<pair<int, string>, cmp>> foodSets;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < (int)foods.size(); i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            foodSets[cuisines[i]].emplace(ratings[i], foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        auto &info = foodInfo[food];
        auto &cuisineSet = foodSets[info.first];
        cuisineSet.erase({info.second, food});
        info.second = newRating;
        cuisineSet.emplace(newRating, food);
    }

    string highestRated(string cuisine) {
        return foodSets[cuisine].begin()->second;
    }
};

