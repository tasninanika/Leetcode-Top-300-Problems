class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        max_gain(root, max_sum);
        return max_sum;
    }

private:
    int max_gain(TreeNode* node, int& max_sum) {
        if (!node) return 0;

        int left_gain = std::max(max_gain(node->left, max_sum), 0);
        int right_gain = std::max(max_gain(node->right, max_sum), 0);

        int current_max_path = node->val + left_gain + right_gain;

        max_sum = std::max(max_sum, current_max_path);

        return node->val + std::max(left_gain, right_gain);
    }
};
