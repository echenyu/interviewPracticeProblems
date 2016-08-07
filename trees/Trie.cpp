class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {}
    
    unordered_map<char, TrieNode *> charMap; 
private:
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *current = root; 
        for(int i = 0; i < word.size(); i++) {
            if(current->charMap.find(word[i]) != current->charMap.end()) {
                current = current->charMap[word[i]]; 
            } else {
                TrieNode *newTrieNode = new TrieNode(); 
                current->charMap[word[i]] = newTrieNode; 
                current = newTrieNode; 
            }
        }
        TrieNode *newTrieNode = new TrieNode(); 
        current->charMap['\0'] = newTrieNode;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if(startsWith(word)) {
           TrieNode *current = root; 
            for(int i = 0; i < word.size(); i++) {
                current = current->charMap[word[i]];
            } 
            if(current->charMap.find('\0') != current->charMap.end()) {
                return true;
            }
        } 
        return false; 
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *current = root; 
        for(int i = 0; i < prefix.size(); i++) {
            if(current->charMap.find(prefix[i]) != current->charMap.end()) {
                current = current->charMap[prefix[i]];
            } else {
                return false;
            }
        }
        return true;  
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");