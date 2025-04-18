class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min_num = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0){
                continue;
            }
            else if(nums[i] == min_num){
                min_num++;
            }

    }
};
