class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        std::stack<TreeNode*> stack;
        TreeNode* current = root;
        TreeNode* prev = nullptr;

        while (current || !stack.empty()) {
            while (current) {
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            stack.pop();
            if (prev && current->val <= prev->val) return false;
            prev = current;
            current = current->right;
        }
        return true;
    }
};
