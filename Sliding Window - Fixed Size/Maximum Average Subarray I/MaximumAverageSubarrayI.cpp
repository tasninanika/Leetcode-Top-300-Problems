class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currentSum = 0;

        for(int i = 0; i < k; ++i){
            currentSum += nums[i];
        }

        double maxSum = currentSum;

        for(int i = k; i < nums.size(); i++){
            currentSum = currentSum - nums[i - k] + nums[i];

            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }

        return maxSum / k;
    }
};
