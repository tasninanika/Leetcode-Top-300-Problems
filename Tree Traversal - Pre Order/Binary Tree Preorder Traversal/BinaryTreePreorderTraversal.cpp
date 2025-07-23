class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == nullptr)
            return result;

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while(!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();

            result.push_back(node->val);

            if (node->right) {
                nodeStack.push(node->right);
            }
            if (node->left) {
                nodeStack.push(node->left);
            }
        }

        return result;
    }
};
