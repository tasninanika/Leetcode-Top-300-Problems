class Solution {
public:
    int rob_linear(std::vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;
        for (int i = start; i <= end; ++i) {
            int temp = std::max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }

    int rob(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        return std::max(rob_linear(nums, 0, nums.size() - 2), rob_linear(nums, 1, nums.size() - 1));
    }
};
