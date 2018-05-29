class TrieNode {
public:
    bool isWord = false;
    TrieNode* child[26];
    
    TrieNode(bool word = false) {
        memset(child, 0, sizeof(child));
        isWord = word;
    }
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    void insert(string& word) {
        TrieNode* p = root;
        for(char s: word) {
            if(p->isWord) return;
            if(!p->child[s-'a']) p->child[s-'a'] = new TrieNode();
            p = p->child[s-'a'];
        }
        p->isWord = true;
    }
    
    string prefix(string& word) {
        TrieNode* p = root;
        string res = "";
        for(char s: word) {
            if(p->isWord) return res;
            if(!p->child[s-'a']) return word;
            res += s;
            p = p->child[s-'a'];
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie t; string res = "", tmp; stringstream ss(sentence);
        for(string s: dict) t.insert(s);
        while(ss >> tmp) {
            res += t.prefix(tmp) + ' ';
        }
        res = res.substr(0, res.size()-1);
        return res;
    }
};