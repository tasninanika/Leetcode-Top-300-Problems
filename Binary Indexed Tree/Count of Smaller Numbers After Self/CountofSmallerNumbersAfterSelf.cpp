class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 10000;
        int size = 2 * offset + 1;
        vector<int> BIT(size + 1, 0);
        vector<int> result(nums.size(), 0);

        auto update = [&](int index, int value) {
            while (index < BIT.size()) {
                BIT[index] += value;
                index += (index & -index);
            }
        };

        auto query = [&](int index) {
            int sum = 0;
            while (index > 0) {
                sum += BIT[index];
                index -= (index & -index);
            }
            return sum;
        };

        for (int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i] + offset;
            result[i] = query(num);
            update(num + 1, 1);
        }
        return result;
    }
};
