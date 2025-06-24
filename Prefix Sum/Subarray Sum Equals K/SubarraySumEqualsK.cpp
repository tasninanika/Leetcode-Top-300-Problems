class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c = 0;

        for (int start = 0; start < nums.size(); start++) {
            int sum = 0;

            for (int end = start; end < nums.size(); end++) {
                sum += nums[end];
                if (sum == k) {
                    c++;
                }
            }
        }
        return c;
    }
};
