class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1;
        int cumulativeSum = 0;

        for(int i = 0; i < nums.size(); ++i){
            cumulativeSum += nums[i];
            int remainder = cumulativeSum % k;

            if(remainder < 0){
                remainder += k;
            }
            if(remainderIndex.find(remainder) != remainderIndex.end()){
                if (i - remainderIndex[remainder] > 1) {
                    return true;
                }
            }
            else{
                remainderIndex[remainder] = i;
            }
        }
        return false;
    }
};
