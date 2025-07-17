class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& currentCombination, vector<vector<int>>& combinations, int start) {
        if (target == 0) {
            combinations.push_back(currentCombination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                currentCombination.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], currentCombination, combinations, i);
                currentCombination.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    }
};
