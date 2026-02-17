class trie{
    public:
    bool isend;
    trie* children[26];
    trie(){

    for(int i =0;i<26;i++){
        children[i]=NULL;
    }
    isend = false;
}
};
class WordDictionary {
public:
    trie* root;
    WordDictionary() {
        root = new trie();
        
    }
    
    void addWord(string word) {
        trie* curr = root;
        for( auto ch : word){

            int idx = ch-'a';
            if(curr->children[idx]==NULL){
                curr->children[idx]=new trie();
            }
            curr = curr->children[idx];
        }
        curr->isend = true;
        
    }

    bool dfs(trie* curr,string word,int index){
        if(index == word.size()){
            if(curr->isend == true){
                return true;
            }
            else{
                return false;
            }
        }

        if(word[index]=='.'){
            for(int i =0;i<26;i++){
                if(curr->children[i]!=NULL){
                    
                    if(dfs(curr->children[i],word,index+1)) {
                        return true;
                    }
                   
                }
            }
        }
        else{
            int idx = word[index]-'a';
            if(curr->children[idx]==NULL){
                return false;
            }
            else{
                return dfs(curr->children[idx],word,index+1);

            }

        
        }
        return false;
       

    }
    
    bool search(string word) {
        trie* curr = root;
       return  dfs(curr,word,0);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */