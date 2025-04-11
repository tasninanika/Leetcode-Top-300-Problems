class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c = 1;

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                c++;
            }
            else {
                c = 1;
            }

            if(c > (nums.size() / 2)) {
                return nums[i];
            }
        }


    }
};
