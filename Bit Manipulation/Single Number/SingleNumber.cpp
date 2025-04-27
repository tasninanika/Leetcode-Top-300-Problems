class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single_value = 0;
        for(int i = 0; i < nums.size(); i++){
            single_value ^= nums[i];
        }

    }
};
