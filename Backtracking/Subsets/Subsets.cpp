class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& subsets) {
        subsets.push_back(current);

        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, subsets);
            current.pop_back();
        }
}


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> current;
        backtrack(0, nums, current, subsets);
        return subsets;
    }
};
