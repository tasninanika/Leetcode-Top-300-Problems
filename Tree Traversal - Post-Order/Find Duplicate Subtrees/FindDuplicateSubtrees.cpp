class Solution {
public:
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::unordered_map<std::string, int> idsMap;
        std::unordered_map<int, int> countMap;
        std::vector<TreeNode*> duplicates;
        issueId = 0;
        collect(root, idsMap, countMap, duplicates);
        return duplicates;
    }

private:
    int collect(TreeNode* node, std::unordered_map<std::string, int>& idsMap, std::unordered_map<int, int>& countMap, std::vector<TreeNode*>& duplicates) {
        if (!node) return 0;

        std::string serialized = std::to_string(node->val) + "," + std::to_string(collect(node->left, idsMap, countMap, duplicates)) + "," + std::to_string(collect(node->right, idsMap, countMap, duplicates));

        int subtreeId = 0;
        if (idsMap.find(serialized) == idsMap.end()) {
            subtreeId = ++issueId;
            idsMap[serialized] = subtreeId;
        } else {
            subtreeId = idsMap[serialized];
        }

        if (++countMap[subtreeId] == 2) {
            duplicates.push_back(node);
        }

        return subtreeId;
    }

    int issueId;
};
