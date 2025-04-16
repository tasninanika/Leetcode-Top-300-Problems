class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c = 0;
        long long result = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                c++;
                result += c;
            }
            else{
                c = 0;
            }

        }
    }
};
