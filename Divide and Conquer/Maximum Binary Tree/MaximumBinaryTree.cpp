class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
            return nullptr;

        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        TreeNode* root = new TreeNode(nums[maxIndex]);

        vector<int> left(nums.begin(), nums.begin() + maxIndex);
        root->left = constructMaximumBinaryTree(left);

        vector<int> right(nums.begin() + maxIndex + 1, nums.end());
        root->right = constructMaximumBinaryTree(right);

        return root;
    }
};
