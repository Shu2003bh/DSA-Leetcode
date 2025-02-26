class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return true;
        if(s.size()==0) return false;

        int i=0;
        int j =0;

        while(i<s.size() && j<t.size()){
            if(s[i]!=t[j]){
                j++;
            }else{
                i++;
                j++;
            }
            if(i == s.size()-1 && s[i]==t[j])
            return true;
        
        }
        return false;
       
        
    }
};