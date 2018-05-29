class Node {
public:
    Node* child[26];
    bool is_key;
    
    Node(bool word = false) {
        memset(child, 0, sizeof(child));
        is_key = word;
    }
};

class Trie {
public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for(int i = 0; i < word.size(); i++) {
            if(!p->child[word[i] - 'a']) p->child[word[i] - 'a'] = new Node();
            p = p->child[word[i] - 'a'];
        }
        p->is_key = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for(int i = 0; i < word.size(); i++) {
            if(!p->child[word[i] - 'a']) return false;
            p = p->child[word[i] - 'a'];
        }
        if(!p->is_key) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(!p->child[prefix[i] - 'a']) return false;
            p = p->child[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */