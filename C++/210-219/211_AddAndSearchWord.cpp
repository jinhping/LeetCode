class TrieNode {
public: 
    TrieNode () {
        children.resize(26);
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isExist = false;
    }
    bool isExist;
    vector<TrieNode*> children;
};

class WordDictionary {
private: 
    TrieNode * root;
public:
    
    WordDictionary () {
        root = new TrieNode();
    }
    
    
    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        TrieNode *p = root;
        for (int i = 0; i < word.length(); i++) {
            int c = word[i] - 'a';
            if (p -> children[c] == nullptr) {
                p -> children[c] = new TrieNode();
            }
            p = p -> children[c];
        }
        p -> isExist = true;
    }

    bool find (string word, int n, int index, TrieNode *root) {
       if (n == index) {
           return root -> isExist;
       }
       if (word[index] == '.') {
           for (int i = 0; i < 26; i++) {
               if (root -> children[i]) {
                    if (find(word, n, index + 1, root -> children[i])) {
                        return true;
                    }
               }
           }
           
       } else {
           int c = word[index] - 'a';
           if (root -> children[c]) {
               return find(word, n, index + 1, root -> children[c]);
           } 
       }
       return false;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        int n = word.length();
        return find(word, n, 0, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");