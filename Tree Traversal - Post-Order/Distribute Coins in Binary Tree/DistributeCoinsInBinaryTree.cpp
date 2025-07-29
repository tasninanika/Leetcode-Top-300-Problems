class Solution {
public:
    int totalMoves = 0;

    int distributeCoins(TreeNode* root) {
        distribute(root);
        return totalMoves;
    }

    int distribute(TreeNode* node) {
        if (!node) return 0;

        int leftExcess = distribute(node->left);
        int rightExcess = distribute(node->right);

        totalMoves += abs(leftExcess) + abs(rightExcess);

        return node->val + leftExcess + rightExcess - 1;
    }
};
