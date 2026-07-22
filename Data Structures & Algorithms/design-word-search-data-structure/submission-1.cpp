class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int child = c - 'a';

            if (curr->children[child] == nullptr)
                curr->children[child] = new TrieNode();

            curr = curr->children[child];
        }

        curr->isEnd = true;
    }

    bool dfs(TrieNode* node, string &word, int idx) {

        if (idx == word.size())
            return node->isEnd;

        char c = word[idx];

        if (c != '.') {

            int child = c - 'a';

            if (node->children[child] == nullptr)
                return false;

            return dfs(node->children[child], word, idx + 1);

        } else {

            for (int i = 0; i < 26; i++) {

                if (node->children[i] != nullptr) {

                    if (dfs(node->children[i], word, idx + 1))
                        return true;
                }
            }

            return false;
        }
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};