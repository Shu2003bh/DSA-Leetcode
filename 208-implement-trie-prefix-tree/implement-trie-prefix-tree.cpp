class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d) {
        this->data = d;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
    
};

class Trie {
public:
TrieNode* root;
    Trie() {
         root = new TrieNode('\0');
    }
    
    void insert(string word)  {
        insertutil(root, word);
    }

    void insertutil(TrieNode* root, string word) {
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertutil(child, word.substr(1));
    }
    
    bool search(string word) {
        return searchutil(root, word);
    }

    bool searchutil(TrieNode* root, string word) {
        if (word.size() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
            return searchutil(child, word.substr(1));
        }
        else {
            return false;
        }
    }
    bool startsWith(string prefix) {
        return searchwith(root,prefix);
        
    }
    bool searchwith(TrieNode* root, string word) {
        if (word.size() == 0) {
           return true;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
            return searchwith(child, word.substr(1));
        }
        else {
            return false;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */