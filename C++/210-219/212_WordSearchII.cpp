class TrieNode {
public: 
    bool is_end;
    vector<TrieNode*> children;
    TrieNode() {
        is_end = false;
        children = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
public: 
    TrieNode * root;

    Trie(vector<string> words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            addWord(words[i]);
        }
    }
    
    void addWord(string word) {
        TrieNode * cur = root; 
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (cur -> children[index] == NULL) {
                cur -> children[index] = new TrieNode();
            }
            cur = cur -> children[index];
        }
        cur -> is_end = true;
    }
};

class Solution {
public:
    void DFS(vector<vector<char>> &board, int i, int j, TrieNode *root, set<string> &s, string word) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') {
            return;
        }
        int index = board[i][j] - 'a';
        if (root -> children[index] != NULL) {
            word = word + board[i][j];
            root = root -> children[index];
            if (root -> is_end) {
                s.insert(word);
            }
            char tmp = board[i][j];
            board[i][j] = '#';
            DFS(board, i + 1, j, root, s, word);
            DFS(board, i - 1, j, root, s, word);
            DFS(board, i, j + 1, root, s, word);
            DFS(board, i, j - 1, root, s, word);
            board[i][j] = tmp;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie * trie = new Trie(words);
        TrieNode * root = trie -> root;
        set<string> s;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                DFS(board, i, j, root, s, "");
            }
        }
        vector<string> result;
        for (auto x : s) {
            result.push_back(x);
        }
        return result;
    }
};