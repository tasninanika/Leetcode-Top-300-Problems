class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> frequency;

        for (int i = 0; i < nums.size(); i++) {
            frequency[nums[i]]++;
        }

        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (frequency[nums[i]] == 1) {
                result.push_back(nums[i]);
                frequency[nums[i]] = 0;
            }
        }

        return result;
    }
};
