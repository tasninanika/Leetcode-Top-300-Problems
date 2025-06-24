class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> window;
        int start = 0;
        long long sum = 0, maxSum = 0;

        for(int end = 0; end < nums.size(); end++){
            while(window.find(nums[end]) != window.end()){
                sum -= nums[start];
                window.erase(nums[start]);
                start++;
            }

            sum += nums[end];
            window.insert(nums[end]);

            if(end - start + 1 == k){
                maxSum = max(maxSum, sum);
                sum -= nums[start];
                window.erase(nums[start]);
                start++;
            }
        }

        return maxSum;
    }
};

