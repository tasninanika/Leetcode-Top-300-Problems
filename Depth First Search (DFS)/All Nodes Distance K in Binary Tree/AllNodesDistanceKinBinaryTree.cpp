class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        createParentMap(root, parentMap, nullptr);

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int currentDistance = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currentDistance == K) {
                vector<int> result;
                for (int i = 0; i < size; ++i) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parentMap[node] && !visited.count(parentMap[node])) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            currentDistance++;
        }

        return {};
    }

private:
    void createParentMap(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* parent) {
        if (!node) return;

        parentMap[node] = parent;

        createParentMap(node->left, parentMap, node);
        createParentMap(node->right, parentMap, node);
    }
};
