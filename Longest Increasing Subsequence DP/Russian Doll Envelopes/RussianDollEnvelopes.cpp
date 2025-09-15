class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        vector<int> heights;
        for(const auto& envelope : envelopes)
            heights.push_back(envelope[1]);

        vector<int> lis;
        for(int height : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), height);
            if(it == lis.end()) {
                lis.push_back(height);
            }
            else {
                *it = height;
            }
        }
        return lis.size();
    }
};
