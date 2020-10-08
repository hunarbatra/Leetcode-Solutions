class Solution {
public:
    struct TrieNode {
        bool isWord;
        unordered_map<char, TrieNode*> children;
        TrieNode(): isWord(false), children(1) {};
    };

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        if(words.empty()) return result; 
        auto mycomp = [&](const string& str1, const string& str2){return str1.size() < str2.size();};
        sort(words.begin(), words.end(), mycomp);
        
        root = new TrieNode();
        for(auto& word: words) {
            if(dfs(word, 0, root, 0)) result.push_back(word);
            else insert(word);
        }
        return result;
    }
    
private:
    TrieNode* root;
    
    void insert(string& word) {
        auto run = root;
        for(char c: word) {
            if(run->children.find(c) == run->children.end()) {
                TrieNode* newnode = new TrieNode();
                run->children[c] = newnode;
            }
            run = run->children[c];
        }
        run->isWord = true;
    }
    
    bool dfs(string& word, int pos, TrieNode* node, int nb) {
        if(pos == word.size()) {
            if(node->isWord && nb > 0) return true;
            else return false;
        }
        
        if(node->children.find(word[pos]) == node->children.end()) return false;
        auto next = node->children[word[pos]];
        if(next->isWord) {
            if(dfs(word, pos+1, root, nb+1)) return true;
        }
        if(dfs(word, pos+1, next, nb)) return true;
        else return false;
    }
};