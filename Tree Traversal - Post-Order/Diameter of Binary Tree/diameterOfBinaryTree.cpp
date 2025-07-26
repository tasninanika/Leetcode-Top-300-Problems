class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return heightAndDiameter(root).second;
    }

private:
    std::pair<int, int> heightAndDiameter(TreeNode* node) {
        if (!node) return {0, 0};

        auto left = heightAndDiameter(node->left);
        auto right = heightAndDiameter(node->right);

        int currentHeight = 1 + std::max(left.first, right.first);

        int currentDiameter = std::max({left.second, right.second, left.first + right.first});

        return {currentHeight, currentDiameter};
    }
};
