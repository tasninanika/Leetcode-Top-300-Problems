class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* current = root;
        for (char &ch : word) {
            if (!current->children.count(ch)) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        return searchInNode(word, 0, root);
    }

private:
    bool searchInNode(const string &word, int index, TrieNode* node) {
        if (index == word.length()) {
            return node->isEndOfWord;
        }

        char ch = word[index];
        if (ch == '.') {
            for (auto &pair : node->children) {
                if (searchInNode(word, index + 1, pair.second)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->children.count(ch)) {
                return false;
            }
            return searchInNode(word, index + 1, node->children[ch]);
        }
    }
};

