struct TrieNode {
    bool isWord;
    TrieNode* Children[26] = {nullptr};
    TrieNode() {
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int length = word.size();
        int num;
        TrieNode* current = root;
        for(int i=0; i<length; ++i) {
            num = word[i] - 'a';
            if(current->Children[num] == nullptr) {
                current->Children[num] = new TrieNode(); //add node in trie
            }
            current = current->Children[num]; //move ahead
        }
        current->isWord = true; //word has been added
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return check(word.c_str(), root);
    }
    
    bool check(const char* word, TrieNode* node) {
        for(int i=0; node && word[i]; ++i) {
            if(word[i] != '.') {
                if(node->Children[word[i]-'a'] == nullptr) return false;
                else node = node->Children[word[i]-'a'];
            } else {
                TrieNode* temp = node;
                for (int j = 0; j < 26; j++) {
                    node = temp->Children[j];
                    if(check(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */