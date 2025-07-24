class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return nullptr;

        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(postorder.back());
        s.push(root);
        postorder.pop_back();

        while (!postorder.empty()) {
            TreeNode* node = new TreeNode(postorder.back());
            postorder.pop_back();

            if (!s.empty() && s.top()->val != inorder.back()) {
                s.top()->right = node;
            } else {
                TreeNode* parent = nullptr;
                while (!s.empty() && s.top()->val == inorder.back()) {
                    parent = s.top();
                    s.pop();
                    inorder.pop_back();
                }
                parent->left = node;
            }

            s.push(node);
        }

        return root;
    }
};
