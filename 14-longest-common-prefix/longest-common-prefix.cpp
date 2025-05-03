class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;
    int childcount = 0;

    TrieNode(char data ){
        this->data = data;
        for(int i =0;i<26;i++){
            this->children[i]=NULL;
        }
        this->isterminal = false;  

    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');

    }

    void insertword(string word){
        insertutil(word,root);
    }

    void insertutil(string word,TrieNode* root ){
        if(word.size()==0){
            root->isterminal = true;
            return;
        }
        TrieNode* child;
        int index = word[0]-'a';
        if(root->children[index]!=NULL){
            child  = root->children[index];
            
        }
        else{
            child = new TrieNode(word[0]);
            root->childcount++;
            root->children[index]=child;
        }

        insertutil(word.substr(1),child);
    }
    void lcp(string &ans,string word){
        TrieNode* temp = root;
        for(int i =0;i<word.size();i++){
            char ch = word[i];

            if(temp->childcount == 1){
                int index = ch-'a';
                ans.push_back(ch);
                temp = temp->children[index];
            }
            else{
                break;

            }
            if(temp->isterminal){
                break;
            }

        }
      

    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (string s : strs) {
        if (s.empty()) return "";  
    }
        Trie *t = new Trie();
        for(int i =0 ;i<strs.size();i++){
            t->insertword(strs[i]);
        }
        string first = strs[0];
        string ans = "";
        t->lcp(ans,first);
        return ans;

        
    }
};