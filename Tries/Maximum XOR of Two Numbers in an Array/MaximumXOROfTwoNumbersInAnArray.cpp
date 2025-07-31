class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        class TrieNode {
        public:
            TrieNode* left;
            TrieNode* right;
            TrieNode() : left(nullptr), right(nullptr) {}
        };

        class Trie {
        public:
            TrieNode* root;
            Trie() {
                root = new TrieNode();
            }
            void insert(int num) {
                TrieNode* curr = root;
                for (int i = 31; i >= 0; --i) {
                    int bit = (num >> i) & 1;
                    if (bit == 0) {
                        if (!curr->left) curr->left = new TrieNode();
                        curr = curr->left;
                    } else {
                        if (!curr->right) curr->right = new TrieNode();
                        curr = curr->right;
                    }
                }
            }
            int findMaxXOR(int num) {
                TrieNode* curr = root;
                int xorNum = 0;
                for (int i = 31; i >= 0; --i) {
                    int bit = (num >> i) & 1;
                    if (bit == 0) {
                        if (curr->right) {
                            xorNum |= (1 << i);
                            curr = curr->right;
                        } else {
                            curr = curr->left;
                        }
                    } else {
                        if (curr->left) {
                            xorNum |= (1 << i);
                            curr = curr->left;
                        } else {
                            curr = curr->right;
                        }
                    }
                }
                return xorNum;
            }
        };

        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }

        int maxXOR = 0;
        for (int num : nums) {
            maxXOR = max(maxXOR, trie.findMaxXOR(num));
        }

        return maxXOR;
    }
};
