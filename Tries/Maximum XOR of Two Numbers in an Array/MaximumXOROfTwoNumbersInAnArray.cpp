class Solution {
public:
    int findMaximumXOR(std::vector<int>& nums) {
        int maxXOR = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int xorVal = nums[i] ^ nums[j];
                maxXOR = std::max(maxXOR, xorVal);
            }
        }

        return maxXOR;
    }

};
