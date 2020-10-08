struct TrieNode {
  bool isWord;
  TrieNode* Children[26] = {nullptr};
  TrieNode() {
      isWord = false; // Something isn't a word until we define it as one.
  }
};


class Trie {
private:
    TrieNode* root; // This will point to our first 26 letters
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int length = word.length();
        int num; // Will contain the integer representation of our character of interest
        TrieNode* current = root;
        for (int i{}; i < length; ++i) {
            num = word[i] - 'a'; // Find the integer value of this letter.
            if (current->Children[num] == nullptr) { // If it doesn't exist in the root, make it
                current->Children[num] = new TrieNode();
            }
            current = current->Children[num]; // Move to the next letter
        }
        current->isWord = true; // This signals that the characters we just traversed in sequence make up a word
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int length = word.length();
        int num;
        TrieNode* current = root;
        for (int i{}; i < length; ++i) {
            num = word[i] - 'a';
            if (current->Children[num] == nullptr) { // If the letter doesn't exist, return false
                return false;
            } else {
                current = current->Children[num]; // else it exists and we go to it
            }
        } // By the end, we are at the last character of a sequence of characters, if this was marked as a word
        // then return true, else it is a subsequene of another word, so return false;
        return current->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int length = prefix.length();
        int num;
        TrieNode* current = root;
        for (int i{}; i < length; ++i) {
            num = prefix[i] - 'a';
            if (current->Children[num] == nullptr) { // If the letter doesn't exist, return false
                return false;
            } else {
                current = current->Children[num]; // else it exists and we go to it
            }
        }
        return true; // Doesn't matter if the letter we are on is a word or not.
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */