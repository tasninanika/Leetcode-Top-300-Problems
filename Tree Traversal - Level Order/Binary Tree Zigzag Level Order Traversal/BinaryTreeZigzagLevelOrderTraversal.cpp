class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        deque<TreeNode*> deq;
        deq.push_back(root);
        bool leftToRight = true;

        while (!deq.empty()) {
            int size = deq.size();
            vector<int> level(size);

            for (int i = 0; i < size; ++i) {
                if (leftToRight) {
                    TreeNode* node = deq.front();
                    deq.pop_front();
                    level[i] = node->val;
                    if (node->left) deq.push_back(node->left);
                    if (node->right) deq.push_back(node->right);
                } else {
                    TreeNode* node = deq.back();
                    deq.pop_back();
                    level[i] = node->val;
                    if (node->right) deq.push_front(node->right);
                    if (node->left) deq.push_front(node->left);
                }
            }

            leftToRight = !leftToRight;
            result.push_back(level);
        }

        return result;
    }
};
