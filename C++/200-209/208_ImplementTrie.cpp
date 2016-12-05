//Solution 1 I like this one better
class TrieNode {
public:
    vector<TrieNode*> children;
    bool flag;
    // Initialize your data structure here.
    TrieNode() {
        children.resize(26);
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        flag = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); i++) {
            int c = word[i] - 'a';
            if (p -> children[c] == nullptr) {
                p -> children[c] = new TrieNode();
            }
            p = p -> children[c];
        }
        p -> flag = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); i++) {
            int c = word[i] - 'a';
            if (p -> children[c] == nullptr) {
                return false;
            }
            p = p -> children[c];
        }
        return p -> flag;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.length(); i++) {
            int c = prefix[i] - 'a';
            if (p -> children[c] == nullptr) {
                return false;
            }
            p = p -> children[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

//Solution 2

class TrieNode {
public:
    // Initialize your data structure here.
    bool isEnd;
    unordered_map<char, TrieNode*> branches;
    TrieNode() {
        isEnd = false;
    }
    TrieNode(bool end) {
        isEnd = end;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        int i;
        for (i = 0; i < word.size(); i++) {
            if (node -> branches.find(word[i]) == node -> branches.end()) {
                break;
            } else {
              node = node -> branches[word[i]];
              node -> isEnd = ((i==word.size()-1)?true:node->isEnd);
            }
        }
        for (; i < word.size(); i++) {
            node -> branches[word[i]] = new TrieNode(i == word.size() - 1? true : false);
            node = node -> branches[word[i]];
            
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node -> branches.find(word[i]) == node -> branches.end()) {
                return false;
            } else {
                node = node -> branches[word[i]];
            }
        }
        if (node -> isEnd == true) {
            return true;
        } else {
            return false;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (node -> branches.find(prefix[i]) == node -> branches.end()) {
                return false;
            } else {
                node = node -> branches[prefix[i]];
            }
        }
        return true;
    }

private:
    TrieNode* root;
};