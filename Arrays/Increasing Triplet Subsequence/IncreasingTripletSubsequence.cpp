class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= first) {
                first = nums[i];
            }
            else if (nums[i] <= second) {
                second = nums[i];
            }
            else {
                c++;
            }
        }

        if(c != 0){
            return true;
        }
        else{
            return false;
        }
    }
};
