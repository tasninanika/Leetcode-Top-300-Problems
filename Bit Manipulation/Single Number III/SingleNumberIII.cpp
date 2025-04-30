class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> frequency;

        for (int i = 0; i < nums.size(); i++) {
            frequency[nums[i]]++;
        }

        vector<int> result;
    }
};
